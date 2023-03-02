#include "Linked.h"

// List contructor
Linked::Linked() {
	head = nullptr;
  tail = nullptr;
  num_items = 0;
}

void Linked::push_back(string name){
  // adds node to the back of the list
  Node* newNode = new Node;
  newNode->name = name;
  newNode->next = nullptr;
  // checks if empty, if so then tail = head
  if (empty()){
    head = newNode;
    tail = newNode;
  }
  // if not empty, add to the end of list and reassign tail
  else{
    tail->next = newNode;
    tail = newNode;
  }
  //increment num_items
  num_items++;
}

void Linked::push_front(string name){
  // adds node to the front of the list
  Node* newNode = new Node;
  newNode->name = name;
  // checks if empty, if so then head = tail
  if (empty()){
    head = newNode;
    tail = newNode;
    newNode->next = nullptr;
  }
    // if not empty, add to the front of list and reassign head
  else{
    newNode->next = head;
    head = newNode;
  }
  //increment num_items
  num_items++;
}

void Linked::pop_back(){ //pop tail node
  //if empty do nothing
  if (empty()){
    return;
  }
  //if only one item in list, pop head = tail node
  if (head->next == nullptr){
    delete head;
    return;
  }
//if more than one item in list
  // Find the second last node
  Node* second_last = head;
  while (second_last->next->next != nullptr)
    second_last = second_last->next;

  // Delete last node and reassign tail
  delete second_last->next;
  second_last->next = nullptr;
  tail = second_last;
// decrement num_items
  num_items--;
}

void Linked::pop_front(){ //pop head node
  //if empty do nothing
  if (empty()){
    return;
  }
  //create temp space to hold head data
  Node* temp = new Node;
  temp = head;
// reassign head and delete old head space and data
  head = head->next;
  delete temp;
// decrement num_items
  num_items--;
}

string Linked::front(){ //return value of head node
  return head->name;
}

string Linked::back(){ //return value of tail node
  return tail->name;
}

bool Linked::empty(){ //check if empty. Return true if empty, return false if not empty
  if (num_items == 0)
    return true;
  return false;
}

void Linked::printList() { //prints the list by creating a temp node and assigning it to the head and then continuing down the list
  Node *tempPtr = new Node;
  tempPtr = head;
  while(tempPtr != nullptr){
    cout << tempPtr->name << endl;
    tempPtr = tempPtr->next;
  }
}

size_t Linked::find(const string n){ //finds index of name entered
  // intstantiate counter and temp node space
  int counter = 0;
  Node *temp = new Node;
  temp = head;
  
  while(temp != nullptr){
    if(temp->name == n){ // if name found, return the counter which equals the index
      return counter;
    }
    else{ //if not found yet, push assign temp to next node in list and increment counter
      temp = temp->next;
      counter++;
    }
  }
  // if never found, return counter which now equals num_items
  return counter;
}

bool Linked::remove(size_t index){
  
  int goal = index;
// instantiate temp node and prev node both pointing to head, later prev will be the node pointing to temp
  Node *temp = new Node;
  temp = head;
  Node *prev = new Node;
  prev = head;


  if(num_items - 1 < goal) //if index of node to remove is past the last item in list, do nothing and return false
    return false;
  else if (goal == 0){ //if goal is the head node pop front node and decrement num_items
    pop_front();
    num_items--;
    return true;
  }
  else if (goal == num_items - 1){ //if goal is the tail node pop back node and decrement num_items
    pop_back();
    num_items--;
    return true;
  }
  // if not any of the above cases, work through list until temp node is at index to remove
  for (int i = 0; i < goal; i++){
    temp = temp->next;
  } 
  // assign prev node to be pointing to temp
  for (int i = 0; i < goal - 1; i++){
    prev = prev->next;
  }
// make prev point to the node after temp, removing temp node from the list
  prev->next = prev->next->next;
  //free temp node space
  delete temp;
  //decrement num_items and return true since we removed a node
  num_items--;
  return true;
}

void Linked::insert(size_t index, const string n){ //inserts a node at the given index and incrememnts num_items
  if(index == 0 || empty()){ // if index is location of head node, push to front of list
    push_front(n);
    num_items++;
    return;
  }
  else if (index >= num_items){ // if index is equal to or greater than location of tail node, push to back of list
    push_back(n);
    num_items++;
    return;
  }
// instantiate temp node and prev node both pointing to head, later prev will be the node pointing to temp
  Node *temp = new Node;
  temp->name = n;
  
  Node *prev = new Node;
  prev = head;
// assign prev node to be pointing to node at node pointing to desired index
  for (int i = 0; i < index - 1; i++){
    prev = prev->next;
  }
// assign temp->next to point to desired index
  temp->next = prev->next;
  // connect inserted node to list by making node before, which used to be in desried index space, point to newly inserted node at the given index.
  prev->next = temp;
  num_items++;
  return;
  
}