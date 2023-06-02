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
	cin >> tmp.m_code;	/*here need add check proper enter the pin-code*/
	tmp.m_balance = 0;
	cout << "The data was got by now going check!" << endl;
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
		cout << "Error read an user" << endl;
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
	}
	else
	{
		perror("Errof save user");
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
	string  username;
	string pin_code;

	cout << "Enter your name: "; cin >> m_username;
	cout << "Enter your pin code: "; cin >> m_pin_code;

	if (SecondaryFunction::checkPinCode(m_pin_code))
	{
		cout << "ok" << endl;
	}
	else
	{
		cout << "not ok" << endl;
	}

	

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
		cout << "Access is denny repeat try" << endl;
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

void SystemBank::UserInterface::ViewBalance(const Account& currentUser)
{
	cout << "Your balance: " << currentUser.m_balance << endl;
}

void SystemBank::UserInterface::EditData(Account& currentUser)
{
	cout << "Change your name: ";
	cin >> currentUser.m_nameuser;
	cout << "Change your family: ";
	cin >> currentUser.m_familyuser;
	cout << "Change your pin - code: ";
	cin >> currentUser.m_code;	/*check pin-code*/

	cout << "Data was changed" << endl;
}

void SystemBank::UserInterface::UpBalance(Account& currentUser)
{
	cout << "Input the summ you want to deposit: ";
	cin >> currentUser.m_balance;	/*check negative value*/
	cout << "Done" << endl;
}

int64_t SystemBank::UserInterface::CashOut(Account& currentUser)
{
	size_t tmp;
	cout << "Input the summ you want take off: ";
	cin >> tmp;
	currentUser.m_balance = currentUser.m_balance - tmp;	/*check negative value*/
	cout << "Done" << endl;
	return currentUser.m_balance;
}

void SystemBank::UserInterface::UserMenu()
{
	cout << "1-Show info about an account" << endl
		<< "2-Change info of an account" << endl
		<< "3-top up card balance" << endl
		<< "4-cash out balance" << endl
		<< "5-View your balance" << endl << endl;
	cout << "Your choose: ";
}


/*function wich to save name user*/
string SecondaryFunction::saveName(const string& username)
{
	return username;
}

/*Main Menu of the programm*/
void SecondaryFunction::MainMenu(void)
{
	cout << "1. Server" << endl;
	cout << "2. Client" << endl;
}

/*check propper the name user*/
bool SecondaryFunction::checkName(const string& name)
{
	return (name == "") ? false : true;
}

bool SecondaryFunction::checkPinCode(const string& pincode)
{
	if (pincode.size() < TO_CODE || pincode.size() > TO_CODE)
	{
		return false;
	}
	else
	{
		for (size_t i = 0; i < pincode.size(); i++)
		{
			if (pincode[i] < ZERO || pincode[i] > NINE) return false;
		}
	}
	
	return true;
}

bool SecondaryFunction::checkBalance(const int64_t& balance)
{
	return (balance <= ZERO || balance > MILLION) ? false : true;
}

bool SecondaryFunction::checkCashOut(const int64_t& balance)
{
	return (balance < ZERO) ? false : true;
}