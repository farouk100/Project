#include <iostream>
#include <string>
#include <fstream>
#define Array_Size 10
using namespace std;
struct Cost
{
	int hour,
		day,
		week;
};
struct Date
{
	int start_day,
		start_month,
		start_year,
		end_day,
		end_month,
		end_year;
};
struct Car
{
	string type,
		L_P_N,
		return_branch,
		current_branch;
	bool status;
	Cost cost;
	Date date;
} car[Array_Size] = {};
int main()
{
	
	fstream index_file;
	index_file.open("index.txt", ios::in);
	string check_st;
	index_file >> check_st;
	int i = stoi(check_st);
	index_file.close();

	fstream my_file;
	my_file.open("car.txt", ios::in);
	my_file >> check_st;
	my_file.close();
	if (check_st != "\0")
	{
		my_file.open("car.txt", ios::in);
		string check_st;
		for (int j = 0; j < i; j++)
		{
			getline(my_file, car[j].type, '#');
			getline(my_file, car[j].L_P_N, '#');
			getline(my_file, check_st, '#');
			car[j].cost.hour = stoi(check_st);
			getline(my_file, check_st, '#');
			car[j].cost.day = stoi(check_st);
			getline(my_file, check_st, '#');
			car[j].cost.week = stoi(check_st);
			getline(my_file, car[j].current_branch, '#');
			getline(my_file, check_st, '#');
			car[j].status = stoi(check_st);
			getline(my_file, check_st, '#');
			car[j].date.start_day = stoi(check_st);
			getline(my_file, check_st, '#');
			car[j].date.start_month = stoi(check_st);
			getline(my_file, check_st, '#');
			car[j].date.start_year = stoi(check_st);
			getline(my_file, check_st, '#');
			car[j].date.end_day = stoi(check_st);
			getline(my_file, check_st, '#');
			car[j].date.end_month = stoi(check_st);
			getline(my_file, check_st, '#');
			car[j].date.end_year = stoi(check_st);
			getline(my_file, car[j].return_branch);
		}
		my_file.close();
	}
	cout << car[0].type;


	char choise;
	do
	{
		if (i == Array_Size)
		{
			cout << "You can't add more than " << Array_Size << " cars.\n";
			break;
		}

		cout << "Enter the car type:\n";
		cin >> car[i].type;
		cout << "Enter the car licence plat number:\n";
		cin >> car[i].L_P_N;
		cout << "Enter the cost of the hour - day - week\n";
		cin >> car[i].cost.hour >> car[i].cost.day >> car[i].cost.week;
		cout << "Enter the current branch:\n";
		cin >> car[i].current_branch;
		cout << "Is the car free to rental (1/0):\n";
		cin >> car[i].status;
		if (car[i].status == 0)
		{
			cout << "Enter the start date of the rental:\n";
			cin >> car[i].date.start_day >> car[i].date.start_month >> car[i].date.start_year;
			cout << "Enter the end date of the rental:\n";
			cin >> car[i].date.end_day >> car[i].date.end_month >> car[i].date.end_year;
			cout << "Enter the return branch:\n";
			cin >> car[i].return_branch;
		}
		cout << "The car is succesfuly added\n";
		i++;
		cout << "Do you want to add another car? (y/n)\n";
		cin >> choise;
	} while (choise == 'y');


	my_file.open("car.txt", ios::out);
	for (int j = 0; j < i; j++)
	{
		my_file << car[j].type << "#" << car[j].L_P_N << "#" << car[j].cost.hour << "#" << car[j].cost.day << "#" << car[j].cost.week << "#" <<
			car[j].current_branch << "#" << car[j].status << "#" << car[j].date.start_day << "#" << car[j].date.start_month << "#" <<
			car[j].date.start_year << "#" << car[j].date.end_day << "#" << car[j].date.end_month << "#" << car[j].date.end_year <<
			"#" << car[j].return_branch << "\n";
	}
	my_file.close();

	index_file.open("index.txt", ios::out);
	index_file << i;
	index_file.close();
	cout << car[0].type;
	return 0;
}