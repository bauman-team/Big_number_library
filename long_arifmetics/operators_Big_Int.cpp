#include "class_Big_Int.h"

ostream& operator<< (ostream &out, Big_Int number)
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

istream& operator>> (istream &in, Big_Int& number)
{
	string s_x;
	cin >> s_x;
	number.num.erase(number.num.begin(), number.num.end());
	number.isNegative = false;
	Big_Int::string_to_big_number(number, s_x);
	return in;
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

bool Big_Int::operator!=(Big_Int b)
{
	if (*this == b)
		return false;
	return true;
}

Big_Int Big_Int::operator-= (const Big_Int &b)
{
	*this = *this - b;
	return *this;
}

bool Big_Int::operator!=(int n)
{
	if (*this == n)
		return false;
	return true;
}

bool Big_Int::operator<=(Big_Int b)
{
	if (*this < b || *this == b)
		return true;
	return false;
}

bool Big_Int::operator>=(Big_Int b)
{
	if (*this > b || *this == b)
		return true;
	return false;
}

Big_Int Big_Int::operator/(Big_Int b)
{
	if (b == 0)
		throw;
	return division(*this, b);
}

Big_Int Big_Int::operator--()
{
	*this = *this - 1;
	return *this;
}

Big_Int Big_Int::operator--(int)
{
	*this = *this - 1;
	return *this + 1;
}

Big_Int Big_Int::operator-(int b)
{
	Big_Int c;
	int_to_big_number(c, b);
	return *this - c;
}

bool Big_Int::operator>=(int b)
{
	if (!(*this < b))
		return true;
	return false;
}

bool Big_Int::operator<=(int b)
{
	if (!(*this > b))
		return true;
	return false;
}

bool Big_Int::operator>(int b)
{
	Big_Int c;
	int_to_big_number(c, b);
	return *this > c;
}

bool Big_Int::operator<(int b)
{
	if (*this > b || *this == b)
		return false;
	return true;
}

Big_Int Big_Int::operator++ () // ++Big_Int
{
	*this = *this + 1;
	return *this;
}

Big_Int Big_Int::operator+(Big_Int b)
{
	return summator(*this, b);
}

Big_Int Big_Int::operator-(Big_Int b)
{
	return subtraction(*this, b);
}

Big_Int Big_Int::operator+(int n)
{
	Big_Int c;
	int_to_big_number(c, n);
	return *this + c;
}

Big_Int & Big_Int::operator+=(const Big_Int & b)
{
	*this = *this + b;
	return *this;
}

Big_Int& Big_Int::operator+=(int n)
{
	*this = *this + n;
	return *this;
}

void Big_Int::operator=(const Big_Int & b)
{
	this->num = b.num; // ?
	this->isNegative = b.isNegative;
}

void Big_Int::operator=(int n)
{
	Big_Int c;
	int_to_big_number(c, n);
	*this = c;
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

bool Big_Int::operator==(int b)
{
	Big_Int c;
	c = b;
	if (c == *this)
		return true;
	return false;
}

bool Big_Int::operator>(const Big_Int & b)
{
	if (this->isNegative != b.isNegative)
	{
		if (this->isNegative)
			return false;
		return true;
	}
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
	if (*this > b)
		return false;
	if (*this == b)
		return false;
	return true;
}