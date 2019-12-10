#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Big_Int
{
public:
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
	Big_Int operator+ (int n); // Big_Int + int
	Big_Int& operator+= (int n); // Big_Int += int
	Big_Int operator--(int);
	Big_Int operator-(int);
	Big_Int operator++ (int); // Big_Int++
	void operator= (int n);
	bool operator<= (Big_Int);
	bool operator>= (Big_Int);
	bool operator== (const Big_Int& b);
	bool operator== (int);
	bool operator> (const Big_Int& b);
	bool operator< (const Big_Int& b);
	bool operator!= (Big_Int b);
	bool operator!= (int);
	bool operator>= (int);
	bool operator<= (int);
	bool operator> (int);
	bool operator< (int);
private:
	vector <int> num;
	bool isNegative = false;
	static void string_to_big_number(Big_Int& number, string s_x);
	static void int_to_big_number(Big_Int& number, int i_x);
	static Big_Int abs(Big_Int);
	static Big_Int multiple(Big_Int a, Big_Int b);
	static Big_Int summator(Big_Int a, Big_Int b);
	static Big_Int subtraction(Big_Int a, Big_Int b);
	static Big_Int division(Big_Int a, Big_Int b);
};