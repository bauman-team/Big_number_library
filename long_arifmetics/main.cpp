#include "class_Big_Int.h"
#include <ctime>
using namespace std;

int get_sizeof_num(Big_Int);

int main()
{
	Big_Int x, y, result;
	result = "00789876787654345678";
	double start;
	char sign;
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
			start = clock();
			switch (sign)
			{
			case '+':
				result = x + y;
				break;
			case '-':
				result = x - y;
				break;
			case '*':
				result = x * y;
				break;
			case '/':
				result = x / y;
				break;
			}
			start = (clock() - start) /  1000.;
			cout << result;
			cout << "\nTime of calculation: " << start << "\n";
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