#include "main.h"

extern int next;
extern int heart;




//=======================================================================================
//avoid_F_game

void start_avoid_F_level1()
{
    fflush(stdin);   //�Է� ���� ����
    cls;
    CursorView(0);
    int life = 3;   // ���
    int score = 0;   // ���� ����

    while (life > 0 && score < DEAD_SCORE)
    {
        draw_pan();
        gotoxy_1(5, 11);
        printf("�ƹ�Ű�� ������ �����մϴ�");
        system("pause > nul");       // ȭ�� �Ͻ����� �����ִ� ��
        gotoxy_1(5, 11);
        printf("                          ");

        score += playGame(&life); // ���� ���� �� ���� �ջ�
    }
    if (score < DEAD_SCORE)
    {
        cls;
        gotoxy_1(15, 10);
        printf("Game OVER!\n");
        gotoxy_1(12, 11);
        printf("����� ������ %d���Դϴ�", score);
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
    int score = 0;              // ���� ����
    int px = 10;                // �÷��̾� ��ġ
    int count = 0;


    while (1)
    {
        gotoxy_1(25, 4);
        printf("Score: %d", score); // ���� ���
        gotoxy_1(25, 5);
        printf("Life: %d", *life);  // ��� ���

        // F ����� �κ�
        if (count % LEVEL_1 == 1)      // ������ ���鼭 ���� count�� ����
        {                            // �ű⿡ F�� �󵵼��� ���� �������� 1�� �� F�� ����
            for (i = 0; i < SIZE_F; i++)
            {
                if (F[i].exist == FALSE)        // F�� ���� ��
                {
                    F[i].exist = TRUE;          // F�� �ִٰ� �����
                    F[i].x = 2 + rand() % 18;   // �������� F�� ��ġ ����
                    F[i].y = 1;
                    break;
                }
            }
        }

        // Ű �Է�
        if (count % PLAYER_SPEED == 1)  // �÷��̾� �ӵ� �����ϴ� ��
        {
            if (IsKeyDown(VK_LEFT))
            {
                if (px >= 3)             // ȭ�� ������ ������ �ʰ� ������ 3���� 18 ���̷� ������
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

        // F �̵�
        if (count % SPEED_1 == 1)
        {
            for (i = 0; i < SIZE_F; i++)
            {
                if (F[i].exist == TRUE)  // F�� ������ ��
                {
                    gotoxy_1(F[i].x, F[i].y);
                    printf(" ");         // ���� F �����
                    if (F[i].y >= 23)    // F�� �� ������ ������
                    {
                        F[i].exist = FALSE;  // F ������ ���� �߰�
                        score += 5;
                        continue;
                    }
                    F[i].y++;            // ���� ���� F ����߸���
                    gotoxy_1(F[i].x, F[i].y);
                    printf("F");
                }
            }
        }
        //������ DEAD_SCORE�� �̻��̸� ���� ����
        if (score >= DEAD_SCORE)
        {
            return score;
        }
        // �׾��� ��
        for (i = 0; i < SIZE_F; i++)
        {
            if (F[i].exist == TRUE && F[i].x == px && F[i].y == 23)  // F�� �÷��̾ �ε�����
            {
                (*life)--;                      // ��� ���
                system("cls");
                if (*life > 0)                  // ����� ������ �ٽ� ����
                {
                    return score;
                }
                else                            // ����� ������ ���� ����
                {
                    return score;
                }
            }
        }
        // �÷��̾� ���
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

BOOL IsKeyDown(int Key) // Ű���� �Է� �޴� �Լ�
{
    return ((GetAsyncKeyState(Key) & 0x8000) != 0);
}

void draw_pan() // ���� ȭ��
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
//���� ���߱� ����     

void guessNumberGame_level1()
{
    fflush(stdin);
    cls;

    int targetNumber, userGuess, attempts;
    int score = 0;

    printf("���� ���߱⿡ ���� �� ȯ���մϴ٣�\n");
    printf("������ Ƚ�� ������ �������� ������ ���ڸ� ����������!\n");
    CursorView(1);
    for (int i = 0; i < 1; i++)
    {
        targetNumber = 1 + rand() % 50;
        attempts = 0;
        printf("\n�� %d���� �õ� �߿��� ���ڸ� �����ּ���.(1-%d)\n", 6, 50);

        while (attempts < 6)
        {
            printf("�� %d �� �õ�: ", attempts + 1);
            scanf("%d", &userGuess);
            attempts++;

            if (userGuess == targetNumber) {
                printf("����!\n");

                score++;
                break;
            }
            else if (userGuess < targetNumber)
            {
                printf("�ʹ� ���ƿ�.\n\n");
            }
            else
            {
                printf("�ʹ� ���ƿ�.\n\n");
            }
        }
        if (attempts == 6 && userGuess != targetNumber)
        {
            printf("�����Դϴ�! ������ %d �Դϴ�!\n", targetNumber);
        }
    }
    printf("\n����Ǿ����ϴ٣���������%d\n", score);
    Sl; Sl;
    cls;
    switch (score)
    {
    case 0:
        printf("������ ������ ���� ��Ʈ�� �����մϴ�.");
        Sl;
        minus_heart();
        break;
    case 1:
        printf("������ ���߾ ��Ʈ�� �����մϴ�.\n");
        Sl;
        plus_heart();
        break;
    }
    cls;
}




//===============================================================================================================
//�̽��͸�����    

void mysteryQuiz_level1()
{
    char c, ans[9] = { 0 };
    int a, i, count = 0;
    int t1 = time(0), t2 = time(0) + 15;            //t2�� ���ϴ� ���� ���ѽð�
    struct QUIZ p[5] = { {11,11,"14"},{28,91,"11218191"},{45,91,"11415191"},{12,34,"11213141"},{37,39,"327191"} };

    i = rand() % 5;

    cls;
    //������ �ִ� 8���ڶ�� ���� �ʿ�
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
        printf("����!");
        plus_heart();
    }
    else
    {
        printf("������ ������ ���߱���...�ƽ����ϴ�");
        minus_heart();
    }

    //��Ʈ ���� �ʿ�
    Sl; Sl;
}





//=========================================================================================================
//������û Ŭ�� 

double get_current_time_in_ms()
{
    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);

    ULARGE_INTEGER ui;
    ui.LowPart = ft.dwLowDateTime;
    ui.HighPart = ft.dwHighDateTime;

    return (double)ui.QuadPart / 10000.0;  // �и��� ������ ��ȯ
}

// �и��ʸ� �ʷ� ��ȯ�Ͽ� ���
int print_time_in_seconds(double milliseconds)
{
    double sec = 0.0, sec_print = 50.0;
    int min = 0;
    sec = milliseconds / 1000.0;
    min = 29 + (int)sec / 10;
    sec_print = sec + 50;
    if (sec_print >= 60)
        sec_print = sec_print - 60;
    printf("\r����09:%2d:%4.2f ", min, sec_print);
    //printf("%d %4.2f", min, sec);
    if (sec >= 19.90)
    {
        printf("\n��!\n");
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
    printf("���� ���� 9�� 29�� 50���Դϴ�. ���� 9�� 30�� 00�ʿ� ����Ǵ� ������û�� �����ϼ���! ���� Ű�� ������ �����ϼ���...\n");
    while (getchar() != '\n');
    printf("���� ����!\n");
    sound();
    start_time = get_current_time_in_ms();
    printf("���� ��... (���� Ű�� ������ �����ϼ���)\n");
    print_time_in_seconds(0, time_over);

    while (!_kbhit())    //������...
    {
        Sleep(100);
        elapsed_time = get_current_time_in_ms() - start_time;
        time_over = print_time_in_seconds(elapsed_time);
        if (time_over == 1)
        {
            printf("�ð��� �� ���̱���. ���� �б��� ����� å�����̴ϴ�...\n");
            break;
        }
    }
    printf("\n���� ����!\n");
    end_time = get_current_time_in_ms();
    double dif_time = (end_time - start_time) / 1000.0 - 10.0;    //���� �ð�(�� ����) -> ���� ����̳� Ŭ���� ���� ���� ����
    printf("\n%.2f\n", dif_time);
    Sl; Sl;

    if (dif_time >= 0.5 || dif_time <= -0.5)    //�������� 0.5
        minus_heart();
    else
        plus_heart();
    cls;
}






//====================================================================================================
//ȭ��ǥ ��Ī

void matching_arrow_level1()
{
    fflush(stdin);

    cls;
    CursorView(1);
    gotoxy(40, 20);
    printf("10���� ������ ���ĺ��� �����Ǵ� ȭ��ǥ�� ���ѽð� �ȿ� ��ġ�ϴ� �����Դϴ�.");
    Sleep(2000);
    cls;
    //��(72,U+2191), �Ʒ�(80,U+2193), ����(75,U+2190), ������(77,U+2192)
    int arrow[] = { 72,80,75,77 };
    int rand_arrow[10] = { 0 };
    int match = 0;
    int t1 = time(0), t2 = time(0) + 10;            //t2�� ���ϴ� ���ڰ� ���ѽð�
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
        middle("���ϵ帳�ϴ�!! Ŭ�����Ͽ����ϴ�!"); Sl; Sl;
        cls;
        np(10);
        middle("������ ȹ���Ͽ����ϴ�!"); Sl; Sl;
        plus_heart();
        cls;
    }
    else
    {
        cls;
        printf("��Ÿ���׿�..�� �й��ؼ� ������!"); Sl; Sl;
        cls;
        minus_heart();
    }
}





//=============================================================================================================
//������ ���ϱ�


void avoid_prof_level1()
{
    POS prof = { 22,12 };
    POS player = { 1,1 };

    char clear = 1;
    int r = 1, se = 0;
    int t1 = time(0), t2 = time(0) + 10;        //t2�� ���ϴ� ���� ���ѽð�


    cls;

    map();

    print_Cur(prof.x, prof.y);
    gotoxy(player.x, player.y);

    while (playtime(&t1, t2, 50, 5))
    {

        if (!(se % 10))							//������ �̵�����
        {
            r = rand() % 4;
        }
        //������ ������
        CursorView(0);
        del_Cur(prof.x, prof.y);

        switch (r)
        {

            //�Ʒ�
        case 0:
            if (prof.y < PFy2_1)
                prof.y++;
            break;

            //��
        case 1:
            if (prof.y > Py1)
                prof.y--;
            break;

            //������
        case 2:
            if (prof.x < PFx2_1)
                prof.x++;
            break;

            //����
        case 3:
            if (prof.x > Px1)
                prof.x--;
            break;
        }

        print_Cur(prof.x, prof.y);
        gotoxy(player.x, player.y);
        wall(prof.x, prof.y, &r);
        CursorView(1);




        if (!(se % 2))					//�÷��̾� ������
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
        middle("���ѹ��ȴ�...\n");
        minus_heart();
    }
    else
    {
        np(10);
        middle("��Ű�� �ʰ� �������� �����\n");
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



static void wall(int x, int y, int* r)		//���� ������ �̵����� �ٲٰ� ��
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