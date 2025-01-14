#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")


#define pause system("pause > nul") // 그냥 내가 많이 쓰는 커맨드를 줄여준 것이다.
#define cls system("cls") //cls입력시 화면 멈춤
#define Sl Sleep(700)
#define RED 12
#define BLUE 9
#define GREEN 10
#define YELLOW 14
#define WHITE 15
#define GAME 13
#define SIZE 41
#define MINUTE 60
//#define CMD_HEIGHT 45
//#define CMD_WIDTH 235
#define TIME_LIMIT 5000


void middle(const char* sentence);
int Console_width();
void CursorView(char show);
void gotoxy(int x, int y);
void Menu(void);
void Level1();
void Level2();
void Level3();
void start();
int game_out();

void Cursor(int x, int y);
void moveCursor(int* x, int* y, int dx, int dy);
void moveCursor1(int* x, int* y, int dx, int dy);    //보물찾기 커서 범위
void moveCursor2(int* x, int* y, int dx, int dy);
void moveCursor3(int* x, int* y, int dx, int dy);
void Cursor1();
void stage1();
void textcolor(int color_number);
void np(int);

void scenario(int);

struct FLAG* flag();
void flag_stage1(struct FLAG* p);
int check(int* x, int* y, struct FLAG* p);

int playtime(int*, int, int, int);
void game_over();
int re_select();
void game_report();
void menu_out();

void sound();

void stage_2_clear();
void stage_1_clear();

void print_level1();
void print_level2();
void print_level3();

void stage2();
void stage3();

void plus_flag();
void plus_pass();
void plus_playtime();

void minus_restart();
void minus_gotoxy();
void minus_stop();

void computer_1();

void explanation_1();

void design_computer();
void design_clear();
void design_over();

void right_menu();

void flag_stage2(struct FLAG* p);
void flag_stage3(struct FLAG* p);

void game_clear(stage);

void plus_heart();
void minus_heart();
void time_map(int, int);

void print_step(int);
int step_check_level1(int*);
int step_check_level2(int*);
int step_check_level3(int*);

//==============================================================================
//전역변수




//===============================================================================
//미니게임 레벨1

//avoid_F_game
#define SIZE_F 100
#define SPEED_1 4    // F의 스피드
#define LEVEL_1 4    // F의 출현 빈도
#define PLAYER_SPEED 2      // 플레이어의 속도
#define DEAD_SCORE 600 //이 점수를 넘어가면 게임 클리어
void start_avoid_F_level1();
void gotoxy_1(int x, int y);
BOOL IsKeyDown(int Key);
void draw_pan();
int playGame(int*);

//숫자 맞추기
void guessNumberGame_level1();
#define NUM_ROUNDS 1      // 게임 라운드
#define MAX_ATTEMPTS 6     // 라운드당 최대 시도 횟수
#define NUMBER_RANGE 50   // 무작위 범위 (0-50)

//미스터리퀴즈
void mysteryQuiz_level1();

//수강신청 클릭
int time_attack_game_level1();
double get_current_time_in_ms();
int print_time_in_seconds(double milliseconds);

//화살표 매칭
void matching_arrow_level1();

//교수님 피하기

#define WIDTH_1 45
#define LENGTH_1 25

//맵 이동 범위 1,1 ~ 43,25.		교수님은 실질적으로 1,1 ~ 39,23
#define Px1 1
#define Py1 1
#define Px2_1 43					
#define Py2_1 25					
#define PFx2_1 35
#define PFy2_1 23

void map();
void print_Cur(int, int);
void del_Cur(int, int);
char avoid_check(int, int, int, int);
void wall(int, int, int*);
void avoid_prof_level1();





//=================================================================================
//미니게임 레벨2

//avoid_F_game
void start_avoid_F_level2();
#define SPEED_2 3             // F의 스피드
#define LEVEL_2 3             // F의 출현 빈도
int playGame_level2(int* life);
void gotoxy_1_level2(int x, int y);

//숫자 맞추기
void guessNumberGame_level2();

//미스터리퀴즈
void mysteryQuiz_level2();

//수강신청 클릭
double get_current_time_in_ms_level2();
int print_time_in_seconds_level2(double milliseconds);
int time_attack_game_level2();

//화살표 매칭
void matching_arrow_level2();

//교수님 피하기
#define WIDTH_2 35                      //-10
#define LENGTH_2 20                     //-5

//맵 이동 범위 1,1 ~ 43,25.		교수님은 실질적으로 1,1 ~ 39,23
#define Px2_2 33					
#define Py2_2 20					
#define PFx2_2 25
#define PFy2_2 18

void avoid_prof_level2();





//==================================================================================
//미니게임 레벨3

//avoid_F_game
void start_avoid_F_level3();
int playGame_level3(int* life);
void gotoxy_1_level3(int x, int y);
#define SPEED_3 2             // F의 스피드
#define LEVEL_3 2             // F의 출현 빈도

//숫자 맞추기
void guessNumberGame_level3();

//미스터리퀴즈
void mysteryQuiz_level3();

//수강신청 클릭
double get_current_time_in_ms_level3();
int print_time_in_seconds_level3(double milliseconds);
int time_attack_game_level3();
void matching_arrow_level3();

//교수님 피하기
#define WIDTH_3 35                      //-10
#define LENGTH_3 17                     //-13

//맵 이동 범위 1,1 ~ 43,25.		교수님은 실질적으로 1,1 ~ 39,23
#define Px2_3 33					
#define Py2_3 17					
#define PFx2_3 25
#define PFy2_3 15

void avoid_prof_level3();

//===================================================================================
//구조체

typedef struct _POSITION
{	//위치
    int x;
    int y;
}POS;

struct obstacle
{
    int x, y;
    int exist;
};

struct QUIZ {
    short one;
    short two;
    char answer[9];
};

struct FLAG {
    short x;
    short y;
    short m;
};



void game_menu();
void minigame_explantion();
void game_explantion();


//스토리 설명
void avoid_F_story();


void guess_story();


void guess_story();


void time_attack_story();


void avoid_prof_story();

void print_developer();