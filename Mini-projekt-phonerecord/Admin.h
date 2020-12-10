#pragma once
#include "stdafx.h"
#include "User.h"
#include "UserChecker.h"
class Admin: public User {
private:
	UserChecker *uc;
public:

	void SavePhoneBook(const PhoneBook& p, std::string filename)
	{
		std::ofstream ofs(filename);
		boost::archive::text_oarchive oa(ofs);
		oa << p;
		ofs.close();
	}
	void AddRecord(std::string nam, std::string snam, std::string count, std::string num)
	{
		database->phoneBook.push_back(Record(nam, snam, count, num));
	}
	void DeleteRecord(std::string info) 
	{
		try 
		{
			int array[3] = { FindByName(info), FindBySurname(info), FindByNumber(info) };
			int false_arr[3] = { -1, -1, -1 };
			if (array[0] == false_arr[0] && array[1] == false_arr[1] && array[2] == false_arr[2])
			{
				throw NotFoundInPhoneBookException();
			}
			for (int i = 0; i < 3; i++)
			{
				if (array[i] != -1) {
					database->phoneBook.erase(database->phoneBook.begin() + array[i]);
					break;
				}
			}
			std::cout << "\nRecord Deleted!\n" << std::endl;
		}
		catch (const NotFoundInPhoneBookException& e)
		{
			std::cout << e.what();
		}
	}
	void DeleteDatabase() 
	{
		database->phoneBook.clear();
	}

	void AddUser(std::string login, std::string password) 
	{
		try
		{
			if (LoginIsTaken(login)) 
			{
				throw LoginTakenException();
			}
			else 
			{
				user tmp = { login, password, false };
				uc->users.push_back(tmp);
				std::cout << "\n\nUser added\n\n" << std::endl;
			}
		}
		catch(const LoginTakenException& e)
		{
			std::cout << e.what();
		}
	}

	void AddAdmin(std::string login, std::string password)
	{
		try
		{
			if (LoginIsTaken(login))
			{
				throw LoginTakenException();
			}
			else
			{
				user tmp = { login, password, true };
				uc->users.push_back(tmp);
				std::cout << "\n\nAdmin added\n\n" << std::endl;
			}
		}
		catch (const LoginTakenException& e)
		{
			std::cout << e.what();
		}
	}

	void DeleteUser(std::string login) 
	{
		try
		{
			if (login == "admin")
			{
				throw DefaultAdminException();
			}
			else if (login == "user") 
			{
				throw DefaultUserException();
			}
			else {
				int index = FindUserByName(login);
				if (index != -1)
				{
					uc->users.erase(uc->users.begin() + index);
				}
				else
				{
					throw InvalidLoginException();
				}
			}
		}
		catch (const InvalidLoginException& e)
		{
			std::cout << e.what();
		}
		catch (const DefaultUserException& e)
		{
			std::cout << e.what();
		}
		catch (const DefaultAdminException& e) 
		{
			std::cout << e.what();
		}
	}

	Admin(PhoneBook* phoneBook, UserChecker* ur) :User(phoneBook) { uc = ur; }

private:
	int FindUserByName(std::string login) 
	{
		auto it = std::find_if(uc->users.begin(), uc->users.end(), [login](const user& u) { return u.login == login; });
		if (it != uc->users.end()) 
		{
			return std::distance(uc->users.begin(), it);
		}
		else 
		{
			return -1;
		}
	}

	bool LoginIsTaken(std::string login) 
	{
		auto it = std::find_if(uc->users.begin(), uc->users.end(), [login](const user& u) { return u.login == login; });
		if (it != uc->users.end())
		{
			return true;
		}
		else
		{
			return false;;
		}
	}

	int FindByName(std::string name) 
	{
		auto it = std::find_if(database->phoneBook.begin(), database->phoneBook.end(), [name](const Record& u) { return u.name == name; });
		if (it != database->phoneBook.end())
		{
			return std::distance(database->phoneBook.begin(), it);
		}
		else
		{
			return -1;
		}
	}

	int FindBySurname(std::string surname) 
	{
		auto it = std::find_if(database->phoneBook.begin(), database->phoneBook.end(), [surname](const Record& u) { return u.surname == surname; });
		if (it != database->phoneBook.end())
		{
			return std::distance(database->phoneBook.begin(), it);
		}
		else
		{
			return -1;
		}
	}

	int FindByNumber(std::string number) 
	{
		auto it = std::find_if(database->phoneBook.begin(), database->phoneBook.end(), [number](const Record& u) { return u.number == number; });
		if (it != database->phoneBook.end())
		{
			return std::distance(database->phoneBook.begin(), it);
		}
		else
		{
			return -1;
		}
	}
};