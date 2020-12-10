#pragma once
#include "stdafx.h"
#include "Record.h"
class PhoneBook
{

private:
	friend class boost::serialization::access;
public:
	std::vector<Record> phoneBook;
	PhoneBook() {};
	template<class Archive>
	void serialize(Archive& a, const unsigned int version) {
		a& phoneBook;
	}
};
