# Attendance Management System
## Contents
1. [Contributors](#Contributors)
2. [Problem Statement](#Problem-Statement)
3. [Sub-Group](#Sub-Group)
4. [Requirements (Stories)](#Requirements)
5. [Use Case](#Use-Case)
6. [Domain Model](#Domain-Model)
7. [System Design Document(SDD)](#System-Design-Document)
## Contributors

|  이름  |   학번   |   Github ID   | 비고 |
| :----: | :------: | :-----------: | :--: |
| 김지혜 | 20161863 |  jihye-kim11  |
| 박종혁 | 20185536 |    jjonyo     |  PM  |
| 윤진호 | 20161676 |  jhyoon9705   |
| 이한용 | 20151322 |    lhy0718    |
| 정나린 | 20180396 |    jnl1128    |
|  진겸  | 20153031 | kevinOriginal |

## Problem Statement

### Problem and Purpose

코로나-19 바이러스로 인한 비대면 수업이 장기화되었다. 제 4차 감염이 예상되는 가운데, 초중고등학교 학생들은 돌봄 부재 속에 방치되어 있다. 비대면 상황 속에서 교수자, 학부모 학생은 아래와 같은 문제점을 겪고 있다.

1. 교수자는 학생에게 공지사항이 제대로 전달이 되었는지 확인하기 어렵다.
1. 학부모는 자녀의 수업 공지사항을 확인하기 어렵다.
1. 학생은 해당 수업에 출결 처리가 정상적으로 처리되었는지 확인하기 어렵고 수업 참여에 대한 동기부여를 얻기 어렵다.

우리는 교수자, 학부모, 학생 모두가 비대면 상황에서 돌봄 공백을 느끼지 않을 수 있는 서비스가 있었으면 좋겠다. 우리는 교수자가 학생과 학부모에게 공지사항을 일괄 전송하고 확인했는지 여부까지 파악해 소통의 문제를 해결할 수 있기를 원한다. 우리는 학부모가 수업별 공지사항를 교수자로부터 확인받아 자녀에 대한 고민을 덜길 바란다. 마지막으로 우리는 학생들이 수업 참여에 대한 동기부여를 잃지 않고 출석과 과제 참여를 높이기 위한 시스템이 있기를 바란다.

### Scenarios

#### 출결관리 웹

출결관리 웹에 접속함과 동시에 로그인 화면이 뜬다. 이때 로그인을 할 수 있는 사용자는 회원가입이 되어있는 교수자와 학생이다.

교수자 계정으로 로그인할 경우, 미리 등록된 정보에 따라 교수자(사용자)가 담당하고 있는 수업의 목록들이 테이블 형식으로 화면에 뜨기 된다. 교수자는 이 화면에서 `추가`, `수정`, `삭제` 버튼들을 통해 수업 목록에서 수업을 추가, 수정, 삭제할 수 있다. 수업 목록들 중 하나를 클릭하여 들어갈 경우 해당 수업을 수강하고 있는 학생들의 명단이 테이블 형식으로 뜨고, 학생들의 이름 옆에는 학생별로 학생의 당일 출결을 체크할 수 있는 4가지(출석, 결석, 지각, 공결)의 체크박스가 있다. 교수자는 이 체크박스들을 단순히 체크함으로써 학생들의 출결체크가 가능하게 된다.  또한 학생들 목록 중에서 검색을 통해 검색조건(학생 이름 등)에 부합하는 학생만을 따로 출력이 가능하다. 교수자는 학생에게 출결과 관련하여 별점(Star Point)를 부과할 수 있으며, 학생들은 자신의 별점과 학급내 별점 순위의 백분율 값을 확인할 수 있다. 또한 교수는 자신이 담당하는 과목의 목록을 확인할 수 있고, 과목별로 해당 과목을 수강하는 학생들에게 일괄적으로 공지를 보낼 수 있다.

학생은 회원 가입시 학교, 학번, 이름 등의 정보를 서비스에 제공한다. 학생은 자신의 학교에서 개설된 수업 목록 중에서 수강중인 수업을 검색하여 수업 그룹에 들어갈 수 있다. 학생이 그룹 신청을 요청하면 과목을 개설한 교수자의 확인 절차를 통해 신청이 완료 또는 거절된다.

## Sub-Group

| Group     | Desecription                                                                    | Contributor    |
| --------- | ------------------------------------------------------------------------------- | -------------- |
| Auth+Core | 개발 환경 세팅 및 사용자 모델 정의, 사용자가 앱에 로그인 및 회원가입            | 김지혜, 진겸   |
| Teacher   | 학생에 대한 출석 체크, 수업 및 학생 목록, 정보 조회, 출결 결과 및 공지사항 발송 | 이한용, 정나린 |
| Student   | 수업 신청, 개인 출결현황 및 수업참여도 확인                                     | 박종혁, 윤진호 |

## Requirements 

- [Core & Auth](/Core/Requirements.md)
- [Teacher](/Teacher/Requirements.md)
- [Student](/Student/Requirements.md)

## Use Case

- [Core & Auth](/Core/UseCases.md)
- [Teacher](/Teacher/UseCases.md)
- [Student](/Student/Usecases.md)

Actor | Actor's Goal | Use Case Name
-|-|-
교수자 | 교수자가 본인임을 인증하고 가입 및 로그인을 할 수 있기 위함 | 교수자 온보딩 (UC-1)
교수자 | 학생들의 출결을 관리 하기 위함 | 출결 관리(UC-2)
교수자 | 학생에게 별점을 부여하거나 뺏기 위함 | 별점 부여 (UC-3)
교수자 | 수업을 만들고 그 정보를 관리하기 위함 | 교수의 수업 관리 (UC-4)
교수자 | 학부모 혹은 학생에게 공지사항을 발송하기 위함 | 공지 발송(UC-5)
교수자 | 자신의 프로필 및 정보를 수정하기 위함 | 교수자정보관리(UC-6)
학생 | 학생이 본인임을 인증하고 가입 및 로그인을 할 수 있기 위함 | 학생 온보딩 (UC-7)
학생 | 나의 이번 학기 수업 목록을 선택해서 그 정보를 보기 위함 | 수업 신청 (UC-8)
학생 | 학생이 수업의 공지 및 출결상태를 확인 하기 위함 | 수업상태확인(UC-9)
학생 | 자신의 프로필 및 정보를 수정하기 위함 | 학생정보관리(UC-10)
교수자,학생 | 지정된 도메인의 메일주소를 가지고 있는지 확인하기 위함 | UC-1,UC-7
교수자,학생 | 서비스 회원 탈퇴를 하기 위함 | 회원탈퇴(UC-11)
서버 | 학부모가 학생들의 출결상태를 확인하기 위함 | 출결 확인(UC-12)
서버,클라이언트 | 사용자 요청에 대한 유효성 검사 (타입, 범위, URL, ...) | 유효성 검사(UC-13)

## Domain Model

- [Core & Auth](/Core/DomainModel.md)
- [Teacher](/Teacher/DomainModel.md)
- [Student](/Student/DomainModel.md)

## System Design Document

### Core
- [Sequence Diagram](/Core/SequenceDiagram.md)
- [Class Diagram](/Core/Classdiagram.md)

### Teacher
- [Sequence Diagram](/Teacher/SequenceDiagram.md)
- [Class Diagram](/Teacher/Classdiagram.md)

### Student
- [Sequence Diagram](/Student/SequenceDiagram.md)
- [Class Diagram](/Student/ClassDiagram.md)
