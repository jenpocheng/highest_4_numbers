// Copyright 2013, Jen-Po Cheng.
// All rights reserved.
//
// A function that finds the highest 4 numbers in an unordered list
// of integers in O(n) time.
// Author: jenpo.cheng.tw@gmail.com (Jen-Po Cheng)

#ifndef HIGHEST_N_H
#define HIGHEST_N_H

#include <vector>

/**
 * Get highest n numbers of an unordered list of integers.
 *
 * @param un_nums - An unordered integer vector which we want to 
 *                  find highest numbers from
 *              n - Number of highest integers we want to find
 * @return A vector of unordered integers which contains the
 *         highest n numbers in un_nums
 */
std::vector<int> highest_n(const std::vector<int> &un_nums, size_t n);

#endif
