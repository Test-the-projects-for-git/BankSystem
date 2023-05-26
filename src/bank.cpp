#include "../includes/bank.hpp"

string SystemBank::LoginUser::m_username;
string SystemBank::LoginUser::m_pin_code;

SystemBank::Account SystemBank::ControlSystemAccount::addUser()
{
	SystemBank::Account tmp;
	cout << "Enter your name: ";
	cin >> tmp.m_nameuser;
	cout << "Enter yout family: ";
	cin >> tmp.m_familyuser;
	cout << "Come up with a four-digit pin code";
	cin >> tmp.m_code;
	tmp.m_balance = 0;
	cout << "A data was got!" << endl;
	return tmp;
}

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
	fstream infile(nameuser, std::ios::out, std::ios::trunc);

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

string SystemBank::LoginUser::LoginAccaount()
{
	string  username, pin_code;

	cout << "Enter username: "; cin >> m_username;
	cout << "Enter password: "; cin >> m_pin_code;
	//????? ??? ? ??????
	ifstream read(m_username + ".txt");
	if (read.is_open())
	{
		//???? ??? ???
		getline(read, username);
		//???? ??? ???
		getline(read, pin_code);
		//?????? ????? ? ??????? ??? ??? ???
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