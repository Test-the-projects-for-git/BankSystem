#include "../includes/bank.hpp"
using namespace SystemBank;

int main()
{
	/*Account tmp = ControlSystemAccount::addUser();
	FileManager::SaveUser(tmp);*/
	
	string ret = LoginUser::LoginAccaount();
	Account tmp = ControlSystemAccount::readUser(ret);
	UserInterface::ShowData(tmp);
	UserInterface::EditData(tmp);
	FileManager::SaveUser(tmp);

	return 0;
}