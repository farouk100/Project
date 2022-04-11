#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <iomanip> //  function setwidth
using namespace std;
void Insert(){
	//cin>> --> stop on the first space. 
	//cin.getline(); --> stop on the first line  --> arrays only --> array of charecters only -->
	
	//id ---> 2021170384 (cin)
	//name ---> farouk khaled (cin.getline())
	//cost (cin)
	//quentity (cin)
	 
	// between every to cin and cin.getline() we should use cin.ignore()
	//but to avoid this confusing we will use cin.getline() only

	fstream my_file;
	char id[10]; // but in act 9 spaces only because null charecter or it will enter infinite loop
	char name[100]; // 99 spaces
	char cost[10];
	char quentity[10];
	my_file.open("Super Market.txt", ios::app);
	char choise[2];
	do {
		cout << "enter id\n"; cin.getline(id , 10);
		cout << "enter name\n"; cin.getline(name, 100);
		cout << "enter cost\n";	cin.getline(cost, 10);
		cout << "enter quentity\n"; cin.getline(quentity, 10);
		my_file << id << "|" << name << "|" << cost << "|" << quentity << "\n";
		cout << "the product is added successfuly\n";
		cout << "do you want to add more (y/Y)\n";
		cin.getline(choise , 2);
	} while ( choise[0] == 'y' || choise[0] == 'Y');
	//to avoid the file is still open in the memory
	my_file.close();
}
void Display()
{
	char id[10]; // but in act 9 spaces only because null chatacter or it will enter infinite loop
	char name[100]; // 99 spaces
	char cost[10];
	char quentity[10];
	fstream my_file;
	my_file.open("Super Market.txt",ios::in);
	cout << "*******************************************************\n";
	cout << "                      My store                         \n";
	cout << "*******************************************************\n";
	cout << left << setw(10) << "ID" << setw(20) << "NAME" << setw(10) << "COST" << setw(10) << "QUENTITY \n";
	cout << "*******************************************************\n";
	//eof --> end of file
	while (!my_file.eof())
	{
		my_file.getline(id, 10, '|');
		my_file.getline(name, 100, '|');
		my_file.getline(cost , 10 , '|');
		my_file.getline(quentity, 10);
		// function setwidth is used to تظبط the shape of your program;
		if (int(id[0]) != 0) { // casting from character to intger 
			// the ascicode of space is zero 
			// to avid display the empty line.
			cout << left << setw(10) << id << setw(20) << name << setw(10) << cost << setw(10) << quentity << "\n";
			cout << "*******************************************************\n";
		}
	}
	my_file.close();
}
void Search()
{
	fstream my_file;
	//my_file.open("Super Market.txt", ios::in);
	char id[10], id_r[10]; // but in act 9 spaces only because null chatacter or it will enter infinite loop
	char name[100], name_r[100]; // 99 spaces
	char cost[10];
	char quentity[10];
	char op[2], x[2];
	bool found;
	do {
		found = 0;
		my_file.open("Super Market.txt", ios::in);
		cout << "***************************\n";
		cout << "To search by id    enter: 1\n";
		cout << "To search by name  enter: 2\n";
		bool flag1 = 0;
		do {
			cout << "Enter option: "; cin.getline(op, 2);
			if (op[0] == '1' || op[0] == '2')
			{
				flag1 = 1;
			}
			else {
				cout << "\a Please Enter 1 or 2 only \n";
			}
		} while (flag1 == 0);
		switch (op[0])
		{
		case '1':
			cout << "Enter id --> "; cin.getline(id_r, 10);
			break;
		case '2':
			cout << "enter name --> "; cin.getline(name_r, 100);
			break;
		}
		while (!my_file.eof())
		{
			my_file.getline(id, 10, '|');
			my_file.getline(name, 100, '|');
			my_file.getline(cost, 10, '|');
			my_file.getline(quentity, 10);
			// strcmp string compare
			if (strcmp(id, id_r) == 0 && op[0] == '1' || strcmp(name, name_r) == 0 && op[0] == '2') {
				cout << "*******************************************************\n";
				cout << "                      The product                      \n";
				cout << "*******************************************************\n";
				cout << left << setw(10) << "ID" << setw(20) << "NAME" << setw(10) << "COST" << setw(10) << "QUENTITY \n";
				cout << "*******************************************************\n";
				cout << left << setw(10) << id << setw(20) << name << setw(10) << cost << setw(10) << quentity << "\n";
				cout << "*******************************************************\n";
				found = true;
				break;
			}
		}
		if (found == 0) cout << "The product is not found!\n";
		cout << "do you want to search more (y / Y)\n";
		cin.getline(x, 2);
		my_file.close();
	} while (x[0] == 'y' || x[0] == 'Y');

}


void Delete()
{
	fstream my_file, temporary_file;
	//my_file.open("Super Market.txt", ios::in);
	char id[10], id_r[10]; // but in act 9 spaces only because null chatacter or it will enter infinite loop
	char name[100], name_r[100]; // 99 spaces
	char cost[10];
	char quentity[10];
	char op[2], x[2];
	bool found;
	do {
		found = 0;
		my_file.open("Super Market.txt", ios::in);
		temporary_file.open("temp.txt", ios::app);
		cout << "***************************\n";
		cout << "To delete by id    enter: 1\n";
		cout << "To delete by name  enter: 2\n";
		bool flag1 = 0;
		do {
			cout << "Enter option: "; cin.getline(op, 2);
			if (op[0] == '1' || op[0] == '2')
			{
				flag1 = 1;
			}
			else {
				cout << "\a Please Enter 1 or 2 only \n";
			}
		} while (flag1 == 0);
		switch (op[0])
		{
		case '1':
			cout << "Enter id --> "; cin.getline(id_r, 10);
			break;
		case '2':
			cout << "enter name --> "; cin.getline(name_r, 100);
			break;
		}
		while (!my_file.eof())
		{
			my_file.getline(id, 10, '|');
			my_file.getline(name, 100, '|');
			my_file.getline(cost, 10, '|');
			my_file.getline(quentity, 10);
			// to avoid the emplty line;
			if (int(id[0]) == 0) {
				continue;
			}
			if (strcmp(id, id_r) == 0 && op[0] == '1' || strcmp(name, name_r) == 0 && op[0] == '2') {
				found = 1;
				continue; // to skip this line in the new file
			}
			temporary_file << id << "|" << name << "|" << cost << "|" << quentity << "\n";
		}
		if (found == 0) {
			cout << "Product not found\n";
		}
		else {
			cout << "The product is deleted successfuly\n";
		}
		cout << "DO You want to remove another one (y / Y)\n";
		cin.getline(x, 2);
		my_file.close();
		temporary_file.close();
		remove("Super Market.txt");
		rename("temp.txt", "Super Market.txt");
	} while (x[0] == 'y' || x[0] == 'Y');
}


/*
ofstream --> write only --> out --> add but deleate all the previous
ifstream --> read only --> in --> the file should be created before
fstream ---> write & read --> in
file_name.dat --> ملفات مشفرة
*/
