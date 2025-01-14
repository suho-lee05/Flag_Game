#include "main.h"
extern int next;
extern int heart;



struct FLAG* flag()                     //좌표 할당 함수
{
    int i, n;
    static struct FLAG fl[GAME] = { 0,0,0 };

    for (i = 0; i < GAME; i++)
    {
        fl[i].x = rand() % 65 + 1;      //x값 할당
        fl[i].y = rand() % 30 + 1;      //y 할당
        fl[i].m = i;

        for (n = 0; n < i; n++)//중복 검사
        {
            if ((fl[n].x == fl[i].x) && (fl[n].y == fl[i].y))
            {
                fl[i].x = rand() % 65 + 1;
                fl[i].y = rand() % 30 + 1;
                n--;
            }
        }
    }
    return fl;      // 배열 포인터 반환
}

/*
darkBLUE,	//1
Dark Green,	//2
darkSkyBlue,    //3
DarkRed,  	//4
DarkPurple,	//5
DarkYellow,	//6
GRAY,		//7
DarkGray,	//8
BLUE,		//9
GREEN,		//10
SkyBlue,	//11
RED,		//12
PURPLE,		//13
YELLOW,		//14
WHITE		//15
*/
void flag_stage1(struct FLAG* p)
{
    int i;

    for (i = 0; i < GAME; i++)
    {
        if ((p[i].x == -100))
            continue;

        gotoxy(p[i].x, p[i].y);
        switch (i)
        {
        case 0:
            textcolor(13);
            printf("F");
            break;
        case 1:             //벌칙 깃발
            textcolor(1);
            printf("F");
            break;
        case 2:
            textcolor(2);
            printf("F");
            break;
        case 3:
            textcolor(3);
            printf("F");
            break;
        case 4:             //이득 깃발
            textcolor(4);
            printf("F");
            break;
        case 5:
            textcolor(5);
            printf("F");
            break;
        case 6:
            textcolor(6);
            printf("F");
            break;
        case 7:
            textcolor(7);
            printf("F");
            break;
        case 8:
            textcolor(8);
            printf("F");
            break;
        case 9:
            textcolor(9);
            printf("F");
            break;
        case 10:
            textcolor(10);
            printf("F");
            break;
        case 11:
            textcolor(11);
            printf("F");
            break;
        case 12:
            textcolor(12);
            printf("F");
            break;
        }
        textcolor(WHITE);

    }

}
void flag_stage2(struct FLAG* p)
{
    int i;

    for (i = 0; i < GAME; i++)
    {
        if ((p[i].x == -100))
            continue;

        gotoxy(p[i].x, p[i].y);
        switch (i)
        {
        case 0:
            textcolor(13);
            printf("F");
            break;
        case 1:             //벌칙 깃발
            textcolor(1);
            printf("F");
            break;
        case 2:
            textcolor(2);
            printf("F");
            break;
        case 3:
            textcolor(3);
            printf("F");
            break;
        case 4:             //이득 깃발
            textcolor(4);
            printf("F");
            break;
        case 5:
            textcolor(5);
            printf("F");
            break;
        case 6:
            textcolor(6);
            printf("F");
            break;
        case 7:
            textcolor(7);
            printf("F");
            break;
        case 8:
            textcolor(8);
            printf("F");
            break;
        case 9:
            textcolor(9);
            printf("F");
            break;
        case 10:
            textcolor(10);
            printf("F");
            break;
        case 11:
            textcolor(11);
            printf("F");
            break;
        case 12:
            textcolor(12);
            printf("F");
            break;
        }
        textcolor(WHITE);

    }

}


void flag_stage3(struct FLAG* p)
{
    int i;

    for (i = 0; i < GAME; i++)
    {
        if ((p[i].x == -100))
            continue;

        gotoxy(p[i].x, p[i].y);
        switch (i)
        {
        case 0:
            textcolor(13);
            printf("F");
            break;
        case 1:             //벌칙 깃발
            textcolor(1);
            printf("F");
            break;
        case 2:
            textcolor(2);
            printf("F");
            break;
        case 3:
            textcolor(3);
            printf("F");
            break;
        case 4:             //이득 깃발
            textcolor(4);
            printf("F");
            break;
        case 5:
            textcolor(5);
            printf("F");
            break;
        case 6:
            textcolor(6);
            printf("F");
            break;
        case 7:
            textcolor(7);
            printf("F");
            break;
        case 8:
            textcolor(8);
            printf("F");
            break;
        case 9:
            textcolor(9);
            printf("F");
            break;
        case 10:
            textcolor(10);
            printf("F");
            break;
        case 11:
            textcolor(11);
            printf("F");
            break;
        case 12:
            textcolor(12);
            printf("F");
            break;
        }
        textcolor(WHITE);
    }
}






int check(int* x, int* y, struct FLAG* p)       //플레이어가 깃발을 밟았는지 확인
{
    int i;

    for (i = 0; i < GAME; i++)
    {
        if ((*x == p[i].x) && (*y == p[i].y))   //밟았을 경우
            switch (p[i].m)                     //m값에 따라 리턴값 다르게 
            {
            case 0:
                p[i].x = -100;                  //깃발의 x값 -100으로 바꿔서 예외처리
                return 0;                       //리턴값에 따라 game10()에서 미니게임 함수 호출
                break;
            case 1:
                p[i].x = -100;
                return 1;
                break;
            case 2:
                p[i].x = -100;
                return 2;
                break;
            case 3:
                p[i].x = -100;
                return 3;
                break;
            case 4:
                p[i].x = -100;
                return 4;
                break;
            case 5:
                p[i].x = -100;
                return 5;
                break;
            case 6:
                p[i].x = -100;
                return 6;
                break;
            case 7:
                p[i].x = -100;
                return 7;
                break;
            case 8:
                p[i].x = -100;
                return 8;
                break;
            case 9:
                p[i].x = -100;
                return 9;
                break;
            case 10:
                p[i].x = -100;
                return 10;
                break;
            case 11:
                p[i].x = -100;
                return 11;
                break;
            case 12:
                p[i].x = -100;
                return 12;
                break;
            }
    }

}


void minus_stop()
{
    cls;
    CursorView(0);
    for (int i = 0; i < 10; i++)
        printf("\n");

    middle("앗 야생의 고양이가 키보드를 두드리고 도망갔습니다.!\n");
    middle("너드 컴공생은 뇌정지가 왔습니다. \n");
    middle("뇌정지로 인해 게임이 2초간 정지됩니다.\n");
    middle("{\\___/}\n");
    middle("(• ㅁ•) \n");
    middle("/ > 🐰 \n");
    middle("이 화면에서 2초간 머물다 맵으로 이동합니다...");
    Sl; Sl;
    CursorView(1);  //커서 보이기

}

void minus_restart()
{
    cls;
    CursorView(0);
    for (int i = 0; i < 10; i++)
        printf("\n");
    middle("벌칙 깃발! \n");
    middle("앗 야생의 고양이가 눈,팔,다리를 긋고 도망갔습니다.\n\n");
    middle("너드컴공생은 치명상을 입었습니다. \n\n");
    middle("눈 앞이 깜깜해집니다.. \n");
    middle("맵이 재배열되고있습니다...\n");

    middle("{\\___/}\n");
    middle("(• ㅁ•) \n");
    middle("/ > 🐰 \n");

    Sl; Sl; Sl; Sl;
    CursorView(1);  //커서 보이기
}

void minus_gotoxy()
{
    cls;
    CursorView(0);
    for (int i = 0; i < 10; i++)
        printf("\n");
    middle("벌칙 깃발! \n");
    middle("앗 야생의 고양이가 눈을 긋고 도망갔습니다.\n\n");
    middle("앞이 보이지 않는 너드컴공생은 처음 위치로 돌아갑니다..\n\n");
    middle("눈 앞이 깜깜해집니다.. \n");
    middle("처음 위치로 돌아갑니다..\n");

    middle("{\\___/}\n");
    middle("(• ㅁ•) \n");
    middle("/ > 🐰 \n");

    Sl; Sl; Sl; Sl;
    CursorView(1);  //커서 보이기
}

void plus_playtime()
{
    cls;
    CursorView(0);
    for (int i = 0; i < 10; i++)
        printf("\n");
    middle("이득 깃발! \n");
    middle("C프 족보를 얻었습니다! 하트를 하나 추가합니다!.\n\n");
    Sl; Sl; Sl; Sl;
    CursorView(1);  //커서 보이기
}
void plus_flag()
{
    cls;
    CursorView(0);
    for (int i = 0; i < 10; i++)
        printf("\n");
    middle("!아무일도 일어나지 않았다.\n");

    Sl; Sl; Sl; Sl;
    CursorView(1);  //커서 보이기
}
void plus_pass()
{
    cls;
    CursorView(0);
    for (int i = 0; i < 10; i++)
        printf("\n");
    middle("이득 깃발! \n");
    middle("C프 족보를 얻었습니다! 하트를 하나 추가합니다.\n\n");
    heart++;
    Sl; Sl; Sl; Sl;
    CursorView(1);  //커서 보이기
}