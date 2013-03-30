// Copyright 2013, Jen-Po Cheng.
// All rights reserved.
//
// A function that finds the highest 4 numbers in an unordered list
// of integers in O(n) time.
// Author: jenpo.cheng.tw@gmail.com (Jen-Po Cheng)

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdexcept>
#include "highest_n.h"

using namespace std;

/**
 * Get highest n numbers of an unordered list of integers.
 *
 * @param un_nums - An unordered integer vector which we want to 
 *                  find highest numbers from
 *              n - Number of highest integers we want to find
 * @return A vector of unordered integers which contains the
 *         highest n numbers in un_nums
 */
vector<int> highest_n(const vector<int> &un_nums, size_t n) {
   if (n > un_nums.size())
      throw out_of_range("Parameter n is out of range");
   if (n == 0)
	   throw length_error("Parameter n must not be zero");
   vector<int> min_heap(un_nums.begin(), un_nums.begin() + n);
   make_heap(min_heap.begin(), min_heap.end(), greater<int>());
   for (vector<int>::const_iterator it = un_nums.begin() + n; it != un_nums.end(); ++it) {
      if (*it >= min_heap.front()) {
         pop_heap(min_heap.begin(), min_heap.end(), greater<int>());
         min_heap.pop_back();
         min_heap.push_back(*it);
         push_heap(min_heap.begin(), min_heap.end(), greater<int>());
      }
   }
   return min_heap;
}
