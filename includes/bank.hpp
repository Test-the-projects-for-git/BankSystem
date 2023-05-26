#include "headers.hpp"

namespace SystemBank {

	typedef struct Account 
	{
		string m_nameuser;
		string m_familyuser;
		int64_t m_balance;
		int16_t m_code;
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



	private:
		ControlSystemAccount() = default;
	};

	/*file manager to work the users of bank*/
	class FileManager : private NonCopyble
	{
	public:
		
		static void SaveUser(const Account& acc);
		static void DeleteUser(const string& nameuser);
	private:
		FileManager() = default;
	};

	class LoginUser : private NonCopyble
	{
	public:
		friend FileManager;
		static string LoginAccaount();
	private:
		static string m_username;
		static string m_pin_code;
	};
}