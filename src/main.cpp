#include "../includes/bank.hpp"
using namespace SystemBank;

int main()
{
	/*Account tmp = ControlSystemAccount::addUser();
	FileManager::SaveUser(tmp);*/
	string ret  = LoginUser::LoginAccaount();
	FileManager::DeleteUser(ret);

	

	return 0;
}