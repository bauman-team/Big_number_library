#include "struct_big_number.h"

int main()
{
	Big_number x, y, result;
	char sign;

	while (true)
	{
		cout << "x: ";
		cin >> x;
		cout << "sign: ";
		cin >> sign;
		cout << "y: ";
		cin >> y;
		cout << "Answer: ";
		switch (sign)
		{
		case '+':
			cout << x + y;
			break;
		case '-':
			cout << x - y;
			break;
		case '*':
			cout << x * y;
			break;
		case '/':
			cout << x / y;
			break;
		}
		cout << endl << endl;
	}
	system("pause");
	return 0;
}