

#include <iostream>
#include <string>
#include <cstdlib>
#include "ComparisonGod.h"
using namespace std;

//main just creates a ComparisonGod and then runs the compare method
//there are two test files available in here, which are the first ones I tested it with
//Big-Oh: O(nlog(n) + klog(n) + x)
int main (){
  ComparisonGod* comparer = new ComparisonGod ();
  comparer->compare();
  return 0;
}
