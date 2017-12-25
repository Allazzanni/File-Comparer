
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


template <class T> class BinaryTree{
private:
  struct Node {
  public:
    struct Node* parent;
    struct Node* right;
    struct Node* left;
    T object;
    //constructor with just a value
    //Big-Oh: O(1)
    Node (T o){
      object = o;
      this->right = NULL;
      this->left = NULL;
    }
    //constructor with a value and a parent node (for assigning a parent)
    //Big-Oh: O(1)
    Node (Node* p, T o){
      parent = p;
      object = o;
      this->right = NULL;
      this->left = NULL;
    }
  };
public:
  Node* head;
  //empty constructor
  //Big-Oh: O(1)
  BinaryTree (){
    head = NULL;
  }
  //constructor with a starting value for the head
  //Big-Oh: O(1)
  BinaryTree (T o){
    head = new Node (o);
  }
  //deconstructor
  //Big-Oh: O(1), didnt count the runtime of execute, which is O(n)
  ~BinaryTree (){
    execute(head);
  }
  //execute is used to delete a node and all descendants of that node using the
  //post order traversal method
  //Big-Oh: O(n) where n is the number of descendants plus 1
  void execute (Node* start){
    if (start->left){
      execute (start->left);
    }
    if (start->right){
      execute (start->right);
    }
    delete (start);
  }
  //put takes a value and puts it where it belongs in the tree
  //Big-Oh: O(log(n))
  void put (T o){
    if (!head){
      head = new Node (o);
    } else {
      bool done = false;
      Node* current = head;
      //finds the location where the new object should be stored and puts a node with the object there
      while (!done){
        if (current->object < o){
          if (current->right){
            current = current->right;
          } else {
            current->right = new Node (current, o);
            done = true;
          }
        } else {
          if (current->left){
            current = current->left;
          } else {
            current->left = new Node (current, o);
            done = true;
          }
        }
      }
    }
  }
  //isThere finds an object if it is contained in the list and removes it. If it
  //finds the object it returns true, if not it returns false
  //Big-Oh: O(log(n)) I am not sure if the fact that this will often run a log(n)
  //method would affect the runtime as it only runs it once at most making this
  //2log(n), which is just log(n)
  bool isThere (T o){
    bool isThere = false;
    if (head->object == o){
      isThere = true;
      takeAway (head);
    } else {
      bool done = false;
      Node* current = head;
      while (!done){
        if (current->object < o){
          if (current->right){
            current = current->right;
          } else {
            done = true;
          }
        } else {
          if (current->left){
            current = current->left;
          } else {
            done = true;
          }
        }
        if (current->object == o){
          isThere = true;
          takeAway (current);
        }
      }
    }
    return isThere;
  }
  //takeAway removes a node from the tree
  //Big-Oh: O(log(n)) (techincally 2log(n), but that is not a problem)
  void takeAway (Node* target){
    T temp;
    Node* current = target;
//finds the first leaf in the tree with a bias to the right
//------------------------------------------------------------------------------
    while (current->right || current->left){
      if (current->right){
        current = current->right;
      } else {
        current = current->left;
      }
    }
//------------------------------------------------------------------------------
//This part checks if the target node was a leaf, and if it is, it just deletes it
//------------------------------------------------------------------------------
    if (current == target){
      if (current == head){ //has to acount for the value being the head
        head = NULL;
        delete (current);
      } else{
        if (current->parent->right == current){
          (current->parent->right) = NULL;
        } else {
          (current->parent->left) = NULL;
        }
        delete (current);
      }
//------------------------------------------------------------------------------
//if the nodes are differenet then it swaps their values so it can delete the leaf
//------------------------------------------------------------------------------
    } else {
      temp = target->object;
      target->object = current->object;
      current->object = target->object;
      if (current->parent->right == current){
        current->parent->right = NULL;
      } else {
        current ->parent->left = NULL;
      }
      delete (current);
//------------------------------------------------------------------------------
//then this ensures that the values swapped into the original position is shifted to where it belongs
//------------------------------------------------------------------------------
      bool done = false;
      current = target;
      while (!done){
        if (current->right && current->right->object < current->object){
          temp = current->object;
          current->object = current->right->object;
          current->right->object = temp;
          current = current->right;
        } else if (current->left && current->left->object > current->object){
          temp = current->object;
          current->object = current->left->object;
          current->left->object = temp;
          current = current->left;
        } else {
          done = true;
        }
      }
    }
//------------------------------------------------------------------------------
  }
  //print uses the in order traversal to cout all of the values contained in the tree
  //Big-Oh: O(n) where n is the size of the tree
  void print (){
    if (head){
      inOrder (head);
    } else {
      cout << " " << endl;
    }
  }
  void inOrder (Node* root){
    if (root->left){
      inOrder (root->left);
    }
    cout << root->object << endl;
    if (root->right){
      inOrder (root->right);
    }
  }
};
