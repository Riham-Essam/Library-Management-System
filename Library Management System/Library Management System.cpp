#include <iostream>
#include <string>
#include <ctime>
const int LIBRARIRIANSNO = 4;
const int CONTACTSNO = 3;
using namespace std;
struct LibrarianCredentials
{
	string username;
	string password;
}nLibrarians[LIBRARIRIANSNO];
struct Date
{
	int day, month, year;
};
struct User
{
	int ID;
	string name;
	string email;
	string password;
	string accountType;
	Date creation_date;
	string contacts[CONTACTSNO];
	int total = 0;
}usersNo[1000], number_of_users;
struct Books
{
	string title;
	int production_year;
	int numberOfCopies;
	string category;
	int edtition;
}booksNo[1000];

int isFound(int t_index)
{
	int temp = 0;
	string username, Pass;
	cout << "Please enter your username" << endl;
	{
		cin.ignore();
		getline(cin, username);
	}
	cout << "Please enter your password" << endl;
	cin >> Pass;

	if (nLibrarians[t_index].username == username && nLibrarians[t_index].password == Pass)
	{
		temp = 1;
	}

	if (temp == 0)
	{
		cout << "Invalid" << endl;
	}
	return temp;
}
int input_user_details(int t_index_users)
{
	int nUsers;
	cout << "How many users will have accounts" << endl;
	{
		cin >> nUsers;
		number_of_users.total += nUsers;
	}
	if (nUsers == 0) //for avoidning wrong input at the first time
	{
		cout << "Invalid please enter the number again" << endl;
		cin >> nUsers;
		number_of_users.total += nUsers;
	}
	while (true)
	{

		cout << "Please enter the user's ID no. " << t_index_users + 1 << endl;
		cin >> usersNo[t_index_users].ID;
		cout << "Please enter user's name no. " << t_index_users + 1 << endl;
		{
			cin.ignore();
			getline(cin, usersNo[t_index_users].name);
		}
		cout << "Please enter user's mail no. " << t_index_users + 1 << endl;
		cin >> usersNo[t_index_users].email;
		cout << "Please enter user's password no. " << t_index_users + 1 << endl;
		cin >> usersNo[t_index_users].password;
		cout << "Please enter user's account type (Student/Staff/Guest) no. " << t_index_users + 1 << endl;
		cin >> usersNo[t_index_users].accountType;
		cout << "Please enter creation date of user's account no. " << t_index_users + 1 << endl;
		cin >> usersNo[t_index_users].creation_date.day >> usersNo[t_index_users].creation_date.month >> usersNo[t_index_users].creation_date.year;
		cout << "Please enter set of contacts for user no. " << t_index_users + 1 << endl;
		for (int i = 0; i < CONTACTSNO; ++i)
		{
			cin >> usersNo[t_index_users].contacts[i];
		}
		nUsers--;
		if ((nUsers) == 0)
		{
			break;
		}
		else
		{
			t_index_users++;
		}
	}
	return t_index_users;
}
void input_books(int t_nbooks)
{
	for (int i = 0; i < t_nbooks; ++i)
	{
		cout << "Please enter the tilte of book " << i + 1 << endl;
		cin >> booksNo[i].title;
		cout << "Please enter the year of production of book " << i + 1 << endl;
		cin >> booksNo[i].production_year;
		cout << "Please enter no of copies of book " << i + 1 << endl;
		cin >> booksNo[i].numberOfCopies;
		cout << "Please enter category of book " << i + 1 << endl;
		cin >> booksNo[i].category;
		cout << "please enter the edition of book " << i + 1 << endl;
		cin >> booksNo[i].edtition;
	}
}
void hasFound()
{
	int found = 0;
	int id;

	for (int i = 0; i < number_of_users.total; ++i)
	{
		cout << "Enter your ID" << endl;
		cin >> id;
		for (int j = 0; j < number_of_users.total; ++j)
		{
			if (id == usersNo[j].ID)
			{
				found = 1;
				cout << "Is found" << endl;
			}
			else
			{
				found = 0;
			}
			if (found == 1)
			{
				break;
			}
		}
		if (found == 0)
		{
			cout << "Is not found" << endl;
		}

	}
}
void search(int t_numOfBooks)
{
	string title;
	int production_year;
	cout << "What's the name of the book you want to search for" << endl;
	cin >> title;
	cout << "What's the production year of the book you want to search for" << endl;
	cin >> production_year;
	int tempp = 0;
	for (int i = 0; i < t_numOfBooks; ++i)
	{
		if (booksNo[i].title == title || booksNo[i].production_year == production_year)
		{
			tempp = 1;
			cout << "Book is found" << endl;
		}
		else
		{
			tempp = 0;
		}
		if (tempp == 1)
		{
			break;
		}
	}
	if (tempp == 0)
	{
		cout << "Book is not found" << endl;
	}
}
void input_librarians()
{
	nLibrarians[0].username = "Ahmed Mohamed";
	nLibrarians[0].password = "123##";
	nLibrarians[1].username = "Mona Ali";
	nLibrarians[1].password = "@@456";
	nLibrarians[2].username = "Ali Mohamed";
	nLibrarians[2].password = "78*&9";
	nLibrarians[3].username = "Esraa Ali";
	nLibrarians[3].password = "012%#";

}
int isStaff(int t_index)
{
	int valid = 0;
	if (t_index >= number_of_users.total)
	{
		valid = -1;
	}
	else
	{
		if (usersNo[t_index].accountType == "staff")
		{
			cout << "He is staff" << endl;
			valid = 1;
		}
		else
		{
			valid = 0;
			cout << "He is not a staff" << endl;
		}
	}
	return valid;
}
int hasValid(int t_num)
{
	string title;
	int production_year;
	cout << "What is the name of the book you want to buy" << endl;
	cin >> title;
	cout << "What is the year of production of the book you want to buy" << endl;
	cin >> production_year;
	int search = -1;
	int index = 0;
	for (int i = 0; i < t_num; ++i)
	{
		if (booksNo[i].title == title || booksNo[i].production_year == production_year)
		{
			cout << "Book is Found" << endl;
			search = 1;
			index = i;
		}

	}
	if (search == -1)
	{
		cout << "Book is not found" << endl;
		return search;
	}
	return index;
}
int report(int t_index_of_users)
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int year_now = newtime.tm_year + 1900;
	int month_now = newtime.tm_mon + 1;
	int day_now = newtime.tm_mday;
	int reported = 0;
	int users_reprot;
	cout << "How many new users do you have right now" << endl;
	cin >> users_reprot;
	while (true)
	{
		int counter = 0;
		int new_days = 0;
		int new_month = 0;

		if (usersNo[t_index_of_users].creation_date.year == year_now)
		{
			if (usersNo[t_index_of_users].creation_date.month == month_now)
			{
				if (usersNo[t_index_of_users].creation_date.day <= day_now)
				{
					if ((day_now - usersNo[t_index_of_users].creation_date.day) <= 7)
					{
						reported = 1;
						cout << "User's ID : " << usersNo[t_index_of_users].ID << endl;
						cout << "User's Name : " << usersNo[t_index_of_users].name << endl;
						cout << "User's E-mail : " << usersNo[t_index_of_users].email << endl;
						cout << "User's Password : " << usersNo[t_index_of_users].password << endl;
						cout << "User's Account Type (Student / Staff / Guest) : " << usersNo[t_index_of_users].accountType << endl;
						cout << "User's Creation Date : " << usersNo[t_index_of_users].creation_date.day;
						cout << " / " << usersNo[t_index_of_users].creation_date.month;
						cout << " / " << usersNo[t_index_of_users].creation_date.year << endl;
						for (int i = 0; i < CONTACTSNO; ++i)
						{
							cout << "User's contatct number " << 1 + i << " : " << usersNo[t_index_of_users].contacts[i] << endl;
						}
						cout << "********************************" << endl;
					}
					else
					{
						reported = 0;
					}
				}
			}
			else if (month_now > usersNo[t_index_of_users].creation_date.month)
			{
				new_month = usersNo[t_index_of_users].creation_date.month;
				if (usersNo[t_index_of_users].creation_date.day >= day_now)
				{
					new_days = usersNo[t_index_of_users].creation_date.day;
					while (true)
					{

						if ((usersNo[t_index_of_users].creation_date.month == 1) ||
							(usersNo[t_index_of_users].creation_date.month == 3) ||
							(usersNo[t_index_of_users].creation_date.month == 5) ||
							(usersNo[t_index_of_users].creation_date.month == 7) ||
							(usersNo[t_index_of_users].creation_date.month == 8) ||
							(usersNo[t_index_of_users].creation_date.month == 10) ||
							(usersNo[t_index_of_users].creation_date.month == 12))
						{
							reported = 1;
							if (new_days == 31)
							{
								new_month++;
								new_days = 0;
								new_days++;
								counter++;
							}
							else if (new_days < 31)
							{
								new_days++;
								counter++;
							}
							if (new_days == day_now)
							{
								break;
							}
						}
						else if ((usersNo[t_index_of_users].creation_date.month == 4) ||
							(usersNo[t_index_of_users].creation_date.month == 6) ||
							(usersNo[t_index_of_users].creation_date.month == 9) ||
							(usersNo[t_index_of_users].creation_date.month == 11))
						{
							reported = 1;
							if (new_days == 30)
							{
								new_days = 0;
								new_month++;
								new_days++;
								counter++;
							}
							else if (new_days < 30)
							{
								new_days++;
								counter++;
							}
							if (new_days == day_now)
							{
								break;
							}

						}
						else if ((usersNo[t_index_of_users].creation_date.month == 2))
						{
							reported = 1;
							if (new_days == 29 || new_days == 28)
							{
								new_month++;
								new_days = 0;
								new_days++;
								counter++;
							}
							else if (new_days < 29 || new_days < 28)
							{
								new_days++;
								counter++;
							}
							if (new_days == day_now)
							{
								break;
							}
						}

					}
					if (counter <= 7 && new_month == month_now)
					{
						cout << "User's ID : " << usersNo[t_index_of_users].ID << endl;
						cout << "User's Name : " << usersNo[t_index_of_users].name << endl;
						cout << "User's E-mail : " << usersNo[t_index_of_users].email << endl;
						cout << "User's Password : " << usersNo[t_index_of_users].password << endl;
						cout << "User's Account Type (Student / Staff / Guest) : " << usersNo[t_index_of_users].accountType << endl;
						cout << "User's Creation Date : " << usersNo[t_index_of_users].creation_date.day;
						cout << " / " << usersNo[t_index_of_users].creation_date.month;
						cout << " / " << usersNo[t_index_of_users].creation_date.year << endl;
						for (int i = 0; i < CONTACTSNO; i++)
						{
							cout << "User's contatct number " << 1 + i << " : " << usersNo[t_index_of_users].contacts[i] << endl;
						}
						cout << "********************************" << endl;

					}
					else
					{
						reported = 0;
					}

				}

			}
			else
			{
				reported = 0;
			}
		}
		else
		{
			reported = 0;
		}
		users_reprot--;
		if ((users_reprot) == 0)
		{
			break;
		}
		else
		{
			t_index_of_users++;
		}
	}

	return t_index_of_users;
}
int buy_book(int t_index, int t_num)
{
	int nCopies = 0;
	if (booksNo[t_index].numberOfCopies >= t_num)
	{
		booksNo[t_index].numberOfCopies = (booksNo[t_index].numberOfCopies - t_num);
		int number = booksNo[t_index].numberOfCopies;
		cout << "You've bought " << t_num << " book(s)" << endl;
		return number;
	}
	else
	{
		cout << "There is no enough copies you can come later " << endl;
		nCopies = booksNo[t_index].numberOfCopies;
	}
	return nCopies;
}
int main()
{

	int nBooks, index_users = 0;
	cout << "How many books do you have ?" << endl;
	cin >> nBooks;
	input_books(nBooks);
	input_librarians();
	char x;
	int option, indexUsersReport = 0;
	int choice, noOfBooks = 0, index = 0;

	while (true)
	{
		cout << "Please enter your option:( 1/Librarian - 2/User - 3/exit )" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
		{

			do
			{
				cout << "Please enter your choice: (1/ Create Accounts - 2/ Report )" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					cout << "Enter the index of the librarian who will continue" << endl;
					cin >> index;

					int isExist = isFound(index);
					if (isExist == 1)
					{
						cout << "Valid" << endl;
						int last_index = input_user_details(index_users);
						index_users = last_index + 1;
					}
					else
					{
						while (isExist == 0)
						{
							int isExist = isFound(index);
							if (isExist == 1)
							{
								cout << "Valid" << endl;
								int last_index = input_user_details(index_users);
								index_users = last_index + 1;
								break;
							}
						}
					}

					break;
				}
				case 2:
				{

					int index_report = report(indexUsersReport);
					indexUsersReport = index_report + 1;
					break;
				}
				}
				cout << "Do you want to continue ?" << endl;
				cin >> x;
			} while (x == 'y');

		}	break;

		case 2:
		{
			do
			{
				cout << "Please enter your choice: (1/ Check - 2/ search - 3/ Buy)" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					cout << "Please check if you're exist or not" << endl;
					hasFound();
					break;
				}
				case 2:
				{
					search(nBooks);
					break;
				}
				case 3:
				{

					cout << "Please enter the user's index " << endl;
					cin >> index;
					int isValid = isStaff(index);
					if (isValid == 1)
					{

						int postion = hasValid(nBooks);
						if (postion != -1)
						{
							int boughtBooks;
							cout << "How many books do you want to buy" << endl;
							cin >> boughtBooks;
							int number = buy_book(postion, boughtBooks);
							cout << "The no of the existed books = " << number << endl;
						}
						else
						{
							break;
						}
					}
					else if (isValid == -1)
					{
						cout << "This is user is not found" << endl;
					}
					else
					{
						break;
					}
					break;
				}
				}
				cout << "Do you want to continue ?" << endl;
				cin >> x;
			} while (x == 'y');
			break;
		}
		case 3:
		{
			exit(0);
			break;
		}
		}
	}
	return 0;
}