// Gavin Hewitt

/*
  A C++ Implementation of the Binary Search Tree data structure.
*/

#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string.h>
using std::string;
using std::to_string;

// Class for each node within the tree (where data and links are stored)
class Node {
  friend class BinarySearchTree;
  public:
    Node(int data) {
      (*this).data = data;
      rightChild = leftChild = nullptr;
    }
  private:
    int data;
    Node *rightChild;
    Node *leftChild;
};

class BinarySearchTree {
  public:
    BinarySearchTree() {
      root = nullptr;
    }
    void add(int data) {
      if (root == nullptr)
        root = new Node(data);
      else
        add(root, data);
    }
    void remove(int data) {
      root = remove(root, data);
    }
    void search(int data) {
      search(root, data);
    }
    int findMin() {
      return (*findMin(root)).data;
    }
    int findMax() {
      return (*findMax(root)).data;
    }
    void print() {
      cout << "BST Nodes are: ";
      print(root);
      cout << endl;
    }
  private:
    Node *root;
    Node * add(Node * node, int data) {
      if (node == nullptr) 
        return new Node(data);
      else if (data < (*node).data) 
        (*node).leftChild = add((*node).leftChild, data); 
      else if (data > (*node).data)
        (*node).rightChild = add((*node).rightChild, data);
      else if (data == (*node).data)
        cout << "Node " << data << " is a duplicate node. Cannot insert Node " << data << " again." << endl;
      return node;
    }
    void search(Node * node, int data) {
      if (node == nullptr) {
        cout << "search key not found" << endl;
      } else if (data < (*node).data) {
        cout << (*node).data << "->";
        search((*node).leftChild, data);
      } else if (data > (*node).data) {
        cout << (*node).data << "->";
        search((*node).rightChild, data);
      } else {
        cout << (*node).data << endl;
      }
    }
    Node * remove(Node * node, int data) {
      if (node == nullptr)
        return nullptr;
      else if(data < (*node).data)
        (*node).leftChild = remove((*node).leftChild, data);
      else if (data > (*node).data)
        (*node).rightChild = remove((*node).rightChild, data);
      else {
        if ((*node).rightChild == nullptr)
          return (*node).leftChild;
        else if((*node).leftChild == nullptr)
          return (*node).rightChild;
        Node *temp = findMin((*node).rightChild);
        (*node).data = (*temp).data;
        (*node).rightChild = remove((*node).rightChild, (*temp).data);
      }
      return node;
    }
    Node * findMin(Node * node) {
      if (node == nullptr)
        return nullptr;
      else if ((*node).leftChild == nullptr)
        return node;
      else
        return findMin((*node).leftChild);
    }
    Node * findMax(Node * node) {
      if (node == nullptr)
        return nullptr;
      else if ((*node).rightChild == nullptr)
        return node;
      else
        return findMax((*node).rightChild);
    }
    void print(Node * node) {
      if (node == nullptr)
        return;
      print((*node).leftChild);
      cout << (*node).data << ", ";
      print((*node).rightChild);
    }
};

int main() {
  int size;
  cout << "How many nodes would you like to add? ";
  cin >> size;
  BinarySearchTree * tree = new BinarySearchTree();
  int data;
  for (int i = 0; i < size; ++i) {
    cout << "Insert node " << (i + 1) << ": ";
    cin >> data;
    (*tree).add(data);
  }
  (*tree).print();
  int input;
  bool cont = true;
  while(cont) {
    cout << "What would you like to do? 1. Insert, 2. Search, 3. Delete, 4. Min Value, 5. Max Value, 6. Exit ";
    cin >> input;
    switch(input) {
      case 1:
        cout << "Insert node ";
        cin >> data;
        (*tree).add(data);
        (*tree).print();
        break;
      case 2:
        cout << "Search for node ";
        cin >> data;
        (*tree).search(data);
        (*tree).print();
        break;
      case 3:
        cout << "Delete node ";
        cin >> data;
        (*tree).remove(data);
        (*tree).print();
        break;
      case 4:
        cout << "BST Node with the smallest value" << endl << "Node " << (*tree).findMin() << endl;
        (*tree).print();
        break;
      case 5:
        cout << "BST Node with the largest value" << endl << "Node " << (*tree).findMax() << endl;
        (*tree).print();
        break;
      case 6:
        cont = false;
        break;
      default:
        cout << "Invalid input. Please choose from the options provided." << endl;
        break;
    }
  }

  delete tree;

  return 0;
}
