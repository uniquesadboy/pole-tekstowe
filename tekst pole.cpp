#include <iostream>
#include <windows.h>
#include <conio.h>
#include <chrono> 
#include <thread> 

using namespace std;
using namespace std::chrono_literals;

HANDLE console;

void area()
{
    COORD pos;
    pos.X = 5;
    pos.Y = 3;
    SetConsoleTextAttribute(console, BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
    for (int i = 1; i < 27; ++i)
    {
        SetConsoleCursorPosition(console, pos);
        cout << " ";
        pos.X++;
    }
    SetConsoleTextAttribute(console, 0);
}

void input()
{
    char input{ '0' };
    int input_int{ 0 };
    while (input_int != 27)
    {
        COORD pos;
        pos.X = 5;
        pos.Y = 3;
        SetConsoleTextAttribute(console, BACKGROUND_BLUE | FOREGROUND_RED); 
        if (_kbhit())
        {

            for (int i = 1; i < 26; ++i)
            {

                SetConsoleCursorPosition(console, pos);
                input_int = _getch();
                if (input_int != 8 && input_int != 27 && input_int != 75 && input_int != 77 && input_int != 224)
                {
                    input = input_int;
                    cout << input;
                    if (pos.X == 29)
                    {
                        SetConsoleTextAttribute(console, BACKGROUND_BLUE | FOREGROUND_GREEN);
                        pos.X;
                        i--;
                        cout << " " << endl;
                        SetConsoleTextAttribute(console, BACKGROUND_BLUE | FOREGROUND_RED); 
                    }
                    else
                    {
                        pos.X++;
                    }

                }
                if (input_int == 75)
                {
                    SetConsoleCursorPosition(console, pos);
                    if (pos.X == 5)
                    {
                        pos.X;
                        i = pos.X;
                    }
                    else
                    {
                        pos.X--;
                        i = pos.X - 5;
                    }
                }
                if (input_int == 77)
                {
                    SetConsoleCursorPosition(console, pos);
                    if (pos.X == 29)
                    {
                        pos.X;
                        i = pos.X - 5;
                    }
                    else
                    {
                        pos.X++;
                        i = pos.X - 5;
                    }
                }
                else if (input_int == 8)
                {
                    if (pos.X <= 5)
                    {
                        pos.X;
                        i = 0;

                    }
                    else
                    {
                        if (i <= 0)
                        {
                            pos.X = 5;
                            SetConsoleCursorPosition(console, pos);
                            cout << " ";
                            i = 0;
                        }
                        else
                        {
                            if (pos.X == 29)
                            {
                                SetConsoleCursorPosition(console, pos);
                                pos.X;
                                cout << " ";
                                i = pos.X - 5;

                            }
                            pos.X--;
                            SetConsoleCursorPosition(console, pos);
                            cout << " ";
                            i -= 2;
                        }
                    }

                }
                else if (input_int == 27)
                {
                    pos.X = 0;
                    pos.Y = 0;
                    SetConsoleTextAttribute(console, BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                    SetConsoleCursorPosition(console, pos);
                    cout << "You came out, bye!" << endl;
                    break;
                }
                if (i == -1)
                {
                    i += 1;
                }
            }
            SetConsoleTextAttribute(console, 0);
        }
    }
}
int main()
{
    console = GetStdHandle(STD_OUTPUT_HANDLE);
    area();
    input();
    return 0;
}
