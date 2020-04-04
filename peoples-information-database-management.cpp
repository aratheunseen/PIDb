/*------- HEADER FILE -------*/
#include <bits/stdc++.h>
#include<stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;

struct citizen{
    char NID[15];
    char fName[30];
    char lName [30];
    char address[50];
    char phone_no[15];
}bd;


/*------- Console Management Function -------*/
void SetColor(int ForgC);
void ClearConsoleToColors(int ForgC, int BackC);
void SetColorAndBackground();
void gotoxy(int x, int y);
void boxBorder();
void window();
void print_heading(const char title[]);
void clearWindow();


/*------- Function Declaration -------*/
void add_info();
void find_info();
void edit_info();
void delete_info();
void display();
void get_password();
void login();
void main_window();


/*------- Main Function -------*/
int main(){
    ClearConsoleToColors(15,15);
    SetConsoleTitle("People's Information: Database Software");
    window();
    login();
    return 0;
}


/*--------------------------------------------
-------------All Function Description---------
---------------------------------------------*/

/*------- Homepage -------*/
void main_window(){
    SetColor(28);
    int choice;
    int x = 2;
    while(1){
        gotoxy(x,8);
            cout << "1. Add Information";
        gotoxy(x,10);
            cout << "2. Find Information";
        gotoxy(x,12);
            cout << "3. Display Information";
        gotoxy(x,14);
            cout << "4. Edit Information";
        gotoxy(x,16);
            cout << "5. Delete Information";
        gotoxy(x,18);
            cout << "6. Sign Out";
        gotoxy(x,20);
            cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                add_info();
                break;
            case 2:
                find_info();
                break;
            case 3:
                display();
                break;
            case 4:
                edit_info();
                break;
            case 5:
                delete_info();
                break;
            case 6:
                clearWindow();
                system("cls");
                window();
                login();
                break;
            default:
                break;
        }
    }
}

/*------- Password Protected Function -------*/
void login(){
    boxBorder();
    SetColor(1028);
    int x = 15, y = 16;
    int username;
    char password[25];
    char mainPassword[25]="123456";
    gotoxy(15,12);
        cout << "The database is password protected.";
    gotoxy(15,13);
        cout << "Enter valid administrator password.";
    SetColor(17);
    gotoxy(20,x);
        cout << "USERNAME:- administrator";
    gotoxy(20,y);
        cout << "PASSWORD:- ";
    gotoxy(34,y);
    int p=0;
    do{
        password[p]=getch();
        if(password[p]!='\r'){
            printf("*");
        }
        p++;
    }while(password[p-1]!='\r');
    password[p-1]='\0';

    if(strcmp(mainPassword,password)==0){
        system("cls");
        window();
        main_window();
    }else {
        system("cls");
        window();
        gotoxy(20,18);
            cout <<"Invalid Password. Try again."<<endl;
        login();
    }
}


/*------- Menu -------*/
void add_info(){
    clearWindow();
    SetColor(10);
    print_heading(" -- Add Information -- ");
    int print = 37;
    char n_id[15];
    int isFound = 0;
    gotoxy(37,10);
        cout << "ID: ";
        fflush(stdin);
        gets(n_id);
    FILE *data;
    data = fopen("info.txt","a+");
    if(strlen(n_id) != 9){
        gotoxy(37,12);
            cout << "ID must be 9 characters";
    }
    else{
        while(fread(&bd,sizeof(bd),1,data) == 1){
            if(strcmp(n_id,bd.NID) == 0){
                isFound = 1;
                gotoxy(37,12);
                    cout << "Information already exist.";
                break;
            }
        }
        if(isFound == 0){
            if(data == NULL){
                MessageBox(0,"Error in Opening file.\nMake sure file is not write protected.","Warning",0);

            }else{
                fflush(stdin);
                    strcpy(bd.NID,n_id);
                gotoxy(print,12);
                    cout << "First Name: ";
                    gets(bd.fName);
                gotoxy(print,14);
                    cout << "Last Name: ";
                    gets(bd.lName);
                gotoxy(print,16);
                    cout << "Address: ";
                    gets(bd.address);
                gotoxy(print,18);
                    cout << "Phone Number: ";
                    gets(bd.phone_no);
                fwrite(&bd,sizeof(bd),1,data);
                gotoxy(40,20);
                    cout << "Information is added successfully.";
            }
        }
    }
    SetColor(28);
    fclose(data);
    return;
}


void find_info(){
    clearWindow();
    SetColor(10);
    print_heading(" -- Find Information -- ");
    char n_id[15];
    int isFound = 0;
    gotoxy(37,10);
        cout << "Enter ID: ";
        fflush(stdin);
        gets(n_id);
    FILE *data;
    data = fopen("info.txt","r");
    while(fread(&bd,sizeof(bd),1,data) == 1){
        if(strcmp(n_id,bd.NID) == 0){
            isFound = 1;
            break;
        }
    }
    if(isFound == 1){
        gotoxy(37,12);
            cout << "The Information is Found.";
        gotoxy(37,14);
            cout << "ID: " << bd.NID;
        gotoxy(37,15);
            cout << "Name: " << bd.fName << " " << bd.lName;
    }else{
        gotoxy(37,12);
            cout << "Sorry, Information not found.";
    }
    SetColor(28);
    fclose(data);
    return;
}


void display(){
    clearWindow();
    SetColor(10);
    print_heading(" -- Display Information -- ");
    char n_id[15];
    int isFound = 0;
    gotoxy(37,10);
        cout << "Enter ID: ";
        fflush(stdin);
    gets(n_id);
    FILE *data;
    data = fopen("info.txt","r");
    while(fread(&bd,sizeof(bd),1,data) == 1){
        if(strcmp(n_id,bd.NID) == 0){
            isFound = 1;
            break;
        }
    }
    if(isFound == 1){
        gotoxy(37,12);
            cout << "Information is Found.";
        gotoxy(37,14);
            cout << "ID: " << bd.NID;
        gotoxy(37,15);
            cout << "Name: " << bd.fName << " " << bd.lName;
        gotoxy(37,16);
            cout << "Address: " << bd.address;
        gotoxy(37,19);
            cout << "Phone No: " << bd.phone_no;
    }else{
        gotoxy(37,12);
            cout << "Sorry, Information not found.";
    }
    SetColor(28);
    fclose(data);
    return;
}


void edit_info(){
    clearWindow();
    SetColor(10);
    print_heading(" -- Edit Information -- ");
    char n_id[15];
    int isFound = 0, print = 37;
    gotoxy(37,10);
        cout << "Enter ID: ";
        fflush(stdin);
    gets(n_id);
    FILE *data;
    data = fopen("info.txt","r+");
    while(fread(&bd, sizeof(bd),1,data) == 1){
        if(strcmp(n_id, bd.NID) == 0){
            fflush(stdin);
            gotoxy(print,12);
                cout << "ID: ";
                gets(bd.NID);
            gotoxy(print,13);
                cout << "First Name: ";
                gets(bd.fName);
            gotoxy(print,14);
                cout << "Name: ";
                gets(bd.lName);
            gotoxy(print,15);
                cout << "Address: ";
                gets(bd.address);
            gotoxy(print,16);
                cout << "Phone Number: ";
                gets(bd.phone_no);
            fseek(data,-sizeof(bd), SEEK_CUR);
            fwrite(&bd,sizeof(bd), 1, data);
            gotoxy(40,20);
                cout << "Information is updated successfully.";
            isFound = 1;
            break;
        }
    }
    if(!isFound){
        gotoxy(print, 12);
            cout << "No Information Found.";
    }
    fclose(data);
    SetColor(28);
    return;
}


void delete_info(){
    clearWindow();
    SetColor(10);
    print_heading(" -- Delete Information -- ");
    char n_id[15];
    int isFound = 0, print = 37;
    gotoxy(37,10);
        cout << "Enter ID: ";
        fflush(stdin);
    gets(n_id);
    FILE *data, *backup;
    data = fopen("info.txt","r");
    backup = fopen("temp.txt", "w");
    while(fread(&bd, sizeof(bd),1,data) == 1){
        if(strcmp(n_id, bd.NID) == 0){
            fwrite(&bd,sizeof(bd),1,backup);
        }
    }
    fclose(data);
    fclose(backup);
    rename("info.txt","backup.txt");
    remove("temp.txt");
    gotoxy(37,12);
        cout << "Information is deleted successfully.";
    SetColor(28);
    return;
}


/*------- Clear Console Color Function (Source: Google) -------*/
void SetColor(int ForgC){
     WORD wColor;
     ///We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     ///We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        ///Mask out all but the background attribute, and add in the foreground color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
void ClearConsoleToColors(int ForgC, int BackC){
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     ///Get the handle to the current output buffer...
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     ///This is used to reset the carat/cursor to the top left.
     COORD coord = {0, 0};
     ///A return value... indicating how many chars were written
     ///   not used but we need to capture this since it will be
     ///   written anyway (passing NULL causes an access violation).
     DWORD count;
     ///This is a structure containing all of the console info
     /// it is used here to find the size of the console.
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     ///Here we will set the current color
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
          ///This fills the buffer with a given character (in this case 32=space).
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          ///This will set our cursor position for the next print statement.
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}
void SetColorAndBackground(int ForgC, int BackC){
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}


/*------- Console Coordinate Function -------*/
COORD coord = {0,0};
void gotoxy(int x, int y){
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


/*------- Title -------*/
void window(){
    boxBorder();
    SetColor(12);
    gotoxy(28,2);
        cout << "People's Information: Database Software";
    SetColor(10);
    gotoxy(28,3);
        cout << "=======================================";
    SetColor(12);
    gotoxy(31,4);
        cout << "People's Republic of Bangladesh";
    SetColor(17);

}

void print_heading(const char title[]){
    SetColor(10);
    SetColorAndBackground(31,3);
    gotoxy(45,8);
        cout << title;
    SetColorAndBackground(17,15);
}


/*------- Clear Window -------*/
void clearWindow(){
    int i,j;
    for(i = 37; i < 78; i++){
        for(j = 7; j < 25; j++){
            gotoxy(i,j);
                cout << " ";
        }
    }
}

/*------- Box Border -------*/
void boxBorder(){

    // Flag of Bangldesh
    for(int i = 6; i<=15; i++){
        for(int j = 2; j <= 4; j++){
            SetColor(2);
            gotoxy(i, j);
            printf("%c",219);
            if ((i == 10 || i == 11) && j == 3){
                SetColor(12);
                gotoxy(i,j);
                printf("%c",219);
            }
        }
    }



    // Box Side Border
    SetColor(8);
    int i, j;
    gotoxy(0,0);
    printf("%c",201);
    for(i = 1; i < 78; i++){
        gotoxy(i, 0);
        printf("%c",205);
    }
    gotoxy(78,0);
    printf("%c",187);
    for(i = 1; i < 25; i++){
        gotoxy(78, i);
        if(i == 6){
            printf("%c",185);
        }else{
            printf("%c",186);
        }
    }
    gotoxy(78, 25);
    printf("%c",188);
    for(i = 77; i > 0; i--){
        gotoxy(i,25);
        if(i == 35){
            printf("%c",205);
        }else{
            printf("%c",205);
        }
    }
    gotoxy(0,25);
    printf("%c",200);
    for(i = 24; i > 0; i--){
        gotoxy(0,i);
        if(i == 6){
            printf("%c",204);
        }else{
            printf("%c",186);
        }
    }

    for(i = 1; i < 78; i++){
        gotoxy(i,6);
        if(i == 35){
            printf("%c",205);
        }else{
            printf("%c",205);
        }
    }

}
