#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <sstream>

using namespace std;

struct Big_number
{
	vector <int> num;
	bool isNegative = false;

	static void string_to_big_number(Big_number &number, string s_x)
	{
		for (int i = s_x.size(); i > 0; i -= 9)
		{
			if (i >= 9)
				number.num.push_back(atoi(s_x.substr(i - 9, 9).c_str()));
			else
				number.num.push_back(atoi(s_x.substr(0, i).c_str()));
		}
	}

	friend ostream& operator<< (ostream &out, const Big_number &number)
	{
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

	friend istream& operator>> (istream &in, Big_number &number)
	{
		string s_x;
		cin >> s_x;
		string_to_big_number(number, s_x);
		return in;
	}

	Big_number operator+ (Big_number b) // Big_number + Big_number
	{
		int buffer = 0;
		Big_number c;
		for (int i = 0; i < min(this->num.size(), b.num.size()); i++)
		{
			buffer += this->num[i] + b.num[i];
			c.num.push_back(buffer % 1000000000);
			buffer /= 1000000000;
		}
		if (this->num.size() > b.num.size())
		{
			for (int i = b.num.size(); i < this->num.size(); i++)
			{
				buffer += this->num[i];
				c.num.push_back(buffer % 1000'000'000);
				buffer /= 1000'000'000;
			}
		}
		else if (this->num.size() < b.num.size())
		{
			for (int i = this->num.size(); i < b.num.size(); i++)
			{
				buffer += b.num[i];
				c.num.push_back(buffer % 1000'000'000);
				buffer /= 1000'000'000;
			}
		}
		if (buffer)
			c.num.push_back(1);
		return c;
	}

	Big_number& operator+ (int n) // Big_number + int
	{
		ostringstream s_x;
		s_x << n;
		Big_number c;
		string_to_big_number(c, s_x.str());
		*this = *this + c;
		return *this;
	}

	Big_number& operator+= (Big_number b) // Big_number += Big_number
	{
		*this = *this + b;
		return *this;
	}

	Big_number& operator+= (int n) // Big_number += int
	{
		*this = *this + n;
		return *this;
	}

	Big_number operator++ (int) // Big_number++
	{
		*this = *this + 1;
		return *this;
	}

	Big_number& operator++ () // ++Big_number
	{
		*this = *this + 1;
		return *this;
	}
};


int main()
{
	Big_number x, y, result;

	cin >> x >> y;
	//result = x + y;
	x += 1'999'999'999;
	//x++;
	cout << x << endl;

	system("pause");
	return 0;
}