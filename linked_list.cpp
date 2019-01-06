/*

  linked_list.cpp

 */

// AUTHOR: KL Wolley
// WHAT: CSCI 2270 Assignment 1

#include "linked_list.h"
#include <iostream> 
#include <string>
#include <sstream>
using namespace std;

// create a new node structure that points to NULL and holds the
// provided integer. return a pointer to that new node.
node* init_node(int data) {
 node* outdat = new node;  // return variables OutDat assigned persistent node ("new") node
 outdat -> data = data; // asign data value to the one that was input by user
 outdat -> next = NULL; // point to the 0 (NULL) address
 return outdat;
}

// create a space-separated string representing the contents of the
// list, in the same order they are found beginning from the head of
// the list. return that string object.  For example, this might
// return "" (the empty string) if the list is empty, or it might
// return "1 7 3" or "1 7 3 " (note the space at the end, you can have
// that there and it is OK).
string report(node* head) {
  if (head == NULL) {
    return ""; // return empty string
    } else {
      string tmp = "";
      while (head != NULL) {
        tmp += " " + std::to_string(head->data); 
        head = head->next; 
      }
      return tmp;
    }
}

// insert an integer into the list pointed to by top. the resulting
// list is one element longer, and the newly appended node has the
// given data value. consider using the 'append' function to help.
void append_data(node** top, int data) {
  node* new_node = new node;
  new_node -> data = data;
  new_node -> next = NULL;
  if (*top == NULL) {    // if this is empty...
    *top = new_node;
    return;
  } else {
     //create new node call cursor and have it point to the same thing as top
    node* cursor = *top; // node pointer called cursor is now pointing to the top
    while (cursor -> next != NULL) { //(cursor -> next != NULL) {
      cursor = cursor -> next; // point to next element
    }
    cursor -> next = new_node;
    return;
 }
}

// this is the same as append_data, except we're adding a node, rather
// than a value. 
void append(node** top, node* new_node) {
  if (*top == NULL) { // if this is empty...
    *top = new_node; // make the first item of the list point to new_node 
    return;
  } else {
     //create new node call cursor and have it point to the same thing as top
    node* cursor = *top; // node pointer called cursor is now pointing to the top
    while (cursor -> next != NULL) { //(cursor -> next != NULL) {
      cursor = cursor -> next; // point to next element
    }
    cursor -> next = new_node;
    return;
 }
}

// similar to append_data. insert a new node that contains the given
// data value, such that the new node occupies the offset
// indicated. Any nodes that were already in the list at that offset
// and beyond are shifted down by one. For example if the list
// contains 23, 74, 93, and we insert 42 at index 1, the resulting
// list should be 23, 42, 74, 93.
void insert_data(node** top, int offset, int data) {
  int count = 1;
  node* cursor = *top;
  node* n = new node;
  n -> data = data;
  n -> next = NULL;
  if (offset == 0){
    *top = n;
    n -> next = cursor;
    return;
  } else {
    while (count != offset) {
      count++;
      cursor = cursor -> next;
    }
    node* n = new node;
    n -> data = data;
    n -> next = cursor -> next;
    cursor -> next = n;
    return;
  }
}

// this is the same as insert_data, except we're inserting a node,
// rather than a value.
void insert(node** top, int offset, node* new_node) {
  int count = 1; // start counter
  node* cursor = *top; // create the cursor
  if (offset == 0) { // if the offset is to occur at position 0
    *top = new_node;
    new_node -> next = cursor;
    return;
  } 
  while (count != offset){
    count++;
    cursor = cursor -> next;    
  }
  new_node -> next = cursor -> next;
  cursor -> next = new_node;
  return;
}

// remove the node indicated by the given offset. For example if our
// list contains 23, 74, 93, and we remove offset 1, the resulting
// list should then contain 23, 93.
void remove(node** top, int offset) {
  node* cursor = *top;
  node* prev_node = cursor;
  if (offset == 0) {  // if offset is 0 (delete first node)
    *top = cursor -> next;  // set the pointer top to the next value in cursor
    delete(cursor); // delete cursor
    return;
  }
  int count = 0; //init counter
  while (count < offset) { //until the offset is reached, increment cursor and couner
    prev_node = cursor;
    cursor  = cursor -> next;
    count++;
  }
  prev_node -> next = cursor -> next; // when offset is reached connect the previous pointer to the pointer following offset
  return;
}

// report the number of nodes in the linked list pointed to by head.
int size(node* head) {
  int count = 0; //initialize new counter
  if (head == NULL){
    return 0;
  }
  node* cursor = head;
  while(cursor != NULL){
    cursor = cursor -> next;
    count++;
  }
  return count;
}

// return true if the linked list pointed to by head contains a node
// with the specified value.
bool contains(node* head, int data) {
  node* cursor = head;
  while(cursor != NULL){
    if (cursor -> data == data) {
      return true;
    }
    cursor = cursor -> next;
  }
  return false;
}


