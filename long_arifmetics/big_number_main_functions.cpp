#include "struct_big_number.h"

Big_number Big_number::operator++ (int) // Big_number++
{
	*this = *this + 1;
	return *this - 1;
}

Big_number Big_number::operator- ()
{
	Big_number c = *this;
	if (c != 0)
		c.isNegative = !c.isNegative;
	return c;
}

Big_number Big_number::operator*(Big_number b)
{
	Big_number c;
	if (abs(*this) < abs(b))
		c = multiple(abs(*this), abs(b));
	else
		c = multiple(abs(b), abs(*this));
	if (this->isNegative != b.isNegative)
		c = -c;
	return c;
}

bool Big_number::operator!=(Big_number b)
{
	if (*this == b)
		return false;
	return true;
}

Big_number Big_number::abs(Big_number b)
{
	b.isNegative = false;
	return b;
}

Big_number Big_number::multiple(Big_number a, Big_number b)
{
	Big_number c, koef, result;
	c.num.push_back(0);
	koef.num.push_back(0);
	result.num.push_back(0);
	while (koef != a)
	{
		if ((koef + koef <= a))
		{
			if (koef == 0)
			{
				koef = 1;
				c = b;
			}
			else
			{
				koef += koef;
				c += c;
			}
		}
		if ((koef + koef > a) || (koef == a))
		{
			a -= koef;
			koef = 0;
			result += c;
		}
	}
	return result;
}

Big_number Big_number::operator-= (const Big_number &b)
{
	*this = *this - b;
	return *this;
}

bool Big_number::operator!=(int n)
{
	if (*this == n)
		return false;
	return true;
}

bool Big_number::operator<=(Big_number b)
{
	if (*this < b || *this == b)
		return true;
	return false;
}

bool Big_number::operator>=(Big_number b)
{
	if (*this > b || *this == b)
		return true;
	return false;
}

Big_number Big_number::operator/(Big_number b)
{
	if (b == 0)
		throw;
	Big_number c, koef, result, a = abs(*this);
	bool flag = false;
	if (this->isNegative != b.isNegative)
		flag = true;
	b = abs(b);
	c.num.push_back(0);
	koef.num.push_back(0);
	result.num.push_back(0);
	while (a >= b)
	{
		if (c + c <= a)
		{
			if (koef == 0)
			{
				koef = 1;
				c = b;
			}
			else
			{
				koef += koef;
				c += c;
			}
		}
		if (c + c > a)
		{
			result += koef;
			if (c != b)
			{
				koef = 0;
				a -= c;
				c = 0;
			}
			else
			{
				break;
			}
		}
	}
	if (flag)
		result = -result;
	return result;
}

Big_number Big_number::operator--()
{
	*this = *this - 1;
	return *this;
}

Big_number Big_number::operator--(int)
{
	*this = *this - 1;
	return *this + 1;
}

Big_number Big_number::operator-(int b)
{
	Big_number c;
	int_to_big_number(c, b);
	return *this - c;
}

Big_number Big_number::operator++ () // ++Big_number
{
	*this = *this + 1;
	return *this;
}

void Big_number::string_to_big_number(Big_number & number, string s_x)
{
	if (s_x[0] == '-')
	{
		number.isNegative = true;
		s_x.erase(0, 1);
	}
	while (s_x[0] == '0' && s_x.size() != 1)
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

void Big_number::int_to_big_number(Big_number & number, int i_x)
{
	number.num.push_back(i_x % 1'000'000'000);
	if (i_x / 1'000'000'000)
		number.num.push_back(i_x / 1'000'000'000);
}

Big_number Big_number::operator+(Big_number b)
{
	Big_number c;
	if (this->isNegative != b.isNegative) // Сложение не меняет знаки переменных => если они разные => вычитание
	{
		if (this->isNegative)
		{
			this->isNegative = false;
			c = b - *this;
			this->isNegative = true; // отменяю изменения
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

Big_number Big_number::operator-(Big_number b)
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
		if (*this == b)
			c.num.push_back(0);
		else if (b.isNegative)
		{
			// (-this) - (-b) --> (+b) - (+this)
			//b = -b;
			//*this = -*this;
			if (*this < b) // (-this) < (-b) | * (-1) == this > b
			{
				for (int i = 0; i < b.num.size(); i++)
					c.num.push_back(this->num[i] - b.num[i]);
				for (int i = b.num.size(); i < this->num.size(); i++)
					c.num.push_back(this->num[i]);
				for (int i = 0; i < c.num.size() - 1; i++)
					if (c.num[i] < 0)
					{
						c.num[i] += 1'000'000'000;
						c.num[i + 1]--;
					}
				c.isNegative = true;
				//*this = -*this; // возвращаю исходное состояние
			}
			else
			{
				for (int i = 0; i < this->num.size(); i++)
					c.num.push_back(b.num[i] - this->num[i]);
				for (int i = this->num.size(); i < b.num.size(); i++)
					c.num.push_back(b.num[i]);
				for (int i = 0; i < c.num.size() - 1; i++)
					if (c.num[i] < 0)
					{
						c.num[i] += 1'000'000'000;
						c.num[i + 1]--;
					}
			}
		}
		else
		{
			//(+this) - (+b)  
			if (*this > b)
			{
				for (int i = 0; i < b.num.size(); i++)
					c.num.push_back(this->num[i] - b.num[i]);
				for (int i = b.num.size(); i < this->num.size(); i++)
					c.num.push_back(this->num[i]);
				for (int i = 0; i < c.num.size() - 1; i++)
					if (c.num[i] < 0)
					{
						c.num[i] += 1'000'000'000;
						c.num[i + 1]--;
					}
			}
			else
			{
				for (int i = 0; i < this->num.size(); i++)
					c.num.push_back(b.num[i] - this->num[i]);
				for (int i = this->num.size(); i < b.num.size(); i++)
					c.num.push_back(b.num[i]);
				for (int i = 0; i < c.num.size() - 1; i++)
					if (c.num[i] < 0)
					{
						c.num[i] += 1'000'000'000;
						c.num[i + 1]--;
					}
				c.isNegative = true;
			}
		}
		// чистка пустых элементов вектора
		for (int i = c.num.size() - 1; (i > 0) && (c.num[i] == 0); i--)
			c.num.pop_back();
	}
	return c;
}

Big_number Big_number::operator+(int n)
{
	Big_number c;
	int_to_big_number(c, n);
	return *this + c;
}

Big_number & Big_number::operator+=(const Big_number & b)
{
	*this = *this + b;
	return *this;
}

Big_number& Big_number::operator+=(int n)
{
	*this = *this + n;
	return *this;
}

void Big_number::operator=(const Big_number & b)
{
	this->num = b.num; // ?
	this->isNegative = b.isNegative;
}

void Big_number::operator=(int n)
{
	Big_number c;
	int_to_big_number(c, n);
	*this = c;
}

bool Big_number::operator==(const Big_number & b)
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

bool Big_number::operator==(int b)
{
	Big_number c;
	c = b;
	if (c == *this)
		return true;
	return false;
}

bool Big_number::operator>(const Big_number & b)
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

bool Big_number::operator< (const Big_number& b)
{
	if (*this > b)
		return false;
	if (*this == b)
		return false;
	return true;
}