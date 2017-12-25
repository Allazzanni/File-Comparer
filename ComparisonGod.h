
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include "BinaryTree.h"
using namespace std;

class ComparisonGod {
private:
  BinaryTree<string> list1;
  vector<string> list2;
  vector<string> inBoth;
public:
  //empty consturctor
  //Big-Oh: O(1)
  ComparisonGod (){
    list2 = vector<string>();
    inBoth = vector<string>();
  }
  //compare asks for a filepath, then stores the contents of that file in a binary tree
  //then it asks for another filepath and then compares the values as it takes them in
  //and either puts them in the inBoth list or the list2 list based on the result
  //once the three lists are full it prints them with an explanaition of what each list contains
  //Big-Oh: O(nlog(n) + klog(n) + x), where k is the number of values in list 2 and n is the number in list 1
  //and x is the largest of either k or n + the number of unique (since the total amount printed is the largest
  // list plus the number of unique ones in the smaller list)
  void compare (){
    string filePath1;
    cout << "please enter the first file to be compared:" << endl;
    cin >> filePath1;
    string line;
    ifstream myfile (filePath1);
    if (myfile.is_open()){
      //runs in nlog(n)
      while (getline (myfile, line)){
        list1.put(line);
      }
      myfile.close();
    }else{
      throw(1);
    }
    string filePath2;
    cout << "please enter the second file to be compared:" << endl;
    cin >> filePath2;
    ifstream myfile2 (filePath2);
    if (myfile2.is_open()){
      //runs in klog(n)
      while (getline (myfile2, line)){
        if (list1.isThere(line)){
          inBoth.push_back (line);
        } else {
          list2.push_back (line);
        }
      }
      myfile2.close();
    }else{
      throw(1);
    }
    //runs in x + |n-k|, (the total number printed is the number of whichever is higher plus the differ)
    cout << "items in " << filePath1 << "that are not in " << filePath2 << ": " << endl;
    list1.print();
    cout << "items in " << filePath2 << "that are not in " << filePath1 << ": " << endl;
    for (int i = 0; i < list2.size(); i++){
      cout << list2.at(i) << endl;
    }
    cout << "items in both: " << endl;
    for (int i = 0; i < inBoth.size(); i++){
      cout << inBoth.at(i) << endl;
    }
  }
};
