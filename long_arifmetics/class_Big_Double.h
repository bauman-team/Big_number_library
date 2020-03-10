#pragma once
#include "class_Big_Int.h"

class Big_Double : public Big_Int
{
	unsigned int index_of_point;
public:
	Big_Double() : Big_Int()
	{
		index_of_point = 0;
	};
	Big_Double(Big_Int &b)
	{
		num = b.num;
		isNegative = b.isNegative;
		index_of_point = 0;
	}
	Big_Double(const Big_Double&);

	operator Big_Int();

	friend std::istream &operator>>(std::istream &stream, Big_Double&);
	friend std::ostream &operator<<(std::ostream &stream, const Big_Double&);
	static void string_to_Big_Double(std::string, Big_Double&);
	static void Big_Double_to_string(std::string&, const Big_Double&);

	Big_Double operator-() const;
	Big_Double operator-(const Big_Double&);
	Big_Double operator+(const Big_Double&);
};