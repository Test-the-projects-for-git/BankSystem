#include "../includes/bank.hpp"

const char* SystemBank::FileManager::extFile = ".txt";

SystemBank::Account SystemBank::ControlSystemAccount::addUser()
{
	Account tmp;
	cout << "Enter your name: ";
	cin >> tmp.m_nameuser;
	cout << "Enter yout family: ";
	cin >> tmp.m_familyuser;
	cout << "Come up with a four-digit pin code";
	cin >> tmp.m_code;
	tmp.m_balance = 0;
	cout << "A data was got!" << endl;
	return Account(tmp);
}

void SystemBank::FileManager::SaveUser(const SystemBank::Account& acc)
{
	ofstream outfile(acc.m_nameuser + extFile);

	if (outfile.is_open())
	{
		outfile << acc.m_nameuser << ' ' << acc.m_familyuser
			<< ' ' << acc.m_balance << ' ' << acc.m_code << endl;
		cout << "For log file was saved" << endl;
	}
	else
	{
		perror("Errof create file");
	}

	outfile.close();
}

void SystemBank::FileManager::DeleteUser()
{
	string name;
	cout << "Enter name User:";
	cin >> name;

	/*used rerecord then when access denied*/
	name.append(extFile);
	fstream infile(name, std::ios::out);

	if (infile.is_open())
	{
		cout << "such user exist" << endl;
		
		

		/*got error permission denied code not be work*/
		/*if (remove("name.txt") == 0)
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