#pragma once
#include "stdafx.h"
struct user
{
public:
	std::string login;
	std::string password;
	bool admin;
};

class UserChecker 
{
public:
	std::vector<user> users;
	UserChecker() {}

	bool Login()
	{
		bool loggedAdmin = NULL;
		bool logged = false;
		while (!logged)
		{
			std::string login, password;
			std::cout << "Login: ";
			std::cin >> login;
			std::cout << "Password: ";
			std::cin >> password;
			std::cout << std::endl;
			loggedAdmin = CheckLoginCredit(login, password);
			if (loggedAdmin == 1 || loggedAdmin == 0) {
				loggedAdmin ? std::cout << "\nLOGGED AS ADMIN\n\n" << std::endl : std::cout << "\nLOGGED AS USER\n\n" << std::endl;
				return loggedAdmin;
			}
		}
	}
	void InitUsers() 
	{
		user default_admin = { "admin", "admin", true };
		user default_user = { "user", "user", false };
		users.push_back(default_admin);
		users.push_back(default_user);
	}
private:
	bool CheckLoginCredit(std::string log, std::string pass) 
	{
		auto it = std::find_if(users.begin(), users.end(), [log](const user& u) { return u.login == log; });
		try {
			if (it != users.end()) 
			{
				auto index = std::distance(users.begin(), it);
				return CheckPassword(pass, index);
			}
			else
			{
				throw InvalidLoginException();
			}
		}
		catch(InvalidLoginException e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	bool CheckPassword(std::string pass, int  index) 
	{
		bool isAdmin = NULL;
		try 
		{
			if (users.at(index).password == pass)
			{
				isAdmin = CheckAdminPermission(index);
				return isAdmin;
			}
			else 
			{
				throw InvalidPasswordException();
			}
		}
		catch (InvalidPasswordException e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	bool CheckAdminPermission(int index) 
	{
		if (users.at(index).admin == true) 
		{
			return true;
		}
		return false;
	}
};