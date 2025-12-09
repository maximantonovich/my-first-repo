#include "gtest/gtest.h"
#include "lab2-test.cpp"

TEST(put_num_in_vector, single_digit) {
	std::vector<int> expected = { 5 };
	EXPECT_EQ(put_num_in_vector(5), expected);
}

TEST(put_num_in_vector, multiple_digit) {
	std::vector<int> expected = { 1,2,3 };
	EXPECT_EQ(put_num_in_vector(123), expected);
}