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
	friend ostream& operator<< (ostream &out, const Big_number &number)
	{
		for (int i = number.num.size() - 1; i >= 0; i--)
		{
			int buffer = 100'000'000;
			//buffer /= 10
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
		for (int i = s_x.size(); i > 0; i -= 9)
		{
			if (i >= 9)
				number.num.push_back(atoi(s_x.substr(i - 9, 9).c_str()));
			else
				number.num.push_back(atoi(s_x.substr(0, i).c_str()));
		}
		return in;
	}

	Big_number operator+ (Big_number b)
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
			for (int i = b.num.size() + 1; i < this->num.size(); i++)
			{
				buffer += this->num[i];
				c.num.push_back(buffer % 1000'000'000);
				buffer /= 1000'000'000;
			}
		}
		else if (this->num.size() < b.num.size())
		{
			for (int i = this->num.size() + 1; i < b.num.size(); i++)
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
};

Big_number summator(const Big_number&, const Big_number&);



int main()
{
	string s_x, s_y;
	Big_number x, y;

	cin >> x >> y;

	//Big_number result = summator(x, y);
	Big_number result = x + y;
	
	cout << result;

	system("pause");
	return 0;
}

Big_number summator(const Big_number &a, const Big_number &b)
{
	int buffer = 0;
	Big_number c;
	for (int i = 0; i < min(a.num.size(), b.num.size()); i++)
	{
		buffer += a.num[i] + b.num[i];
		c.num.push_back(buffer % 1000000000);
		buffer /= 1000000000;
	}
	if (a.num.size() > b.num.size())
	{
		c.num.push_back(a.num[b.num.size()] + buffer);
		for (int i = b.num.size() + 1; i < a.num.size(); i++)
		{
			c.num.push_back(a.num[i]);
		}
	}
	else if (a.num.size() < b.num.size())
	{
		c.num.push_back(b.num[a.num.size()] + buffer);
		for (int i = a.num.size() + 1; i < b.num.size(); i++)
		{
			c.num.push_back(b.num[i]);
		}
	}
	else if (buffer)
		c.num.push_back(1);
	return c;
}