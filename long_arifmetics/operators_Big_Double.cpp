#include "class_Big_Double.h"

std::istream &operator>>(std::istream &stream, Big_Double& number)
{
	std::string s_x;
	std::cin >> s_x;
	Big_Double::string_to_Big_Double(s_x, number);
	return stream;
}

std::ostream &operator<<(std::ostream & stream, const Big_Double &number)
{
	std::string s_x = "";
	Big_Double::Big_Double_to_string(s_x, number);
	stream << s_x;
	return stream;
}

Big_Double::Big_Double(const Big_Double &b)
{
	num = b.num;
	isNegative = b.isNegative;
	index_of_point = b.index_of_point;
	std::string s_x = "";
	Big_Double::Big_Double_to_string(s_x, *this);
	Big_Double::string_to_Big_Double(s_x, *this);
}

Big_Double::operator Big_Int()
{
	Big_Int b;
	b.num = num;
	b.isNegative = isNegative;
	return b;
}

Big_Double Big_Double::operator-() const
{
	Big_Double number = *this;
	number.isNegative = !number.isNegative;
	return number;
}

Big_Double Big_Double::operator-(const Big_Double & b)
{
	return *this + -b;
}

Big_Double Big_Double::operator+(const Big_Double& b)
{
	int point_first = index_of_point, point_second = b.index_of_point, max, point_delta;
	Big_Int a = (Big_Int)*this, c = (Big_Int)b;
	if (a == 0)
		return b;
	if (c == 0)
		return *this;
	if (point_first > point_second)
	{
		max = point_first;
		point_delta = max - point_second;
		for (int i = 0; i != point_delta; ++i)
			c *= 10;
	}
	else
	{
		max = point_second;
		point_delta = max - point_first;
		for (int i = 0; i != point_delta; ++i)
			a *= 10;
	}
	a += c;
	Big_Double result = a;
	result.index_of_point = max;
	return result;
}