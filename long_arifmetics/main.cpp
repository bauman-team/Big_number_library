#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

struct Big_number
{
	vector <int> num;
	bool isNegative = false;

	static void string_to_big_number(Big_number& number, string s_x)
	{
		if (s_x[0] == '-')
		{
			number.isNegative = true;
			s_x.erase(0, 1);
		}
		for (int i = s_x.size(); i > 0; i -= 9)
		{
			if (i >= 9)
				number.num.push_back(atoi(s_x.substr(i - 9, 9).c_str()));
			else
				number.num.push_back(atoi(s_x.substr(0, i).c_str()));
		}
	}

	static void int_to_big_number(Big_number& number, int i_x)
	{
		number.num.push_back(i_x % 1'000'000'000);
		if (i_x / 1'000'000'000)
			number.num.push_back(i_x / 1'000'000'000);	
	}

	friend ostream& operator<< (ostream &out, Big_number number)
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

	friend istream& operator>> (istream &in, Big_number& number)
	{
		string s_x;
		cin >> s_x;
		string_to_big_number(number, s_x);
		return in;
	}

	Big_number operator+ (Big_number b) // Big_number + Big_number
	{
		Big_number c;
		if (this->isNegative != b.isNegative) // Сложение не меняет знаки переменных => если они разные => вычитание
		{
			if (this->isNegative)
			{
				this->isNegative = false;
				c = b - *this;
			}
			else
			{
				b.isNegative = false;
				c = *this - b;
			}
		}
		else
		{
			int buffer = 0;
			c.isNegative = b.isNegative;
			for (int i = 0; i < min(this->num.size(), b.num.size()); i++)
			{
				buffer += this->num[i] + b.num[i];
				c.num.push_back(buffer % 1'000'000'000);
				buffer /= 1'000'000'000;
			}
			if (this->num.size() > b.num.size())
			{
				for (int i = b.num.size(); i < this->num.size(); i++)
				{
					buffer += this->num[i];
					c.num.push_back(buffer % 1000'000'000);
					buffer /= 1'000'000'000;
				}
			}
			else if (this->num.size() < b.num.size())
			{
				for (int i = this->num.size(); i < b.num.size(); i++)
				{
					buffer += b.num[i];
					c.num.push_back(buffer % 1'000'000'000);
					buffer /= 1'000'000'000;
				}
			}
			if (buffer)
				c.num.push_back(1);
		}
		return c;
	}

	Big_number operator- (Big_number b) // Big_number - Big_number
	{
		Big_number c;
		if (this->isNegative != b.isNegative) // Вычитание меняет знак => переменные станут одного занка => сложение
		{
			b.isNegative = !b.isNegative; 
			c = *this + b;
		}
		else
		{
			// Здесь надо переопределить операцию вычитания
		}
		return c;
	}

	Big_number operator+ (int n) // Big_number + int
	{
		/*ostringstream s_x;
		s_x << n;
		Big_number c;
		string_to_big_number(c, s_x.str());*/
		Big_number c;
		int_to_big_number(c, n);
		return *this + c;
	}

	Big_number& operator+= (const Big_number& b) // Big_number += Big_number
	{
		*this = *this + b;
		return *this;
	}

	Big_number& operator+= (int n) // Big_number += int
	{
		*this = *this + n;
		return *this;
	}

	void operator= (const Big_number& b)
	{
		this->num = b.num; // ?
		this->isNegative = b.isNegative;
	}

	void operator= (int n)
	{
		Big_number c;
		int_to_big_number(c, n);
		*this = c;
	}

	bool operator== (const Big_number& b)
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

	Big_number& operator++ () // ++Big_number
	{
		*this = *this + 1;
		return *this;
	}

	Big_number operator++ (int) // Big_number++
	{
		Big_number temp = *this;
		*this = *this + 1;
		return temp;
	}
};


int main()
{
	Big_number x, y, result;

	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;

	cout << endl;
	cout << "x + y = " << x + y << endl;

	cout << endl;
	cout << "x + 15 = " << x + 15 << endl;
	x += 15;
	cout << "x += 15 = " << x << endl;

	cout << "x + 1'000'000'001 = " << x + 1'000'000'001 << endl;
	x += 1'000'000'001;
	cout << "x += 1'000'000'001 = " << x << endl;

	cout << endl;
	y = x;
	x = 2'000'000'002;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "x + y = " << x + y << endl;
	x += y;
	cout << "x += y = " << x << endl;
	
	cout << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	if (x == y)
		cout << "x == y" << endl;
	else
		cout << "x != y" << endl;
	x = y;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	if (x == y)
		cout << "x == y" << endl;
	else
		cout << "x != y" << endl;

	cout << endl;
	cout << "x = " << x << endl;
	cout << "x++ = " << x++ << endl;
	cout << "x++ = " << x++ << endl;
	cout << "++x = " << ++x << endl;
	cout << "x = " << x << endl;

	system("pause");
	return 0;
}