#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <iomanip> //  function setwidth
using namespace std;
void Insert1() {
	//cin>> --> stop on the first space. 
	//cin.getline(); --> stop on the first line  --> arrays only --> array of stringecters only -->

	//id ---> 2021170384 (cin)
	//name ---> farouk khaled (cin.getline())
	//cost (cin)
	//quentity (cin)

	// between every to cin and cin.getline() we should use cin.ignore()
	//but to avoid this confusing we will use cin.getline() only

	fstream my_file;
	string id; // but in act 9 spaces only because null chatacter or it will enter infinite loop
	string name; // 99 spaces
	string cost;
	string quentity;
	my_file.open("Super Market.txt", ios::app);
	string choise;
	do {
		cout << "enter id\n";getline( cin , id);
		cout << "enter name\n";getline(cin,name);
		cout << "enter cost\n";getline(cin,cost);
		cout << "enter quentity\n";getline(cin,quentity);
		my_file << id << "|" << name << "|" << cost << "|" << quentity << "\n";
		cout << "the product is added successfuly\n";
		cout << "do you want to add more (y/Y)\n";
		getline(cin , choise);
	} while (choise[0] == 'y' || choise[0] == 'Y');
	//to avoid the file is still open in the memory
	my_file.close();
}
void Display1()
{
	string id; // but in act 9 spaces only because null chatacter or it will enter infinite loop
	string name; // 99 spaces
	string cost;
	string quentity;
	fstream my_file;
	my_file.open("Super Market.txt", ios::in);
	cout << "*******************************************************\n";
	cout << "                      My store                         \n";
	cout << "*******************************************************\n";
	cout << left << setw(10) << "ID" << setw(20) << "NAME" << setw(10) << "COST" << setw(10) << "QUENTITY \n";
	cout << "*******************************************************\n";
	//eof --> end of file
	while (!my_file.eof())
	{
		getline(my_file,id,'|');
		getline(my_file,name,'|');
		getline(my_file,cost,'|');
		getline(my_file,quentity);
		// function setwidth is used to تظبط the shape of your program;
		if (int(id[0]) != 0) { // casting from stringacter to intger 
			// the ascicode of space is zero 
			// to avid display the empty line.
			cout << left << setw(10) << id << setw(20) << name << setw(10) << cost << setw(10) << quentity << "\n";
			cout << "*******************************************************\n";
		}
	}
	my_file.close();
}
void Search1()
{
	fstream my_file;
	//my_file.open("Super Market.txt", ios::in);
	string id, id_r; // but in act 9 spaces only because null chatacter or it will enter infinite loop
	string name, name_r; // 99 spaces
	string cost;
	string quentity;
	string op, x;
	bool found;
	do {
		found = 0;
		my_file.open("Super Market.txt", ios::in);
		cout << "***************************\n";
		cout << "To search by id    enter: 1\n";
		cout << "To search by name  enter: 2\n";
		bool flag1 = 0;
		do {
			cout << "Enter option: "; getline(cin,op);
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
			cout << "Enter id --> ";getline( cin , id_r);
			break;
		case '2':
			cout << "enter name --> "; getline(cin,name_r);
			break;
		}
		while (!my_file.eof())
		{
			getline(my_file,id, '|');
			getline(my_file,name,'|');
			getline(my_file,cost,'|');
			getline(my_file,quentity);
			// strcmp string compare
			if (id == id_r && op[0] == '1' || name == name_r && op[0] == '2') {
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
		getline(cin,x);
		my_file.close();
	} while (x[0] == 'y' || x[0] == 'Y');

}

void Delete1()
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
		cout << "DO You want to remove another one\n";
		cin.getline(x, 2);
		my_file.close();
		temporary_file.close();
		remove("Super Market.txt");
		rename("temp.txt", "Super Market.txt");
	} while (x[0] == 'y' || x[0] == 'Y');
}

void Update() {
	fstream my_file, temporary_file;
	//my_file.open("Super Market.txt", ios::in);
	char id[10], id_r[10]; // but in act 9 spaces only because null chatacter or it will enter infinite loop
	char name[100], name_r[100]; // 99 spaces
	char cost[10];
	char quentity[10];
	char op[2], x[2] , update[2];
	bool found;
	do {
		found = 0;
		my_file.open("Super Market.txt", ios::in);
		temporary_file.open("temp.txt", ios::app);
		cout << "***************************\n";
		cout << "To Search by id    enter: 1\n";
		cout << "To Search by name  enter: 2\n";
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
				cout << "To update the id -- > enter 1\n";
				cout << "To update the name -- > enter 2\n";
				cout << "To update the cost -- > enter 3\n";
				cout << "To update the quentity -- > enter 4\n";
				cout << "To update the whole data -- > enter 5\n";
				cin.getline(update, 2);
				switch (update[0])
				{
				case '1':
					cout << "Enter new id\n";
					cin.getline(id, 10);
					temporary_file << id << "|" << name << "|" << cost << "|" << quentity << "\n";
					cout << "the product is upadted successfully\n";
					break;
				case '2':
					cout << "Enter new name\n";
					cin.getline(name, 100);
					temporary_file << id << "|" << name << "|" << cost << "|" << quentity << "\n";
					cout << "the product is upadted successfully\n";
					break;
				case '3':
					cout << "Enter new cost\n";
					cin.getline(cost, 10);
					temporary_file << id << "|" << name << "|" << cost << "|" << quentity << "\n";
					
					cout << "the product is upadted successfully\n"; 
					break;
				case '4':
					cout << "Enter new quentity\n";
					cin.getline(quentity, 10);
					temporary_file << id << "|" << name << "|" << cost << "|" << quentity << "\n";
					cout << "the product is upadted successfully\n";
					break;
				case '6':
					cout << "Enter new id\n";
					cin.getline(id, 10);
					cout << "Enter new name\n";
					cin.getline(name, 100);
					cout << "Enter new cost\n";
					cin.getline(cost, 10);
					cout << "Enter new quentity\n";
					cin.getline(quentity, 10);
					temporary_file << id << "|" << name << "|" << cost << "|" << quentity << "\n";
					
					cout << "the product is upadted successfully\n"; break;

				default:
					cout << "invalid!\n";
					break;
				}
			}
			else {
				temporary_file << id << "|" << name << "|" << cost << "|" << quentity << "\n";
			}
		}
		if (found == 0) {
			cout << "Product not found\n";
		}
		cout << "DO You want to update another one\n";
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