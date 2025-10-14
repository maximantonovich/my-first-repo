#include <iostream>
#include <random>
void keyboard_input(int **arr1, int m1, int n1);
void random_input(int** arr2, int m2, int n2);
void swap(int** arr3, int m3, int n3);

int main() 
{
	int m, n;
	std::cout << "write number of lines\n";
	if (!(std::cin >> m))
	{
		std::cout << "number of lines must be a number";
	}
	std::cout << "write number of columns\n";
	if (!(std::cin >> n))
	{
		std::cout << "number of columns must be a number";
	}
	int** arr;
	arr = new int* [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n];
	}
	int input_method;
	std::cout << "write input method(1-keyboard, 2-random)\n";
	std::cin >> input_method;
	switch (input_method)
	{	
	case 1: keyboard_input(arr, m, n); break;
	case 2: random_input(arr, m, n); break;
	default: std::cout << "method must be 1 or 2";  break;
	}
	
	swap(arr, m, n);
}


void keyboard_input(int** arr1, int m1, int n1)
{
	for (int i = 0; i < m1; i++)
	{
		std::cout << "write " << i + 1 << " line of matrix ";
		for (int j = 0; j < n1; ++j)
		{
			if (!(std::cin >> arr1[i][j]))
			{
				std::cout << "elements of array have to be numbers";
				exit(1);
			}
		}
	}
	for (int i = 0; i < m1; i++)
	{
		std::cout << "line " << i + 1 << " of matrix ";
		for (int j = 0; j < n1; ++j)
		{
			std::cout << arr1[i][j] << " ";
		}
		std::cout << "\n";
	}
}


void random_input(int** arr2, int m2, int n2)
{
	int a, b, temp1;
	std::cout << "write range of numbers\n";
	if (!(std::cin >> a >> b))
	{
		std::cout << "range must be numbers";
		exit(1);
	}
	if (a > b)
	{
		temp1 = a;
		a = b;
		b = temp1;
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(a, b);

	for (int i = 0; i < m2; i++)
	{
		for (int j = 0; j < n2; ++j)
		{
			arr2[i][j] = dist(gen);
		}
	}
	for (int i = 0; i < m2; i++)
	{
		std::cout << "line " << i + 1 << " of matrix ";
		for (int j = 0; j < n2; ++j)
		{
			std::cout << arr2[i][j] << " ";
		}
		std::cout << "\n";


	}
}

