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
            game_menu();                 //蝶纔檜雖 謙猿衛 濠翕戲煎 詭景煎 給嬴褥
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
    { "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖",
        "弛                                                   弛",
        "弛                                                   弛",
        "弛                                                   弛",
        "弛                                                   弛",
        "弛                                                   弛",
        "弛                                                   弛",
        "弛                                                   弛",
        "弛                                                   弛",
        "弛                                                   弛",
        "弛                                                   弛",
        "弛                                                   弛",
        "弛                                                   弛",
        "弛                                                   弛",
        "弛                                                   弛",
        "弛                                                   弛",
        "弛                                                   弛",
        "弛                                                   弛",
        "弛                                                   弛",
        "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎",
        "                 弛                弛                 ",
        "                 弛                弛                 ",
        "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖",
        "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎",
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
    puts("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
    gotoxy(5, 3);
    puts("弛          --------------------          弛\n");
    gotoxy(5, 4);
    puts("弛           詭景蒂 摹鷗п輿撮蹂          弛\n");
    gotoxy(5, 5);
    puts("弛          --------------------          弛\n");
    gotoxy(5, 6);
    puts("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

    gotoxy(13, 10);//65,20
    printf("[ ] 啪歜衛濛   (Select Level)");
    gotoxy(13, 12);
    printf("[ ] 嘐棲啪歜 撲貲   (Minigame info.)");
    gotoxy(13, 14);
    printf("[ ] 啪歜 撲貲   (Game info.)");
    gotoxy(13, 16);
    printf("[ ] 啪歜謙猿   (OUT)");
    gotoxy(14, 10);
    while (1)
    {
        if (_kbhit())
        {
            int ch = _getch();

            if (ch == 13)       //Enter酈
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
        printf(">>  [ ] 啪歜衛濛     (Select Level)  \n");
        gotoxy(14, 10);
        textcolor(WHITE); Sl; Sl;    //棻衛 儀 滲唳
        break;
    case 2:
        gotoxy(9, 12);
        textcolor(BLUE);
        printf(">>  [ ] 嘐棲啪歜 撲貲 (Minigame info.)  \n");
        gotoxy(14, 12);
        textcolor(WHITE); Sl; Sl;    //棻衛 儀 滲唳
        break;
    case 3:
        gotoxy(9, 14);
        textcolor(RED);
        printf(">>  [ ] 啪歜 撲貲   (Game info.)  \n");
        gotoxy(14, 14);
        textcolor(WHITE); Sl; Sl;    //棻衛 儀 滲唳
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
                // 縛攪 酈陛 揚溜擊 陽
                explanation_1();
                break;
            }
        }
    }
}

void game_explantion()
{

    printf("з薄 寡纂 ル\n");

    printf("5 * Ⅵ = A+ \n");

    printf("4 * Ⅵ = A0\n");

    printf("3 * Ⅵ = B0\n");

    printf("2 * Ⅵ = C0 \n");

    printf("1 * Ⅵ = D0\n");

    printf("0 * Ⅵ = F\n\n\n");

    printf("啪歜 撲貲\n");

    printf("_______________________________________________________________\n");

    printf(" * 擎 Ы溯檜橫殮棲棻.\n");

    printf("闡У攪 賅棲攪 樓縑 獗啖霞 A蒂 瓊嬴 棻擠 欽啗煎 剩橫陛撿 м棲棻.\n");

    printf("醞除 醞除 嘐棲啪歜擊 鱔婁ж罹 Ⅵ蒂 隸陛衛麵 з薄擊 堪罹爾撮蹂!\n");

    printf("溯漣檜 螢塭陞熱煙 晦獄 жお 偃熱陛 馬模м棲棻.\n\n");

    printf("蝶纔檜雖 樓 薑п霞 檜翕�蝦鷏� 剩晦賊 Ⅵ 陛 馬模м棲棻. 輿曖ж撮蹂!\n\n");

    printf("(給嬴陛溥賊 [Esc] 酈蒂 援腦撮蹂) ");

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
    printf("\n< FЯж晦 啪歜 >\n");

    printf("寞щ酈 -> <- 舒 偃蒂 餌辨ж罹 ж棺縑憮 雲橫雖朝 Fз薄擊 Яп塭!\n\n");

    printf("< 熱鬼褐羶 啪歜 >\n");

    printf("啻檜綠闈 模葬縑 蜃醮 9衛 30碟縑 霞ч腎朝 熱鬼褐羶擊 螢贗ж罹 傘萄 闡奢儅擊 掘п爾撮蹂!\n\n");

    printf("< �香嚂� 衙蘆 >\n");

    printf("傘萄 闡奢儅曖 牖嫦溘擊 爾罹輿撮蹂! 薯и衛除 寰縑 �香嚂扔橉� 寞щ擊 蜃醮撿 м棲棻.\n\n");

    printf("< 嘐蝶纔葬 襪鍔 >\n");

    printf("傘萄 闡奢儅曖 璽曖溘擊 葆擠盔 爾罹輿撮蹂! �飛橦� 釭顫釭朝 僥薯蒂 璽曖溘擊 嫦�秷狤� ヴ橫撿 м棲棻.\n\n");

    printf("< 璋濠 蜃蹺晦 啪歜 >\n");

    printf("闡У攪奢з偃煩縑憮 寡辦朝 檜霞匐儀 憲堅葬闈擊 �倏踿� 薯и衛除 寰縑 薑港擊 蜃醮爾撮蹂!\n\n");

    printf("< 掖熱椒 Яж晦 >\n");

    printf("掖熱椒檜 翱掘褒擊 嶸嶸�� 給嬴棻棲堅 氈蝗棲棻. 掖熱椒曖 衛撿蒂 Яп 殖嬴釭撮蹂!\n\n");

    printf("給嬴陛溥賊 [Esc] 酈蒂 援腦撮蹂 ");

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
    CursorView(0);             // 醴憮 獗晦晦
    gotoxy(100, 50);
    textcolor(GREEN);
    printf("<<<  啗樓ж溥賊 [Enter] 酈蒂 殮溘ж撮蹂...  >>>");
    textcolor(WHITE);
    while (count != 6)
    {
        getchar();
        count++;
        if (count == 1)
        {
            gotoxy(85, 25);
            printf("< 捱渠 虜晦瞪羲擊 葆耀 傘萄 闡奢儅擎 2з喇戲煎 犒зж啪 脹棻. >");
        }
        else if (count == 2)
        {
            gotoxy(85, 29);
            printf("< ж雖虜 橫梯橈檜 斜蒂 嬪⑺ж朝 熱號擎 з掖儅��.. >");
        }
        else if (count == 3)
        {
            gotoxy(85, 33);
            printf("< 斜朝 з掖縑憮 橾橫釭朝 螞乾 з掖儅�偯� ④藥釭陛 >");
        }
        else if (count == 4)
        {
            gotoxy(85, 37);
            printf("< з掖縑 獗啖霞 A蒂 瓊嬴 з喇擊 葆藥撿 и棻. >");
        }
        else if (count == 5)
        {
            gotoxy(85, 41);
            printf("< 婁翱 傘萄 闡奢儅擎 з掖蒂 鼠餌�� 褸機ж罹 霞薑и 奢渠 傘萄陴檜 腆 熱 氈擊梱..? >");
        }
        else
            break;
    }

    CursorView(1);             // 醴憮 爾檜晦
}

void right_menu()
{

    while (1)               //螃艇薹 鼻鷓璽
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
            printf("Ⅵ ");
        }
        textcolor(WHITE);

        //printf("Ⅴ");


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
    puts("|              橫蛤煎 陛衛啊蝗棲梱?            |\n");
    gotoxy(x - 26, 11);
    puts("|              ---------++---------            |\n");
    gotoxy(x - 26, 12);
    puts("+==============================================+\n");

    gotoxy(x - 11, 20);//65,20
    printf("[ ] 2з喇 (EASY)");
    gotoxy(x - 11, 22);
    printf("[ ] 3з喇 (NORMAL)");
    gotoxy(x - 11, 24);
    printf("[ ] 4з喇 (HARD)");
    gotoxy(x - 11, 26);
    printf("[ ] 啪歜謙猿(OUT)");
    gotoxy(x - 10, 20);
    while (1)
    {
        fflush(stdin);
        if (_kbhit())
        {
            int ch = _getch();

            if (ch == 13)       //Enter酈
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
        printf(">>  [ ] 2з喇 (EASY)  <<\n");
        gotoxy(x - 10, 20);
        textcolor(WHITE); Sl; Sl;    //棻衛 儀 滲唳
        break;
    case 2:
        gotoxy(x - 15, 22);
        textcolor(BLUE);
        printf(">>  [ ] 3з喇 (NORMAL)   <<\n");
        gotoxy(x - 10, 22);
        textcolor(WHITE); Sl; Sl;    //棻衛 儀 滲唳
        break;
    case 3:
        gotoxy(x - 15, 24);
        textcolor(RED);
        printf(">>  [ ] 4з喇 (HARD)   <<\n");
        gotoxy(x - 10, 24);
        textcolor(WHITE); Sl; Sl;    //棻衛 儀 滲唳
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
    struct FLAG* pf = NULL;         //梓嫦曖 輿模 嫡擊 ん檣攪
    int x = 1, y = 32;
    int f = 0;                      //啪歜 謙猿 罹睡蒂 �挫恉炱� 嬪и 滲熱
    int step = 40;

    char map[38][300] =
    { "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎",
        "                        弛                弛                            ",
        "                        弛                弛                            ",
        "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖",
        "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎",
    };





    while (1)       //衙廓 奩犒戲煎 裘 轎溘
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

        if (!pf) {                                      //pf==0檜賊 褒ч(蟾晦高檜 0檜晦 ��僥.檜嘐 梓嫦 高檜 й渡腋氈戲賊 棻擠 奩犒縑憮 棻衛 й渡ж雖 彊啪 л)
            pf = flag();                                //梓嫦 謝ル й渡ж堅 輿模 pf縑 渠殮    
        }
        flag_stage1(pf);                                      //梓嫦 寡纂

        Cursor(x, y);


        while (1) {
            if (_kbhit()) {
                int ch = _getch();
                switch (ch) {
                case 72: //嶺 寞щ酈
                    moveCursor(&x, &y, 0, -1);
                    step--;
                    print_step(step);
                    break;
                case 80: //嬴楚 寞щ酈
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
                    c = game_out();             //л熱 檜葷 escmenu陛 渦 橫選萵 蛭

                    if (c == 1)
                    {
                        pf = 0;                //Ы溯檜橫陛 棻衛ж晦蒂 摹鷗и 唳辦 pf縑 0擊 渠殮п憮 梓嫦,衛除 婦溼 高菟 蟾晦�� ж啪 л
                        heart = 5;
                        step = 40;
                    }
                    else if (c == 2)       //Ы溯檜橫陛 詭景煎 給嬴陛晦蒂 摹鷗и 唳辦縑朝 f縑 1擊 渠殮л
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
                    time_attack_game_level1(); //熱鬼褐羶 贗葛
                    break;
                case 8:
                    avoid_prof_story();
                    avoid_prof_level1(); //掖熱椒Яж晦
                    break;
                case 9:
                    guess_story();
                    guessNumberGame_level1();  //璋濠蜃蹺晦
                    break;
                case 10:
                    avoid_F_story();
                    start_avoid_F_level1();        //FЯж晦

                    break;
                case 11:            //嘐蝶攪葬襪鍔
                    mysteryQuiz_level1();
                    break;
                case 12:
                    matching_arrow_level1();                //�香嚂斥藏葑�
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
        if (f == 1)                            //f陛 1檣 唳辦縑朝 蝶纔檜雖蒂 謙猿л
            break;
    }
}



void stage2()
{
    struct FLAG* pf = NULL;         //梓嫦曖 輿模 嫡擊 ん檣攪
    //int c_time, p_time;             //啪歜 衛除 婦溼 滲熱
    int x = 1, y = 32;
    int f = 0;                      //啪歜 謙猿 罹睡蒂 �挫恉炱� 嬪и 滲熱
    int step = 30;

    char map[38][300] =
    {
        "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎",
        "                        弛                弛                            ",
        "                        弛                弛                            ",
        "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖",
        "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎",
    };







    while (1)       //衙廓 奩犒戲煎 裘 轎溘
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


        if (!pf) {                                      //pf==0檜賊 褒ч(蟾晦高檜 0檜晦 ��僥.檜嘐 梓嫦 高檜 й渡腋氈戲賊 棻擠 奩犒縑憮 棻衛 й渡ж雖 彊啪 л)
            pf = flag();                                //梓嫦 謝ル й渡ж堅 輿模 pf縑 渠殮    
        }
        flag_stage2(pf);                                      //梓嫦 寡纂

        Cursor(x, y);


        while (1) {
            if (_kbhit()) {
                int ch = _getch();
                switch (ch) {
                case 72: //嶺 寞щ酈
                    moveCursor(&x, &y, 0, -1);
                    step--;
                    print_step(step);
                    break;
                case 80: //嬴楚 寞щ酈
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
                    c = game_out();             //л熱 檜葷 escmenu陛 渦 橫選萵 蛭

                    if (c == 1)
                    {
                        pf = 0;                //Ы溯檜橫陛 棻衛ж晦蒂 摹鷗и 唳辦 pf縑 0擊 渠殮п憮 梓嫦,衛除 婦溼 高菟 蟾晦�� ж啪 л
                        heart = 4;
                        step = 30;
                    }
                    else if (c == 2)       //Ы溯檜橫陛 詭景煎 給嬴陛晦蒂 摹鷗и 唳辦縑朝 f縑 1擊 渠殮л
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
                    time_attack_story();    //熱鬼褐羶 顫歜橫鷗 啪歜
                    time_attack_game_level2(); //熱鬼褐羶
                    break;
                case 8:
                    avoid_prof_story();
                    avoid_prof_level2();  //掖熱椒Яж晦
                    break;
                case 9:
                    guess_story();
                    guessNumberGame_level2();  //璋濠蜃蹺晦
                    break;
                case 10:
                    avoid_F_story();
                    start_avoid_F_level2();        //FЯж晦

                    break;
                case 11:            //嘐蝶攪葬襪鍔
                    mysteryQuiz_level2();
                    break;
                case 12:
                    matching_arrow_level2();                //�香嚂斥藏葑�
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
        if (f == 1)                            //f陛 1檣 唳辦縑朝 蝶纔檜雖蒂 謙猿л
            break;
    }
}





void stage3()
{
    struct FLAG* pf = NULL;         //梓嫦曖 輿模 嫡擊 ん檣攪
    int x = 1, y = 32;
    int f = 0;                      //啪歜 謙猿 罹睡蒂 �挫恉炱� 嬪и 滲熱
    int step = 15;

    char map[38][300] =
    {
        "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "弛                                                                    弛",
        "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎",
        "                        弛                弛                            ",
        "                        弛                弛                            ",
        "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖",
        "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎",
    };

    while (1)       //衙廓 奩犒戲煎 裘 轎溘
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

        if (!pf) {                                      //pf==0檜賊 褒ч(蟾晦高檜 0檜晦 ��僥.檜嘐 梓嫦 高檜 й渡腋氈戲賊 棻擠 奩犒縑憮 棻衛 й渡ж雖 彊啪 л)
            pf = flag();                                //梓嫦 謝ル й渡ж堅 輿模 pf縑 渠殮    
        }
        flag_stage3(pf);                                      //梓嫦 寡纂

        Cursor(x, y);


        while (1) {
            if (_kbhit()) {
                int ch = _getch();
                switch (ch) {
                case 72: //嶺 寞щ酈
                    moveCursor(&x, &y, 0, -1);
                    step--;
                    print_step(step);
                    break;
                case 80: //嬴楚 寞щ酈
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
                    c = game_out();             //л熱 檜葷 escmenu陛 渦 橫選萵 蛭

                    if (c == 1)
                    {
                        pf = 0;                //Ы溯檜橫陛 棻衛ж晦蒂 摹鷗и 唳辦 pf縑 0擊 渠殮п憮 梓嫦,衛除 婦溼 高菟 蟾晦�� ж啪 л
                        heart = 3;
                        step = 15;
                    }
                    else if (c == 2)       //Ы溯檜橫陛 詭景煎 給嬴陛晦蒂 摹鷗и 唳辦縑朝 f縑 1擊 渠殮л
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
                    time_attack_story();    //熱鬼褐羶 顫歜橫鷗 啪歜
                    time_attack_game_level3(); //熱鬼褐羶
                    break;
                case 8:
                    avoid_prof_story();
                    avoid_prof_level3(); //掖熱椒Яж晦
                    break;
                case 9:
                    guess_story();
                    guessNumberGame_level3();  //璋濠蜃蹺晦
                    break;
                case 10:
                    avoid_F_story();
                    start_avoid_F_level3();        //FЯж晦
                    break;
                case 11:                 //嘐蝶攪葬襪鍔
                    mysteryQuiz_level3();
                    break;
                case 12:
                    matching_arrow_level3();                //�香嚂斥藏葑�
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
        if (f == 1)                            //f陛 1檣 唳辦縑朝 蝶纔檜雖蒂 謙猿л
            break;
    }
}



void game_over()
{
    cls;
    np(10);
    middle("渡褐擎 Fз薄擊 嫡嬴幗溜棻.\n");
    Sl; Sl;
    np(3);
    middle("棻擠 з喇擊 晦擒ж濠...\n");
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
    printf("[ ] 詭景 �飛橉虞� 給嬴陛晦 (MENU)");
    gotoxy(65, 22);
    printf("[ ] 謙猿ж晦 (OUT)");
    gotoxy(66, 20);

    while (1)
    {
        if (_kbhit())
        {
            int ch = _getch();

            if (ch == 13)       //Enter酈
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
        printf(">>  [ ] 詭景 �飛橉虞� 給嬴陛晦 (MENU)   <<");
        gotoxy(66, 20);
        textcolor(WHITE); Sl; Sl;    //棻衛 儀 滲唳
        return 1;
        break;
    case 2:
        gotoxy(61, 22);
        textcolor(RED);
        printf(">>  [ ] 謙猿ж晦 (OUT)   <<\n");
        gotoxy(66, 22);
        textcolor(WHITE); Sl; Sl;    //棻衛 儀 滲唳
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
        middle("渡褐曖 檜廓 з喇 з薄擎 D 殮棲棻.\n");
        np(3);
        middle("碟嫦ж敷撿啊橫蹂~\n");
        break;
    case 2:
        np(10);
        middle("渡褐曖 檜廓 з喇 з薄擎 C 殮棲棻.\n");
        np(3);
        middle("碟嫦ж敷撿啊橫蹂~\n");
        break;
    case 3:
        np(10);
        middle("渡褐曖 檜廓 з喇 з薄擎 B 殮棲棻.\n");
        np(3);
        middle("遽熱и 撩瞳檜捱蹂?\n");
        break;
    case 4:
        np(10);
        middle("渡褐曖 檜廓 з喇 з薄擎 A 殮棲棻.\n");
        np(3);
        middle("�К〥桭炴�!\n");
        break;
    case 5:
        np(10);
        middle("渡褐曖 檜廓 з喇 з薄擎 A+ 殮棲棻.\n");
        np(3);
        middle("渠欽п蹂!\n");
        break;
    }


    Sl; Sl; Sl;
}