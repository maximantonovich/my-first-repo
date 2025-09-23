#include <iostream>

int main() {
	float arr[1000], sum_odd = 0, sum2 = 1;
	int n, first_neg, last_neg;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
		if (i % 2 != 0)
		{
			sum_odd += arr[i];
		}
	}
	for (int i = 0; i < n-1; i++)
	{
		if (arr[i] < 0)
		{
			first_neg = i;
			break;
		}
	}
	for (int i = n-1; i >= 0 ; i--)
	{
		if (arr[i] < 0)
		{
			last_neg = i;
			break;
		}
	}
	for (;  first_neg < last_neg - 1; first_neg++)
	{
		sum2 *= arr[first_neg+1];
	}
	std::cout << sum_odd << "\n" << sum2;
}