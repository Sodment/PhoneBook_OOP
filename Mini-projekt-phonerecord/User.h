#pragma once
#include "stdafx.h"
#include "PhoneBook.h"
class User{
public:
	PhoneBook* database;

	void LoadPhoneBook(PhoneBook& p, std::string filename)
	{
		std::ifstream ifs(filename);
		boost::archive::text_iarchive ia(ifs);
		ia >> p;
		ifs.close();
	}

	void PrintPhoneBook(std::string choice) 
	{
		std::vector<Record> copy(database->phoneBook);
		int option;
		try
		{
			option = std::stoi(choice);
			if (option < 0)
			{
				throw NegativeNumberException();
			}
		}
		catch (const std::invalid_argument& e)
		{
			option = 0;
			std::cerr << "\n\nInvalid Argument, please provide an int!\n\n" << std::endl;
		}
		catch (const NegativeNumberException& e)
		{
			option = 0;
			std::cout << e.what();
		}
		catch (const std::out_of_range& e)
		{
			option = 0;
			std::cerr << "\nToo big number\n" << std::endl;
		}
		switch (option) 
		{
		case 0:
		{
			int i = 0;
			for (auto& record : copy)
			{
				std::cout << "Record index: " << i << std::endl;
				std::cout << record << std::endl;
				i++;
			}
			break;
		}
		case 1: 
		{
			std::sort(copy.begin(), copy.end(), sortByName);
			Print(copy);
			break;
		}
		case 2:
		{
			std::sort(copy.begin(), copy.end(), sortBySurname);
			Print(copy);
			break;
		}
		case 3:
		{
			std::sort(copy.begin(), copy.end(), sortByCountry);
			Print(copy);
			break;
		}
		default: 
		{
			std::cout << "\n\nPlease give a valid option\n\n" << std::endl;
		}
		}
	}

	User(PhoneBook* phoneBook) { database = phoneBook; }
protected:
	std::string username;
	std::string password;
};

