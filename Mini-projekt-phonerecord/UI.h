#pragma once
#include "stdafx.h"
#include "Admin.h"

class UserInterface 
{
public:
	bool loginFlag = false;
	UserInterface() {}
	void AdminUI(PhoneBook* pb, UserChecker* uc)
	{
		bool optionFlag = true;
		Admin* admin = new Admin(pb, uc);
		std::string choosenOption;
		int option = 0;
		while(optionFlag)
		{ 
			std::cout << "------------------------------------------------------------------------------------" << std::endl;
			std::cout << "Possible options: " << std::endl;
			std::cout << "1. Add new record to phone book" << std::endl;
			std::cout << "2. Delete record from phone book by component (name or surname or number)" << std::endl;
			std::cout << "3. Delete whole record (will ask for confirmation)" << std::endl;
			std::cout << "4. Print out record of phone numbers" << std::endl;
			std::cout << "5. Manual save to .txt file" << std::endl;
			std::cout << "6. Load record from .txt file" << std::endl;
			std::cout << "7. Add new user" << std::endl;
			std::cout << "8. Add new admin" << std::endl;
			std::cout << "9. Delete user or admin by login" << std::endl;
			std::cout << "10. Log out" << std::endl;
			std::cout << "11. Quit" << std::endl;
			std::cout << "------------------------------------------------------------------------------------" << std::endl;
			std::cout << "Please choose: ";
			std::cin >> choosenOption;
			std::cout << "\n\n";
			try
			{
				option = std::stoi(choosenOption);
				if (option <= 0)
				{
					throw NegativeNumberException();
				}
			}
			catch (const std::invalid_argument& e)
			{
				option = 0;
				std::cerr << "\n\nInvalid Argument, please provide an int!\n\n " << std::endl;
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
			case 1:
			{
				std::string name, surname, country, number;
				std::cout << "Name: ";
				std::cin >> name;
				std::cout << "Surname: ";
				std::cin >> surname;
				std::cout << "Country: ";
				std::cin >> country;
				std::cout << "Number: ";
				std::cin >> number;
				admin->AddRecord(name, surname, country, number);
				std::cout << "\nRecord Added!\n" << std::endl;
				admin->SavePhoneBook(*pb, "C:\\Users\\Public\\PhoneRecord.txt");
				break;
			}
			case 2:
			{
				std::string info;
				std::cout << "Name or Surname or Number to be delted: ";
				std::cin >> info;
				admin->DeleteRecord(info);
				admin->SavePhoneBook(*pb, "C:\\Users\\Public\\PhoneRecord.txt");
				break;
			}
			case 3:
			{
				std::string choice;
				std::cout << "Are you sure? (yes/no)(y/n)" << std::endl;
				std::cin >> choice;
				try 
				{
					if (choice == "y" || choice == "yes") 
					{
						admin->DeleteDatabase();
						std::cout << "\n\nAll records deleted\n\n" << std::endl;
					}
					else if(choice == "n" || choice == "no")
					{
						break;
					}
					else 
					{
						throw InvalidStringException();

					}
				}
				catch(const InvalidStringException& e)
				{
					std::cout << e.what();
				}
				break;
			}
			case 4:
			{
				std::cout << "Please choose way of printing the phonebook" << std::endl;
				std::cout << "0. Print by index in vector" << std::endl;
				std::cout << "1. Print alphabetically by name" << std::endl;
				std::cout << "2. Print alphabetically by surname" << std::endl;
				std::cout << "3. Print alphabetically by country" << std::endl;
				std::cout << "Choice: ";
				std::cout << "\n\n";
				std::string ch;
				std::cin >> ch;
				admin->PrintPhoneBook(ch);
				break;
			}
			case 5:
			{
				admin->SavePhoneBook(*pb, "C:\\Users\\Public\\PhoneRecord.txt");
				std::cout << "Phone book saved in C:\\Users\\Public\\PhoneRecord.txt" << std::endl;
				break;
			}
			case 6:
			{
				admin->LoadPhoneBook(*pb, "C:\\Users\\Public\\PhoneRecord.txt");
				std::cout << "Phone book loaded from C:\\Users\\Public\\PhoneRecord.txt" << std::endl;
				break;
			}
			case 7:
			{
				std::string log, pas;
				std::cout << "New user login: ";
				std::cin >> log;
				std::cout << "New user paswword: ";
				std::cin >> pas;
				admin->AddUser(log, pas);
				break;
				
			}
			case 8:
			{
				std::string log, pas;
				std::cout << "New user login: ";
				std::cin >> log;
				std::cout << "New user paswword: ";
				std::cin >> pas;
				admin->AddAdmin(log, pas);
				break;
				break;
			}
			case 9:
			{
				std::string log;
				std::cout << "Login of user or admin to be deleted: ";
				std::cin >> log;
				admin->DeleteUser(log);
				break;
			}
			case 10:
			{
				delete(admin);
				loginFlag = false;
				optionFlag = false;
				break;
			}
			case 11:
			{
				delete(admin);
				loginFlag = true;
				optionFlag = false;
				break;
			}
			default:
			{
				std::cout << "\n\nPlease choose a valid option\n\n" << std::endl;
			}
			}
		}
			
		

	}
	void UserUI(PhoneBook* pb)
	{
		bool optionFlag = true;
		User* user = new User(pb);
		std::string choosenOption;
		int option = 0;
		while (optionFlag) 
		{
			std::cout << "------------------------------------------------------------------------------------" << std::endl;
			std::cout << "Possible options: " << std::endl;
			std::cout << "1. Print out the phone book" << std::endl;
			std::cout << "2. Load  from .txt file" << std::endl;
			std::cout << "3. Log out" << std::endl;
			std::cout << "4. Quit" << std::endl;
			std::cout << "------------------------------------------------------------------------------------" << std::endl;
			std::cout << "Please choose: ";
			std::cin >> choosenOption;
			std::cout << "\n\n";
			try
			{
				option = std::stoi(choosenOption);
				if (option <= 0)
				{
					throw NegativeNumberException();
				}
			}
			catch (const std::invalid_argument& e)
			{
				option = 0;
				std::cerr << "\n\n\n\Invalid Argument, please provide an int!\n\n\n " << std::endl;
			}
			catch (const NegativeNumberException& e)
			{
				option = 0;
				std::cout << e.what();
			}
			catch (const std::out_of_range& e)
			{
				std::cerr << "\nToo big number\n" << std::endl;
			}
			switch (option)
			{
			case 1:
			{
				std::cout << "Please choose way of printing the phonebook" << std::endl;
				std::cout << "0. Print by index in vector" << std::endl;
				std::cout << "1. Print alphabetically by name" << std::endl;
				std::cout << "2. Print alphabetically by surname" << std::endl;
				std::cout << "3. Print alphabetically by country" << std::endl;
				std::cout << "Choice: ";
				std::string ch;
				std::cin >> ch;
				user->PrintPhoneBook(ch);
				break;
			}
			case 2: 
			{
				user->LoadPhoneBook(*pb, "C:\\Users\\Public\\PhoneRecord.txt");
				break;
			}
			case 3:
			{

				delete(user);
				loginFlag = false;
				optionFlag = false;
				break;
			}
			case 4:
			{
				delete(user);
				loginFlag = true;
				optionFlag = false;
				break;
			}
			default:
			{
				std::cout << "\n\nPlease choose a valid option\n\n" << std::endl;
			}
			}
		}
	}
};