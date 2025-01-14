#define _CRT_SECURE_NO_WARNINGS
#include "main.h"

extern int next = 0;
extern int heart = 6;

int main(void)
{
    int level = 0;
    srand((unsigned)time(NULL));
    system("COLOR 0F");
    start();
    while (1)
    {
        switch (next)
        {
        case 0:
            game_menu();                 //스테이지 종료시 자동으로 메뉴로 돌아옴
            break;
        case 1:
            Level1();
            break;
        case 2:
            Level2();
            break;
        case 3:
            Level3();
            break;
        }
    }

    return 0;
}


void game_menu()
{
    cls;
    char map[24][300] =
    { "┌───────────────────────────────────────────────────┐",
        "│                                                   │",
        "│                                                   │",
        "│                                                   │",
        "│                                                   │",
        "│                                                   │",
        "│                                                   │",
        "│                                                   │",
        "│                                                   │",
        "│                                                   │",
        "│                                                   │",
        "│                                                   │",
        "│                                                   │",
        "│                                                   │",
        "│                                                   │",
        "│                                                   │",
        "│                                                   │",
        "│                                                   │",
        "│                                                   │",
        "└───────────────────────────────────────────────────┘",
        "                 │                │                 ",
        "                 │                │                 ",
        "┌───────────────────────────────────────────────────┐",
        "└───────────────────────────────────────────────────┘",
    };



    //textcolor(GREEN);
    for (int i = 0; i < 24; i++)
    {
        printf("%s\n", map[i]);
    }
    //textcolor(WHITE);
    int choice = 1;
    int level = 0;


    //computer_1();
    for (int i = 0; i < 5; i++)
        printf("\n");
    gotoxy(5, 2);
    puts("┌────────────────────────────────────────┐\n");
    gotoxy(5, 3);
    puts("│          --------------------          │\n");
    gotoxy(5, 4);
    puts("│           메뉴를 선택해주세요          │\n");
    gotoxy(5, 5);
    puts("│          --------------------          │\n");
    gotoxy(5, 6);
    puts("└────────────────────────────────────────┘\n");

    gotoxy(13, 10);//65,20
    printf("[ ] 게임시작   (Select Level)");
    gotoxy(13, 12);
    printf("[ ] 미니게임 설명   (Minigame info.)");
    gotoxy(13, 14);
    printf("[ ] 게임 설명   (Game info.)");
    gotoxy(13, 16);
    printf("[ ] 게임종료   (OUT)");
    gotoxy(14, 10);
    while (1)
    {
        if (_kbhit())
        {
            int ch = _getch();

            if (ch == 13)       //Enter키
                break;
            else if (ch == 224)
            {
                ch = _getch();

                if (ch == 72)
                {
                    if (choice > 1)
                        choice--;
                }
                else if (ch == 80)
                {
                    if (choice < 5)
                        choice++;
                }
            }
            switch (choice)
            {
            case 1:
                gotoxy(14, 10);
                break;
            case 2:
                gotoxy(14, 12);
                break;
            case 3:
                gotoxy(14, 14);
                break;
            case 4:
                gotoxy(14, 16);
                break;
            }

        }
    }
    level = choice;
    switch (level)
    {
    case 1:
        gotoxy(9, 10); //61,20
        textcolor(GREEN);
        printf(">>  [ ] 게임시작     (Select Level)  \n");
        gotoxy(14, 10);
        textcolor(WHITE); Sl; Sl;    //다시 색 변경
        break;
    case 2:
        gotoxy(9, 12);
        textcolor(BLUE);
        printf(">>  [ ] 미니게임 설명 (Minigame info.)  \n");
        gotoxy(14, 12);
        textcolor(WHITE); Sl; Sl;    //다시 색 변경
        break;
    case 3:
        gotoxy(9, 14);
        textcolor(RED);
        printf(">>  [ ] 게임 설명   (Game info.)  \n");
        gotoxy(14, 14);
        textcolor(WHITE); Sl; Sl;    //다시 색 변경
        break;
    case 4:
        menu_out();
        //game_out();
        break;
    }
    cls;

    switch (level)
    {
    case 1:
        Menu();
        break;
    case 2:
        minigame_explantion();
        break;
    case 3:
        game_explantion();
        break;
    }



}


void start()
{
    cls;
    design_computer();

    while (1) {
        if (_kbhit()) {
            int ch = _getch();
            if (ch == 13)
            {
                // 엔터 키가 눌렸을 때
                explanation_1();
                break;
            }
        }
    }
}

void game_explantion()
{

    printf("학점 배치 표\n");

    printf("5 * ♥ = A+ \n");

    printf("4 * ♥ = A0\n");

    printf("3 * ♥ = B0\n");

    printf("2 * ♥ = C0 \n");

    printf("1 * ♥ = D0\n");

    printf("0 * ♥ = F\n\n\n");

    printf("게임 설명\n");

    printf("_______________________________________________________________\n");

    printf(" * 은 플레이어입니다.\n");

    printf("컴퓨터 모니터 속에 숨겨진 A를 찾아 다음 단계로 넘어가야 합니다.\n");

    printf("중간 중간 미니게임을 통과하여 ♥를 증가시켜 학점을 높여보세요!\n");

    printf("레벨이 올라갈수록 기본 하트 개수가 감소합니다.\n\n");

    printf("스테이지 속 정해진 이동횟수를 넘기면 ♥ 가 감소합니다. 주의하세요!\n\n");

    printf("(돌아가려면 [Esc] 키를 누르세요) ");

    while (1)
    {


        if (_kbhit())
        {
            int ch = _getch();

            if (ch == 27)                  //esc
            {
                break;

            }

        }
    }
    game_menu();



}

void minigame_explantion()
{
    printf("\n< F피하기 게임 >\n");

    printf("방향키 -> <- 두 개를 사용하여 하늘에서 떨어지는 F학점을 피해라!\n\n");

    printf("< 수강신청 게임 >\n");

    printf("네이비즘 소리에 맞춰 9시 30분에 진행되는 수강신청을 올클하여 너드 컴공생을 구해보세요!\n\n");

    printf("< 화살표 매칭 >\n");

    printf("너드 컴공생의 순발력을 보여주세요! 제한시간 안에 화살표들의 방향을 맞춰야 합니다.\n\n");

    printf("< 미스테리 퀴즈 >\n");

    printf("너드 컴공생의 창의력을 마음껏 보여주세요! 화면에 나타나는 문제를 창의력을 발휘하여 풀어야 합니다.\n\n");

    printf("< 숫자 맞추기 게임 >\n");

    printf("컴퓨터공학개론에서 배우는 이진검색 알고리즘을 활용해 제한시간 안에 정답을 맞춰보세요!\n\n");

    printf("< 교수님 피하기 >\n");

    printf("교수님이 연구실을 유유히 돌아다니고 있습니다. 교수님의 시야를 피해 달아나세요!\n\n");

    printf("돌아가려면 [Esc] 키를 누르세요 ");

    while (1)
    {


        if (_kbhit())
        {
            int ch = _getch();

            if (ch == 27)                  //esc
            {
                break;

            }

        }
    }
    game_menu();





}


void explanation_1()
{
    Sl;
    fflush(stdin);
    int count = 0;
    cls;
    CursorView(0);             // 커서 숨기기
    gotoxy(100, 50);
    textcolor(GREEN);
    printf("<<<  계속하려면 [Enter] 키를 입력하세요...  >>>");
    textcolor(WHITE);
    while (count != 6)
    {
        getchar();
        count++;
        if (count == 1)
        {
            gotoxy(85, 25);
            printf("< 군대 만기전역을 마친 너드 컴공생은 2학년으로 복학하게 된다. >");
        }
        else if (count == 2)
        {
            gotoxy(85, 29);
            printf("< 하지만 어김없이 그를 위협하는 수많은 학교생활.. >");
        }
        else if (count == 3)
        {
            gotoxy(85, 33);
            printf("< 그는 학교에서 일어나는 온갖 학교생활을 헤쳐나가 >");
        }
        else if (count == 4)
        {
            gotoxy(85, 37);
            printf("< 학교에 숨겨진 A를 찾아 학년을 마쳐야 한다. >");
        }
        else if (count == 5)
        {
            gotoxy(85, 41);
            printf("< 과연 너드 컴공생은 학교를 무사히 졸업하여 진정한 공대 너드남이 될 수 있을까..? >");
        }
        else
            break;
    }

    CursorView(1);             // 커서 보이기
}

void right_menu()
{

    while (1)               //오른쪽 상태창
    {
        gotoxy(75, 3);
        printf("--------------------------\n");
        gotoxy(75, 4);
        printf("|                        |\n");
        gotoxy(75, 5);
        printf("|                        |\n");
        gotoxy(75, 6);
        printf("|                        |\n");
        gotoxy(75, 7);
        printf("--------------------------\n");
        gotoxy(77, 4);
        for (int i = 0; i < heart; i++)
        {
            textcolor(RED);
            printf("♥ ");
        }
        textcolor(WHITE);

        //printf("♡");


        break;
    }

}

void Menu(void)
{
    int choice = 1;
    int level = 0;
    int x = Console_width() / 2;

    cls;
    computer_1();
    for (int i = 0; i < 5; i++)
        printf("\n");

    gotoxy(x - 26, 8);                //92
    puts("+==============================================+");
    gotoxy(x - 26, 9);
    puts("|              ---------++---------            |\n");
    gotoxy(x - 26, 10);
    puts("|              어디로 가시겠습니까?            |\n");
    gotoxy(x - 26, 11);
    puts("|              ---------++---------            |\n");
    gotoxy(x - 26, 12);
    puts("+==============================================+\n");

    gotoxy(x - 11, 20);//65,20
    printf("[ ] 2학년 (EASY)");
    gotoxy(x - 11, 22);
    printf("[ ] 3학년 (NORMAL)");
    gotoxy(x - 11, 24);
    printf("[ ] 4학년 (HARD)");
    gotoxy(x - 11, 26);
    printf("[ ] 게임종료(OUT)");
    gotoxy(x - 10, 20);
    while (1)
    {
        fflush(stdin);
        if (_kbhit())
        {
            int ch = _getch();

            if (ch == 13)       //Enter키
                break;
            else if (ch == 224)
            {
                ch = _getch();

                if (ch == 72)
                {
                    if (choice > 1)
                        choice--;
                }
                else if (ch == 80)
                {
                    if (choice < 5)
                        choice++;
                }
            }
            switch (choice)
            {
            case 1:
                gotoxy(108, 20);
                break;
            case 2:
                gotoxy(108, 22);
                break;
            case 3:
                gotoxy(108, 24);
                break;
            case 4:
                gotoxy(108, 26);
                break;
            }

        }
    }
    level = choice;
    switch (level)
    {
    case 1:
        gotoxy(x - 15, 20); //61,20
        textcolor(GREEN);
        printf(">>  [ ] 2학년 (EASY)  <<\n");
        gotoxy(x - 10, 20);
        textcolor(WHITE); Sl; Sl;    //다시 색 변경
        break;
    case 2:
        gotoxy(x - 15, 22);
        textcolor(BLUE);
        printf(">>  [ ] 3학년 (NORMAL)   <<\n");
        gotoxy(x - 10, 22);
        textcolor(WHITE); Sl; Sl;    //다시 색 변경
        break;
    case 3:
        gotoxy(x - 15, 24);
        textcolor(RED);
        printf(">>  [ ] 4학년 (HARD)   <<\n");
        gotoxy(x - 10, 24);
        textcolor(WHITE); Sl; Sl;    //다시 색 변경
        break;
    case 4:
        menu_out();
        break;
    }
    cls;

    switch (level)
    {
    case 1:
        Level1();
        break;
    case 2:
        Level2();
        break;
    case 3:
        Level3();
        break;
    }
}

void Level1()
{
    next = 0;
    heart = 5;
    print_level1(); Sl; Sl;
    cls;
    stage1();
}

void Level2()
{
    next = 0;
    heart = 4;
    print_level2(); Sl; Sl;
    cls;
    stage2();
}

void Level3()
{
    next = 0;
    heart = 3;
    print_level3(); Sl; Sl;
    cls;
    stage3();
}

void stage1()
{
    struct FLAG* pf = NULL;         //깃발의 주소 받을 포인터
    int x = 1, y = 32;
    int f = 0;                      //게임 종료 여부를 확인하기 위한 변수
    int step = 40;

    char map[38][300] =
    { "┌────────────────────────────────────────────────────────────────────┐",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "└────────────────────────────────────────────────────────────────────┘",
        "                        │                │                            ",
        "                        │                │                            ",
        "┌────────────────────────────────────────────────────────────────────┐",
        "└────────────────────────────────────────────────────────────────────┘",
    };





    while (1)       //매번 반복으로 맵 출력
    {
        f = 0;

        cls;
        textcolor(GREEN);
        for (int i = 0; i < 38; i++)
        {
            printf("%s\n", map[i]);
        }
        textcolor(WHITE);

        right_menu();
        print_step(step);

        if (!pf) {                                      //pf==0이면 실행(초기값이 0이기 떄문.이미 깃발 값이 할당돼있으면 다음 반복에서 다시 할당하지 않게 함)
            pf = flag();                                //깃발 좌표 할당하고 주소 pf에 대입    
        }
        flag_stage1(pf);                                      //깃발 배치

        Cursor(x, y);


        while (1) {
            if (_kbhit()) {
                int ch = _getch();
                switch (ch) {
                case 72: //윗 방향키
                    moveCursor(&x, &y, 0, -1);
                    step--;
                    print_step(step);
                    break;
                case 80: //아래 방향키
                    moveCursor(&x, &y, 0, 1);
                    step--;
                    print_step(step);
                    break;
                case 75: // LEFT arrow key
                    moveCursor(&x, &y, -1, 0);
                    step--;
                    print_step(step);
                    break;
                case 77: // RIGHT arrow key
                    moveCursor(&x, &y, 1, 0);
                    step--;
                    print_step(step);
                    break;
                }
                if (ch == 27)                  //esc
                {
                    char c;
                    c = game_out();             //함수 이름 escmenu가 더 어울릴 듯

                    if (c == 1)
                    {
                        pf = 0;                //플레이어가 다시하기를 선택한 경우 pf에 0을 대입해서 깃발,시간 관련 값들 초기화 하게 함
                        heart = 5;
                        step = 40;
                    }
                    else if (c == 2)       //플레이어가 메뉴로 돌아가기를 선택한 경우에는 f에 1을 대입함
                        f = 1;

                    break;
                }

            }

            int m = check(&x, &y, pf);
            if (m >= 0 && m <= 12)
            {
                switch (m)
                {
                case 0:
                    game_clear(1);
                    f = 1;
                    break;
                case 1:
                    plus_flag();
                    plus_heart();
                    break;
                case 2:
                    plus_pass();
                    plus_heart();
                    break;
                case 3:
                    plus_playtime();
                    plus_heart();
                    break;
                case 4:
                    minus_restart();
                    pf = 0;
                    x = 1;
                    y = 32;
                    minus_heart();
                    break;
                case 5:
                    minus_stop();
                    Sleep(2000);
                    minus_heart();
                    break;
                case 6:
                    minus_gotoxy();
                    x = 1;
                    y = 32;
                    minus_heart();
                    break;
                case 7:
                    time_attack_story();
                    time_attack_game_level1(); //수강신청 클릭
                    break;
                case 8:
                    avoid_prof_story();
                    avoid_prof_level1(); //교수님피하기
                    break;
                case 9:
                    guess_story();
                    guessNumberGame_level1();  //숫자맞추기
                    break;
                case 10:
                    avoid_F_story();
                    start_avoid_F_level1();        //F피하기

                    break;
                case 11:            //미스터리퀴즈
                    mysteryQuiz_level1();
                    break;
                case 12:
                    matching_arrow_level1();                //화살표맞추기
                    break;
                }
                break;
            }

            if (!step_check_level1(&step))
                break;

            if (!heart)
            {
                game_over();
                f = 1;
            }

            if (f == 1 || f == 100)
                break;
        }
        if (f == 1)                            //f가 1인 경우에는 스테이지를 종료함
            break;
    }
}



void stage2()
{
    struct FLAG* pf = NULL;         //깃발의 주소 받을 포인터
    //int c_time, p_time;             //게임 시간 관련 변수
    int x = 1, y = 32;
    int f = 0;                      //게임 종료 여부를 확인하기 위한 변수
    int step = 30;

    char map[38][300] =
    {
        "┌────────────────────────────────────────────────────────────────────┐",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "└────────────────────────────────────────────────────────────────────┘",
        "                        │                │                            ",
        "                        │                │                            ",
        "┌────────────────────────────────────────────────────────────────────┐",
        "└────────────────────────────────────────────────────────────────────┘",
    };







    while (1)       //매번 반복으로 맵 출력
    {
        f = 0;

        cls;
        textcolor(BLUE);
        for (int i = 0; i < 38; i++)
        {
            printf("%s\n", map[i]);
        }
        textcolor(WHITE);

        right_menu();
        print_step(step);


        if (!pf) {                                      //pf==0이면 실행(초기값이 0이기 떄문.이미 깃발 값이 할당돼있으면 다음 반복에서 다시 할당하지 않게 함)
            pf = flag();                                //깃발 좌표 할당하고 주소 pf에 대입    
        }
        flag_stage2(pf);                                      //깃발 배치

        Cursor(x, y);


        while (1) {
            if (_kbhit()) {
                int ch = _getch();
                switch (ch) {
                case 72: //윗 방향키
                    moveCursor(&x, &y, 0, -1);
                    step--;
                    print_step(step);
                    break;
                case 80: //아래 방향키
                    moveCursor(&x, &y, 0, 1);
                    step--;
                    print_step(step);
                    break;
                case 75: // LEFT arrow key
                    moveCursor(&x, &y, -1, 0);
                    step--;
                    print_step(step);
                    break;
                case 77: // RIGHT arrow key
                    moveCursor(&x, &y, 1, 0);
                    step--;
                    print_step(step);
                    break;
                }
                if (ch == 27)                  //esc
                {
                    char c;
                    c = game_out();             //함수 이름 escmenu가 더 어울릴 듯

                    if (c == 1)
                    {
                        pf = 0;                //플레이어가 다시하기를 선택한 경우 pf에 0을 대입해서 깃발,시간 관련 값들 초기화 하게 함
                        heart = 4;
                        step = 30;
                    }
                    else if (c == 2)       //플레이어가 메뉴로 돌아가기를 선택한 경우에는 f에 1을 대입함
                        f = 1;

                    break;
                }

            }

            int m = check(&x, &y, pf);
            if (m >= 0 && m <= 12)
            {
                switch (m)
                {
                case 0:
                    //Level2;
                    game_clear(2);
                    f = 1;
                    break;
                case 1:
                    plus_flag();
                    plus_heart();
                    break;
                case 2:
                    plus_pass();
                    plus_heart();
                    break;
                case 3:
                    plus_playtime();
                    plus_heart();
                    break;
                case 4:
                    minus_restart();
                    pf = 0;
                    x = 1;
                    y = 32;
                    minus_heart();
                    break;
                case 5:
                    minus_stop();
                    Sleep(2000);
                    minus_heart();
                    break;
                case 6:
                    minus_gotoxy();
                    x = 1;
                    y = 32;
                    minus_heart();
                    break;
                case 7:
                    time_attack_story();    //수강신청 타임어택 게임
                    time_attack_game_level2(); //수강신청
                    break;
                case 8:
                    avoid_prof_story();
                    avoid_prof_level2();  //교수님피하기
                    break;
                case 9:
                    guess_story();
                    guessNumberGame_level2();  //숫자맞추기
                    break;
                case 10:
                    avoid_F_story();
                    start_avoid_F_level2();        //F피하기

                    break;
                case 11:            //미스터리퀴즈
                    mysteryQuiz_level2();
                    break;
                case 12:
                    matching_arrow_level2();                //화살표맞추기
                    break;
                }
                break;
            }

            if (!step_check_level1(&step))
                break;

            if (!heart)
            {
                game_over();
                f = 1;
            }

            if (f == 1 || f == 100)
                break;
        }
        if (f == 1)                            //f가 1인 경우에는 스테이지를 종료함
            break;
    }
}





void stage3()
{
    struct FLAG* pf = NULL;         //깃발의 주소 받을 포인터
    int x = 1, y = 32;
    int f = 0;                      //게임 종료 여부를 확인하기 위한 변수
    int step = 15;

    char map[38][300] =
    {
        "┌────────────────────────────────────────────────────────────────────┐",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "│                                                                    │",
        "└────────────────────────────────────────────────────────────────────┘",
        "                        │                │                            ",
        "                        │                │                            ",
        "┌────────────────────────────────────────────────────────────────────┐",
        "└────────────────────────────────────────────────────────────────────┘",
    };

    while (1)       //매번 반복으로 맵 출력
    {
        f = 0;

        cls;
        textcolor(RED);
        for (int i = 0; i < 38; i++)
        {
            printf("%s\n", map[i]);
        }
        textcolor(WHITE);
        right_menu();
        print_step(step);

        if (!pf) {                                      //pf==0이면 실행(초기값이 0이기 떄문.이미 깃발 값이 할당돼있으면 다음 반복에서 다시 할당하지 않게 함)
            pf = flag();                                //깃발 좌표 할당하고 주소 pf에 대입    
        }
        flag_stage3(pf);                                      //깃발 배치

        Cursor(x, y);


        while (1) {
            if (_kbhit()) {
                int ch = _getch();
                switch (ch) {
                case 72: //윗 방향키
                    moveCursor(&x, &y, 0, -1);
                    step--;
                    print_step(step);
                    break;
                case 80: //아래 방향키
                    moveCursor(&x, &y, 0, 1);
                    step--;
                    print_step(step);
                    break;
                case 75: // LEFT arrow key
                    moveCursor(&x, &y, -1, 0);
                    step--;
                    print_step(step);
                    break;
                case 77: // RIGHT arrow key
                    moveCursor(&x, &y, 1, 0);
                    step--;
                    print_step(step);
                    break;
                }
                if (ch == 27)                  //esc
                {
                    char c;
                    c = game_out();             //함수 이름 escmenu가 더 어울릴 듯

                    if (c == 1)
                    {
                        pf = 0;                //플레이어가 다시하기를 선택한 경우 pf에 0을 대입해서 깃발,시간 관련 값들 초기화 하게 함
                        heart = 3;
                        step = 15;
                    }
                    else if (c == 2)       //플레이어가 메뉴로 돌아가기를 선택한 경우에는 f에 1을 대입함
                        f = 1;

                    break;
                }

            }

            int m = check(&x, &y, pf);
            if (m >= 0 && m <= 12)
            {
                switch (m)
                {
                case 0:
                    game_clear(3);
                    f = 1;
                    break;
                case 1:
                    plus_flag();
                    break;
                case 2:
                    plus_pass();
                    break;
                case 3:
                    plus_playtime();
                    break;
                case 4:
                    minus_restart();
                    pf = 0;
                    x = 1;
                    y = 32;
                    break;
                case 5:
                    minus_stop();
                    Sleep(2000);
                    break;
                case 6:
                    minus_gotoxy();
                    x = 1;
                    y = 32;
                    break;
                case 7:
                    time_attack_story();    //수강신청 타임어택 게임
                    time_attack_game_level3(); //수강신청
                    break;
                case 8:
                    avoid_prof_story();
                    avoid_prof_level3(); //교수님피하기
                    break;
                case 9:
                    guess_story();
                    guessNumberGame_level3();  //숫자맞추기
                    break;
                case 10:
                    avoid_F_story();
                    start_avoid_F_level3();        //F피하기
                    break;
                case 11:                 //미스터리퀴즈
                    mysteryQuiz_level3();
                    break;
                case 12:
                    matching_arrow_level3();                //화살표맞추기
                    break;
                }
                break;
            }

            if (!step_check_level1(&step))
                break;

            if (!heart)
            {
                game_over();
                f = 1;
            }

            if (f == 1 || f == 100)
                break;
        }
        if (f == 1)                            //f가 1인 경우에는 스테이지를 종료함
            break;
    }
}



void game_over()
{
    cls;
    np(10);
    middle("당신은 F학점을 받아버렸다.\n");
    Sl; Sl;
    np(3);
    middle("다음 학년을 기약하자...\n");
    Sl; Sl; Sl;

    while (!re_select());
}


void game_clear(stage)
{
    game_report();

    Sl; Sl; Sl;

    switch (stage)
    {
    case 1:
        next = 2;
        break;
    case 2:
        next = 3;
        break;
    case 3:
        next = 0;
        design_clear();
        while (!re_select());
        break;
    }

}

int re_select()
{
    int choice = 1;
    cls;
    CursorView(1);
    gotoxy(65, 20);
    printf("[ ] 메뉴 화면으로 돌아가기 (MENU)");
    gotoxy(65, 22);
    printf("[ ] 종료하기 (OUT)");
    gotoxy(66, 20);

    while (1)
    {
        if (_kbhit())
        {
            int ch = _getch();

            if (ch == 13)       //Enter키
                break;
            else if (ch == 224)
            {
                ch = _getch();

                if (ch == 72)
                {
                    if (choice > 1)
                        choice--;
                }
                else if (ch == 80)
                {
                    if (choice < 2)
                        choice++;
                }
            }
            switch (choice)
            {
            case 1:
                gotoxy(66, 20);
                break;
            case 2:
                gotoxy(66, 22);
                break;
            case 3:
                gotoxy(66, 24);
                break;
            }
        }
    }
    switch (choice)
    {
    case 1:
        gotoxy(61, 20);
        textcolor(GREEN);
        printf(">>  [ ] 메뉴 화면으로 돌아가기 (MENU)   <<");
        gotoxy(66, 20);
        textcolor(WHITE); Sl; Sl;    //다시 색 변경
        return 1;
        break;
    case 2:
        gotoxy(61, 22);
        textcolor(RED);
        printf(">>  [ ] 종료하기 (OUT)   <<\n");
        gotoxy(66, 22);
        textcolor(WHITE); Sl; Sl;    //다시 색 변경
        gotoxy(61, 30);
        cls;
        printf("Good bye.\n\n\n\n\n");
        exit(0);
        return 0;
        break;
    }
}

void game_report()
{
    cls;


    switch (heart)
    {
    case 1:
        np(10);
        middle("당신의 이번 학년 학점은 D 입니다.\n");
        np(3);
        middle("분발하셔야겠어요~\n");
        break;
    case 2:
        np(10);
        middle("당신의 이번 학년 학점은 C 입니다.\n");
        np(3);
        middle("분발하셔야겠어요~\n");
        break;
    case 3:
        np(10);
        middle("당신의 이번 학년 학점은 B 입니다.\n");
        np(3);
        middle("준수한 성적이군요?\n");
        break;
    case 4:
        np(10);
        middle("당신의 이번 학년 학점은 A 입니다.\n");
        np(3);
        middle("훌륭합니다!\n");
        break;
    case 5:
        np(10);
        middle("당신의 이번 학년 학점은 A+ 입니다.\n");
        np(3);
        middle("대단해요!\n");
        break;
    }


    Sl; Sl; Sl;
}