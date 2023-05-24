#include<iostream>
#include<fstream>
#include<string>
#include<set>

using std::cout;
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
		__int64 balance;
		__int16 code;
	}Account;

	class NonCopyble {
	public:
		NonCopyble() = default;
	private:
		
		NonCopyble(const NonCopyble& other){}
		NonCopyble operator = (NonCopyble& other){}
	};


	class ControlSystemAccount : private NonCopyble
	{
	public:
		static void test() { cout << "test\n"; }
	protected:
		ControlSystemAccount() = default;
	};
}

