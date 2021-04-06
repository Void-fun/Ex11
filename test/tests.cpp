// Copyright 2021 asma
#include <gtest/gtest.h>
#include <string>
#include "train.h"

TEST(Train, test1) {
	int len = 20;
	Train train(len);
	EXPECT_EQ(calculate_len(train.first), len);
}
TEST(Train, test2) {
	int len = 50;
	Train train(len);
	EXPECT_EQ(calculate_len(train.first), len);
}
TEST(Train, test3) {
	int len = 70;
	Train train(len);
	EXPECT_EQ(calculate_len(train.first), len);
}
TEST(Train, test4) {
	int len = 100;
	Train train(len);
	EXPECT_EQ(calculate_len(train.first), len);
}