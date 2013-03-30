// Copyright 2013, Jen-Po Cheng.
// All rights reserved.
//
// Testcases for testing the function highest_n()
// Author: jenpo.cheng.tw@gmail.com (Jen-Po Cheng)

#include <vector>
#include <algorithm>
#include <stdexcept>
#include "../../src/highest_n.h"
#include "gtest/gtest.h"

TEST(HighestNTest, Normal) {
   static const int arr[] = {10,1,3,2,6,5,4,7,9,8,0};
   std::vector<int> input(arr, arr + sizeof(arr) / sizeof(arr[0]));

   // Highest 4 numbers
   static const int arr_4[] = {10,9,8,7};
   std::vector<int> answer_4(arr_4, arr_4 + sizeof(arr_4) / sizeof(arr_4[0]));
   std::vector<int> output_4 = highest_n(input, 4);
   std::sort(output_4.begin(), output_4.end());
   std::sort(answer_4.begin(), answer_4.end());
   EXPECT_TRUE( output_4 == answer_4 );

   // Highest 5 numbers
   static const int arr_5[] = {10,9,8,7,6};
   std::vector<int> answer_5(arr_5, arr_5 + sizeof(arr_5) / sizeof(arr_5[0]));
   std::vector<int> output_5 = highest_n(input, 5);
   std::sort(output_5.begin(), output_5.end());
   std::sort(answer_5.begin(), answer_5.end());
   EXPECT_TRUE( output_5 == answer_5 );
}

TEST(HighestNTest, Edge) {
   // Negative input
   static const int arr[] = {-10,-1,-3,-2,-6,-5,-4,-7,-9,-8,-0};
   std::vector<int> input(arr, arr + sizeof(arr) / sizeof(arr[0]));

   // Highest n numbers
   std::vector<int> answer_11(input);
   std::vector<int> output_11 = highest_n(input, 11);
   std::sort(output_11.begin(), output_11.end());
   std::sort(answer_11.begin(), answer_11.end());
   EXPECT_TRUE( output_11 == answer_11 );

   // Duplicate numbers in input
   static const int arr_dup[] = {10,1,3,2,6,5,4,7,9,8,0,10,8};
   std::vector<int> input_dup(arr_dup, arr_dup + sizeof(arr_dup) / sizeof(arr_dup[0]));
   static const int arr_5[] = {10,10,9,8,8};
   std::vector<int> answer_5(arr_5, arr_5 + sizeof(arr_5) / sizeof(arr_5[0]));
   std::vector<int> output_5 = highest_n(input_dup, 5);
   std::sort(output_5.begin(), output_5.end());
   std::sort(answer_5.begin(), answer_5.end());
   EXPECT_TRUE( output_5 == answer_5 );
}

TEST(HighestNTest, Exception) {
   static const int arr[] = {-10,-1,-3,-2,-6,-5,-4,-7,-9,-8,-0};
   std::vector<int> input(arr, arr + sizeof(arr) / sizeof(arr[0]));

   // Exception
   EXPECT_THROW(highest_n(input, -1), std::out_of_range);
   EXPECT_THROW(highest_n(input, 0), std::length_error);
   EXPECT_THROW(highest_n(input, 12), std::out_of_range);
}
