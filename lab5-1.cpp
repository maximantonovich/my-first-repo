#include <iostream>
#include <string>

std::string write_str();
char divider(std::string str);
std::string biggest_word(std::string str, char length, char separator);



int main()
{
	std::string str = write_str();
	
	int length = str.size();

	char separator = divider(str);

	biggest_word(str, length, separator);


}

std::string write_str()
{
	std::string str;
	getline(std::cin, str);
	return str;
}

char divider(std::string* str)
{
	std::cout << "write what do you want divider to be?";
	std::cin.ignore();
	int divider;
	std::cin >> divider;
	return divider;
 }

std::string biggest_word(std::string str, char length, char separator)
{
	int temp_begin = 0, temp_end = 0, previous_word_length = -1, end_word, begin_word;
	for (int i = length; i > 0; i = temp_end - temp_begin)
	{
		
		temp_end = str.find_last_of(separator, i);
		temp_begin = str.find_last_of(separator, i - 1) + 1;
			for (int j = 2; j < length; j++)
			{
				if (temp_end - 1 == temp_begin)
				{
					temp_end = temp_begin;
					temp_begin = str.find_last_of(separator, i - j) + 1;
				}
				else
				{
					break;
				}
			}
		if (previous_word_length < temp_end - temp_begin || previous_word_length == -1)
		{
			end_word = temp_end;
			begin_word = temp_begin;
			previous_word_length = end_word - begin_word;
		}
	}
	std::cout << begin_word << end_word;
	return str;
}

