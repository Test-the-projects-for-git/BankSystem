#include<iostream>
#include<fstream>
#include<string>
#include<set>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ofstream;
using std::ifstream;
using std::string;
using std::set;


namespace SystemBank {

	typedef struct Account 
	{
		string m_nameuser;
		string m_familyuser;
		__int64 m_balance;
		__int16 m_code;
	}Account;

	class NonCopyble 
	{
	public:
		NonCopyble() = default;
	private:
		
		NonCopyble(const NonCopyble& other){}
		NonCopyble operator = (NonCopyble& other) { return *this; }
	};

	/*itself the system*/
	class ControlSystemAccount : private NonCopyble
	{
	public:
		static Account addUser();

	protected:
		ControlSystemAccount() = default;
	};

	/*file manager to work the users of bank*/
	class FileManager : private NonCopyble
	{
	public:
		static void SaveUser(const Account& acc);

		static void DeleteUser();

	private:
		static const char* extFile;
		FileManager() = default;
	};

}