#include "class_Big_Int.h"

void Big_Int::string_to_big_number(Big_Int & number, string s_x)
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

//void Big_Int::int_to_big_number(Big_Int & number, int i_x)
//{
//	do
//	{
//		number.num.push_back(i_x % 1'000'000'000);
//		i_x /= 1'000'000'000;
//	} while (i_x);
//}

Big_Int Big_Int::abs(Big_Int b)
{
	b.isNegative = false;
	return b;
}

Big_Int Big_Int::multiple(Big_Int a, Big_Int b)
{
	Big_Int c, koef, result;
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

Big_Int Big_Int::summator(Big_Int a, Big_Int b)
{
	Big_Int c;
	if (a.isNegative != b.isNegative) // Сложение не меняет знаки переменных => если они разные => вычитание
	{
		if (a.isNegative)
		{
			a.isNegative = false;
			c = b - a;
			a.isNegative = true; // отменяю изменения
		}
		else
		{
			b.isNegative = false;
			c = a - b;
		}
	}
	else
	{
		int buffer = 0;
		c.isNegative = b.isNegative;
		int minLen = (a.num.size() <= b.num.size()) ? a.num.size() : b.num.size(); // if vector.size() > MAXINT -> Big_Int
		for (int i = 0; i < minLen; i++)
		{
			buffer += a.num[i] + b.num[i];
			c.num.push_back(buffer % 1'000'000'000);
			buffer /= 1'000'000'000;
		}
		if (a.num.size() > b.num.size())
		{
			for (int i = b.num.size(); i < a.num.size(); i++)
			{
				buffer += a.num[i];
				c.num.push_back(buffer % 1000'000'000);
				buffer /= 1'000'000'000;
			}
		}
		else if (a.num.size() < b.num.size())
		{
			for (int i = a.num.size(); i < b.num.size(); i++)
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

Big_Int Big_Int::subtraction(Big_Int a, Big_Int b)
{
	Big_Int c;
	if (a.isNegative != b.isNegative) // Вычитание меняет знак => переменные станут одного занка => сложение
	{
		b.isNegative = !b.isNegative;
		c = a + b;
	}
	else
	{
		if (a == b)
			c.num.push_back(0);
		else if (b.isNegative)
		{
			// (-this) - (-b) --> (+b) - (+this)
			//b = -b;
			//a = -a;
			if (a < b) // (-this) < (-b) | * (-1) == this > b
			{
				for (int i = 0; i < b.num.size(); i++)
					c.num.push_back(a.num[i] - b.num[i]);
				for (int i = b.num.size(); i < a.num.size(); i++)
					c.num.push_back(a.num[i]);
				for (int i = 0; i < c.num.size() - 1; i++)
					if (c.num[i] < 0)
					{
						c.num[i] += 1'000'000'000;
						c.num[i + 1]--;
					}
				c.isNegative = true;
				//a = -a; // возвращаю исходное состояние
			}
			else
			{
				for (int i = 0; i < a.num.size(); i++)
					c.num.push_back(b.num[i] - a.num[i]);
				for (int i = a.num.size(); i < b.num.size(); i++)
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
			if (a > b)
			{
				for (int i = 0; i < b.num.size(); i++)
					c.num.push_back(a.num[i] - b.num[i]);
				for (int i = b.num.size(); i < a.num.size(); i++)
					c.num.push_back(a.num[i]);
				for (int i = 0; i < c.num.size() - 1; i++)
					if (c.num[i] < 0)
					{
						c.num[i] += 1'000'000'000;
						c.num[i + 1]--;
					}
			}
			else
			{
				for (int i = 0; i < a.num.size(); i++)
					c.num.push_back(b.num[i] - a.num[i]);
				for (int i = a.num.size(); i < b.num.size(); i++)
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

Big_Int Big_Int::division(Big_Int a, Big_Int b)
{
	Big_Int c, koef, result, copy_a = abs(a);
	bool flag = false;
	if (a.isNegative != b.isNegative)
		flag = true;
	b = abs(b);
	c.num.push_back(0);
	koef.num.push_back(0);
	result.num.push_back(0);
	while (copy_a >= b)
	{
		if (c + c <= copy_a)
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
		if (c + c > copy_a)
		{
			result += koef;
			if (c != b)
			{
				koef = 0;
				copy_a -= c;
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