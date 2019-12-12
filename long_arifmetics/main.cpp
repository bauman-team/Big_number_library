#include "class_Big_Int.h"

int main()
{
	Big_Int x, y, result;
	x = 5;
	Big_Int z = x;

	char sign;
	unsigned int a = 5;
	while (true)
	{
		cout << "x: ";
		cin >> x;
		cout << "sign: ";
		cin >> sign;
		cout << "y: ";
		cin >> y;
		cout << "Answer: ";
		//x = a;
		//cout << x  << endl;
		try
		{
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
		}
		catch (const exception &ex)
		{
			cout << ex.what();
		}
		cout << endl << endl;
	}
	system("pause");
	return 0;
}