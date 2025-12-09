#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
int get_num();
std::vector<int> put_num_in_vector(int n);
std::vector<int> amount_times_repeat(const std::vector<int>& v);
int make_num(const std::vector<int>& v, const std::vector<int>& amount);

int main()
{
    std::cout << "write number n\n";
    int n = get_num();

    std::vector<int> num = put_num_in_vector(n);
    std::vector<int> amount = amount_times_repeat(num);

    int result = make_num(num, amount);

    std::cout << "result is: " << result;
}

int get_num()
{
    int n;
    if (!(std::cin >> n))
    {
        throw "not a number";
    }
    if (n <= 0)
    {
        throw "number is not natural";
    }
    return n;
}

std::vector<int> put_num_in_vector(int n)
{
    std::vector<int> v;
    while (n != 0)
    {
        int digit;
        digit = n % 10;
        v.push_back(digit);
        n /= 10;
    }

    return v;
}

std::vector<int> amount_times_repeat(const std::vector<int>& v)
{
    std::vector<int> amount(10, 0);
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < v.size(); j++)
        {
            if (i == v.at(j))
            {
                amount.at(i)++;
            }
        }
    }

    return amount;
}

int make_num(const std::vector<int>& v, const std::vector<int>& amount)
{
    int digit_place = 1, num = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        if (amount.at(v.at(i)) % 2 != 0)
        {
            num += v.at(i) * digit_place;
            digit_place *= 10;
        }
    }

    return num;
}