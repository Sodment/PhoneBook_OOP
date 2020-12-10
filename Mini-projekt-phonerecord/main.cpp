#pragma warning(disable : 4996)
#include "stdafx.h"
#include "UI.h"

int main() 
{
	UserChecker* userChecker = new UserChecker();;
	UserInterface ui;
	PhoneBook* pb = new PhoneBook();
	userChecker->InitUsers();
	while (!ui.loginFlag) 
	{
		switch (userChecker->Login()) 
		{
		case 0: 
		{
			ui.UserUI(pb);
			break;
		}
		case 1:
		{
			ui.AdminUI(pb, userChecker);
			break;
		}
		}
	}
	delete(userChecker);
	delete(pb);
	return 0;
}
