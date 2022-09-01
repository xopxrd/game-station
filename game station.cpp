#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include "snake.h"

bool loggedIn();

int main(){
	system("color F0");
	std::string name, password, repass;
	int choice;
	std::cout << "welcome to cold gamestation\n";
	std::cout << "1. register\n";
	std::cout << "2. login\n";
	std::cout << "your choice: ";
	std::cin >> choice;
	
	switch(choice){
		case 1:
		{
			regist:
			std::cout << "enter your name: ";
			std::cin >> name;
			std::cout << "enter your password: ";
			// hide character with *
			char ch = getch(); // carriage return
			while(ch != 13){
				password.push_back(ch);
				std::cout << "*";
				ch = getch();
				}
				std::cout << std::endl;
			
			std::cout << "reenter password: ";
			ch = getch();
			while(ch != 13){
				repass.push_back(ch);
				std::cout << "*";
				ch = getch();
				}
				std::cout << std::endl;
			
			if(password != repass){
				std::cout << "the password doesn't match!\n";
				std::cout << "press any key to continue . . .\n";
				getch();
				goto regist;
			}
			{
				std::ofstream data(name + ".txt");
				data << name << "\n" << password << std::endl;
				data.close();
			}
			std::cout << "account created!\n";
			std::cout << "press any key to continue . . .\n";
			
			getch();
			std::cout << std::string(50, '\n'); //clear screen
			main();
		}
		break;
		
		case 2:
		{
			bool login = loggedIn();
			if(!login){
				std::cout << "the data is not exist\n";
				std::cout << "press any key to continue . . .\n";
				
				getch();
				std::cout << std::string(50, '\n');
				main();
			}else{
				std::cout << "succesfully logged in!\n";
				std::cout << "1. snake game\n"; 
				std::cout << "choose the game you want to play: ";
				std::cin >> choice;
				switch(choice){
					case 1:
						play();
						break;
					default:
						std::cout << "lol";
				}
			}
		}
		break;
		
		default:
			std::cout << "invalid input!\n";
			std::cout << "press any key to continue . . .\n";
			getch();
	}
	
	return 0;
}

bool loggedIn(){
	std::string name, password, usrnm, pw;
	std::cout << "enter your name: ";
	std::cin >> name;
	std::cout << "enter your password: ";
	char ch = getch(); // carriage return
	while(ch != 13){
		password.push_back(ch);
		std::cout << "*";
		ch = getch();
		}
	std::cout << std::endl;
	std::ifstream readData(name + ".txt");
	getline(readData, usrnm);
	getline(readData, pw);
	readData.close();
			
	if(usrnm == name && pw == password)
		return true;
	else
		return false;
}
