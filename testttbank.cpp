#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>   //CLOCK_REALTIME 
#include <fstream>  ///Input/output read file stream class
#include <cstdio>   ///this is for READ AND WRITE THE FILES BYTE
#include <climits> ///THIS IS FOR BITS VALUEE MAX FUNCTIONS

using namespace std;

int r; //random characters
int chkacc(int a);
int chkaccreg(int b);
int chkbnk(int c);
/*a, which is an integer representing the column number (also known as the x-coordinate) of the desired cursor position
b, which is an integer representing the row number (also known as the y-coordinate) of the desired cursor position
The function begins by assigning the values of a and b to the X and Y fields of a COORD struct called coord.
The COORD struct is a simple data structure that is used to represent a point in a console window,
and it contains two fields: X and Y, which represent the column and row numbers, respectively.

Next, the function calls the SetConsoleCursorPosition function, which takes two arguments:
a handle to the console output device and a COORD struct specifying the new cursor position.
The handle to the console output device is obtained by calling the GetStdHandle function with the STD_OUTPUT_HANDLE constant as the argument.
The SetConsoleCursorPosition function moves the cursor to the position specified by the COORD struct.

This function can be used to move the cursor to a specific position on the console window,
which can be useful if you want to print text at a specific location on the screen.
For example, if you call this function with gotoxy(10, 5), it will move the cursor to column 10, row 5 on the console window.*/
COORD coord = {0,0};

void gotoxy(int a, int b){
    coord.X = a;
    coord.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/*x, which is an integer representing the number of times the character specified by y should be printed
y, which is an integer representing the ASCII value of the character that should be printed
The function uses a for loop to iterate x times, and in each iteration,
it prints the character corresponding to the ASCII value of y. The (char) typecast is used to convert the integer value of y to a character,
which is then printed to the console using cout.
For example, if you call this function with design(5, 65), it will print AAAAA to the console,
because 65 is the ASCII value for the letter A. Similarly, if you call this function with design(7, 66),
it will print BBBBBBB to the console, because 66 is the ASCII value for the letter B.*/
void design(int x, int y) {
    for (int i = 0; i <= x; i++)
        cout<<(char)y;
}

class bms{
    // data encapsulation
    char id[20], password[15];
    private:
        int m;
    public: // data abstraction
        bms(){ //constructor
            system("cls");
            system("color f4");
            gotoxy(26, 4);
            design(15, 177);
            cout<<" WELCOME TO TBC BANKING SYSTEM ";
            design(15, 177);
            gotoxy(50, 8);
            cout<<"ACCOUNT TYPE";
            gotoxy(44, 10);
            cout<<"[1] . ADMINISTRATOR ";
            gotoxy(44, 11);
            cout<<"[2] . USER ";
            gotoxy(44, 12);
            cout<<"[3] . Register ";
            gotoxy(44, 14);
            cout<<"Enter Your Choice .... ";
            cin>>m;
            if (m != 1 && m != 2 && m != 3) {
                system("cls");
                bms();
            }
            else if (m ==1){
                system("cls");
                authenticate();
            }
            else if (m ==2){
                userlogin();
            }
            else if (m == 3)
			{
            	regis();	
			}
            
        }

        void authenticate(){
            system("color f4");
            gotoxy(26, 4);
            design(15, 177);
            cout<<" WELCOME TO TBC BANKING SYSTEM ";
            design(15, 177);
            login();
            if (verify() == 1) {
                if (m == 1){
                    menu();
                }
                

            } else if (verify() == 0) {
                system("cls");
                gotoxy(35, 17);
                design(48, 45);
                gotoxy(43, 16);
                cout<<"Incorrect Username / Password !!!!";
                authenticate();
            }
        }

        void login(){ // Takes the user-name and password .
            gotoxy(44, 10);
            cout<<"Enter The Username : ";
            cin>>id;
            gotoxy(44, 12);
            cout<<"Enter The Password : ";
            cin>>password;
        }
        void regis();
        void userlogin();

        int verify(){ // verifies the user-name and password .
            char a;
            if (m == 1) {
                if ((strcmp(id, "admin") == 0 && strcmp(password, "admin") == 0)) {
                    gotoxy(35, 17);
                    design(48, 45);
                    gotoxy(38, 16);
                    cout<<"You Have Successfully Logged In : "<<'"'<<id<<'"'<<endl;
                    time_t t;
                    time(&t);
                    gotoxy(39, 18);
                    cout<<"Logged In Time : "<<ctime(&t);
                    gotoxy(44, 22);
                    cout<<"Press any key to continue .... ";
                    getch();
                    return 1;
                } else
                    return 0;
            } else if (m == 2) {
                userlogin();
            }else
                regis();
            return 0;
        }

        void menu(){ // displays the main user.
            system("cls");
            gotoxy(28, 4);
            design(20, 177);
            cout<<" WELCOME TO MAIN MENU ";
            design(20, 177);
            gotoxy(44, 8);
            cout<<"[1] . View Customer Accounts";
            gotoxy(44, 9);
            cout<<"[2] . Customer Account Registration";
            gotoxy(44, 10);
            cout<<"[3] . Edit Customer Account";
            gotoxy(44, 11);
            cout<<"[4] . Delete Customer Account";
            gotoxy(44, 12);
            cout<<"[5] . Search Customer Account";
            gotoxy(44, 13);
            cout<<"[6] . Transaction";
            gotoxy(44, 14);
            cout<<"[7] . Add Bank Branch";
            gotoxy(44, 15);
            cout<<"[8] . Delete Bank Branch";
            gotoxy(44, 16);
            cout<<"[9] . View Bank Branch";
            gotoxy(44, 17);
            cout<<"[10] . Log Out !!! ";
            gotoxy(44, 18);
            cout<<"[11] . About US ";
            gotoxy(43, 22);
            cout<<"Please Enter Your Choice [1-11] : ";
            option();
        }

        void option() { // takes user choice.
            int i;
            cin>>i;
            system("cls");
            switch (i) {
                case 1:
                    view();
                    break;
                case 2:
                    add();
                    break;
                case 3:
                    edit();
                    break;
                case 4:
                    del();
                    break;
                case 5:
                    srch();
                    break;
                case 6:
                    transactions();
                    break;
                case 7:
                    bankadd();
                    break;
                case 8:
                    delbnk();
                    break;
                case 9:
                    bnkview();
                    break;
                case 10:
                    bms();
                    break;
                case 11:
                    about();
                    break;
                default:
                    menu();
            }
        }

        void view();
        void add();
        void edit();
        void del();

        void srch(){ //module for searching account ( 2 types by number and name )
            system("cls");
            int a;
            gotoxy(28, 4);
            design(25, 177);
            cout<<" SEARCH MENU ";
            design(25, 177);
            gotoxy(49, 10);
            cout<<"[1] . Search By Account ";
            gotoxy(49, 12);
            cout<<"[2] . Search By Name ";
            gotoxy(47, 17);
            cout<<"Enter Your Choice [1-2] : ";
            scanf("%d", &a);
            system("cls");
            if (a == 1) {
                search_acc();
            } else if (a == 2) {
                search_name();
            } else
                menu();
        }
        void search_acc();
        void search_name();

        void transactions(){ // displays screen for the transaction options and takes the user choice .
            int a;
            system("CLS");
            gotoxy(25, 4);
            design(25, 177);
            cout<<" TRANSACTION MENU ";
            design(25, 177);
            gotoxy(49, 9);
            cout<<"[1] . Balance Inquiry";
            gotoxy(49, 10);
            cout<<"[2] . Cash Deposit";
            gotoxy(49, 11);
            cout<<"[3] . Cash Withdrawal";
            gotoxy(49, 12);
            cout<<"[4] . Fund Transfer";
            gotoxy(49, 13);
            cout<<"[5] . Main Menu";
            gotoxy(49, 13);
            cout<<"[5] . Exit";
            gotoxy(45, 17);
            cout<<"Please Enter Your Choice [1-5] : ";
            scanf("%d", &a);
            switch (a) {
                case 1:
                    system("cls");
                    chkblnc();
                    break;
                case 2:
                    system("cls");
                    deposit();
                    break;
                case 3:
                    system("cls");
                    withdrawl();
                    break;
                case 4:
                    system("cls");
                    transfer();
                    break;
                case 5:
                    bms();
                    break;
                default:
                    transactions();
            }
        }

        void chkblnc();
        void deposit();
        void withdrawl();
        void transfer();
        void bankadd();
        void bnkviewuser();
        void bnkview();
        void delbnk();
        void menuexit();
        void about(){
            gotoxy(30, 4);
            design(25, 177);
            cout<<" ABOUT US ";
            design(25, 177);
            gotoxy(30, 9);
            cout<<"Bank Management System Project for C++ programming language.";
                    gotoxy(45, 12);
                    cout<<"Members of the group: ";
                    gotoxy(28, 13);
                    design(65, 205);
                    gotoxy(48, 15);
                    cout<<"[1] . Sabado Jerald";
                    gotoxy(48, 16);
                    cout<<"[2] . Tolentino Jhon Jaymark";
                    gotoxy(48, 17);
                    cout<<"[3] . Faith Pacumio ";
                    gotoxy(48, 18);
                    cout<<"[4] . Rea Arigo";
                    gotoxy(48, 19);
                    cout<<"[5] . Jezlyn Lagui";
                    gotoxy(41, 21);
                    design(42, 196);
                    gotoxy(42,24);
                    cout<<"Press any key to return back to main menu. ";
                    char z = getch();
                    if (z == 13) {
                    menu();
            }
        }
};

//vvvvvvvvvvvvvvvvvvvvvvvvINHERITANCEvvvvvvvvvvvvvvvvvvvvvv
class record{ //inheritance
    public:
        char name[25];
        int account, passw;
        char phone[15];
        char address[25];
        char email[35];
        char citiz[20];
        double blnc;
        char UserID[10];
};
class bnkrecord{
    public:
        char bnkname[40];
        int bnkid;
};
//^^^^^^^^^^^^^^^^^^^^^^^^^INHERITANCE^^^^^^^^^^^^^^^^^^^^^

//-------------REA---------------------------//
void bms:: userlogin(){
    system("cls");
    record rec;
    ifstream f;
    int number,b;
    gotoxy(23, 4);
    design(25, 177);
    cout<<" Log in Your ACCOUNT ";
    design(25, 177);
    gotoxy(43, 7);
    cout<<"Enter Your Account Number : ";
    cin>>number;
    gotoxy(43, 8);
    cout<<"Enter Your Account Password : ";
    scanf("%d", &b);
    if (chkaccreg(b) == 1) {
        f.open("record.bin", ios::in | ios::binary);
        while (f.read(reinterpret_cast<char*>(&rec),sizeof(rec))) {
            if (rec.passw == b) {
                bnkviewuser();
                getch();
            }
        }
        f.close();
    }
    if (chkaccreg(b) == 0) {
        system("cls");
        gotoxy(41, 14);
        design(42, 196);
        gotoxy(41, 16);
        design(42, 196);
        gotoxy(52, 15);
        cout<<"Account Doesn't Exist.";
        getch();
        userlogin();  
    }
    gotoxy(46, 21);
    cout<<"Press any key to return back to main menu. ";
    getch();
    bms();
}

// Module for Creating users account
void bms:: regis(){ // Takes the user-name and password
    char c;
    record rec;
    //app = append binary / write data to the file
    ofstream f;
    f.open("record.bin", ios::app | ios::binary); // data will be written at end of the file
    int i = 0, x;
        system("cls");
        gotoxy(24, 4);
        design(20, 177);
        cout<<" CUSTOMER ACCOUNT REGISTRATION ";
        design(20, 177);
        gotoxy(36, 8);
        cout<<"[1] . Enter Your Name           : ";
        cin>>rec.name;
        gotoxy(36, 9);
        cout<<"[2] . Enter Your Account Number : ";
        scanf(" %d", &rec.account);
        gotoxy(36, 10);
        cout<<"[3] . Enter Your PIN            : ";
        scanf(" %d", &rec.passw);
        gotoxy(36, 11);
        cout<<"[4] . Enter Your Phone Number   : ";
        cin>>rec.phone;
        gotoxy(36, 12);
        cout<<"[5] . Enter Your Address        : ";
        cin>>rec.address;
        gotoxy(36, 13);
        cout<<"[6] . Enter Your E-mail         : ";
        cin>>rec.email;
        gotoxy(36, 14);
        cout<<"[7] . Enter Your Citizenship No.: ";
        cin>>rec.citiz;
        gotoxy(36, 15);
        cout<<"[8] . Enter Amount To Deposit   : $";
        scanf(" %lf", &rec.blnc);
        srand(time(0)); //random number
        for (r = 0; r < 10; r++) {
            rec.UserID[r] = rand() % 10;
        }
        //write() = for writing binary data
        // reinterpret_cast - casting one pointer data type to another pointer data type
        //This helps to write contents in a class variable in the file and stores it in the variable rec.
        f.write(reinterpret_cast<char*>(&rec), sizeof(rec)); //whatever &rec is treat it as char *
        //char is just a byte , //sizeof gets no. of byte it takes to hold whatevery type rec is
        gotoxy(38, 18);
        cout<<" REGISTRATION SUCCESSFULL";
        i++;
    f.close();
    gotoxy(40, 23);
    cout<<"Press any key to return back to main menu. ";
    char z = getch();
    if (z == 13) {
        bms();
    } else
        view();
}
        
//-------------REA---------------------------//
//--------------------FAITH------------------------//

// module for viewing account details
void bms:: view(){
    int i = 7;
    record rec;
    //read from the file
    ifstream f;
    f.open("record.bin", ios::in | ios::binary); //open file for read only
    gotoxy(25, 3);
    design(25, 177);
    cout<<" CUSTOMERS LIST ";
    design(25, 177);
    gotoxy(5, 5);
    cout<<"A/C No.";
    gotoxy(16, 5);
    cout<<"Account Name";
    gotoxy(34, 5);
    cout<<"UserID";
    gotoxy(49, 5);
    cout<<"Email Address";
    gotoxy(85, 5);
    cout<<"Phone No.";
    gotoxy(99, 5);
    cout<<"Balance";
    gotoxy(5, 6);
    design(109, 205);
    /* f.read() = for reading binary data
     This reads the contents of a class variable from the file and stores it in the variable rec.
     The f.read() function will keep returning 1 until there are records in the file.
     As soon as the end-of-file (EOF) is encountered fread() will return a value less than 1 and
     the condition in the while loop become false and the control comes out of the while loop.
    */
    while (f.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
        gotoxy(5, i);
        cout<<rec.account;
        gotoxy(17, i);
        cout<<rec.name;
        gotoxy(35, i);
        for (r = 0; r < 10; r++) {
            cout<<(int)rec.UserID[r];
        }
        gotoxy(52, i);
        cout<<rec.email;
        gotoxy(85, i);
        cout<<rec.phone;
        gotoxy(100, i);
        cout<<rec.blnc<<"$";
        i++;
    }
    f.close();
    int x;
    gotoxy(42, i + 2);
    cout<<"Press [Enter] to return back to main menu. ";
    x = getch();
    if (x == 13) { // 13 = '\r' i.e carriage return
        menu();
    } else
        view();
};

//module for adding accounts.
void bms:: add(){
    char c;
    record rec;
    //app = append binary / write data to the file
    ofstream f;
    f.open("record.bin", ios::app | ios::binary); // data will be written at end of the file
    int i = 0, x;
    // first we evaluate body and check condition
    do {
        system("cls");
        gotoxy(24, 4);
        design(20, 177);
        cout<<" CUSTOMER ACCOUNT REGISTRATION ";
        design(20, 177);
        gotoxy(36, 8);
        cout<<"[1] . Enter Your Name           : ";
        cin>>rec.name;
        gotoxy(36, 9);
        cout<<"[2] . Enter Your Account Number : ";
        scanf(" %d", &rec.account);
        gotoxy(36, 10);
        cout<<"[3] . Enter Your PIN            : ";
        scanf(" %d", &rec.passw);
        gotoxy(36, 11);
        cout<<"[4] . Enter Your Phone Number   : ";
        cin>>rec.phone;
        gotoxy(36, 12);
        cout<<"[5] . Enter Your Address        : ";
        cin>>rec.address;
        gotoxy(36, 13);
        cout<<"[6] . Enter Your E-mail         : ";
        cin>>rec.email;
        gotoxy(36, 14);
        cout<<"[7] . Enter Your Citizenship    : ";
        cin>>rec.citiz;
        gotoxy(36, 15);
        cout<<"[8] . Enter Amount To Deposit   : $";
        scanf(" %lf", &rec.blnc);
        srand(time(0)); //random number
        for (r = 0; r < 10; r++) {
            rec.UserID[r] = rand() % 10;
        }
        //write() = for writing binary data
        // reinterpret_cast - casting one pointer data type to another pointer data type
        //This helps to write contents in a class variable in the file and stores it in the variable rec.
        f.write(reinterpret_cast<char*>(&rec), sizeof(rec)); //whatever &rec is treat it as char *
        //char is just a byte , //sizeof gets no. of byte it takes to hold whatevery type rec is
        gotoxy(38, 17);
        cout<<"CUSTOMER ACCOUNT REGISTRATION SUCCESSFULL";
        i++;
        gotoxy(36, 19);
        cout<<"Do You Want To Add Another Record ? (Y/N) : ";
        scanf(" %c", &c);
    } while (c == 'Y' || c == 'y');
    f.close();
    gotoxy(40, 22);
    cout<<"Press any key to return back to main menu. ";
    char z = getch();
    if (z == 13) {
        menu();
    } else
        view();
}

//--------------------FAITH------------------------//

//-------------REA---------------------------//
//module to check whether the entered account is in the database or not
int chkacc(int a) {
    record rec;
    //read binary
    ifstream f;
    f.open("record.bin", ios::in | ios::binary);
    while (!f.eof(  )) {    //eof means end of file
        f.read(reinterpret_cast<char*>(&rec),sizeof(rec)); //whatever &rec is treat it as char *
        //char is just a byte , //sizeof gets no. of byte it takes to hold whatevery type rec is

        if (a == rec.account) {
            f.close();
            return 1;
        }
    }
    f.close();
    return 0;
}
//module to chec reg account
int chkaccreg(int b) {
    record rec;
    //read binary
    ifstream f;
    f.open("record.bin", ios::in | ios::binary);
    while (!f.eof()) {
        f.read(reinterpret_cast<char*>(&rec),sizeof(rec)); //whatever &rec is treat it as char *
        //char is just a byte , //sizeof gets no. of byte it takes to hold whatevery type rec is

        if (b == rec.passw) {
            f.close();
            return 1;
        }
    }
    f.close();
    return 0;
}

int chkbnk(int c) {
    bnkrecord rec;
    //read binary
    ifstream f;
    f.open("recordbank.bin", ios::in | ios::binary);
    while (!f.eof(  )) {
        f.read(reinterpret_cast<char*>(&rec),sizeof(rec)); //whatever &rec is treat it as char *
        //char is just a byte , //sizeof gets no. of byte it takes to hold whatevery type rec is

        if (c == rec.bnkid) {
            f.close();
            return 1;
        }
    }
    f.close();
    return 0;
}
//-------------REA---------------------------//
// module for editing details.
void bms::edit(){
    record rec;
    ifstream f1;
    ofstream f2;
    int a, c;
re: //label for goto
    gotoxy(23, 4);
    design(25, 177);
    cout<<" EDIT CUSTOMER ACCOUNT ";
    design(25, 177);
    gotoxy(43, 7);
    cout<<"Enter Your Account Number To Edit : ";
    scanf("%d", &a);
    if (chkacc(a) == 1) {
        f1.open("record.bin", ios::in | ios::binary); //read
        f2.open("new.bin", ios::app | ios::binary); //write
        while (f1.read(reinterpret_cast<char*>(&rec),sizeof(rec))) {
            if (rec.account != a)
                f2.write(reinterpret_cast<char*>(&rec),sizeof(rec));
            else if (rec.account == a) {
                gotoxy(41, 20);
                design(42, 45);
                gotoxy(52, 21);
                cout<<"Account Number Matched";
                gotoxy(41, 22);
                design(42, 45);
                gotoxy(51, 10);
                cout<<"Enter Your Details";
                gotoxy(28, 11);
                design(65, 205);
                gotoxy(31, 12);
                cout<<"[1] . Enter Your Name           : ";
                cin>>rec.name;
                gotoxy(31, 13);
                cout<<"[2] . Enter Your Account Number : ";
                scanf(" %d", &rec.account);
                gotoxy(31, 14);
                cout<<"[3] . Enter Your Phone Number   : ";
                cin>>rec.phone;
                gotoxy(31, 15);
                cout<<"[4] . Enter Your Address        : ";
                cin>>rec.address;
                gotoxy(31, 16);
                cout<<"[5] . Enter Your E-mail         : ";
                cin>>rec.email;
                gotoxy(31, 17);
                cout<<"[6] . Enter Your Citizenship No : ";
                cin>>rec.citiz;
                f2.write(reinterpret_cast<char*>(&rec),sizeof(rec));
            }
        }
        f1.close();
        f2.close();
    }
    if (chkacc(a) == 0) {
        system("CLS");
        gotoxy(41, 20);
        design(42, 45);
        gotoxy(52, 21);
        cout<<"Account Doesn't Exist. ";
        gotoxy(41, 22);
        design(42, 45);
        goto re; // unconditional jump statement goto <label>
    }
    remove("record.bin");
    rename("new.bin", "record.bin");
    gotoxy(45, 21);
    cout<<"CUSTOMER ACCOUNT UPDATE SUCCESSFULL";
    gotoxy(42, 24);
    cout<<"Press any key to return back to main menu . ";
    getch();
    menu();
}

//module for deleting account
void bms::del(){
    record rec;
    ifstream f1;
    ofstream f2;
    int a, c;
re:
    gotoxy(23, 4);
    design(25, 177);
    cout<<" DELETE CUSTOMER ACCOUNT ";
    design(25, 177);
    gotoxy(41, 9);
    cout<<"Enter Your Account Number To Delete : ";
    scanf("%d", &a);
    if (chkacc(a) == 1) {
        f1.open("record.bin", ios::in | ios::binary);
        f2.open("new.bin", ios::out | ios::binary);
        while (f1.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
            if (rec.account != a)
                f2.write(reinterpret_cast<char*>(&rec), sizeof(rec));
        }
        f1.close();
        f2.close();
        ifstream f2;
        ofstream f1;
        f1.open("record.bin", ios::out | ios::binary); // write only
        f2.open("new.bin", ios::in | ios::binary);
        while (f2.read(reinterpret_cast<char*>(&rec), sizeof(rec)))
            f1.write(reinterpret_cast<char*>(&rec), sizeof(rec));
        f1.close();
        f2.close();
    } else if (chkacc(a) == 0) {
        system("CLS");
        gotoxy(41, 14);
        design(42, 196);
        gotoxy(51, 15);
        cout<<"Account Doesn't Exist";
        gotoxy(41, 16);
        design(42, 196);
        goto re;
    }
    gotoxy(41, 14);
    design(42, 196);
    gotoxy(44, 15);
    cout<<"CUSTOMER ACCOUNT DELETED SUCCESSFULLY";
    gotoxy(41, 16);
    design(42, 196);
    gotoxy(42, 18);
    cout<<"Press any key to return back to main menu. ";
    getch();
    menu();
}


void bms::search_acc() {
        record rec;
        ifstream f;
        int b = 0;
        int a, x, interestRate = 0.06;
    re:
        gotoxy(23, 4);
        design(25, 177);
        cout<<" SEARCH CUSTOMER ACCOUNT ";
        design(25, 177);
        gotoxy(43, 6);
        cout<<"Enter Your Account Number To Search : ";
        scanf("%d", &a);
        if (chkacc(a) == 1) {
            f.open("record.bin", ios::in | ios::binary);
            while (f.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
                if (rec.account == a) {
                    gotoxy(41, 21);
                    design(42, 196);
                    gotoxy(52, 22);
                    cout<<"Account Number Matched";
                    gotoxy(41, 23);
                    design(42, 196);
                    gotoxy(45, 9);
                    cout<<"Detail Information of "<< rec.name;
                    gotoxy(28, 10);
                    design(65, 205);
                    gotoxy(37, 11);
                    cout<<"[1] . Account Number : "<< rec.account;
                    gotoxy(37, 12);
                    cout<<"[2] . Name           : "<< rec.name;
                    gotoxy(37, 13);
                    cout<<"[3] . UserID         : ";
                    for (r = 0; r < 10; r++) {
                        cout<<(int)rec.UserID[r];
                    }
                    gotoxy(37, 14);
                    cout<<"[4] . Phone Number   : "<< rec.phone;
                    gotoxy(37, 15);
                    cout<<"[5] . Address        : "<< rec.address;
                    gotoxy(37, 16);
                    cout<<"[6] . E-mail         : "<< rec.email;
                    gotoxy(37, 17);
                    cout<<"[7] . Citizenship No : "<< rec.citiz;
                    gotoxy(37, 18);
                    cout<<"[8] . Current Balance: "<< rec.blnc;
                    gotoxy(37,19);
                    cout<<"[9] . Status         : ";
                    if (rec.blnc > 25){
                        cout<<"Active";
                    } else{
                        cout<<"Inactive";
                    }
                    gotoxy(37,20);
                    cout<<"[10] . Acquired Interest: ";
                        double monthlyInterestRate = interestRate / 12;
                        double monthlyInterest = rec.blnc * monthlyInterestRate;
                        rec.blnc += monthlyInterest;
                        cout<<rec.blnc<<"$";
                        break;
                } else
                    b = 1;
            }
            f.close();
        }
        if (chkacc(a) == 0) {
            system("CLS");
            gotoxy(41, 20);
            design(42, 196);
            gotoxy(52, 21);
            cout<<"Account Doesn't Exist. ";
            gotoxy(41, 22);
            design(42, 196);
            goto re;
        }
        gotoxy(42, 24);
        cout<<"Press [ENTER] to return back to main menu. ";
        char z = getch();
        if (z == 13)
            menu();
        else
            srch();
}

void bms::search_name() {
    int i = 0, b, x, interestRate = 0.06;
    char nam[30];
    gotoxy(23, 4);
    design(25, 177);
    cout<<" SEARCH CUSTOMER ACCOUNT ";
    design(25, 177);
    gotoxy(43, 6);
    cout<<"Enter Your Full Name To Search : ";
    cin>>nam;
    record rec;
    ifstream f;
    f.open("record.bin", ios::in | ios::binary);
    while (f.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
        b = 0;
        strupr(rec.name);
        strupr(nam);
        if (strcmp(rec.name, nam) == 0) {
            gotoxy(41, 21);
            design(42, 196);
            gotoxy(52, 22);
            cout<<"Account Number Matched";
            gotoxy(41, 23);
            design(42, 196);
            gotoxy(45, 9);
            cout<<"Detail Information of "<< rec.name;
            gotoxy(28, 10);
            design(65, 205);
            gotoxy(37, 11);
            cout<<"[1] . Account Number : "<< rec.account;
            gotoxy(37, 12);
            cout<<"[2] . Name           : "<< rec.name;
            gotoxy(37, 13);
            cout<<"[3] . UserID         : ";
            for (r = 0; r < 10; r++) {
                cout<<(int)rec.UserID[r];
            }
            gotoxy(37, 14);
            cout<<"[4] . Phone Number   : "<< rec.phone;
            gotoxy(37, 15);
            cout<<"[5] . Address        : "<< rec.address;
            gotoxy(37, 16);
            cout<<"[6] . E-mail         : "<< rec.email;
            gotoxy(37, 17);
            cout<<"[7] . Citizenship No : "<< rec.citiz;
            gotoxy(37, 18);
            cout<<"[8] . Current Balance: "<< rec.blnc;
            gotoxy(37,19);
            cout<<"[9] . Status         : ";
            if (rec.blnc > 25){
                cout<<"Active";
            } else{
                cout<<"Inactive";
            }
            gotoxy(37,20);
            cout<<"[10] . Acquired Interest: ";
                double monthlyInterestRate = interestRate / 12;
                double monthlyInterest = rec.blnc * monthlyInterestRate;
                rec.blnc += monthlyInterest;
                cout<<rec.blnc<<"$";
            break;
        } else
            b = 1;
    }
    f.close();
    if (b == 1) {
        system("cls");
        gotoxy(41, 20);
        design(42, 196);
        gotoxy(52, 21);
        cout<<"Account Doesn't Exist. ";
        gotoxy(41, 22);
        design(42, 196);
        search_name();
    }
    gotoxy(42, 24);
    cout<<"Press [ENTER] to return back to main menu. ";
    char z = getch();
    if (z == 13)
        menu();
    else
        srch();
}

//---------------------JEZLYN---------------------//

void bms:: chkblnc(){ // module for checking account balance and displaying it
    record rec;
    ifstream f;
    int a;
    gotoxy(27, 4);
    design(25, 177);
    cout<<" BALANCE INQUIRY ";
    design(25, 177);
    gotoxy(47, 12);
    cout<<"Enter Your Account Number : ";
    scanf("%d", &a);
    if (chkacc(a) == 1) {
        f.open("record.bin", ios::in | ios::binary);
        while (f.read(reinterpret_cast<char*>(&rec),sizeof(rec))) {
            if (rec.account == a) {
                gotoxy(41, 14);
                design(42, 196);
                gotoxy(41, 16);
                design(42, 196);
                gotoxy(50, 15);
                cout<<"Your Balance is : $"<< rec.blnc;
            }
        }
        f.close();
    }
    if (chkacc(a) == 0) {
        system("cls");
        gotoxy(41, 14);
        design(42, 196);
        gotoxy(41, 16);
        design(42, 196);
        gotoxy(52, 15);
        cout<<"Account Doesn't Exist.";
        chkblnc();
    }
    gotoxy(46, 21);
    cout<<"Press any key to return back to main menu. ";
    getch();
    transactions();
}

void bms::deposit() { // module for adding amount to a account
    int a;
    double b;
    record rec;
    ifstream f1;
    ofstream f2;
    gotoxy(29, 4);
    design(25, 177);
    cout<<" CASH DEPOSIT ";
    design(25, 177);
    gotoxy(47, 10);
    cout<<"Enter Your Account Number : ";
    scanf("%d", &a);
    if (chkacc(a) == 1) {
        f1.open("record.bin", ios::in | ios::binary);
        f2.open("new.bin", ios::out | ios::binary);
        while (f1.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
            if (rec.account != a)
                f2.write(reinterpret_cast<char*>(&rec), sizeof(rec));
            else if (rec.account == a) {
                rec.name;
                rec.account;
                rec.phone;
                rec.address;
                rec.email;
                rec.citiz;
                gotoxy(45, 13);
                cout<<"Enter The Amount To Deposit : $ ";
                scanf("%lf", &b);
                rec.blnc += b;
                f2.write(reinterpret_cast<char*>(&rec), sizeof(rec));
            }
        }
        f1.close();
        f2.close();
        ifstream f2;
        ofstream f1;
        f1.open("record.bin", ios::out | ios::binary); // write only
        f2.open("new.bin", ios::in | ios::binary);
        while (f2.read(reinterpret_cast<char*>(&rec), sizeof(rec)))
            f1.write(reinterpret_cast<char*>(&rec), sizeof(rec));
        f1.close();
        f2.close();
    }
    if (chkacc(a) == 0) {
        system("CLS");
        gotoxy(41, 20);
        design(42, 196);
        gotoxy(52, 21);
        cout<<"Account Doesn't Exist. ";
        gotoxy(41, 22);
        design(42, 196);
        deposit();
    }
    gotoxy(41, 20);
    design(42, 196);
    gotoxy(41, 22);
    design(42, 196);
    gotoxy(52, 15);
    gotoxy(52, 21);
    cout<<"CASH DEPOSIT SUCCESSFULL";
    gotoxy(50, 24);
    cout<<"Press any key to return back...";
    getch();
    transactions();
}

void bms::withdrawl(){ // module to withdraw amount from account
    record rec;
    ifstream f1;
    ofstream f2;
    int a;
    double b, z;
    z = rec.blnc;
    gotoxy(25, 4);
    design(25, 177);
    cout<<" CASH WITHDRAWAL ";
    design(25, 177);
    gotoxy(45, 10);
    cout<<"Enter Your Account Number : ";
    scanf("%d", &a);
    if (chkacc(a) == 1) {
        f1.open("record.bin", ios::in | ios::binary);
        f2.open("new.bin", ios::out | ios::binary);
        gotoxy(42, 13);
        cout<<"Enter The Amount To Withdraw : $ ";
        scanf("%lf", &b);
        while (f1.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
            if (rec.account != a)
                f2.write(reinterpret_cast<char*>(&rec), sizeof(rec));
            else if (rec.account == a) {
                rec.name;
                rec.account;
                rec.phone;
                rec.address;
                rec.email;
                rec.citiz;
                z = rec.blnc;
                if (b <= rec.blnc) {
                    rec.blnc -= b;
                    gotoxy(39, 20);
                    design(42, 196);
                    gotoxy(39, 22);
                    design(42, 196);
                    gotoxy(44, 21);
                    cout<<"    CASH WITHDRAWAL SUCCESSFULL     ";
                }
                if (rec.blnc > 100){
                    rec.blnc -= 1;
                    gotoxy(46,16);
                    cout<<" 1$ withdrawn charge taken ";
                }
                f2.write(reinterpret_cast<char*>(&rec), sizeof(rec));
            }
        }
        f1.close();
        f2.close();
        remove("record.bin");
        rename("new.bin", "record.bin");
        if (z < b) {
            system("CLS");
            gotoxy(39, 20);
            design(42, 196);
            gotoxy(39, 22);
            design(42, 196);
            gotoxy(48, 21);
            cout<<"Current Balance is "<< z;
            gotoxy(42, 24);
            cout<<"Entered amount exceeds current balance";
            withdrawl();
        }
    }
    if (chkacc(a) == 0) {
        system("CLS");
        gotoxy(39, 20);
        design(42, 196);
        gotoxy(50, 21);
        cout<<"Account Doesn't Exist.";
        gotoxy(39, 22);
        design(42, 196);
        withdrawl();
    }
    gotoxy(42, 24);
    cout<<"     Press Any Key To Continue ....   ";
    getch();
    transactions();
}

void bms::transfer(){ // module for transfering amount from 1 acc to another
    int a;
    double b, z;
    record rec;
    ifstream f1;
    ofstream f2;
    f1.open("record.bin", ios::in | ios::binary);
    f2.open("new.bin", ios::out | ios::binary);
    gotoxy(27, 4);
    design(25, 177);
    cout<<" CASH TRANSFER ";
    design(25, 177);
    gotoxy(42, 10);
    cout<<"Enter Your Account Number      : ";
re:
    scanf("%d", &a);
    if (chkacc(a) == 0) {
        system("CLS");
        gotoxy(38, 20);
        design(42, 196);
        gotoxy(50, 21);
        cout<<"Account Doesn't Exist.";
        gotoxy(38, 22);
        design(42, 196);
        goto re;
    } else if (chkacc(a) == 1) {
        gotoxy(42, 13);
        cout<<"Enter The Amount To Transfer   : $ ";
        scanf("%lf", &b);
        while (f1.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
            if (rec.account != a)
                f2.write(reinterpret_cast<char*>(&rec), sizeof(rec));
            else if (rec.account == a) {
                rec.name;
                rec.account;
                rec.phone;
                rec.address;
                rec.email;
                rec.citiz;
                if (b < rec.blnc) {
                    z = rec.blnc;
                    rec.blnc -= b;
                }
                f2.write(reinterpret_cast<char*>(&rec), sizeof(rec));
            }
        }
    }
    f1.close();
    f2.close();
    remove("record.bin");
    rename("new.bin", "record.bin");
    if (b > z) {
        gotoxy(38, 20);
        design(42, 196);
        gotoxy(38, 22);
        design(42, 196);
        gotoxy(44, 21);
        cout<<"Current Balance is $"<< z;
        gotoxy(41, 24);
        cout<<"Entered amount exceeds current balance";
        transactions();
    }

    f1.open("record.bin", ios::in | ios::binary);
    f2.open("new.bin", ios::out | ios::binary);
    gotoxy(42, 16);
    cout<<"Enter Recipient Account Number : ";
    scanf("%d", &a);
    if (chkacc(a) == 0) {
        gotoxy(38, 20);
        design(42, 196);
        gotoxy(50, 21);
        cout<<"Account Doesn't Exist.";
        gotoxy(38, 22);
        design(42, 196);
    } else if (chkacc(a) == 1) {
        while (f1.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
            if (rec.account != a)
                f2.write(reinterpret_cast<char*>(&rec), sizeof(rec));
            else if (rec.account == a) {
                rec.name;
                rec.account;
                rec.phone;
                rec.address;
                rec.email;
                rec.citiz;
                rec.blnc += b;
                f2.write(reinterpret_cast<char*>(&rec), sizeof(rec));
            }
        }
        f1.close();
        f2.close();
        remove("record.bin");
        rename("new.bin", "record.bin");
    }
    gotoxy(38, 20);
    design(42, 196);
    gotoxy(38, 22);
    design(42, 196);
    gotoxy(40, 21);
    cout<<"        CASH TRANSFER SUCCESSFULL        ";
    gotoxy(38, 24);
    cout<<"        Press Any Key To Continue ....        ";
    getch();
    system("cls");
    transactions();
}

//---------------------JEZLYN---------------------//

//--------------------FAITH------------------------//
void bms:: bankadd(){
    char c;
    bnkrecord rec;
    //app = append binary / write data to the file
    ofstream f;
    f.open("recordbank.bin", ios::app | ios::binary); // data will be written at end of the file
    int i = 0, x;
    // first we evaluate body and check condition
    do {
        system("cls");
        gotoxy(24, 4);
        design(20, 177);
        cout<<" BANK REGISTRATION ";
        design(20, 177);
        gotoxy(36, 8);
        cout<<"[1] . Enter  Name of the Bank        : ";
        cin>>rec.bnkname;
        gotoxy(36, 9);
        cout<<"[2] . Enter Bank ID                  : ";
        cin>>rec.bnkid;
        gotoxy(36, 10);
        //write() = for writing binary data
        // reinterpret_cast - casting one pointer data type to another pointer data type
        //This helps to write contents in a class variable in the file and stores it in the variable rec.
        f.write(reinterpret_cast<char*>(&rec), sizeof(rec)); //whatever &rec is treat it as char *
        //char is just a byte , //sizeof gets no. of byte it takes to hold whatevery type rec is
        gotoxy(47, 17);
        cout<<"BANK ADDED SUCCESSFULL";
        i++;
        gotoxy(36, 19);
        cout<<"Do You Want To Add Another Record ? (Y/N) : ";
        scanf(" %c", &c);
    } while (c == 'Y' || c == 'y');
    f.close();
    gotoxy(40, 22);
    cout<<"Press any key to return back to main menu. ";
    char z = getch();
    if (z == 13) {
        menu();
    }
}

void bms:: bnkviewuser(){
    system("cls");
    int input;
    int i = 6;
    bnkrecord rec;
    //read from the file
    ifstream f;
    f.open("recordbank.bin", ios::in | ios::binary); //open file for read only
    gotoxy(24, 1);
    design(24, 177);
    cout<<" BANK LIST ";
    design(24, 177);
    gotoxy(30, 4);
    cout<<"Bank Name.";
    gotoxy(70, 4);
    cout<<"Bank ID.";
    while (f.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
        gotoxy(30, i);
        cout<<rec.bnkname;
        gotoxy(70, i);
        cout<<rec.bnkid;
        i++;
    }
    f.close();
    int x;
    gotoxy(34, i + 5);
    cout<<"Indicate the Bank Id you want to Transac. ";
    while (!(cin >> input)) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Invalid input. Please enter an Bank ID: ";
    }
    transactions();
};

void bms:: bnkview(){
    system("cls");
    int input;
    int i = 6;
    bnkrecord rec;
    //read from the file
    ifstream f;
    f.open("recordbank.bin", ios::in | ios::binary); //open file for read only
    gotoxy(24, 1);
    design(24, 177);
    cout<<" BANK LIST ";
    design(24, 177);
    gotoxy(30, 4);
    cout<<"Bank Name.";
    gotoxy(70, 4);
    cout<<"Bank ID.";
    while (f.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
        gotoxy(30, i);
        cout<<rec.bnkname;
        gotoxy(70, i);
        cout<<rec.bnkid;
        i++;
    }
    f.close();
    int x;
    gotoxy(42, i + 5);
    cout<<"Press [Enter] to return back to main menu. ";
    x = getch();
    if (x == 13) { // 13 = '\r' i.e carriage return
        menu();
    } else
        view();
};

void bms::delbnk(){
    bnkrecord rec;
    ifstream f1;
    ofstream f2;
    int b, d, c;
m:
    gotoxy(23, 4);
    design(25, 177);
    cout<<" DELETE BANK ";
    design(25, 177);
    gotoxy(41, 9);
    cout<<"Enter The Bank ID To Delete : ";
    scanf("%d", &c);
    if (chkbnk(c) == 1) {
        f1.open("recordbank.bin", ios::in | ios::binary);
        f2.open("newbank.bin", ios::out | ios::binary);
        while (f1.read(reinterpret_cast<char*>(&rec), sizeof(rec))) {
            if (rec.bnkid != c)
                f2.write(reinterpret_cast<char*>(&rec), sizeof(rec));
        }
        f1.close();
        f2.close();
        ifstream f2;
        ofstream f1;
        f1.open("recordbank.bin", ios::out | ios::binary); // write only
        f2.open("newbank.bin", ios::in | ios::binary);
        while (f2.read(reinterpret_cast<char*>(&rec), sizeof(rec)))
            f1.write(reinterpret_cast<char*>(&rec), sizeof(rec));
        f1.close();
        f2.close();
    } else if (chkbnk(c) == 0) {
        system("CLS");
        gotoxy(41, 14);
        design(42, 196);
        gotoxy(51, 15);
        cout<<"BANK Doesn't Exist";
        gotoxy(41, 16);
        design(42, 196);
        goto m;
    }
    gotoxy(41, 14);
    design(42, 196);
    gotoxy(44, 15);
    cout<<"BANK  DELETED SUCCESSFULLY";
    gotoxy(41, 16);
    design(42, 196);
    gotoxy(42, 18);
    cout<<"Press any key to return back to main menu. ";
    getch();
    menu();
}

//--------------------FAITH------------------------//

void bms::menuexit(){ //module for logging out of the program.
    system("cls");
        gotoxy(30, 4);
        design(25, 177);
        cout<<" THANK YOU ";
        design(25, 177);
        time_t t;
        time(&t);
        gotoxy(42, 14);
        cout<<"Logged Out Time :: "<< ctime(&t);
        fflush(stdin);
        getch();
        gotoxy(0, 26);
        exit(0);
}

int main()
{
    bms w;
    return 0;
}

