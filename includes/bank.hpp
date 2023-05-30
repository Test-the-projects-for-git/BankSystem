#include "headers.hpp"

namespace SystemBank {


	/*Struct Users*/
	typedef struct Account 
	{
		string m_nameuser;
		string m_familyuser;
		int64_t m_balance;
		int16_t m_code;
	}Account;

	/*Main menu*/
	void MainMenu(void);

	/*template for create single instance the class*/
	class NonCopyble {
	public:
		NonCopyble() = default;
	private:
		
		NonCopyble(const NonCopyble& other){}
		NonCopyble operator = (NonCopyble& other) { return *this; }
	};

	/*itself the system*/
	class ControlSystemAccount : private NonCopyble{
	public:
		static Account addUser();
		static void ServerMenu(void);
	private:
		ControlSystemAccount() = default;
	};

	/*file manager to work the users of bank*/
	class FileManager : private NonCopyble{
	public:
		
		static void SaveUser(const Account& acc);
		static Account ReadUser(const string& username);
		static void DeleteUser(const string& nameuser);
		static void ResaveUser(const Account& currentuser);
	private:
		FileManager() = default;
	};

	/*User login*/
	class LoginUser : private NonCopyble
	{
	public:
		static string LoginAccaount();
	private:
		static string m_username;
		static string m_pin_code;
	};

	class UserInterface : private NonCopyble {
	public:
		static void ShowData(const Account& currentUser);
		static void EditData(Account& currentUser);
		static void UserMenu(void);

	};

	/*secondary functions*/
	string saveName(const string& nameuser);

}