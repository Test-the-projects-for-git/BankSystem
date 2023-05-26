#include "../includes/bank.hpp"
using namespace SystemBank;

int main()
{
	/*Account tmp = ControlSystemAccount::addUser();
	FileManager::SaveUser(tmp);*/
	FileManager::DeleteUser();

	return 0;
}