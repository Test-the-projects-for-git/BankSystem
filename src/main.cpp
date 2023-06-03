#include "../includes/bank.hpp"
using namespace SystemBank;
using namespace SecondaryFunction;

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

				if (checkPinCode(tmp.m_code))
				{
					FileManager::SaveUser(tmp);
				}
				else
				{
					cout << "The pin-code must be no less than and no more four digits." << endl;
				}

				
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
			string username = LoginUser::LoginAccaount();
			Account currentuser = FileManager::ReadUser(username);
			while (choose != 'n')
			{
				if (checkName(currentuser.m_nameuser))
				{
					cout << "Access is allowed" << endl;
				}
				else
				{
					cout << "In Access denny" << endl;
					break;
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
					/*Up balance here add function on verify propper input balance*/
					UserInterface::UpBalance(currentuser);
					if (checkBalance(currentuser.m_balance))
					{
						FileManager::ResaveUser(currentuser);
					}
					else
					{
						cout << "You balance not should be less zero or equal zero also great million" << endl;
					}

				}
				else if (act == '4')
				{
					/*Cash out balance similary how Up Balance*/
					int64_t tmp = UserInterface::CashOut(currentuser);
					if (SecondaryFunction::checkCashOut(tmp))
					{
						FileManager::ResaveUser(currentuser);
					}
					else
					{
						cout << "On your card not sufficient means! " << endl;
					}

				}
				else if (act == '5')
				{
					UserInterface::ViewBalance(currentuser);
				}
				else
				{
					cout << "Not propper input" << endl;
				}
				cout << "Repeat y/n";
				cin >> choose;
			}

		}
		else
		{
			cout << "Not propper input" << endl;
		}
		
		cout << "Y - repeat programm N - exit programm you choose:";
		cin >> choose;
		system("cls");
	} while (choose != 'n');


	return 0;
}
