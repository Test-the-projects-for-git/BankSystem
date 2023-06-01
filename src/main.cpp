#include "../includes/bank.hpp"
using namespace SystemBank;

extern uint8_t choose;
extern uint8_t act;

int main()
{
	

	do
	{
		MainMenu();
		
		cin >> act;
		if (act == '1') /*Server portion*/
		{
			ControlSystemAccount::ServerMenu();
			cin >> act;
			if (act == '1')	/*Add User*/
			{
				Account tmp = ControlSystemAccount::addUser();
				FileManager::SaveUser(tmp);
			}
			else if (act == '2')	/*Delete User*/
			{
				string username = LoginUser::LoginAccaount();
				if (username != "")
				{
					FileManager::DeleteUser(username);
				}
				else
				{
					cout << "Of an user such name not exist" << endl;
				}
			}
		}
		else if (act == '2')	/*Client portion*/
		{
			/*Login user and check user*/
			cout << "For entry into account record input your name and pin code" << endl;

			string username  = LoginUser::LoginAccaount();
			Account currentuser  = FileManager::ReadUser(username);

			if (checkName(currentuser.m_nameuser))
			{
				cout << "Access is allowed"<<endl;
			}
			else
			{
				cout << "In Access denny" << endl;
				main();
			}

			/*UserMenu*/
			UserInterface::UserMenu();
			cin >> act;
			if (act == '1')
			{

				UserInterface::ShowData(currentuser);	/*Show data*/
			}
			else if (act == '2')
			{
				string othername = saveName(currentuser.m_nameuser);
				UserInterface::EditData(currentuser);	/*Edit data*/
				FileManager::ResaveUser(currentuser);
				FileManager::DeleteUser(othername);
			}
			else if (act == '3')
			{
				/*Up balance*/
				UserInterface::UpBalance(currentuser);
				FileManager::ResaveUser(currentuser);
			}
			else if (act == '4')
			{
				UserInterface::CashOut(currentuser);
				FileManager::ResaveUser(currentuser);
			}
		}
		else
		{
			cout << "Not propper value you should repeat try or exit programm."<< endl;
		}
		cout << "Repeat is programm y-yes / n - not:";
		cin >> choose;
		system("cls");
	} while (choose != 'n');


	return 0;
}
