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
            game_menu();                 //�������� ����� �ڵ����� �޴��� ���ƿ�
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
    { "����������������������������������������������������������������������������������������������������������",
        "��                                                   ��",
        "��                                                   ��",
        "��                                                   ��",
        "��                                                   ��",
        "��                                                   ��",
        "��                                                   ��",
        "��                                                   ��",
        "��                                                   ��",
        "��                                                   ��",
        "��                                                   ��",
        "��                                                   ��",
        "��                                                   ��",
        "��                                                   ��",
        "��                                                   ��",
        "��                                                   ��",
        "��                                                   ��",
        "��                                                   ��",
        "��                                                   ��",
        "����������������������������������������������������������������������������������������������������������",
        "                 ��                ��                 ",
        "                 ��                ��                 ",
        "����������������������������������������������������������������������������������������������������������",
        "����������������������������������������������������������������������������������������������������������",
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
    puts("������������������������������������������������������������������������������������\n");
    gotoxy(5, 3);
    puts("��          --------------------          ��\n");
    gotoxy(5, 4);
    puts("��           �޴��� �������ּ���          ��\n");
    gotoxy(5, 5);
    puts("��          --------------------          ��\n");
    gotoxy(5, 6);
    puts("������������������������������������������������������������������������������������\n");

    gotoxy(13, 10);//65,20
    printf("[ ] ���ӽ���   (Select Level)");
    gotoxy(13, 12);
    printf("[ ] �̴ϰ��� ����   (Minigame info.)");
    gotoxy(13, 14);
    printf("[ ] ���� ����   (Game info.)");
    gotoxy(13, 16);
    printf("[ ] ��������   (OUT)");
    gotoxy(14, 10);
    while (1)
    {
        if (_kbhit())
        {
            int ch = _getch();

            if (ch == 13)       //EnterŰ
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
        printf(">>  [ ] ���ӽ���     (Select Level)  \n");
        gotoxy(14, 10);
        textcolor(WHITE); Sl; Sl;    //�ٽ� �� ����
        break;
    case 2:
        gotoxy(9, 12);
        textcolor(BLUE);
        printf(">>  [ ] �̴ϰ��� ���� (Minigame info.)  \n");
        gotoxy(14, 12);
        textcolor(WHITE); Sl; Sl;    //�ٽ� �� ����
        break;
    case 3:
        gotoxy(9, 14);
        textcolor(RED);
        printf(">>  [ ] ���� ����   (Game info.)  \n");
        gotoxy(14, 14);
        textcolor(WHITE); Sl; Sl;    //�ٽ� �� ����
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
                // ���� Ű�� ������ ��
                explanation_1();
                break;
            }
        }
    }
}

void game_explantion()
{

    printf("���� ��ġ ǥ\n");

    printf("5 * �� = A+ \n");

    printf("4 * �� = A0\n");

    printf("3 * �� = B0\n");

    printf("2 * �� = C0 \n");

    printf("1 * �� = D0\n");

    printf("0 * �� = F\n\n\n");

    printf("���� ����\n");

    printf("_______________________________________________________________\n");

    printf(" * �� �÷��̾��Դϴ�.\n");

    printf("��ǻ�� ����� �ӿ� ������ A�� ã�� ���� �ܰ�� �Ѿ�� �մϴ�.\n");

    printf("�߰� �߰� �̴ϰ����� ����Ͽ� ���� �������� ������ ����������!\n");

    printf("������ �ö󰥼��� �⺻ ��Ʈ ������ �����մϴ�.\n\n");

    printf("�������� �� ������ �̵�Ƚ���� �ѱ�� �� �� �����մϴ�. �����ϼ���!\n\n");

    printf("(���ư����� [Esc] Ű�� ��������) ");

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
    printf("\n< F���ϱ� ���� >\n");

    printf("����Ű -> <- �� ���� ����Ͽ� �ϴÿ��� �������� F������ ���ض�!\n\n");

    printf("< ������û ���� >\n");

    printf("���̺��� �Ҹ��� ���� 9�� 30�п� ����Ǵ� ������û�� ��Ŭ�Ͽ� �ʵ� �İ����� ���غ�����!\n\n");

    printf("< ȭ��ǥ ��Ī >\n");

    printf("�ʵ� �İ����� ���߷��� �����ּ���! ���ѽð� �ȿ� ȭ��ǥ���� ������ ����� �մϴ�.\n\n");

    printf("< �̽��׸� ���� >\n");

    printf("�ʵ� �İ����� â�Ƿ��� ������ �����ּ���! ȭ�鿡 ��Ÿ���� ������ â�Ƿ��� �����Ͽ� Ǯ��� �մϴ�.\n\n");

    printf("< ���� ���߱� ���� >\n");

    printf("��ǻ�Ͱ��а��п��� ���� �����˻� �˰����� Ȱ���� ���ѽð� �ȿ� ������ ���纸����!\n\n");

    printf("< ������ ���ϱ� >\n");

    printf("�������� �������� ������ ���ƴٴϰ� �ֽ��ϴ�. �������� �þ߸� ���� �޾Ƴ�����!\n\n");

    printf("���ư����� [Esc] Ű�� �������� ");

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
    CursorView(0);             // Ŀ�� �����
    gotoxy(100, 50);
    textcolor(GREEN);
    printf("<<<  ����Ϸ��� [Enter] Ű�� �Է��ϼ���...  >>>");
    textcolor(WHITE);
    while (count != 6)
    {
        getchar();
        count++;
        if (count == 1)
        {
            gotoxy(85, 25);
            printf("< ���� ���������� ��ģ �ʵ� �İ����� 2�г����� �����ϰ� �ȴ�. >");
        }
        else if (count == 2)
        {
            gotoxy(85, 29);
            printf("< ������ ������ �׸� �����ϴ� ������ �б���Ȱ.. >");
        }
        else if (count == 3)
        {
            gotoxy(85, 33);
            printf("< �״� �б����� �Ͼ�� �°� �б���Ȱ�� ���ĳ��� >");
        }
        else if (count == 4)
        {
            gotoxy(85, 37);
            printf("< �б��� ������ A�� ã�� �г��� ���ľ� �Ѵ�. >");
        }
        else if (count == 5)
        {
            gotoxy(85, 41);
            printf("< ���� �ʵ� �İ����� �б��� ������ �����Ͽ� ������ ���� �ʵ峲�� �� �� ������..? >");
        }
        else
            break;
    }

    CursorView(1);             // Ŀ�� ���̱�
}

void right_menu()
{

    while (1)               //������ ����â
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
            printf("�� ");
        }
        textcolor(WHITE);

        //printf("��");


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
    puts("|              ���� ���ðڽ��ϱ�?            |\n");
    gotoxy(x - 26, 11);
    puts("|              ---------++---------            |\n");
    gotoxy(x - 26, 12);
    puts("+==============================================+\n");

    gotoxy(x - 11, 20);//65,20
    printf("[ ] 2�г� (EASY)");
    gotoxy(x - 11, 22);
    printf("[ ] 3�г� (NORMAL)");
    gotoxy(x - 11, 24);
    printf("[ ] 4�г� (HARD)");
    gotoxy(x - 11, 26);
    printf("[ ] ��������(OUT)");
    gotoxy(x - 10, 20);
    while (1)
    {
        fflush(stdin);
        if (_kbhit())
        {
            int ch = _getch();

            if (ch == 13)       //EnterŰ
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
        printf(">>  [ ] 2�г� (EASY)  <<\n");
        gotoxy(x - 10, 20);
        textcolor(WHITE); Sl; Sl;    //�ٽ� �� ����
        break;
    case 2:
        gotoxy(x - 15, 22);
        textcolor(BLUE);
        printf(">>  [ ] 3�г� (NORMAL)   <<\n");
        gotoxy(x - 10, 22);
        textcolor(WHITE); Sl; Sl;    //�ٽ� �� ����
        break;
    case 3:
        gotoxy(x - 15, 24);
        textcolor(RED);
        printf(">>  [ ] 4�г� (HARD)   <<\n");
        gotoxy(x - 10, 24);
        textcolor(WHITE); Sl; Sl;    //�ٽ� �� ����
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
    struct FLAG* pf = NULL;         //����� �ּ� ���� ������
    int x = 1, y = 32;
    int f = 0;                      //���� ���� ���θ� Ȯ���ϱ� ���� ����
    int step = 40;

    char map[38][300] =
    { "��������������������������������������������������������������������������������������������������������������������������������������������",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��������������������������������������������������������������������������������������������������������������������������������������������",
        "                        ��                ��                            ",
        "                        ��                ��                            ",
        "��������������������������������������������������������������������������������������������������������������������������������������������",
        "��������������������������������������������������������������������������������������������������������������������������������������������",
    };





    while (1)       //�Ź� �ݺ����� �� ���
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

        if (!pf) {                                      //pf==0�̸� ����(�ʱⰪ�� 0�̱� ����.�̹� ��� ���� �Ҵ�������� ���� �ݺ����� �ٽ� �Ҵ����� �ʰ� ��)
            pf = flag();                                //��� ��ǥ �Ҵ��ϰ� �ּ� pf�� ����    
        }
        flag_stage1(pf);                                      //��� ��ġ

        Cursor(x, y);


        while (1) {
            if (_kbhit()) {
                int ch = _getch();
                switch (ch) {
                case 72: //�� ����Ű
                    moveCursor(&x, &y, 0, -1);
                    step--;
                    print_step(step);
                    break;
                case 80: //�Ʒ� ����Ű
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
                    c = game_out();             //�Լ� �̸� escmenu�� �� ��︱ ��

                    if (c == 1)
                    {
                        pf = 0;                //�÷��̾ �ٽ��ϱ⸦ ������ ��� pf�� 0�� �����ؼ� ���,�ð� ���� ���� �ʱ�ȭ �ϰ� ��
                        heart = 5;
                        step = 40;
                    }
                    else if (c == 2)       //�÷��̾ �޴��� ���ư��⸦ ������ ��쿡�� f�� 1�� ������
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
                    time_attack_game_level1(); //������û Ŭ��
                    break;
                case 8:
                    avoid_prof_story();
                    avoid_prof_level1(); //���������ϱ�
                    break;
                case 9:
                    guess_story();
                    guessNumberGame_level1();  //���ڸ��߱�
                    break;
                case 10:
                    avoid_F_story();
                    start_avoid_F_level1();        //F���ϱ�

                    break;
                case 11:            //�̽��͸�����
                    mysteryQuiz_level1();
                    break;
                case 12:
                    matching_arrow_level1();                //ȭ��ǥ���߱�
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
        if (f == 1)                            //f�� 1�� ��쿡�� ���������� ������
            break;
    }
}



void stage2()
{
    struct FLAG* pf = NULL;         //����� �ּ� ���� ������
    //int c_time, p_time;             //���� �ð� ���� ����
    int x = 1, y = 32;
    int f = 0;                      //���� ���� ���θ� Ȯ���ϱ� ���� ����
    int step = 30;

    char map[38][300] =
    {
        "��������������������������������������������������������������������������������������������������������������������������������������������",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��������������������������������������������������������������������������������������������������������������������������������������������",
        "                        ��                ��                            ",
        "                        ��                ��                            ",
        "��������������������������������������������������������������������������������������������������������������������������������������������",
        "��������������������������������������������������������������������������������������������������������������������������������������������",
    };







    while (1)       //�Ź� �ݺ����� �� ���
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


        if (!pf) {                                      //pf==0�̸� ����(�ʱⰪ�� 0�̱� ����.�̹� ��� ���� �Ҵ�������� ���� �ݺ����� �ٽ� �Ҵ����� �ʰ� ��)
            pf = flag();                                //��� ��ǥ �Ҵ��ϰ� �ּ� pf�� ����    
        }
        flag_stage2(pf);                                      //��� ��ġ

        Cursor(x, y);


        while (1) {
            if (_kbhit()) {
                int ch = _getch();
                switch (ch) {
                case 72: //�� ����Ű
                    moveCursor(&x, &y, 0, -1);
                    step--;
                    print_step(step);
                    break;
                case 80: //�Ʒ� ����Ű
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
                    c = game_out();             //�Լ� �̸� escmenu�� �� ��︱ ��

                    if (c == 1)
                    {
                        pf = 0;                //�÷��̾ �ٽ��ϱ⸦ ������ ��� pf�� 0�� �����ؼ� ���,�ð� ���� ���� �ʱ�ȭ �ϰ� ��
                        heart = 4;
                        step = 30;
                    }
                    else if (c == 2)       //�÷��̾ �޴��� ���ư��⸦ ������ ��쿡�� f�� 1�� ������
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
                    time_attack_story();    //������û Ÿ�Ӿ��� ����
                    time_attack_game_level2(); //������û
                    break;
                case 8:
                    avoid_prof_story();
                    avoid_prof_level2();  //���������ϱ�
                    break;
                case 9:
                    guess_story();
                    guessNumberGame_level2();  //���ڸ��߱�
                    break;
                case 10:
                    avoid_F_story();
                    start_avoid_F_level2();        //F���ϱ�

                    break;
                case 11:            //�̽��͸�����
                    mysteryQuiz_level2();
                    break;
                case 12:
                    matching_arrow_level2();                //ȭ��ǥ���߱�
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
        if (f == 1)                            //f�� 1�� ��쿡�� ���������� ������
            break;
    }
}





void stage3()
{
    struct FLAG* pf = NULL;         //����� �ּ� ���� ������
    int x = 1, y = 32;
    int f = 0;                      //���� ���� ���θ� Ȯ���ϱ� ���� ����
    int step = 15;

    char map[38][300] =
    {
        "��������������������������������������������������������������������������������������������������������������������������������������������",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��                                                                    ��",
        "��������������������������������������������������������������������������������������������������������������������������������������������",
        "                        ��                ��                            ",
        "                        ��                ��                            ",
        "��������������������������������������������������������������������������������������������������������������������������������������������",
        "��������������������������������������������������������������������������������������������������������������������������������������������",
    };

    while (1)       //�Ź� �ݺ����� �� ���
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

        if (!pf) {                                      //pf==0�̸� ����(�ʱⰪ�� 0�̱� ����.�̹� ��� ���� �Ҵ�������� ���� �ݺ����� �ٽ� �Ҵ����� �ʰ� ��)
            pf = flag();                                //��� ��ǥ �Ҵ��ϰ� �ּ� pf�� ����    
        }
        flag_stage3(pf);                                      //��� ��ġ

        Cursor(x, y);


        while (1) {
            if (_kbhit()) {
                int ch = _getch();
                switch (ch) {
                case 72: //�� ����Ű
                    moveCursor(&x, &y, 0, -1);
                    step--;
                    print_step(step);
                    break;
                case 80: //�Ʒ� ����Ű
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
                    c = game_out();             //�Լ� �̸� escmenu�� �� ��︱ ��

                    if (c == 1)
                    {
                        pf = 0;                //�÷��̾ �ٽ��ϱ⸦ ������ ��� pf�� 0�� �����ؼ� ���,�ð� ���� ���� �ʱ�ȭ �ϰ� ��
                        heart = 3;
                        step = 15;
                    }
                    else if (c == 2)       //�÷��̾ �޴��� ���ư��⸦ ������ ��쿡�� f�� 1�� ������
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
                    time_attack_story();    //������û Ÿ�Ӿ��� ����
                    time_attack_game_level3(); //������û
                    break;
                case 8:
                    avoid_prof_story();
                    avoid_prof_level3(); //���������ϱ�
                    break;
                case 9:
                    guess_story();
                    guessNumberGame_level3();  //���ڸ��߱�
                    break;
                case 10:
                    avoid_F_story();
                    start_avoid_F_level3();        //F���ϱ�
                    break;
                case 11:                 //�̽��͸�����
                    mysteryQuiz_level3();
                    break;
                case 12:
                    matching_arrow_level3();                //ȭ��ǥ���߱�
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
        if (f == 1)                            //f�� 1�� ��쿡�� ���������� ������
            break;
    }
}



void game_over()
{
    cls;
    np(10);
    middle("����� F������ �޾ƹ��ȴ�.\n");
    Sl; Sl;
    np(3);
    middle("���� �г��� �������...\n");
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
    printf("[ ] �޴� ȭ������ ���ư��� (MENU)");
    gotoxy(65, 22);
    printf("[ ] �����ϱ� (OUT)");
    gotoxy(66, 20);

    while (1)
    {
        if (_kbhit())
        {
            int ch = _getch();

            if (ch == 13)       //EnterŰ
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
        printf(">>  [ ] �޴� ȭ������ ���ư��� (MENU)   <<");
        gotoxy(66, 20);
        textcolor(WHITE); Sl; Sl;    //�ٽ� �� ����
        return 1;
        break;
    case 2:
        gotoxy(61, 22);
        textcolor(RED);
        printf(">>  [ ] �����ϱ� (OUT)   <<\n");
        gotoxy(66, 22);
        textcolor(WHITE); Sl; Sl;    //�ٽ� �� ����
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
        middle("����� �̹� �г� ������ D �Դϴ�.\n");
        np(3);
        middle("�й��ϼž߰ھ��~\n");
        break;
    case 2:
        np(10);
        middle("����� �̹� �г� ������ C �Դϴ�.\n");
        np(3);
        middle("�й��ϼž߰ھ��~\n");
        break;
    case 3:
        np(10);
        middle("����� �̹� �г� ������ B �Դϴ�.\n");
        np(3);
        middle("�ؼ��� �����̱���?\n");
        break;
    case 4:
        np(10);
        middle("����� �̹� �г� ������ A �Դϴ�.\n");
        np(3);
        middle("�Ǹ��մϴ�!\n");
        break;
    case 5:
        np(10);
        middle("����� �̹� �г� ������ A+ �Դϴ�.\n");
        np(3);
        middle("����ؿ�!\n");
        break;
    }


    Sl; Sl; Sl;
}