
#include <iostream>
#include <string>
#include <cstdlib>
#include "BinaryTree.h"
using namespace std;

//this test file was used to unsure that the binary tree was working using integers
//Big-Oh: O(nlog(n))
int main (){
  BinaryTree<int> tree = BinaryTree<int> ();
  for (int i = 0; i < 100; i++){
    tree.put (i);
  }
  tree.print ();
  cout << "begin deleting" << endl;
  for (int i = 0; i < 100; i++){
    if (tree.isThere(i)){
      cout << i << endl;
    }
  }
  cout << "should be blank" << endl;
  tree.print();
}
