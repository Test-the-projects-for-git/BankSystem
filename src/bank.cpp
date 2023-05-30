#include "../includes/bank.hpp"

/*Defined Varibles of classes and other varibles*/
string SystemBank::LoginUser::m_username;
string SystemBank::LoginUser::m_pin_code;

uint8_t choose = '0';
uint8_t act = '0';

/*Functions to communication with Main System*/
SystemBank::Account SystemBank::ControlSystemAccount::addUser()
{
	SystemBank::Account tmp;
	cout << "Enter your name: ";
	cin >> tmp.m_nameuser;
	cout << "Enter yout family: ";
	cin >> tmp.m_familyuser;
	cout << "Come up with a four-digit pin code: ";
	cin >> tmp.m_code;
	tmp.m_balance = 0;
	cout << "The data was got!" << endl;
	return tmp;
}


void SystemBank::ControlSystemAccount::ServerMenu()
{
	cout << "1. add user" << endl;
	cout << "2. delete user" << endl;
}

SystemBank::Account SystemBank::FileManager::ReadUser(const string& username)
{
	Account tmp;
	ifstream infile(username);
	if (infile.is_open())
	{
		infile >> tmp.m_nameuser >> tmp.m_code >> tmp.m_familyuser >> tmp.m_balance;
	}
	else
	{
		cout << "Error read the file!" << endl;
	}

	infile.close();

	return tmp;
}


/*Here FileManager for store data and delete and e t c*/
void SystemBank::FileManager::SaveUser(const Account& acc)
{
	ofstream outfile(acc.m_nameuser + ".txt");

	if (outfile.is_open())
	{
		outfile << acc.m_nameuser << endl << acc.m_code
			<< endl << acc.m_familyuser << endl << acc.m_balance << endl;
		cout << "For log file was saved" << endl;
	}
	else
	{
		perror("Errof create file");
	}

	outfile.close();
}

void SystemBank::FileManager::DeleteUser(const string& nameuser)
{
	/*we to truncate file if function remove not be worked*/
	fstream infile(nameuser + ".txt", std::ios::out, std::ios::trunc);

	if (infile.is_open())
	{
		cout << "such user exist deleting pass success" << endl;

		/*here expect got access denied*/
		/*if (remove(nameuser + extFile) == 0)
		{
			cout << "account was deleted" << endl;
		}
		else
		{
			perror("Error delete a user \n");
		}*/
	}
	else
	{
		cout << "file not may be open" << endl;
	}

	infile.close();

}

void SystemBank::FileManager::ResaveUser(const Account& currentuser)
{
	ofstream reoutfile(currentuser.m_nameuser + ".txt", std::ios::out);

	if (reoutfile.is_open())
	{
		cout << "The file was open with success" << endl;

		reoutfile << currentuser.m_nameuser << endl
			<< currentuser.m_code << endl
			<< currentuser.m_familyuser << endl
			<< currentuser.m_balance << endl;

		cout << "Data is changed" << endl;
	}
	else
	{
		cout << "Error changed the data" << endl;
	}

	reoutfile.close();
}

/*System to access to users*/
string SystemBank::LoginUser::LoginAccaount()
{
	string  username, pin_code;

	cout << "Enter your name: "; cin >> m_username;
	cout << "Enter your pin code: "; cin >> m_pin_code;
	ifstream read(m_username + ".txt");
	if (read.is_open())
	{
		getline(read, username);
		getline(read, pin_code);
		if (username == m_username && pin_code == m_pin_code)
		{
			return m_username + ".txt";
		}
		else
		{
			return "";
		}
	}
	else
	{
		cout << "Error openning a file" << endl;
	}

	return "";
}

/*User interface*/

void SystemBank::UserInterface::ShowData(const Account& currentUser)
{
	cout << "You name: " << currentUser.m_nameuser << endl
		<< "You code: " << currentUser.m_code << endl
		<< "You family: " << currentUser.m_familyuser << endl
		<< "Your balance: " << currentUser.m_balance << endl;
}

void SystemBank::UserInterface::EditData(Account& currentUser)
{
	cout << "Change your name." << endl;
	cin >> currentUser.m_nameuser;
	cout << "Change your family." << endl;
	cin >> currentUser.m_familyuser;
	cout << "Change your pin - code" << endl;
	cin >> currentUser.m_code;

	cout << "Data was changed" << endl;
}

void SystemBank::UserInterface::UserMenu()
{
	cout << "1-Show info about an account" << endl
		<< "2-Change info of an account" << endl
		<< "3-top up card balance" << endl
		<< "4-cash out balance" << endl
		<< "5-sum deposit" << endl;
}


/*function wich to save name user*/
string SystemBank::saveName(const string& username)
{
	return username;
}

/*Main Menu of the programm*/
void SystemBank::MainMenu(void)
{
	cout << "1. Server" << endl;
	cout << "2. Client" << endl;
}