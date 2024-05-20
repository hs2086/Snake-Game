#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<ctime>
#include<cstdlib>
using namespace std;
bool gameOver;
//for see game snake is play or not play
const int width = 40;
// width for screan
const int height = 20;
// length for screan
int x, y, fruitX, fruitY, score = 0;
// x, y for to set location head the snake
// fruitX, fruitY for to set location the fruit this the snake is eat
// score for to record score the player
int bigfruitx, bigfruity;
int bombx, bomby;
int tailX[10000] = { 0 }, tailY[10000] = { 0 };
// tailX , tailY matrices to store location the body of snake
int nTail = 0;
// nTail for to number of body the snake
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
// enum for to the store value const
void levels()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    // Change color to blue and red
    cout << "\n<<      Controls         >>\n";
    cout << "<<  W     ===>       UP  >>\n";
    cout << "<<  S     ===>     DOWN  >>\n";
    cout << "<<  D     ===>    RIGHT  >>\n";
    cout << "<<  A     ===>     LEFT  >>\n";
    cout << "<<  P     ===>    PAUSE  >>\n";
    cout << "<<  X     ===>     EXIT  >>\n";
    cout << "\n<< Choose Map >>\n";
    cout << "==> Map 1" << endl;
    cout << "==> Map 2 " << endl;
    cout << "==> Map 3" << endl;
    cout << "Enter Map : ";
}
void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    // x,y cordinate the head of snake
    srand(time(0));
    // srand for to give me numbers diffrent in time for run program
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    nTail = 0;
    srand(time(NULL));
    bigfruitx = rand() % (width - 2) + 1;
    bigfruity = rand() % (height - 2) + 1;
    bombx = rand() % width;
    bomby = rand() % height;
}
void Draw_1()
{
    system("cls");   // Linux system("clear");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    // Change color to green
    cout << "=================WELCOME=================" << endl;
    for (int i = 0; i < width + 2; i++)
    {

        cout << "@";
    }
    cout << endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {

                cout << "@";
            }
            if (i == y && j == x)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                // Change color to white
                cout << "O";
            }
            else if (i == fruitY && j == fruitX)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                // Change color to blue
                cout << "$";
            }
            else  if (i == bigfruity && j == bigfruitx) {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                // Change color to blue
                if (score % 5 == 0 && score != 0)
                    cout << "G";
                else cout << " ";
            }
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
                        // Change color to green and blue
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                {
                    cout << " ";
                }
            }
            if (j == width - 1)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                // Change color to green
                cout << "@";
            }

        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
    {

        cout << "@";
    }
    cout << endl;
    cout << "Score : " << score << endl;
}
void Draw_2() {
    system("cls");   // Linux system("clear");
    // system cls(clear screen) used to remove any things in the screen console
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    // Change color to green
    cout << "=================WELCOME=================" << endl;
    for (int i = 0; i < width + 2; i++)
    {

        cout << "@";
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {

                cout << "@";
            }
            if (i == y && j == x)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                // Change color to white
                cout << "O";
            }
            else if (i == fruitY && j == fruitX)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                // Change color to blue
                cout << "$";
            }
            else if (i == bomby && j == bombx)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                // Change color to red
                    if (score % 3 == 0 && score != 0)
                        cout << "*";
                    else cout << " ";
            }
            else if (i == bigfruity && j == bigfruitx)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                // Change color to blue
                    if (score % 5 == 0 && score != 0)
                        cout << "G";
                    else cout << " ";
            }
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
                        // Change color to green and blue
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                {
                    cout << " ";
                }
            }
            if (j == width - 1)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                // Change color to green
                cout << "@";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
    {

        cout << "@";
    }
    cout << endl;
    cout << "Score : " << score << endl;
}
void Draw_3() {
    system("cls");
    // system cls(clear screen) used to remove any things in the screen console
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    // Change color to green
    cout << "=================WELCOME=================" << endl;
    for (int i = 0; i < width + 2; i++)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        // Change color to green
        cout << "@";
    }
    cout << endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                // Change color to green
                cout << "@";
            }
            if (i == y && j == x)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                // Change color to white
                cout << "O";
            }
            else if (i == fruitY && j == fruitX)
            {
                if ((i > 5) == fruitY && (i < 15) == fruitY && (fruitX == 10 || fruitX == 30)) {
                    srand(time(0));
                    // srand for to give me numbers diffrent in time for run program
                    fruitX = rand() % width;
                    fruitY = rand() % height;
                }
                else {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                    // Change color to blue
                    cout << "$";
                }
            }
            else if (i == bomby && j == bombx)
            {
                if ((i > 5) == bomby && (i < 15) == bomby && bombx == 10 || bombx == 30) {
                    srand(time(NULL));
                    bombx = rand() % width;
                    bomby = rand() % height;
                }
                else {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    // Change color to red
                    if (score % 3 == 0 && score != 0)
                        cout << "*";
                    else cout << " ";
                }
            }
            else if (i == bigfruity && j == bigfruitx)
            {
                if ((i > 5) == bomby && (i < 15) == bomby && bombx == 10 || bombx == 30) {
                    srand(time(NULL));
                    bigfruitx = rand() % (width - 2) + 1;
                    bigfruity = rand() % (height - 2) + 1;
                }
                else {
                    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                    // Change color to blue
                    if (score % 5 == 0 && score != 0)
                        cout << "G";
                    else cout << " ";
                }
            }
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE);
                        // Change color to green and blue
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                {
                    cout << " ";
                }
            }
            if (j == width - 1)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                // Change color to green
                cout << "@";
            }
            if (j == 10 && i > 5 && i < 15)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                // Change color to green
                cout << '\b' << "&";
            }
            if (j == 30 && i > 5 && i < 15)
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                // Change color to green
                cout << '\b' << "&";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < width + 2; i++)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        // Change color to green
        cout << "@";
    }
    cout << endl;
    cout << "Score : " << score << endl;
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            if (dir == RIGHT)
                dir = RIGHT;
            else dir = LEFT;
            break;
        case 'd':
            if (dir == LEFT)
                dir = LEFT;
            else dir = RIGHT;
            break;
        case 'w':
            if (dir == DOWN)
                dir = DOWN;
            else dir = UP;
            break;
        case 's':
            if (dir == UP)
                dir = UP;
            else dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        case 'p':
            system("pause");
            break;
        }
    }
    // _kbhit() to sea if the user press key in keyboard
    // _getch() to know the char is the user press
}
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        swap(tailX[i], prevX);
        swap(tailY[i], prevY);
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
}
void map_1() {
    if (x >= width)
    {
        x = 0;
        //the snake will not die if enter the all wall;
    }
    else if (x < 0)
    {
        x = width - 1;
        //the snake will not die if enter the all wall;
    }
    if (y >= height)
    {
        //the snake will not die if enter the all wall;
        y = 0;
    }
    else if (y < 0)
    {
        //the snake will not die if enter the all wall;
        y = height - 1;
    }
    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
        }
    }
    if (x == fruitX && y == fruitY)
    {
        score += 1;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
    if (x == bigfruitx && y == bigfruity)
    {
        score += 2;
        bigfruitx = rand() % width;
        bigfruity = rand() % height;
        nTail += 2;
    }
}
void map_2() {
    if (x >= width || x == -1 || y >= height || y == -1)
    {
        gameOver = true;
        //for the snake enter all the wall will die;
    }
    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
        }
    }
    if (x == fruitX && y == fruitY)
    {
        score += 1;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
    if (x == bombx && y == bomby)
    {
        score -= 1;
        bombx = rand() % width;
        bomby = rand() % height;
        nTail--;
    }
    if (x == bigfruitx && y == bigfruity)
    {
        score += 2;
        bigfruitx = rand() % width;
        bigfruity = rand() % height;
        nTail += 2;
    }
    if (score == -1) {
        gameOver = true;
    }
}
void map_3() {
    if (x >= width)
    {
        x = 0;
        //the snake will not die if enter the all wall;
    }
    else if (x < 0)
    {
        x = width - 1;
        //the snake will not die if enter the all wall;
    }
    if (y >= height)
    {
        //the snake will not die if enter the all wall;
        y = 0;
    }
    else if (y < 0)
    {
        //the snake will not die if enter the all wall;
        y = height - 1;
    }
    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
        }
    }
    if (x == fruitX && y == fruitY)
    {
        score += 1;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }

    if (x == bombx && y == bomby)
    {
        score--;
        bombx = rand() % width;
        bomby = rand() % height;
        nTail--;
    }
    if (score == -1) {
        gameOver = true;
    }
    if (x == bigfruitx && y == bigfruity)
    {
        score += 2;
        bigfruitx = rand() % width;
        bigfruity = rand() % height;
        nTail += 2;
    }
    if ((x == 10 && y > 5 && y < 15) || (x == 30 && y > 5 && y < 15)) {
        gameOver = true;
    }
}
void print()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    // Change color to green and red
    cout << "==================================" << endl;
    if (score == -1)
        cout << "=========== Score  : " << 0 << " ===========" << endl;
    else
        cout << "=========== Score  : " << score << " ===========" << endl;
    cout << "==================================" << endl;
}
void game()
{
    int n, s = 90;
    levels();
    cin >> n;
    Setup();
    while (!gameOver)
    {
        if (n == 1) {
            Draw_1();
            Input();
            Logic();
            map_1();
        }
        else if (n == 2) {
            Draw_2();
            Input();
            Logic();
            map_2();
        }
        else if (n == 3) {
            Draw_3();
            Input();
            Logic();
            map_3();
        }
        else {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            // Change color to green and red
            cout << "\n<<  WRONG CHOICE  >>\n";
            cout << "<<  TRY AGAIN  >>\n";
            game();
        }
        if (s - 3 * score <= 0)
            Sleep(0);
        else
            Sleep(s - 3 * score);
    }
    cout << "\a\a\a";
    system("pause");
    system("cls");
    print();
}
int main()
{
    char replacegame;
    do
    {
        game();
        cout << "Do You Want Replace Game press y : ";
        cin >> replacegame;
    } while (replacegame == 'y');
}