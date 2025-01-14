#include "main.h"

extern int next;
extern int heart;

void moveCursor1(int* x, int* y, int dx, int dy) //커서 범위 
{
    int newX = *x + dx;
    int newY = *y + dy;

    if (newX >= 1 && newX <= 37 && newY >= 1 && newY <= 18)
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

void moveCursor2(int* x, int* y, int dx, int dy) //커서 범위 
{
    int newX = *x + dx;
    int newY = *y + dy;

    if (newX >= 1 && newX <= 47 && newY >= 1 && newY <= 21)
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

void moveCursor3(int* x, int* y, int dx, int dy) //커서 범위 
{
    int newX = *x + dx;
    int newY = *y + dy;

    if (newX >= 1 && newX <= 57 && newY >= 1 && newY <= 23)
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




