// Copyright 2013, Jen-Po Cheng.
// All rights reserved.
//
// A function that finds the highest 4 numbers in an unordered list
// of integers in O(n) time.
// Author: jenpo.cheng.tw@gmail.com (Jen-Po Cheng)

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "highest_n.h"

using namespace std;

int main(int argc, char *argv[]) {
   static const int arr[] = {13,12,34,53,456,3,445,456,32,8,57,8,465};
   vector<int> input_vec (arr, arr + sizeof(arr) / sizeof(arr[0]));

   try {
      vector<int> highest_4 = highest_n(input_vec, 4);
      for (vector<int>::iterator it = highest_4.begin(); 
         it != highest_4.end(); ++it) {
         cout << *it << " ";
      }
      cout << endl;
   } catch (exception &e) {
      cout << e.what() << endl;
      return 1;
   }

   return 0;
}
