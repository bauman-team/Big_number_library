#pragma once

#define typeint template<class T, class = std::enable_if_t< \
		   std::is_same<T, int>					::value \
		|| std::is_same<T, long long>			::value \
		|| std::is_same<T, long>				::value \
		|| std::is_same<T, short>				::value \
		|| std::is_same<T, unsigned int>		::value \
		|| std::is_same<T, unsigned long long>	::value \
		|| std::is_same<T, unsigned long>		::value \
		|| std::is_same<T, unsigned short>		::value >>

#include <iostream>
#include <vector>
#include <string>

class Big_Double;
class Big_Int
{
protected:
	std::vector <int> num;
	bool isNegative = false;
	
	friend Big_Double;
	template <class T>
	static void string_to_big_number(T&, std::string);
	typeint
	static Big_Int int_to_big_number(T i_x)
	{
		Big_Int number;
		do
		{
			number.num.push_back(i_x % 1'000'000'000);
			i_x /= 1'000'000'000;
		} while (i_x);
		return number;
	}
	static Big_Int abs			(Big_Int);
	static Big_Int multiple		(Big_Int, Big_Int);
	static Big_Int summator		(Big_Int, Big_Int);
	static Big_Int subtraction	(Big_Int, Big_Int);
	static Big_Int division		(Big_Int, Big_Int);
	static bool is_valid_format (std::string);
public:
	Big_Int() {}
	typeint
	Big_Int(T n)
	{
		*this = n;
	}
	Big_Int(const char *n)
	{
		*this = n;
	}

	friend std::ostream& operator<< (std::ostream&, const Big_Int&);
	friend std::istream& operator>> (std::istream&,		  Big_Int&);

	Big_Int operator+ (Big_Int);
	Big_Int operator- (Big_Int);
	Big_Int operator* (Big_Int);
	Big_Int operator/ (Big_Int);

	Big_Int operator++ ();		// ++Big_Int
	Big_Int operator--();		// --Big_Int
	Big_Int operator++ (int);	// Big_Int++
	Big_Int operator-- (int);	// Big_Int--
	Big_Int operator- ();
	
	Big_Int& operator+= (const Big_Int&);
	Big_Int& operator-=	(const Big_Int&);
	Big_Int& operator*= (const Big_Int&);
	Big_Int& operator/= (const Big_Int&);
	
	Big_Int operator=	(const Big_Int&);
	Big_Int operator=	(const char*);
	bool operator>	(const Big_Int&);
	bool operator<	(const Big_Int&);
	bool operator<= (const Big_Int&);
	bool operator>= (const Big_Int&);
	bool operator== (const Big_Int&);
	bool operator!= (const Big_Int&);
	
	typeint
	Big_Int operator+ (T n)
	{
		return *this + int_to_big_number(n);
	}
	typeint
		Big_Int operator-(T n)
	{
		return *this - int_to_big_number(n);
	}
	typeint
	Big_Int operator= (T n)
	{
		*this = int_to_big_number(n);
		return *this;
	}
	typeint
	Big_Int& operator+= (T n)
	{
		*this = *this + n;
		return *this;
	}
	typeint
	Big_Int& operator-= (T n)
	{
		*this = *this - n;
		return *this;
	}
	typeint
	Big_Int& operator*=(T n)
	{
		*this = *this * n;
		return *this;
	}
	typeint
	Big_Int& operator/=(T n)
	{
		*this = *this / n;
		return *this;
	}
	typeint
	bool operator== (T n)
	{
		return (*this == int_to_big_number(n)) ? true : false;
	}
	typeint
	bool operator!= (T n)
	{
		return (*this == n) ? false : true;
	}
	typeint
	bool operator>= (T n)
	{
		return (*this < n) ? false : true;
	}
	typeint
	bool operator<= (T n)
	{
		return (*this > n) ? false : true;
	}
	typeint
	bool operator> (T n)
	{
		return *this > int_to_big_number(n);
	}
	typeint
	bool operator< (T n)
	{
		return *this < int_to_big_number(n);
	}
};

template<class T>
inline void Big_Int::string_to_big_number(T & number, std::string s_x)
{
	if (s_x[0] == '-')
	{
		number.isNegative = true;
		s_x.erase(0, 1);
	}
	while (s_x[0] == '0' && s_x.size() != 1 && typeid(number).name() == const_cast<const char*> ("Big_Int"))
		s_x.erase(0, 1);
	for (int i = s_x.size(); i > 0; i -= 9)
	{
		if (i >= 9)
			number.num.push_back(atoi(s_x.substr(i - 9, 9).c_str()));
		else
			number.num.push_back(atoi(s_x.substr(0, i).c_str()));
	}
	if (number.num.size() == 1 && number.num[0] == 0)
		number.isNegative = false;
}
