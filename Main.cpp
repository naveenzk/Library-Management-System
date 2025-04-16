#include <Windows.h> 
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <cwchar>

using namespace std;

void load();
void regist();
void student_data();
void student(int index);
void return_date(int index);

fstream myfile;
int index = 10;
struct student_rec {
	string name, fname, email, pass, name_bb;
	string num; // phone number includes more than 9 digits, cannot use int.
	int id = 0;
	int d_b = 0, m_b = 0, y_b = 0; //date borrowed
	int d_r = 0, m_r = 0, y_r = 0; //date returned
	bool book_borrowed = 0;
};
student_rec info[50];


struct Inventory {
	int id = 0;
	string name_of_book;
	string name_of_author;
	string status = "Available";
	int quantity = 0;
};
Inventory obj[100];

int b = -1, s = -1;
string code;

void load()
{
	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	int bar1 = 177, bar2 = 219;

	cout << "\n\n\t\t\t\t\t\t\t\tLoading...";
	cout << "\n\t\t\t\t\t\t\t\t";

	for (int i = 0; i < 25; i++)
		cout << (char)bar1;

	cout << "\r";
	cout << "\t\t\t\t\t\t\t\t";
	for (int i = 0; i < 25; i++)
	{
		cout << (char)bar2;
		Sleep(150);
	}
	cout << "\t\t" << (char)1 << "!";
}


void menu(char& choice)
{
	cout << "\t\t\t\t\t\t\t\t>> Choose an option to login\n";
	cout << "\n\t\t\t\t\t\t\t\tPress A if you are an admin.\n";
	cout << "\n\t\t\t\t\t\t\t\tPress B if you are a registered student.\n";
	cout << "\n\t\t\t\t\t\t\t\tPress C if you would like to register now.\n";
	cout << "\n\t\t\t\t\t\t\t\tPress X to exit.\t";
	cin >> choice;
	while (choice != 'A' && choice != 'a' && choice != 'B' && choice != 'b' && choice != 'C' && choice != 'c' && choice != 'x' && choice != 'X')
	{
		cout << "Invalid choice. Please enter again: ";
		cin >> choice;
	}
}

//Already stored data

void data()
{
	myfile.open("books.txt", ios::in);
	if (myfile)
	{
		string book_name, author_name;
		int id = 0, quantity = 0;
		for (b = 0; b < index; b++)
		{

			myfile >> obj[b].id;
			getline(myfile >> ws, obj[b].name_of_book);
			getline(myfile >> ws, obj[b].name_of_author);
			myfile >> obj[b].quantity;
		}
		myfile.close();
	}
	else
	{
		cout << "\nFile not found.";
	}
}

void student_data()
{
	data();
	s = -1;
	s++;
	info[s].id = 1216;
	info[s].name = "Naveen Zaman Khan";
	info[s].fname = "Khurram Zaman Khan";
	info[s].email = "naveen.zkhan@gmail.com";
	info[s].num = "033406719256";
	info[s].pass = "xts4m";
	info[s].book_borrowed = 0;
	info[s].name_bb = "None";

	s++;
	info[s].id = 1291;
	info[s].name = "Aiman Yousuf";
	info[s].fname = "Yousuf Ahmed";
	info[s].email = "aiman.lodhi@gmail.com";
	info[s].num = "03317281902";
	info[s].pass = "pvyw2";
	info[s].book_borrowed = 1;
	info[s].name_bb = obj[5].name_of_book;
	info[s].d_b = 12;
	info[s].m_b = 04;
	info[s].y_b = 2022;

	s++;
	info[s].id = 1210;
	info[s].name = "Hafsa Khattak";
	info[s].fname = "Khattak Hussain";
	info[s].email = "hafsa.k@gmail.com";
	info[s].num = "03327819731";
	info[s].pass = "oqw1r";
	info[s].book_borrowed = 1;
	info[s].name_bb = obj[7].name_of_book;
	info[s].d_b = 25;
	info[s].m_b = 12;
	info[s].y_b = 2022;

	s++;
	info[s].id = 1264;
	info[s].name = "Nahin Fatima";
	info[s].fname = "Bilal Faisal ";
	info[s].email = "nahin_fatima@gmail.com";
	info[s].num = "033172893561";
	info[s].pass = "gr4kw";
	info[s].book_borrowed = 0;
	info[s].name_bb = "None";

	s++;
	info[s].id = 1297;
	info[s].name = "Alishba Siraj";
	info[s].fname = "Siraj Shah";
	info[s].email = "alishba.ss@gmail.com";
	info[s].num = "033391026348";
	info[s].pass = "7skow";
	info[s].book_borrowed = 1;
	info[s].name_bb = obj[8].name_of_book;
	info[s].d_b = 18;
	info[s].m_b = 03;
	info[s].y_b = 2022;
}

//functions for admin

void view_admin()
{
	int i, f;
	cout << "\n\n\t\t\t\t\t\t\t\t\tINVENTORY\n\n";
	cout << "\t\t" << left << setw(5) << "ID      ";
	cout << "\t\t" << left << setw(30) << "Name of Book";
	cout << "\t\t" << left << setw(20) << "Name of Author";
	cout << "\t\t" << left << setw(15) << "Status";
	cout << "\t\t" << left << setw(10) << "Quantity" << "\n\t";
	for (f = 0; f < 70; f++)
	{
		cout << "- ";
	}
	for (i = 0; i < index; i++)
	{
		cout << "\n\t\t" << right << setw(4) << setfill('0') << obj[i].id << "\t";
		cout << "\t\t" << left << setw(30) << setfill(' ') << obj[i].name_of_book;
		cout << "\t\t" << left << setw(20) << obj[i].name_of_author;
		cout << "\t\t" << left << setw(15) << obj[i].status;
		cout << "\t\t" << left << setw(10) << obj[i].quantity;
	}
	cout << "\n\n";
}

void add_book()
{
	int f;
	index++;
	b = index - 1;
	obj[b].id = b + 1;
	cout << "\n\n\t\t\t\t\t\t\tPlease enter the details of the book you want to add.\n\n\t\t\t\t\t\t\t\t";
	for (f = 0; f < 20; f++)
	{
		cout << "- ";
	}
	cout << "\n\n\t\t\t\t\t\t\tName of book: ";
	getline(cin >> ws, obj[b].name_of_book);
	cout << "\n\t\t\t\t\t\t\tName of author: ";
	getline(cin, obj[b].name_of_author);
	cout << "\n\t\t\t\t\t\t\tQuantity to be added: ";
	cin >> obj[b].quantity;

	myfile.open("books.txt", ios::app);
	myfile << endl << "00" << obj[b].id << endl;
	myfile << obj[b].name_of_book << endl;
	myfile << obj[b].name_of_author << endl;
	myfile << obj[b].quantity;
	myfile.close();

	load();
	cout << "\n\n\n\t\t\t\t\t\tThe book has been added to record.";
}

void search_book()
{
	bool found = false;
	int search, f;
	cout << "\n\n\t\t\t\t\t\tPlease enter the id of the book you want to search: ";
	cin >> search;
	cout << "\n\n\t\t\t\t\t\t\t";
	for (f = 0; f < 20; f++)
	{
		cout << "- ";
	}
	load();
	int i;
	for (i = 0; i <= b; i++)
	{
		if (search == obj[i].id)
		{
			found = true;
			break;
		}
		else
		{
			found = false;
		}
	}
	if (found == true)
	{
		cout << "\n\n\n\t\t\t\t\t\t\t" << obj[i].name_of_book << " by " << obj[i].name_of_author << endl;
		cout << "\n\t\t\t\t\t\t\tStatus = " << obj[i].status << "\tQuantity = " << obj[i].quantity << "\t";
	}
	else
	{
		cout << "\n\n\n\t\t\t\t\t\t\tInvalid ID, this book is not in our record.\t";
	}
}

void personal_info()
{
	student_data();
	int i;
	cout << "\n\n\n\t\t\t\t\t\t\t\tCurrently registered students\n";
	for (i = 0; i <= s; i++)
	{
		cout << "\n\n\t\t\t\t\t\t\t\t" << left << setw(20) << "ID: " << info[i].id << endl;
		cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Name: " << info[i].name << endl;
		cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Father's name: " << info[i].fname << endl;
		cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Email: " << info[i].email << endl;
		cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Phone: " << info[i].num << endl;
		cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Password: " << info[i].pass << "\n\n\t\t\t\t\t\t\t";
		for (int f = 0; f < 50; f++)
		{
			cout << "-";
		}
	}
	cout << "\t\t";
}

void library_info()
{
	student_data();
	int i;

	for (i = 0; i <= s; i++)
	{
		cout << "\n\n\t\t\t\t\t\t\t\t" << left << setw(20) << "ID: " << info[i].id << endl;
		cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Name: " << info[i].name << endl;
		cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Book borrowed: " << info[i].name_bb << endl;
		if (info[i].book_borrowed == 0)
		{
			cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Issue date: " << "00/00/0000" << endl;
			cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Return date: " << "00/00/0000" << "\n\n\t\t\t\t\t\t\t";
		}
		else
		{
			cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Issue date: " << right << setw(2) << info[i].d_b << "/" << right << setw(2) << info[i].m_b << "/" << setw(4) << info[i].y_b << endl;
			return_date(i);
			cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << setfill(' ') << "Return date: " << right << setw(2) << info[i].d_r << "/" << right << setw(2) << info[i].m_r << "/" << setw(4) << info[i].y_r << "\n\n\t\t\t\t\t\t\t";
		}
		for (int f = 0; f < 50; f++)
		{
			cout << "-";
		}
	}
	cout << "\t\t";
}

void search_student()
{
	student_data();
	int id, i;
	bool found = false;
	cout << "\n\n\t\t\t\t\t\t\t\tEnter student ID: ";
	cin >> id;
	load();
	for (i = 0; i <= s; i++)
	{
		if (id == info[i].id)
		{
			found = true;
			break;
		}
		else
		{
			found = false;
		}
	}
	if (found == true)
	{
		cout << "\n\n\t\t\t\t\t\t\t";
		for (int f = 0; f < 50; f++)
		{
			cout << "-";
		}

		cout << "\n\n\t\t\t\t\t\t\t\t" << left << setw(20) << "ID: " << info[i].id << endl;
		cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Name: " << info[i].name << endl;
		cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Father's name: " << info[i].fname << endl;
		cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Email: " << info[i].email << endl;
		cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Phone: " << info[i].num << endl;
		cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Password: " << info[i].pass << endl;
		cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Book borrowed: " << info[i].name_bb << endl;
		if (info[i].book_borrowed == 0)
		{
			cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Issue date: " << "00/00/0000" << endl;
			cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Return date: " << "00/00/0000";
		}
		else
		{
			cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Issue date: " << right << setw(2) << info[i].d_b << "/" << right << setw(2) << info[i].m_b << "/" << setw(4) << info[i].y_b << endl;
			return_date(i);
			cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Return date: " << right << setw(2) << info[i].d_r << "/" << right << setw(2) << info[i].m_r << "/" << setw(4) << info[i].y_r;
		}
	}
	else
	{
		cout << "\n\n\n\t\t\t\t\t\t\t\tID not found.";
	}
	cout << "\n\n\t\t\t\t\t\t\t";
	for (int f = 0; f < 50; f++)
	{
		cout << "-";
	}
	cout << "\t\t";
}

void view_student_rec()
{
	char back;
	int choice2 = 0, f;
	do {
		cout << "\n\n\t\t\t\t\t\t\t";
		for (f = 0; f < 20; f++)
		{
			cout << " ";
		}
		cout << " STUDENT DATA ";
		for (f = 0; f < 20; f++)
		{
			cout << " ";
		}
		cout << "\n\n\n\t\t\t\t\t\t\t\t1. View personal information\n";
		cout << "\n\t\t\t\t\t\t\t\t2. View library information\n";
		cout << "\n\t\t\t\t\t\t\t\t3. Search for a specific student\n";
		cout << "\n\t\t\t\t\t\t\t\t4. Go back to menu\n";
		cout << "\n\n\t\t\t\t\t\t\tEnter your choice: ";
		cin >> choice2;
		if (choice2 == 1)
		{
			personal_info();
		}
		else if (choice2 == 2)
		{
			library_info();
		}
		else if (choice2 == 3)
		{
			search_student();
		}
		else if (choice2 == 4)
		{
			break;
		}
		else
		{
			while (choice2 != 1 && choice2 != 2 && choice2 != 3 && choice2 != 4)
			{
				cout << "Invalid number, pls enter again: ";
				cin >> choice2;
			}
		}
		cout << "\t\tPress X to go back. ";
		cin >> back;
		while (back != 'x' && back != 'X')
		{
			cout << "\nInvalid letter. Please enter again.\n";
			cin >> back;
		}
	} while (back == 'x' || back == 'X');
}


void admin()
{
	data();
	char action;
	do {
		int choice = 0, f;
		cout << "\n\n\t\t\t\t\t\t";
		for (f = 0; f < 20; f++)
		{
			cout << "-";
		}
		cout << " ADMINISTRATIVE MENU ";
		for (f = 0; f < 20; f++)
		{
			cout << "-";
		}
		cout << "\n\n\n\t\t\t\t\t\t\t\t1. View inventory.\n";
		cout << "\n\t\t\t\t\t\t\t\t2. Add a new book.\n";
		cout << "\n\t\t\t\t\t\t\t\t3. Search in inventory.\n";
		cout << "\n\t\t\t\t\t\t\t\t4. View student record.\n";
		cout << "\n\t\t\t\t\t\t\t\t5. Go back to login page.\n";
		cout << "\n\n\t\t\t\t\t\tEnter your choice: ";
		cin >> choice;
		if (choice == 1)
		{
			view_admin();
		}
		else if (choice == 2)
		{
			add_book();
		}
		else if (choice == 3)
		{
			search_book();
		}
		else if (choice == 4)
		{
			view_student_rec();
		}
		else if (choice == 5)
		{
			cout << "\n\n";
			break;
		}
		else
		{
			while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
			{
				cout << "Invalid choice. Please enter again: ";
				cin >> choice;
			}
		}
		if (choice == 4)
		{
			action = 'Y';
		}
		else
		{
			cout << "\tPress Y to go back to menu. ";
			cin >> action;
			while (action != 'y' && action != 'Y' && action != 'x' && action != 'X')
			{
				cout << "\nInvalid letter. Please enter again.\n";
				cin >> action;
			}
		}
	} while (action == 'y' || action == 'Y');
}


//functions for student

void view_student()
{
	cout << "\n\n\t\t\t\t\t\t\t\t\tBOOK LIST\n\n";
	cout << "\t\t\t\t" << left << setw(5) << "ID      ";
	cout << "\t\t" << left << setw(30) << "Name of Book";
	cout << "\t\t" << left << setw(20) << "Name of Author";
	cout << "\t\t" << left << setw(15) << "Status\n\t";
	for (int f = 0; f < 70; f++)
	{
		cout << "- ";
	}
	int i;
	for (i = 0; i < b; i++)
	{
		cout << "\n\t\t\t\t" << right << setw(4) << setfill('0') << obj[i].id << "\t";
		cout << "\t\t" << left << setw(30) << setfill(' ') << obj[i].name_of_book;
		cout << "\t\t" << left << setw(20) << obj[i].name_of_author;
		cout << "\t\t" << left << setw(15) << obj[i].status;
	}
	cout << "\n\n\t";
}

void return_date(int index)
{
	if (info[index].m_b != 12)
	{
		if (info[index].d_b > 20)
		{
			info[index].d_r = (info[index].d_b + 10) - 30;
			info[index].m_r = info[index].m_b + 1;
			info[index].y_r = info[index].y_b;
		}
		else
		{
			info[index].d_r = info[index].d_b + 10;
			info[index].m_r = info[index].m_b;
			info[index].y_r = info[index].y_b;
		}
	}
	else
	{
		if (info[index].d_b > 20)
		{
			info[index].d_r = (info[index].d_b + 10) - 30;
			info[index].m_r = 01;
			info[index].y_r = info[index].y_b + 1;
		}
		else
		{
			info[index].d_r = info[index].d_b + 10;
			info[index].m_r = info[index].m_b;
			info[index].y_r = info[index].y_b;
		}
	}
}

void book_borrow(int index)
{
	if (info[index].book_borrowed == 1)
	{
		cout << "\n\t\t\tYou can only borrow 1 book at a time. You must return " << info[index].name_bb << " first.";
	}
	else
	{
		int id_borrow, back;
		cout << "\n\n\t\t\t\t\tPls view your desired book in the book list and enter its ID.";
		cout << "\n\t\t\t\t\tIf you do not remember the ID, Press 1 to go back to menu or else press 2 to continue. ";
		cin >> back;
		if (back == 1)
		{
			b = -1;
			student(index);
		}
		while (back != 2 && back != 1)
		{
			cout << "\t\t\t\t\tInvalid number, pls enter again: ";
			cin >> back;
		}
		cout << "\n\t\t\t\t\t\t\t\tID: ";
		cin >> id_borrow;
		int j;
		for (j = 0; j <= b; j++)
		{
			if (id_borrow == obj[j].id)
			{
				if (obj[j].status == "Available")
				{
					if (obj[j].quantity == 0)
					{
						obj[j].status = "Unavailable";
					}
					else
					{
						obj[j].quantity--;
					}
					cout << "\n\n\t\t\t\t\tPlease wait while the book is being added to your record.\n";
					load();
					cout << "\n\n\n\t\t\t\t\tYou have borrowed " << obj[j].name_of_book << " by " << obj[j].name_of_author << " successfully.";
					info[index].book_borrowed = 1;
					info[index].name_bb = obj[j].name_of_book;;
					cout << "\n\n\t\t\t\t\tPlease enter today's date(dd mm yyyy): ";
					cin >> info[index].d_b >> info[index].m_b >> info[index].y_b;
					cout << "\n\t\t\t\t\tYou can only keep this book for 10 days. Must return on ";
					return_date(index);
					cout << info[index].d_r << "/" << info[index].m_r << "/" << info[index].y_r;
				}
				else
				{
					cout << "\n\t\tThis book is currently unavailable.";
				}
			}
		}
	}

}

void book_return(int index)
{
	char return_book;
	if (info[index].book_borrowed == 0)
	{
		cout << "\n\t\t\t\t\t\tYou dont have any book in your record.";
	}
	else
	{
		cout << "\n\n\t\t\t\t\t\t\tYou currently have " << info[index].name_bb << " in your record.\n";
		cout << "\t\t\t\t\t\t\tPress R to return it: ";
		cin >> return_book;
		while (return_book != 'R' && return_book != 'r')
		{
			cout << "\n\t\t\t\t\t\t\t\tInvalid letter. Enter again: ";
			cin >> return_book;
		}

		int k, date, month, year;
		for (k = 0; k <= b; k++)
		{
			if (info[index].name_bb == obj[k].name_of_book)
			{
				obj[k].quantity++;
				cout << "\n\t\t\t\t\tPlease enter today's date(dd mm yyyy): ";
				cin >> date >> month >> year;
				cout << "\n\n\t\t\t\t\tPlease wait while the book is being removed from your record.\n";
				load();
				return_date(index);

				if (date == info[index].d_r && month == info[index].m_r && year == info[index].y_r)
				{
					cout << "\n\n\n\t\t\t\t\tYou have returned " << obj[k].name_of_book << " by " << obj[k].name_of_author << " successfully.";
				}
				else
				{
					cout << "\n\n\n\t\t\t\t\tYou have exceeded the due date. You are fined $50.";
				}
				info[index].book_borrowed = 0;
			}
		}
	}
}

void view_rec(int index)
{
	cout << "\n\n\t\t\t\t\t\t\t";
	for (int f = 0; f < 50; f++)
	{
		cout << "-";
	}
	cout << "\n\n\t\t\t\t\t\t\t\t" << left << setw(20) << "ID: " << info[index].id << endl;
	cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Name: " << info[index].name << endl;
	cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Father's name: " << info[index].fname << endl;
	cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Email: " << info[index].email << endl;
	cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Phone: " << info[index].num << endl;
	cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Password: " << info[index].pass << endl;
	cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Book borrowed: " << info[index].name_bb << endl;
	if (info[index].book_borrowed == 0)
	{
		cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Issue date: " << "00/00/0000" << endl;
		cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Return date: " << "00/00/0000" << endl << "\n\t\t\t\t\t\t\t";
	}
	else
	{
		cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Issue date: " << right << setw(2) << info[index].d_b << "/" << right << setw(2) << info[index].m_b << "/" << setw(4) << info[index].y_b << endl;
		return_date(index);
		cout << "\t\t\t\t\t\t\t\t" << left << setw(20) << "Return date: " << right << setw(2) << info[index].d_r << "/" << right << setw(2) << info[index].m_r << "/" << setw(4) << info[index].y_r << "\n\t\t\t\t\t\t\t";
	}
	for (int f = 0; f < 50; f++)
	{
		cout << "-";
	}
	cout << "\t\t";
}

void student(int index)
{
	student_data();
	b = -1;
	data();
	char ch;
	do {
		int choice;
		cout << "\n\n\t\t\t\t\t\t";
		for (int f = 0; f < 30; f++)
		{
			cout << "-";
		}
		cout << " STUDENT MENU ";
		for (int f = 0; f < 30; f++)
		{
			cout << "-";
		}

		cout << "\n\n\n\t\t\t\t\t\t\t\t1. View book list.\n";
		cout << "\n\t\t\t\t\t\t\t\t2. Borrow a book.\n";
		cout << "\n\t\t\t\t\t\t\t\t3. Return a book.\n";
		cout << "\n\t\t\t\t\t\t\t\t4. View your record.\n";
		cout << "\n\t\t\t\t\t\t\t\t5. Go back to login page.\n\n";
		cout << "\n\n\t\t\t\t\t\t\tEnter your choice: ";
		cin >> choice;
		while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)
		{
			cout << "\t\t\t\tInvalid number. Pls enter again: ";
			cin >> choice;
		}
		if (choice == 5)
		{
			cout << endl;
			break;
		}
		else
		{
			switch (choice)
			{
			case 1:
				view_student();
				break;
			case 2:
				book_borrow(index);
				break;
			case 3:
				book_return(index);
				break;
			case 4:
				view_rec(index);
				break;
			}
		}
		cout << "\tPress Y to go back to menu. ";
		cin >> ch;
		while (ch != 'y' && ch != 'Y' && ch != 'x' && ch != 'X')
		{
			cout << "\t\t\t\tInvalid letter. Please enter again.\n";
			cin >> ch;
		}
	} while (ch == 'y' || ch == 'Y');

}

void regist()
{
	student_data();
	int n = s++;
	cout << "\n\n\t\t\t\t\tFill in the form below to register.";
	cout << "\n\n\n\t\t\t\t\tName: ";
	getline(cin >> ws, info[n].name);
	cout << "\n\t\t\t\t\tFather's name: ";
	getline(cin, info[n].fname);
	cout << "\n\t\t\t\t\tEmail: ";
	getline(cin, info[n].email);
	cout << "\n\t\t\t\t\tPhone Number : +92 ";
	cin >> info[n].num;
	cout << "\n\n\t\t\t\t\tPlease wait while your account is being made.";
	load();
	const char alphanum[] = "1234567890qwertyuioplkjhgfdsazxcvbnm";
	int string_length = sizeof(alphanum) - 1;
	srand(time(0));
	int m;
	cout << "\n\n\t\t\t\t\tDear " << info[n].name << " you have been registered successfully.";
	cout << "\n\n\t\t\t\t\tYour login code is: ";
	for (m = 0; m < 5; m++)
	{
		info[n].pass = alphanum[rand() % string_length];
		cout << info[n].pass;
	}

	cout << "\n\n\t\t\t\t\tYou can now access all library features.\t\t\t";
	system("pause");
}

int login()
{
	student_data();
	bool found = false;
	int i = 0;
	cout << "\n\n\t\t\t\t\t\t\t\t\tEnter your login code: ";
	cin >> code;
	for (i = 0; i <= s; i++)
	{
		if (code == info[i].pass)
		{
			found = true;
			break;
		}
		else
		{
			found = false;
		}
	}
	if (found == true)
	{
		load();
		cout << "\n\n";
	}
	else {
		cout << "\n\t\t\t\t\t\t\t\t\tInvalid code. Pls register first.\n";
		regist();
	}
	return i;
}

void main()
{
	system("COLOR 0e");
	char choice;
	int f;
	cout << "\t\t\t\t";
	for (f = 0; f < 100; f++)
	{
		cout << "*";
	}
	cout << "\n\n\t\t\t\t\t\t\t\t\tBAHRIA VIRTUAL LIBRARY\n\n\t\t\t\t";
	for (f = 0; f < 100; f++)
	{
		cout << "*";
	}
	cout << "\n\n\n";
	do {
		menu(choice);

		if (choice == 'a' || choice == 'A')
		{
			string pass;
			b = -1;
			cout << "\n\n\t\t\t\t\t\t\t\tLogin Code: ";
			cin >> pass;
			while (pass != "library123")
			{
				cout << "\n\t\t\t\t\t\t\t\tInvalid code. Enter again: ";
				cin >> pass;
			}
			admin();
		}

		else if (choice == 'b' || choice == 'B')
		{
			int index = login();
			student(index);
		}

		else if (choice == 'c' || choice == 'C')
		{
			s++;
			regist();
			student(s);
		}
	} while (choice != 'x' && choice != 'X');

	system("exit");
}
