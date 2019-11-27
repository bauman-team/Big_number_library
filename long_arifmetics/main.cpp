#include "struct_big_number.h"

int main()
{
	Big_number x, y, result;

	while (true)
	{
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
		cout << endl;
		cout << "x * y: " << (x * y);
		//cout << x - y;
		cout << endl;
	}
	system("pause");
	return 0;
}