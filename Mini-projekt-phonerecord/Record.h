#pragma once
#include "stdafx.h"
#include "MyExceptionsk.h"
class Record 
{
public:
	std::string name, surname, country, number;
	Record() {};
	Record(std::string nam, std::string snam, std::string count, std::string num) {
		name = nam, surname = snam, country = count, number = num;
	}
	template<class Archive>
	void serialize(Archive& a, const unsigned int version) {
		a& name& surname& country& number;
	}
};

std::ostream& operator <<(std::ostream& stream, const Record& record)
{
	return stream << "Name: " << record.name << "\n" << "Surname: " << record.surname << "\n" << "Country: " << record.country << "\n" << "Number: " << record.number << std::endl;
}

void Print(std::vector<Record> v)
{
	for (auto& record : v)
	{
		std::cout << record << std::endl;
	}
}
bool sortByName(const Record& r1, const Record& r2) { return r1.name < r2.name; }
bool sortBySurname(const Record& r1, const Record& r2) { return r1.surname < r2.surname; }
bool sortByCountry(const Record& r1, const Record& r2) { return r1.country < r2.country; }
