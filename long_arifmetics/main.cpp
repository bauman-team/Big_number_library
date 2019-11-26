#include "main_header.h"

int main()
{
	Big_number x, y, result;

	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;

	cout << endl;
	cout << "x + y = " << x + y << endl;

	cout << endl;
	cout << "x + 15 = " << x + 15 << endl;
	x += 15;
	cout << "x += 15 = " << x << endl;

	cout << "x + 1'000'000'001 = " << x + 1'000'000'001 << endl;
	x += 1'000'000'001;
	cout << "x += 1'000'000'001 = " << x << endl;

	cout << endl;
	y = x;
	x = 2'000'000'002;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "x + y = " << x + y << endl;
	x += y;
	cout << "x += y = " << x << endl;
	
	cout << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	if (x == y)
		cout << "x == y" << endl;
	else
		cout << "x != y" << endl;
	x = y;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	if (x == y)
		cout << "x == y" << endl;
	else
		cout << "x != y" << endl;


	cout << endl;
	cout << "x = " << x << endl;
	cout << "x++ = " << x++ << endl;
	cout << "x++ = " << x++ << endl;
	cout << "++x = " << ++x << endl;
	cout << "x = " << x << endl;

	y = x++;
	
	if (x < y)
		cout << "x < y" << endl;

	if (y < x)
		cout << "y < x" << endl;

	cin >> x;
	cin >> y;

	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "x - y = " << x - y << endl;
	cout << "y - x = " << y - x << endl;


	system("pause");
	return 0;
}