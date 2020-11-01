# OthelloGame

1. 게임 설명
- 8*8판에 사각형으로 엇갈리게 검은 돌과 흰 돌을 각각 2개씩 놓고 시작한다.
- 돌은 반드시 상대방 돌을 양쪽에서 포위하여 뒤집을 수 있는 곳에 놓아야 한다.
- 돌을 뒤집을 곳이 없는 경우에는 차례가 자동적으로 상대방에게 넘어가게 된다.
- 아래와 같은 조건에 의해 양쪽 모두 더 이상 돌을 놓을 수 없게 되면 게임이 끝나게 된다.
  - 64개의 돌 모두가 판에 가득 찬 경우 (가장 일반적)
  - 어느 한 쪽이 돌을 모두 뒤집은 경우
  - 한 차례에 양 쪽 모두 서로 차례를 넘겨야 하는 경우
  - 게임이 끝났을 때 돌이 많이 있는 플레이어가 승자가 된다. 만일 돌의 개수가 같을 경우는 무승부가 된다.