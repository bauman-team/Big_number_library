#pragma once
// добавить класс Big_Double наследовать Big_Int
// добавить геттеры и сеттеры ???

int LEN = 80 / n - 1;
cout << scientific << setprecision(LEN - 6);
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
	{
		cout << matrix[i][j];
		if (j != n - 1)
			cout << " ";
	}
	cout << endl << endl;
}