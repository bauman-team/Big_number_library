#include "class_Big_Int.h"
using namespace std;

int main()
{
	Big_Int x, y, result;
	char sign;
	y = 0;
	result = x = y;
	y = x = 0;
	while (true)
	{
		try
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