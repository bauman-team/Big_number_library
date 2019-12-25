#include "class_Big_Int.h"

std::ostream& operator<< (std::ostream &out, const Big_Int& number)
{
	if (number.isNegative)
		out << '-';
	for (int i = number.num.size() - 1; i >= 0; i--)
	{
		int buffer = 100'000'000;
		if (i != number.num.size() - 1)
			while (buffer > number.num[i] && buffer)
			{
				out << 0;
				buffer /= 10;
			}
		if (buffer)
			out << number.num[i];
	}
	return out;
}

std::istream& operator>> (std::istream &in, Big_Int& number)
{
	std::string s_x;
	std::cin >> s_x;
	if (!Big_Int::is_valid_format(s_x))
		throw std::exception("Invalid number!");
	if (s_x.find('.') != std::string::npos)
		s_x.erase(s_x.find('.'));
	number.num.clear();
	number.isNegative = false;
	Big_Int::string_to_big_number(number, s_x);
	return in;
}

Big_Int Big_Int::operator+(Big_Int b)
{
	return summator(*this, b);
}

Big_Int Big_Int::operator-(Big_Int b)
{
	return subtraction(*this, b);
}

Big_Int Big_Int::operator++ (int) // Big_Int++
{
	*this = *this + 1;
	return *this - 1;
}

Big_Int Big_Int::operator- ()
{
	Big_Int c = *this;
	if (c != 0)
		c.isNegative = !c.isNegative;
	return c;
}

Big_Int Big_Int::operator/(Big_Int b)
{
	if (b == 0)
		throw std::exception("Division by zero!");
	return division(*this, b);
}

Big_Int Big_Int::operator--()
{
	*this = *this - 1;
	return *this;
}

Big_Int Big_Int::operator*(Big_Int b)
{
	Big_Int c;
	if (abs(*this) < abs(b))
		c = multiple(abs(*this), abs(b));
	else
		c = multiple(abs(b), abs(*this));
	if (this->isNegative != b.isNegative)
		c = -c;
	return c;
}

Big_Int& Big_Int::operator+=(const Big_Int& b)
{
	*this = *this + b;
	return *this;
}

void Big_Int::operator=(const Big_Int& b)
{
	this->num = b.num; // ?
	this->isNegative = b.isNegative;
}

Big_Int& Big_Int::operator-= (const Big_Int& b)
{
	*this = *this - b;
	return *this;
}

Big_Int& Big_Int::operator*=(const Big_Int& b)
{
	*this = *this * b;
	return *this;
}

Big_Int& Big_Int::operator/=(const Big_Int& b)
{
	*this = *this / b;
	return *this;
}

bool Big_Int::operator<=(const Big_Int& b)
{
	return (*this > b) ? false : true;
}

bool Big_Int::operator>=(const Big_Int& b)
{
	return (*this < b) ? false : true;
}

bool Big_Int::operator==(const Big_Int & b)
{
	if (this->isNegative != b.isNegative)
		return false;

	if (this->num.size() != b.num.size())
		return false;

	for (int i = 0; i < b.num.size(); i++)
		if (this->num[i] != b.num[i])
			return false;

	return true;
}

bool Big_Int::operator>(const Big_Int & b)
{
	if (this->isNegative != b.isNegative)
		return (this->isNegative) ? false : true;

	if (this->num.size() != b.num.size())
	{
		if (this->isNegative && (this->num.size() > b.num.size()))
			return false;
		if (!this->isNegative && (this->num.size() < b.num.size()))
			return false;
		return true;
	}

	for (int i = this->num.size() - 1; i >= 0; i--)
		if (this->num[i] > b.num[i])
			return !b.isNegative;
		else if (this->num[i] < b.num[i])
			return b.isNegative;
	return false;
}

bool Big_Int::operator< (const Big_Int& b)
{
	return ((*this > b) || (*this == b)) ? false : true;
}

bool Big_Int::operator!=(const Big_Int& b)
{
	return (*this == b) ? false : true;
}

Big_Int Big_Int::operator++ () // ++Big_Int
{
	*this = *this + 1;
	return *this;
}

Big_Int Big_Int::operator--(int)
{
	*this = *this - 1;
	return *this + 1;
}