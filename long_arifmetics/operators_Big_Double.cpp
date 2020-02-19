#include "class_Big_Double.h"

std::istream &operator>>(std::istream &stream, Big_Double& number)
{
	int position;
	std::string s_x;
	std::cin >> s_x;
	if (!Big_Int::is_valid_format(s_x))
		throw std::exception("Invalid number!");
	if (s_x.find('.') != std::string::npos)
		s_x.erase((position = s_x.find('.')), 1);
	position = s_x.length() - position;
	number.num.clear();
	number.isNegative = false;
	Big_Int::string_to_big_number(number, s_x);
	number.index_of_point = position;
	return stream;
}

std::ostream &operator<<(std::ostream & stream, Big_Double &number)
{
	register int i;
	if (number.isNegative)
		stream << '-';
	for (i = number.num.size() - 1; i >= 0; i--)
	{
		int buffer = 100'000'000;
		if (!(number.index_of_point >= i * 9 && number.index_of_point < (i + 1) * 9))
		{
			if (i != number.num.size() - 1)
				while (buffer > number.num[i] && buffer)
				{
					stream << 0;
					buffer /= 10;
				}
			if (buffer)
				stream << number.num[i];
		}
		else
		{
			int num = number.num[i];
			for (int j = 8; j != -1; --j)
			{
				if (i != number.num.size() - 1 || num / buffer)
				{
					stream << num / buffer;
					num %= buffer;
					buffer /= 10;
				}
				else if (number.index_of_point == i * 9 + j)
				{
					stream << 0;
					num %= buffer;
					buffer /= 10;
				}
				else
				{
					num %= buffer;
					buffer /= 10;
				}
				if (number.index_of_point == i * 9 + j)
				{
					stream << '.';
				}
			}
		}
	}
	return stream;
}
