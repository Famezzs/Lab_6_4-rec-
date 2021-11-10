// Lab_6_4(iter).cpp
// Козубенко Андрій
// Лабораторна робота № 6.4
// Опрацювання та впорядкування одновимірних динамічних масивів.
// Варіант 10
// Рекурсивний спосіб
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::setw;
using std::endl;

void CreateArr(int *a, const int size, const int i);
void PrintArr(int *a, const int size, const int i);
int Min(int *a, const int size, int min, const int i);
int SearchZero(int *a, const int size, const int i);
int AbsSum(int *a, const int size, int Sum, const int i);
void SortArr(int *a, const int size, const int z, const int i);

int main()
{
	int n;
	int numzero;

	cout << "How many elements should a new array consist of?\n";
	cout << "n = "; cin >> n;

	if (n <= 0)
	{
		std::cerr << "n must be > 0";
		return -1;
	}

	int *a = new int[n];

	CreateArr(a, n, 0);
	PrintArr(a, n, 0);

	cout << "Minimal absolute value in the array = " << Min(a, n, abs(a[0]), 1) << endl;

	numzero = SearchZero(a, n, 0);

	if (numzero != -1)
	{
		int i = numzero + 1;
		cout << "Sum of absolute values of all elements after first zero encountered = " << AbsSum(a, n, 0, i) << endl;
	}
		
	else
		cout << "No zeros encountered" << endl;

	SortArr(a, n, 0, 0);
	PrintArr(a, n, 0);

	delete[] a;
	return 0;
}

void CreateArr(int *a, const int size, const int i)
{
	cout << "a[" << i << "] = "; cin >> a[i];
	
	if (i < size - 1)
		CreateArr(a, size, i + 1);
}

void PrintArr(int *a, const int size, const int i)
{
	if (i == 0)
		cout << "a = { ";

	cout << setw(4) << a[i];

	if (i < size - 1)
	{
		cout << ", ";
		PrintArr(a, size, i + 1);
	}
	else
		cout << " }" << endl;
}

int Min(int *a, const int size, int min, const int i)
{
	if (i < size)
	{
		if (abs(a[i]) < abs(min))
			min = abs(a[i]);
		return Min(a, size, min, i + 1);
	}
	else
		return min;
}

int SearchZero(int *a, const int size, const int i)
{
	if (i < size)
	{
		if (a[i] == 0)
			return i;
		else
			return SearchZero(a, size, i + 1);
	}
	else
		return -1;
}

int AbsSum(int *a, const int size, int Sum, const int i)
{
	if (i < size)
	{
		Sum += abs(a[i]);
		return AbsSum(a, size, Sum, i + 1);
	}
	else
		return Sum;
}

void SortArr(int *a, const int size, const int z, const int i)
{
	if (z < size / 2.0)
	{
		if (i < size - z - 1)
		{
			int tmp = a[i + z];
			a[i + z] = a[i + z + 1];
			a[i + z + 1] = tmp;

			SortArr(a, size, z, i + 1);
		}
		else
			SortArr(a, size, z + 1, 0);
	}
}