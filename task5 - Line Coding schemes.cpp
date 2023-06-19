/// task 5 - simulating NRZ-L, NRZ-I and Pseudoternary line coding schemes

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

/// Coordinates Handler
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

/// Prototypes
void gotoXY(int x, int y);
void nrzl(char a[], int s);
void nrzi(char a[], int s);
void pseudoternary(char a[], int s);

int main()
{
k:
    Sleep(800);
    system("cls");
    cout<<"How many digits you want to give as input? ";
    int n;
    cin>>n;
    char a[n+2];
    cout<<"Enter a "<<n<<" digit binary number: ";

    for(int i=0; i<n; i++)
        cin>>a[i];

    for(int i=0; i<n; i++)
    {
        if(!(a[i]=='0' || a[i]=='1'))
        {
            cout<<"Invalid Binary";
            goto k;
        }
    }

    cout<<"Enter the Encoding Method: ";
    string b;
    cin>>b;

    for(int i=0; i<b.size(); i++)
        b[i] = toupper(b[i]);

    if(b == "NRZL") /// for NRZ-L scheme
        nrzl(a, n);
    else if(b == "NRZI") /// for NRZ-I scheme
        nrzi(a, n);
    else if(b == "PTER") /// for Pseudoternary scheme
        pseudoternary(a, n);
    else
    {
        cout<<"Invalid Method"<<endl;
        goto k;
    }

    return 0;
}

void gotoXY(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

void nrzl(char a[], int b)
{
    int x = 0, y = 0;
    system("cls");
    cout<<"Amplitude";
    x = 4;
    y = 1;
    gotoXY(x, y);
    cout<<"^";
    y++;

    while(y != 17)
    {
        gotoXY(x, y);
        cout<<"|";
        y++;
    }

    x = 0;
    y = 9;
    gotoXY(x, y);
    cout<<"NRZL";

    for(int i=0; i<b; i++)
    {
        int temp = 0;

        if(a[i] == '0')
        {
            if(i == 0)
            {
                x = 7;
                y = 2;
                gotoXY(x, y);
                cout<<a[i];
                x = 5;
                y = 7;
                gotoXY(x, y);
                cout<<"_____";
            }

            if(i>0 && a[i-1]=='1')
            {
                x += 3;
                temp = y;
                y = 2;
                gotoXY(x, y);
                cout<<a[i];
                x -= 3;
                y = temp;
                gotoXY(x, y);
                cout<<"|";
                y++;
                gotoXY(x, y);
                cout<<"|";
                y++;
                gotoXY(x, y);
                cout<<"|";
                y -= 3;
                x++;
                gotoXY(x, y);
                cout<<"_____";
            }

            if(i> 0 && a[i-1]=='0')
            {
                y = 2;
                x += 2;
                gotoXY(x, y);
                cout<<a[i];
                x -= 2;
                y = 7;
                gotoXY(x, y);
                cout<<"_____";
            }
        }
        else
        {
            if(i == 0)
            {
                x = 7;
                y = 2;
                gotoXY(x, y);
                cout<<a[i];
                x = 5;
                y = 10;
                gotoXY(x, y);
                cout<<"_____";
            }

            if(i>0 && a[i-1]=='0')
            {
                x += 3;
                temp = y;
                y = 2;
                gotoXY(x, y);
                cout<<a[i];
                x -= 3;
                y = temp;
                gotoXY(x, y);
                cout<<"|";
                y++;
                gotoXY(x, y);
                cout<<"|";
                y++;
                gotoXY(x, y);
                cout<<"|";
                x += 1;
                gotoXY(x, y);
                cout<<"_____";
            }

            if(i>0 && a[i-1]=='1')
            {
                y = 2;
                x += 2;
                gotoXY(x, y);
                cout<<a[i];
                x -= 2;
                y = 10;
                gotoXY(x, y);
                cout<<"_____";
            }
        }

        x += 5;
        y = 8;
    }

    y++;
    gotoXY(x, y);
    cout<<"---------> Time"<<endl;
    char choice;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<"Enter \"Y\" to try again and \"N\" or any character to quit: ";
    cin>>choice;
    choice = toupper(choice);

    if(choice == 'Y')
        main();
    else
        exit(0);
}

void nrzi(char a[], int b)
{
    int x = 0, y = 0;
    system("cls");
    cout<<"Amplitude";
    x = 4;
    y = 1;
    gotoXY(x, y);
    cout<<"^";
    y++;

    while(y != 17)
    {
        gotoXY(x, y);
        cout<<"|";
        y++;
    }

    x = 0;
    y = 9;
    gotoXY(x, y);
    cout<<"NRZI";

    for(int i=0; i<b; i++)
    {
        int temp = 0;

        if(a[i] == '0')
        {
            if(i == 0)
            {
                x = 7;
                y = 2;
                gotoXY(x, y);
                cout<<a[i];
                x = 5;
                y = 7;
                gotoXY(x, y);
                cout<<"_____";
            }

            if(i > 0)
            {
                temp = y;
                y = 2;
                x += 2;
                gotoXY(x, y);
                cout<<a[i];
                x -= 2;
                y = temp;
                gotoXY(x, y);
                cout<<"_____";
            }
        }
        else
        {
            if(i == 0)
            {
                x = 7;
                y = 2;
                gotoXY(x, y);
                cout<<a[i];
                x = 5;
                y = 10;
                gotoXY(x, y);
                cout<<"_____";
            }

            if(i > 0)
            {
                x += 3;
                temp = y;
                y = 2;
                gotoXY(x, y);
                cout<<a[i];
                x -= 3;
                y = temp;

                if(y == 7)
                {
                    y++;
                    gotoXY(x, y);
                    cout<<"|";
                    y++;
                    gotoXY(x, y);
                    cout<<"|";
                    y++;
                    gotoXY(x, y);
                    cout<<"|";
                }
                else
                {
                    gotoXY(x, y);
                    cout<<"|";
                    y--;
                    gotoXY(x, y);
                    cout<<"|";
                    y--;
                    gotoXY(x, y);
                    cout<<"|";
                    y--;
                }

                x += 1;
                gotoXY(x, y);
                cout<<"_____";
            }
        }

        x += 5;
    }

    y = 9;
    gotoXY(x, y);
    cout<<"---------> Time"<<endl;
    char choice;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<"Enter \"Y\" to try again and \"N\" or any character to quit: ";
    cin>>choice;
    choice = toupper(choice);

    if(choice == 'Y')
        main();
    else
        exit(0);
}

void pseudoternary(char a[], int b)
{
    int x = 0, y = 0;
    system("cls");
    cout<<"Amplitude";
    x = 4;
    y = 1;
    gotoXY(x, y);
    cout<<"^";
    y++;

    while(y != 17)
    {
        gotoXY(x, y);
        cout<<"|";
        y++;
    }

    x = 0;
    y = 9;
    gotoXY(x, y);
    cout<<"PTER";
    int lastLevel = 7;

    for(int i=0; i<b; i++)
    {
        int temp = 0;

        if(a[i] == '1')
        {
            if(i == 0)
            {
                x = 7;
                y = 2;
                gotoXY(x, y);
                cout<<a[i];
                x = 5;
                y = 9;
                gotoXY(x, y);
                cout<<"_____";
            }

            if(i > 0)
            {
                temp = y;
                y = 2;
                x += 2;
                gotoXY(x, y);
                cout<<a[i];
                x -= 2;
                y = temp;

                if(y == 7)
                {
                    y++;
                    gotoXY(x, y);
                    cout<<"|";
                    y++;
                    gotoXY(x, y);
                    cout<<"|";
                }
                else if(y == 11)
                {
                    gotoXY(x, y);
                    cout<<"|";
                    y--;
                    gotoXY(x, y);
                    cout<<"|";
                    y--;
                }
                else
                {
                    gotoXY(x, y);
                    cout<<"_";
                }

                gotoXY(x+1, y);
                cout<<"____";
            }
        }
        else
        {
            if(i == 0)
            {
                x = 7;
                y = 2;
                gotoXY(x, y);
                cout<<a[i];
                x = 5;
                y = 7;
                gotoXY(x, y);
                cout<<"_____";
            }

            if(i > 0)
            {
                x += 3;
                temp = y;
                y = 2;
                gotoXY(x, y);
                cout<<a[i];
                x -= 3;
                y = temp;

                if(a[i-1] == '1')
                {
                    if(lastLevel == 7)
                    {
                        y++;
                        gotoXY(x, y);
                        cout<<"|";
                        y++;
                        gotoXY(x, y);
                        cout<<"|";
                    }
                    else
                    {
                        gotoXY(x, y);
                        cout<<"|";
                        y--;
                        gotoXY(x, y);
                        cout<<"|";
                        y--;
                    }
                }
                else
                {
                    if(lastLevel == 7)
                    {
                        y++;
                        gotoXY(x, y);
                        cout<<"|";
                        y++;
                        gotoXY(x, y);
                        cout<<"|";
                        y++;
                        gotoXY(x, y);
                        cout<<"|";
                        y++;
                        gotoXY(x, y);
                        cout<<"|";
                    }
                    else
                    {
                        gotoXY(x, y);
                        cout<<"|";
                        y--;
                        gotoXY(x, y);
                        cout<<"|";
                        y--;
                        gotoXY(x, y);
                        cout<<"|";
                        y--;
                        gotoXY(x, y);
                        cout<<"|";
                        y--;
                    }
                }

                x += 1;
                gotoXY(x, y);
                cout<<"_____";
                lastLevel = y;
            }
        }

        x += 5;
    }

    y = 9;
    gotoXY(x, y);
    cout<<"---------> time"<<endl;
    char choice;
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<"Enter \"Y\" to try again and \"N\" or any character to quit: ";
    cin>>choice;
    choice = toupper(choice);

    if(choice == 'Y')
        main();
    else
        exit(0);
}
