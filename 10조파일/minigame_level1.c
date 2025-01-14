#include "main.h"

extern int next;
extern int heart;




//=======================================================================================
//avoid_F_game

void start_avoid_F_level1()
{
    fflush(stdin);   //입력 버퍼 비우기
    cls;
    CursorView(0);
    int life = 3;   // 목숨
    int score = 0;   // 게임 점수

    while (life > 0 && score < DEAD_SCORE)
    {
        draw_pan();
        gotoxy_1(5, 11);
        printf("아무키나 누르면 시작합니다");
        system("pause > nul");       // 화면 일시정지 시켜주는 것
        gotoxy_1(5, 11);
        printf("                          ");

        score += playGame(&life); // 게임 실행 및 점수 합산
    }
    if (score < DEAD_SCORE)
    {
        cls;
        gotoxy_1(15, 10);
        printf("Game OVER!\n");
        gotoxy_1(12, 11);
        printf("당신의 점수는 %d점입니다", score);
        gotoxy_1(10, 12);
        system("pause");
        CursorView(1);

        minus_heart();
        cls;
    }
    else
    {
        cls;
        gotoxy_1(15, 10);
        printf("Mission clear!\n");
        gotoxy_1(10, 12);
        system("pause");
        CursorView(1);

        plus_heart();
        cls;
    }
}

int playGame(int* life)
{
    struct obstacle F[SIZE_F] = { 0, };
    int i = 0;
    int score = 0;              // 게임 점수
    int px = 10;                // 플레이어 위치
    int count = 0;


    while (1)
    {
        gotoxy_1(25, 4);
        printf("Score: %d", score); // 점수 출력
        gotoxy_1(25, 5);
        printf("Life: %d", *life);  // 목숨 출력

        // F 만드는 부분
        if (count % LEVEL_1 == 1)      // 루프가 돌면서 변수 count가 증가
        {                            // 거기에 F의 빈도수를 나눈 나머지가 1일 때 F를 만듬
            for (i = 0; i < SIZE_F; i++)
            {
                if (F[i].exist == FALSE)        // F가 없을 때
                {
                    F[i].exist = TRUE;          // F가 있다고 만들고
                    F[i].x = 2 + rand() % 18;   // 랜덤으로 F의 위치 생성
                    F[i].y = 1;
                    break;
                }
            }
        }

        // 키 입력
        if (count % PLAYER_SPEED == 1)  // 플레이어 속도 제한하는 것
        {
            if (IsKeyDown(VK_LEFT))
            {
                if (px >= 3)             // 화면 밖으로 나가지 않게 범위를 3에서 18 사이로 설정함
                {
                    gotoxy_1(px, 23);
                    printf(" ");
                    px--;
                }
            }
            else if (IsKeyDown(VK_RIGHT))
            {
                if (px <= 18)
                {
                    gotoxy_1(px, 23);
                    printf(" ");
                    px++;
                }
            }
        }

        // F 이동
        if (count % SPEED_1 == 1)
        {
            for (i = 0; i < SIZE_F; i++)
            {
                if (F[i].exist == TRUE)  // F가 존재할 때
                {
                    gotoxy_1(F[i].x, F[i].y);
                    printf(" ");         // 먼저 F 지우기
                    if (F[i].y >= 23)    // F가 판 밖으로 나가면
                    {
                        F[i].exist = FALSE;  // F 삭제와 점수 추가
                        score += 5;
                        continue;
                    }
                    F[i].y++;            // 범위 내면 F 떨어뜨리기
                    gotoxy_1(F[i].x, F[i].y);
                    printf("F");
                }
            }
        }
        //점수가 DEAD_SCORE점 이상이면 게임 종료
        if (score >= DEAD_SCORE)
        {
            return score;
        }
        // 죽었을 때
        for (i = 0; i < SIZE_F; i++)
        {
            if (F[i].exist == TRUE && F[i].x == px && F[i].y == 23)  // F와 플레이어가 부딪히면
            {
                (*life)--;                      // 목숨 깎고
                system("cls");
                if (*life > 0)                  // 목숨이 있으면 다시 시작
                {
                    return score;
                }
                else                            // 목숨이 없으면 게임 종료
                {
                    return score;
                }
            }
        }
        // 플레이어 출력
        gotoxy_1(px, 23);
        printf("A");
        count++;
        Sleep(20);
    }
}

void gotoxy_1(int x, int y)
{
    COORD pos = { 2 * x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

BOOL IsKeyDown(int Key) // 키보드 입력 받는 함수
{
    return ((GetAsyncKeyState(Key) & 0x8000) != 0);
}

void draw_pan() // 게임 화면
{
    int i;
    for (i = 0; i <= 20; i++) // x
    {
        gotoxy_1(i + 1, 0);
        printf("-");
        gotoxy_1(i + 1, 24);
        printf("-");
    }
    for (i = 0; i <= 22; i++) // y
    {
        gotoxy_1(1, i + 1);
        printf("|");
        gotoxy_1(21, i + 1);
        printf("|");
    }
}




//=====================================================================================================
//숫자 맞추기 게임     

void guessNumberGame_level1()
{
    fflush(stdin);
    cls;

    int targetNumber, userGuess, attempts;
    int score = 0;

    printf("숫자 맞추기에 오신 걸 환영합니다！\n");
    printf("한정된 횟수 내에서 무작위로 생성된 숫자를 맞혀보세요!\n");
    CursorView(1);
    for (int i = 0; i < 1; i++)
    {
        targetNumber = 1 + rand() % 50;
        attempts = 0;
        printf("\n총 %d번의 시도 중에서 숫자를 맞혀주세요.(1-%d)\n", 6, 50);

        while (attempts < 6)
        {
            printf("제 %d 차 시도: ", attempts + 1);
            scanf("%d", &userGuess);
            attempts++;

            if (userGuess == targetNumber) {
                printf("정답!\n");

                score++;
                break;
            }
            else if (userGuess < targetNumber)
            {
                printf("너무 낮아요.\n\n");
            }
            else
            {
                printf("너무 높아요.\n\n");
            }
        }
        if (attempts == 6 && userGuess != targetNumber)
        {
            printf("오답입니다! 정답은 %d 입니다!\n", targetNumber);
        }
    }
    printf("\n종료되었습니다．성적은：%d\n", score);
    Sl; Sl;
    cls;
    switch (score)
    {
    case 0:
        printf("정답을 맞추지 못해 하트가 감소합니다.");
        Sl;
        minus_heart();
        break;
    case 1:
        printf("정답을 맞추어서 하트가 증가합니다.\n");
        Sl;
        plus_heart();
        break;
    }
    cls;
}




//===============================================================================================================
//미스터리퀴즈    

void mysteryQuiz_level1()
{
    char c, ans[9] = { 0 };
    int a, i, count = 0;
    int t1 = time(0), t2 = time(0) + 15;            //t2에 더하는 수가 제한시간
    struct QUIZ p[5] = { {11,11,"14"},{28,91,"11218191"},{45,91,"11415191"},{12,34,"11213141"},{37,39,"327191"} };

    i = rand() % 5;

    cls;
    //정답은 최대 8글자라고 설명 필요
    gotoxy(40, 10);
    printf("11#13 = 1331");
    gotoxy(40, 12);
    printf("15#37 = 11315171");
    gotoxy(40, 14);
    printf("64#48 = 426181");

    gotoxy(40, 16);
    printf("%d#%d ? ", p[i].one, p[i].two);

    time_map(83, 13);

    while (playtime(&t1, t2, 49, 7))
    {
        gotoxy(48 + count, 16);
        if (_kbhit())
        {
            c = _getch();
            if (c == 8)
            {
                if (count > 0)
                {
                    ans[count] = 0;
                    count--;
                    printf("\b \b");
                }
            }
            else if (c == 13)
                break;
            else if (c >= 48 && c <= 57)
            {
                if (count < 9)
                {
                    ans[count] = c;
                    printf("%c", c);
                    count++;
                }
            }
        }
    }

    gotoxy(40, 20);

    if (!strcmp(ans, p[i].answer))
    {
        printf("정답!");
        plus_heart();
    }
    else
    {
        printf("정답을 맞추지 못했군요...아쉽습니다");
        minus_heart();
    }

    //하트 조정 필요
    Sl; Sl;
}





//=========================================================================================================
//수강신청 클릭 

double get_current_time_in_ms()
{
    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);

    ULARGE_INTEGER ui;
    ui.LowPart = ft.dwLowDateTime;
    ui.HighPart = ft.dwHighDateTime;

    return (double)ui.QuadPart / 10000.0;  // 밀리초 단위로 변환
}

// 밀리초를 초로 변환하여 출력
int print_time_in_seconds(double milliseconds)
{
    double sec = 0.0, sec_print = 50.0;
    int min = 0;
    sec = milliseconds / 1000.0;
    min = 29 + (int)sec / 10;
    sec_print = sec + 50;
    if (sec_print >= 60)
        sec_print = sec_print - 60;
    printf("\r오전09:%2d:%4.2f ", min, sec_print);
    //printf("%d %4.2f", min, sec);
    if (sec >= 19.90)
    {
        printf("\n엥!\n");
        return 1;
    }
    fflush(stdout);
}

int time_attack_game_level1()
{
    fflush(stdin);
    cls;
    int time_over = 0;
    double start_time, end_time, elapsed_time;
    printf("현재 오전 9시 29분 50초입니다. 오전 9시 30분 00초에 진행되는 수강신청에 도전하세요! 엔터 키를 눌러서 시작하세요...\n");
    while (getchar() != '\n');
    printf("측정 시작!\n");
    sound();
    start_time = get_current_time_in_ms();
    printf("측정 중... (엔터 키를 눌러서 종료하세요)\n");
    print_time_in_seconds(0, time_over);

    while (!_kbhit())    //측정중...
    {
        Sleep(100);
        elapsed_time = get_current_time_in_ms() - start_time;
        time_over = print_time_in_seconds(elapsed_time);
        if (time_over == 1)
        {
            printf("시간을 못 보셨군요. 다음 학기의 당신이 책임질겁니다...\n");
            break;
        }
    }
    printf("\n측정 종료!\n");
    end_time = get_current_time_in_ms();
    double dif_time = (end_time - start_time) / 1000.0 - 10.0;    //오차 시간(초 단위) -> 점수 계산이나 클리어 정도 결정 가능
    printf("\n%.2f\n", dif_time);
    Sl; Sl;

    if (dif_time >= 0.5 || dif_time <= -0.5)    //오차범위 0.5
        minus_heart();
    else
        plus_heart();
    cls;
}






//====================================================================================================
//화살표 매칭

void matching_arrow_level1()
{
    fflush(stdin);

    cls;
    CursorView(1);
    gotoxy(40, 20);
    printf("10개의 랜덤한 알파벳에 대응되는 화살표를 제한시간 안에 매치하는 게임입니다.");
    Sleep(2000);
    cls;
    //위(72,U+2191), 아래(80,U+2193), 왼쪽(75,U+2190), 오른쪽(77,U+2192)
    int arrow[] = { 72,80,75,77 };
    int rand_arrow[10] = { 0 };
    int match = 0;
    int t1 = time(0), t2 = time(0) + 10;            //t2에 더하는 숫자가 제한시간
    int x = 40, y = 20;

    gotoxy(x, y);
    for (int i = 0; i < 10; i++)
    {
        rand_arrow[i] = arrow[rand() % 4];
        if (rand_arrow[i] == 72)
            printf("W  ");
        else if (rand_arrow[i] == 80)
            printf("S  ");
        else if (rand_arrow[i] == 75)
            printf("A  ");
        else
            printf("D  ");
    }

    gotoxy(x, y);
    while (playtime(&t1, t2, 58, 15))
    {
        gotoxy(x, y);

        if (_kbhit())
        {
            char ch = _getch();
            if (ch == rand_arrow[match])
            {
                textcolor(GREEN);
                if (rand_arrow[match] == 72)
                    printf("W  ");
                else if (rand_arrow[match] == 80)
                    printf("S  ");
                else if (rand_arrow[match] == 75)
                    printf("A  ");
                else
                    printf("D  ");
                textcolor(WHITE);

                match++;
                x += 3;
                if (match > 9)
                    break;
                continue;
            }
            else
            {
                continue;
            }
        }
    }
    if (match > 9)
    {
        cls;
        np(10);
        middle("축하드립니다!! 클리어하였습니다!"); Sl; Sl;
        cls;
        np(10);
        middle("학점을 획득하였습니다!"); Sl; Sl;
        plus_heart();
        cls;
    }
    else
    {
        cls;
        printf("안타깝네요..더 분발해서 오세요!"); Sl; Sl;
        cls;
        minus_heart();
    }
}





//=============================================================================================================
//교수님 피하기


void avoid_prof_level1()
{
    POS prof = { 22,12 };
    POS player = { 1,1 };

    char clear = 1;
    int r = 1, se = 0;
    int t1 = time(0), t2 = time(0) + 10;        //t2에 더하는 값이 제한시간


    cls;

    map();

    print_Cur(prof.x, prof.y);
    gotoxy(player.x, player.y);

    while (playtime(&t1, t2, 50, 5))
    {

        if (!(se % 10))							//교수님 이동방향
        {
            r = rand() % 4;
        }
        //교수님 움직임
        CursorView(0);
        del_Cur(prof.x, prof.y);

        switch (r)
        {

            //아래
        case 0:
            if (prof.y < PFy2_1)
                prof.y++;
            break;

            //위
        case 1:
            if (prof.y > Py1)
                prof.y--;
            break;

            //오른쪽
        case 2:
            if (prof.x < PFx2_1)
                prof.x++;
            break;

            //왼쪽
        case 3:
            if (prof.x > Px1)
                prof.x--;
            break;
        }

        print_Cur(prof.x, prof.y);
        gotoxy(player.x, player.y);
        wall(prof.x, prof.y, &r);
        CursorView(1);




        if (!(se % 2))					//플레이어 움직임
        {
            printf("we\b\b");

            if (_kbhit())
            {
                int ch = _getch();
                if (ch == 224)
                {
                    ch = _getch();
                    switch (ch)
                    {
                    case 77:
                        if (player.x < Px2_1)
                        {
                            printf("  ");
                            player.x++;
                            gotoxy(player.x, player.y);
                            printf("we\b\b");
                        }
                        break;
                    case 75:
                        if (player.x > Px1)
                        {
                            printf("  ");
                            player.x--;
                            gotoxy(player.x, player.y);
                            printf("we\b\b");
                        }
                        break;
                    case 72:
                        if (player.y > Py1)
                        {
                            printf("  ");
                            player.y--;
                            gotoxy(player.x, player.y);
                            printf("we\b\b");
                        }
                        break;
                    case 80:
                        if (player.y < Py2_1)
                        {
                            printf("  ");
                            player.y++;
                            gotoxy(player.x, player.y);
                            printf("we\b\b");
                        }
                        break;
                    }

                }
            }

        }

        se++;

        if (avoid_check(player.x, player.y, prof.x, prof.y))
        {
            clear = 0;
            break;
        }
        Sleep(20);
    }

    cls;

    if (!clear)
    {
        np(10);
        middle("들켜버렸다...\n");
        minus_heart();
    }
    else
    {
        np(10);
        middle("들키지 않고 시험지를 얻었다\n");
        plus_heart();
    }

    Sleep(1000);
    cls;
}

static void map()
{
    int i, n;
    for (i = 0; i < WIDTH_1; i++)
    {
        textcolor(GREEN);
        printf("0");
    }
    for (i = 0; i < LENGTH_1; i++)
    {
        printf("\n0");

        for (n = 0; n < WIDTH_1 - 2; n++)
            printf(" ");

        printf("0");
    }
    printf("\n");
    for (i = 0; i < WIDTH_1; i++)
    {
        printf("0");
    }
    textcolor(WHITE);
}



static void wall(int x, int y, int* r)		//벽에 닿으면 이동방향 바꾸게 함
{
    int i, count = 0;
    char ch[5] = { 100,0,1,2,3 };
    char random[4] = { 0 };

    if (x == Px1)
    {
        ch[0] = ch[4] = -1;
    }
    else if (x == PFx2_1)
    {
        ch[0] = ch[3] = -1;
    }

    if (y == Py1)
    {
        ch[0] = ch[2] = -1;
        ;
    }
    else if (y == PFy2_1)
    {
        ch[0] = ch[1] = -1;
    }

    if (ch[0] == -1)
    {
        for (i = 0; i < 5; i++)
        {
            if (ch[i] != -1)
            {
                random[count] = ch[i];
                count++;
            }
        }
        *r = random[rand() % count];
    }
}