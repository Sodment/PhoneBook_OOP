#pragma once
#include "stdafx.h"
struct InvalidLoginException : public std::exception
{
	const char* what() const throw() {
		return "Invalid Login\n";
	}
};

struct InvalidPasswordException : public std::exception
{
	const char* what() const throw() {
		return "Invalid Password\n";
	}
};

struct NegativeNumberException : public std::exception
{
	const char* what() const throw() {
		return "\n\nNon positive number found\n\n";
	}
};

struct InvalidStringException : public std::exception
{
	const char* what() const throw() {
		return "\n\nIncorrect string found\n\n";
	}
};

struct LoginTakenException : public std::exception
{
	const char* what() const throw() {
		return "\n\nThis login is taken\n\n";
	}
};

struct DefaultAdminException : public std::exception
{
	const char* what() const throw() {
		return "\n\nCant modify default admin\n\n";
	}
};

struct DefaultUserException : public std::exception
{
	const char* what() const throw() {
		return "\n\nCant modify default user\n\n";
	}
};

struct NotFoundInPhoneBookException : public std::exception
{
	const char* what() const throw() {
		return "\n\nCant find this element in phonebook\n\n";
	}
};