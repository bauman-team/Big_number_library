#pragma once
#define typeint template<class T, class = enable_if_t<is_same<T, int>::value || is_same<T, long long>::value || is_same<T, long>::value || is_same<T, short>::value || is_same<T, unsigned int>::value || is_same<T, unsigned long long>::value || is_same<T, unsigned long>::value || is_same<T, unsigned short>::value>>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Big_Int
{
private:
	vector <int> num;
	bool isNegative = false;
	static void string_to_big_number(Big_Int& number, string s_x);
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
	static Big_Int abs(Big_Int);
	static Big_Int multiple(Big_Int a, Big_Int b);
	static Big_Int summator(Big_Int a, Big_Int b);
	static Big_Int subtraction(Big_Int a, Big_Int b);
	static Big_Int division(Big_Int a, Big_Int b);
public:
	Big_Int(){}
	Big_Int(int b)
	{
		*this = b;
	}
	friend ostream& operator<< (ostream &out, Big_Int number);
	friend istream& operator>> (istream &in, Big_Int& number);
	Big_Int operator+ (Big_Int b); // Big_Int + Big_Int
	Big_Int operator- (Big_Int b); // Big_Int - Big_Int
	Big_Int operator++ (); // ++Big_Int
	Big_Int operator- ();
	Big_Int operator/ (Big_Int b);
	Big_Int operator--();
	Big_Int operator* (Big_Int b);
	Big_Int& operator+= (const Big_Int& b); // Big_Int += Big_Int
	void operator= (const Big_Int& b);
	Big_Int operator-= (const Big_Int &b);
	bool operator<= (Big_Int);
	bool operator>= (Big_Int);
	bool operator== (const Big_Int& b);
	bool operator> (const Big_Int& b);
	bool operator< (const Big_Int& b);
	bool operator!= (Big_Int b);
	Big_Int operator++ (int); // Big_Int++
	Big_Int operator--(int);
	typeint
	Big_Int operator+ (T n) // Big_Int + int
	{
		return *this + int_to_big_number(n);
	}
	typeint
	Big_Int& operator+= (T n) // Big_Int += int
	{
		*this = *this + n;
		return *this;
	}
	typeint
	Big_Int operator-(T n)
	{
		return *this - int_to_big_number(n);
	}
	typeint
	Big_Int& operator-= (T n) // Big_Int += int
	{
		*this = *this - n;
		return *this;
	}
	typeint
	void operator= (T n)
	{
		*this = int_to_big_number(n);
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