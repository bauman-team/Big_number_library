#include "class_Big_Double.h"

std::istream &operator>>(std::istream &stream, Big_Double& number)
{
	int position;
	register int i = 0;
	std::string s_x;
	std::cin >> s_x;
	if (!Big_Int::is_valid_format(s_x))
		throw std::exception("Invalid number!"); // �������� ������������ ����� ����� �� ��� Big_Int
	if ((position = s_x.find('.')) != std::string::npos) // ����������� ������� ����� � ������ �����
	{
		while (s_x[s_x.length() - i - 1] == '0') // �������� ���������� ����� � ������� �����
			s_x.erase(s_x.length() - i - 1, 1);
		s_x.erase(position, 1);
	}
	position = position == std::string::npos ? 0 : s_x.length() - position; // ������ ������� ����� � ����� �����
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
		if (!(number.index_of_point >= i * 9 && number.index_of_point < (i + 1) * 9)) // ���� ����� �� �������� � ������������ �������� ������� ������� ��������� �������(0)
		{
			if (i != number.num.size() - 1) // ����������� ����� ����� (��� � Big_Int)
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
			for (int j = 8; j != -1; --j) // ������� ���� ������� �����
			{
				if (i != number.num.size() - 1 || number.num[i] / buffer) // ���� ����� ��������� �� ������ ��� ������ �� 0
				{
					stream << num / buffer;
					num %= buffer;
					buffer /= 10;
				}
				else if (number.index_of_point == i * 9 + j) //���� ��������� ������� ����� ������� 0
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
				if (number.index_of_point == i * 9 + j && number.index_of_point != 0) // ���� ������� ��������� � ���. ����� � �� ��������� �� � �����  
				{
					stream << '.';
				}
			}
		}
	}
	return stream;
}
