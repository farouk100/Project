#include <iostream>
#include <fstream>
#include "Header.h"                  //sasa
#include "Header1.h"
using namespace std;
int main()
{
	fstream my_file;
	my_file.open("Super Market.txt", ios::app); //text document
	my_file.close(); // you should close the file
	//bool flag = true;
	int choice;
	do {
		cout<< "***************************\n"
            << "Welcome to our Super Market\n"
			<< "***************************\n"
			<< "*To insert        Enter: 1*\n"
			<< "*To Display All   Enter: 2*\n"
			<< "*To Search        Enter: 3*\n"
			<< "*To Delete        Enter: 4*\n"
			<< "*To Update        Enter: 5*\n"
			<< "*To Exist         Enter: 6*\n"
			<< "***************************\n";
		cout<< "Enter Your Choice -->  ";cin >> choice;cin.ignore();
		switch (choice)
		{
		case 1 :
			Insert1();break;
		case 2 :
			Display1();break;
		case 3:
			Search1();break;
		
		case 4:
		    Delete();
		    break;
		
		case 5:
				Update();break;
		case 6:
			cout << "thank you\n";//flag = false; 
			break;
		default:
			cout << "\ainvalid\n";break;
		}
	} while (/*flag*/ choice != 6);
	return 0;
}
