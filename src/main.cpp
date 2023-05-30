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
			UserInterface::UserMenu();
		}
		else
		{
			cout << "Not propper value you should repeat the try or exit programm."<< endl;
		}
		cout << "Repeat is programm y-yes / n - not:";
		cin >> choose;
		system("cls");
	} while (choose != 'n');


	


	return 0;
}
