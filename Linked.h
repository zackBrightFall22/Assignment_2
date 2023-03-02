#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// Node struct to serve as list structure
// I chose to make the list a list of names, based on the example seen in class.
struct Node {
	string name;
	Node* next;

};

class Linked {
private:
// Required member variables
	Node* head;
  Node* tail;
  size_t num_items;

public:
// Required mamber functions
	Linked();
  bool empty();
  void push_back(string name); 
  void push_front(string name);
  void pop_back(); 
  void pop_front(); 
  string front(); 
  string back(); 
  size_t find(const string name); 
  bool remove(size_t index); 
  void insert(size_t index, const string name); 
// Extra member function I added
  void printList();
};