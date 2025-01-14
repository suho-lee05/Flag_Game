#include "main.h"


extern int next;
extern int heart;

int Console_width()   //�ܼ� â ũ��
{
    CONSOLE_SCREEN_BUFFER_INFO Cur;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Cur);

    return Cur.dwSize.X - 1;
}

void CursorView(char show)
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void textcolor(int color_number)    //���� �� ���� �Լ�
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}


void gotoxy(int x, int y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Cursor1()
{
    int x = 40, y = 12, ch;
    while (1)
    {
        gotoxy(x, y);
        printf("*");
        ch = _getch();
        if (ch == 224)
        {
            ch = _getch();
            switch (ch)
            {
            case 72:
                y--;
                break;
            case 80:
                y++;
                break;
            case 75:
                x--;
                break;
            case 77:
                x++;
                break;
            }
        }
        printf(" ");
    }
}

void Cursor(int x, int y)
{
    CursorView(0);
    gotoxy(x, y);
    printf("*");
}

void moveCursor(int* x, int* y, int dx, int dy) //Ŀ�� ���� 
{
    int newX = *x + dx;
    int newY = *y + dy;
    // Check boundaries to ensure the cursor stays within the map
    if (newX >= 1 && newX <= 68 && newY >= 1 && newY <= 32)
    {
        // Erase the current cursor position
        gotoxy(*x, *y);
        printf(" ");
        // Move the cursor to the new position
        *x = newX;
        *y = newY;
        Cursor(*x, *y);
    }
}





int playtime(int* c, int p, int x, int y)
{
    if (p - time(0) >= 0)       //�ð��� �����ִ��� üũ
    {
        if (time(0) > *c)
        {
            gotoxy(x, y);
            printf("\b\b\b    \b\b\b\b");
            printf("%lld", p - time(0));

            (*c)++;
        }
        return 1;
    }
    else                    //���ѽð��� ������ 0 ��ȯ
        return 0;
}

int game_out()
{
    CursorView(1);
    int choice = 1;
    int level = 0;
    cls;

    for (int i = 0; i < 5; i++)
        printf("\n");

    gotoxy(50, 12);
    puts("               �����Ͻðڽ��ϱ�?              \n");



    gotoxy(65, 20);
    printf("[ ] ����ϱ�(PLAY)");
    gotoxy(65, 22);
    printf("[ ] �ٽ� �����ϱ�(RESTART)");
    gotoxy(65, 24);
    printf("[ ] �޴� ȭ������ ���ư���(MENU)");
    gotoxy(65, 26);
    printf("[ ] ��������(OUT)");
    gotoxy(66, 20);

    while (1)
    {
        if (_kbhit())
        {
            int ch = _getch();

            if (ch == 13)       //13 ���� ����
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
                    if (choice < 4)
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
            case 4:
                gotoxy(66, 26);
                break;
            }

        }
    }
    level = choice;
    switch (level)
    {
    case 1:
        return 0;
        break;
    case 2:
        gotoxy(61, 22);
        textcolor(YELLOW);
        printf(">>  [ ] �ٽ� �����ϱ�(RESTART)  <<");
        gotoxy(66, 22);
        textcolor(WHITE); Sl; Sl; //�ٽ� �� ����
        return 1;
        break;

    case 3:
        gotoxy(61, 24);
        textcolor(YELLOW);
        printf(">>  [ ] �޴� ȭ������ ���ư���(MENU)  <<\n");
        gotoxy(66, 24);
        textcolor(WHITE); Sl; Sl;   //�ٽ� �� ����
        return 2;
        break;

    case 4:
        gotoxy(61, 26);
        textcolor(RED);
        printf(">>  [ ] ��������(OUT)  <<\n");
        gotoxy(66, 26);
        textcolor(WHITE); Sl; Sl;   //�ٽ� �� ����
        printf("\n\n\n\n\n");
        exit(0);
        return 0;
        break;

        cls;
    }

}


void menu_out()
{
    char ch;

    cls;
    gotoxy(61, 20);
    printf("���� �����Ͻðڽ��ϱ�?");
    gotoxy(53, 23);
    textcolor(YELLOW);
    printf("�޴��� ���ư��� (esc)");
    textcolor(WHITE);
    printf(" / ");
    textcolor(RED);
    printf("���� (Enter)");
    textcolor(WHITE);

    while (1)
    {
        ch = _getch();
        if (ch == 13)
        {
            printf("\n\n\n\n\n");
            exit(0);
        }
        else if (ch == 27)
            break;
    }
}

/*
void MP(const char* sentence)
{
    int word_length = (int)strlen(sentence);

    int empty = (CMD_WIDTH - word_length) / 2;

    for (int i = 0; i < empty; i++)
        printf(" ");

    printf("%s", sentence);


}
*/

void middle(const char* sentence)
{
    int word_length = (int)strlen(sentence);

    int empty = (Console_width() - word_length) / 2;

    for (int i = 0; i < empty; i++)
        printf(" ");

    printf("%s", sentence);


}

//���������ϱ�

void print_Cur(int x, int y)
{
    gotoxy(x, y);
    printf("professor");
    gotoxy(x, y + 1);
    printf("professor");
    gotoxy(x, y + 2);
    printf("professor");
}

void del_Cur(int x, int y)
{
    gotoxy(x, y);
    printf("         ");
    gotoxy(x, y + 1);
    printf("         ");
    gotoxy(x, y + 2);
    printf("         ");
}

char avoid_check(int x1, int y1, int x2, int y2)
{
    if (((x1 >= x2 && x1 <= x2 + 8) || (x1 + 1 >= x2 && x1 + 1 <= x2 + 8)) && y1 >= y2 && y1 <= y2 + 2)
        return 1;
    else
        return 0;
}

void sound()
{
    PlaySound(TEXT("c:\\����_ȿ����_3.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void plus_heart()
{
    if (heart < 5)
        heart++;
}

void minus_heart()
{
    heart--;
}

void print_step(int step)
{
    textcolor(YELLOW);
    gotoxy(89, 6);
    printf("\b\b  \b\b");
    printf("%d", step);
    textcolor(WHITE);
}

int step_check_level1(int* step)
{
    if (!(*step))
    {
        minus_heart();

        *step = 40;

        return 0;
    }
    else
        return 1;
}

int step_check_level2(int* step)
{
    if (!(*step))
    {
        minus_heart();

        *step = 30;

        return 0;
    }
    else
        return 1;
}

int step_check_level3(int* step)
{
    if (!(*step))
    {
        minus_heart();

        *step = 15;

        return 0;
    }
    else
        return 1;
}

void np(int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("\n");
}