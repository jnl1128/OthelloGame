#include <bangtal>
#include <iostream>
using namespace bangtal;
using namespace std;

ObjectPtr board[8][8];

enum class State {
	BLANK,//0
	POSSIBLE,//1
	BLACK,//2
	WHITE//3
};


State board_state[8][8];//보드 상태 저장

enum class Turn {
	BLACK,
	WHITE
};

Turn turn = Turn::BLACK; //black이 선

void setState(int x, int y, State state) {
	switch (state) {
		case State::BLANK: board[y][x]->setImage("images/blank.png"); break;
		case State::POSSIBLE: board[y][x]->setImage(turn == Turn::BLACK ? "images/black possible.png" :"images/white possible.png" ); break;
		case State::BLACK: board[y][x]->setImage("images/black.png"); break;
		case State::WHITE: board[y][x]->setImage("images/white.png"); break;
	}
	board_state[y][x] = state;
	
}

bool checkPossible(int x, int y, int dx, int dy) { 
	State self = turn == Turn::BLACK ? State::BLACK : State::WHITE;//black 놓을 차례인지 -> 아니라면 white놓을 차례
	State other = turn == Turn::BLACK ? State::WHITE : State::BLACK;
	
	bool possible = false;//디폴트 놓을 수 없음
	for (x += dx, y += dy; x >= 0 && x < 8 && y >= 0 && y < 8; x += dx, y += dy) {//dx, dy만큼 움직여서
		if (board_state[y][x] == other) {//나랑 다른 색이라면
			possible = true;//possible이미지가 놓일 수 잇는 상태로 바뀌고
			
		}
		else if (board_state[y][x] == self) {//그 전에는 나랑 다른 색이고, 이젠 나랑 같은 색이라면
			return possible;// possible이미지가 놓일 곳임을 의미하는 possible
		}
		else {
			return false;
		}
	}
	return false;
}

bool checkPossible(int x, int y) {

	if (board_state[y][x] == State::BLACK) return false;//이미 검은 돌 놓인 상태면 이 함수 끝
	if (board_state[y][x] == State::WHITE) return false;//이미 흰 돌 놓인 상태면 이 함수 끝
	setState(x, y, State::BLANK);//나머지는 blank상태임 그리고 아래 코드 실행


	int delta[8][2] = {
		{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}//북, 북동, 동, 남동, 남, 남서, 서, 북서
	};
	bool possible = false;//디폴트는 possible이미지가 놓일 수 없도록
	for (auto d: delta) {
		if (checkPossible(x, y, d[0], d[1])) possible = true;//8개 방향에 possible이미가 놓일 곳이 있다면
	}

	return possible; 
}

void reverse(int x, int y, int dx, int dy) {
	State self = turn == Turn::BLACK ? State::BLACK : State::WHITE;//지금 차례가 뭔지
	State other = turn == Turn::BLACK ? State::WHITE : State::BLACK;// self가 black이면, other는 white임. (서로 반대)

	bool possible = false;
	for (x += dx, y += dy; x >= 0 && x < 8 && y >= 0 && y < 8; x += dx, y += dy) {
		if (board_state[y][x] == other) {//지금 돌이 현 State와 다른 색이면
			possible = true;
			
		}
		else if (board_state[y][x] == self) {//지금 돌이 현 State와 같은 색이고
			if (possible) {//지금 돌 전에 8개 방향으로, 현 State와 다른 색이 있었다
				for (x -= dx, y -= dy; x >= 0 && x < 8 && y >= 0 && y < 8; x -= dx, y -= dy) {
					if (board_state[y][x] == other) {//지금 돌 전으로 8개의 방향 중 그 하나로 돌아가면서 현 State랑 다른 색이라면
						setState(x, y, self);//현 State의 색으로 세팅을 바꿔준다
					}
					else {
						return;
					}
				}
				
			}
		}
		else {
			return ;
		}
	}
	
}

void reverse(int x, int y) {

	int delta[8][2] = {
		{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}
	};
	bool possible = false;//기본은 색 바꾸지 못함
	for (auto d : delta) {
		reverse(x, y, d[0], d[1]);
	}

}

bool setPossible() {
	//8*8의 모든 위치에 대해서 놓여질 수 있으면 상태를 possible로 바꾼다
	bool possible = false;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (checkPossible(x, y)) {
				setState(x, y, State::POSSIBLE);
				possible =  true;
			}
		}
	 }
	return possible;
}
int main() {

	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);

	auto scene = Scene::create("Othello", "images/background.png");

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			board[y][x] = Object::create("images/blank.png", scene, 40 + x * 80, 40 + y * 80);
			board[y][x]->setOnMouseCallback([&, x, y](ObjectPtr object, int, int, MouseAction)->bool {
				if (board_state[y][x] == State::POSSIBLE) {
					if (turn == Turn::BLACK) {//black차례라면
						setState(x, y, State::BLACK);
						reverse(x, y);
						turn = Turn::WHITE;
					}
					else {//white차례라면
						setState(x, y, State::WHITE);
						reverse(x, y);
						turn = Turn::BLACK;
					}
					if (!setPossible()) {
						turn = turn == Turn::BLACK ? Turn::WHITE : Turn::BLACK;
						if (!setPossible()) {
							showMessage("end game");
						}
					}

				}
				
				return true;
				});
			board_state[y][x] = State::BLANK;

		}
	}

	setState(3, 3, State::BLACK);
	setState(4, 4, State::BLACK);
	setState(3, 4, State::WHITE);
	setState(4, 3, State::WHITE);

	setPossible();

	startGame(scene);

}