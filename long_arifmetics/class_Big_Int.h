#pragma once

#define typeint template<class T, class = enable_if_t<is_same<T, int>::value || is_same<T, long long>::value || is_same<T, long>::value || is_same<T, short>::value || is_same<T, unsigned int>::value || is_same<T, unsigned long long>::value || is_same<T, unsigned long>::value || is_same<T, unsigned short>::value>>

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Big_Int
{
private:
	vector <int> num;
	bool isNegative = false; // может переместить в конструктор?
	static void string_to_big_number(Big_Int&, string);
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
public:
	Big_Int(){}
	Big_Int(int b)
	{
		*this = b;
	}

	friend ostream& operator<< (ostream&, const Big_Int&);
	friend istream& operator>> (istream&,		Big_Int&);

	Big_Int operator+ (Big_Int);
	Big_Int operator- (Big_Int);
	Big_Int operator* (Big_Int);
	Big_Int operator/ (Big_Int);

	Big_Int operator++ ();		// ++Big_Int
	Big_Int operator--();		// --Big_Int
	Big_Int operator++ (int);	// Big_Int++
	Big_Int operator-- (int);	// Big_Int--
	Big_Int operator- ();
	
	void operator=		(const Big_Int&);
	Big_Int& operator+= (const Big_Int&);
	Big_Int& operator-=	(const Big_Int&);
	
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
	void operator= (T n)
	{
		*this = int_to_big_number(n);
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