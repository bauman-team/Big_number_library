#include "class_Big_Double.h"

void Big_Double::string_to_Big_Double(std::string s_x, Big_Double &number)
{
	int position;
	register int i = 0;
	if (!Big_Int::is_valid_format(s_x))
		throw std::exception("Invalid number!"); // проверка правильности ввода такая же для Big_Int
	if ((position = s_x.find('.')) != std::string::npos) // определение позиции точки с начала числа
	{
		while (s_x[s_x.length() - i - 1] == '0') // удаление незначащих нулей в дробной части
			s_x.erase(s_x.length() - i - 1, 1);
		s_x.erase(position, 1);
	}
	position = position == std::string::npos ? 0 : s_x.length() - position; // отсчет позиции точки с конца числа
	number.num.clear();
	number.isNegative = false;
	Big_Int::string_to_big_number(number, s_x);
	number.index_of_point = position;
}

void Big_Double::Big_Double_to_string(std::string &s_x, const Big_Double &number)
{
	register int i;
	if (number.isNegative)
		s_x += '-';
	for (i = number.num.size() - 1; i >= 0; i--)
	{
		int buffer = 100'000'000;
		if (!(number.index_of_point >= i * 9 && number.index_of_point < (i + 1) * 9)) // если точка не попадает в полуинтервал элемента вектора включая последнюю позицию(0)
		{
			if (i != number.num.size() - 1) // стандартный вывод числа (как у Big_Int)
				while (buffer > number.num[i] && buffer)
				{
					s_x += '0';
					buffer /= 10;
				}
			if (buffer)
				s_x += std::to_string(number.num[i]);
		}
		else
		{
			int num = number.num[i];
			bool point_is_printed = false;
			for (int j = 8; j != -1; --j) // перебор всех позиций числа
			{
				if (i != number.num.size() - 1 || number.num[i] >= buffer || point_is_printed) // если число выводится не первым или первый не 0
				{
					s_x += std::to_string(num / buffer);
				}
				else if (number.index_of_point == i * 9 + j) //если следующий элемент точка вывести 0
				{
					s_x += '0';
				}
				num %= buffer;
				buffer /= 10;
				if (number.index_of_point == i * 9 + j && number.index_of_point != 0) // если позиция совпадает с поз. точки и ее положение не в конце  
				{
					s_x += '.';
					point_is_printed = true;
				}
			}
		}
	}
}
