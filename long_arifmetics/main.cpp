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
			c.num.push_back(this->num[b.num.size()] + buffer);
			for (int i = b.num.size() + 1; i < this->num.size(); i++)
			{
				c.num.push_back(this->num[i]);
			}
		}
		else if (this->num.size() < b.num.size())
		{
			c.num.push_back(b.num[this->num.size()] + buffer);
			for (int i = this->num.size() + 1; i < b.num.size(); i++)
			{
				c.num.push_back(b.num[i]);
			}
		}
		else if (buffer)
			c.num.push_back(1);
		return c;
	}
};


int main()
{
	Big_number x, y, result;

	cin >> x >> y;
	result = x + y;
	cout << result << endl;

	system("pause");
	return 0;
}