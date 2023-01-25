

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>

using namespace std;

int ac = 4;
int nc = 0;
char admin[10] = {"admin"};
char apass[10] = {"admin"};
char accounts[20][10] = {"user1", "user2", "user3", "user4"};
char password[20][10] = {"u1", "u2", "u3", "u4"};

void umenu();
void headmain();
void amain();
void costumermain();

void login(){
	
	char user[20], pass[20];
	
	system("cls");
	
	cout<<"Login Page"<<endl;
	cout<<endl;
	cout<<"Enter Username: ";
	cin>>user;
	cout<<endl;
	cout<<"Password: ";
	cin>>pass;
	cout<<endl;
	
	if(strcmp(user, admin) == 0 && strcmp(pass, apass) == 0){
		amain();
	}
	
	else{
	
		for(int i = 0; i < ac; i++){
			if(strcmp(accounts[i], user) == 0 && strcmp(password[i], pass) == 0){
				cout<<"Checking..."<<endl;
				
				nc = i;
				
				
				cout<<"Log in Success!!!"<<endl;
				
				umenu();
			}
		}
		
		cout<<"Account Error/Non Existing"<<endl;
		sleep(5000);
		cout<<"Exiting..."<<endl;
		sleep(2000);
		headmain();		
		
	}
}
void amain(){

}
void umenu(){

}
void headmain(){

}
int main(){

    login();
    return 0;
}