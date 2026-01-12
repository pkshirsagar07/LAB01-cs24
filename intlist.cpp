// intlist.cpp
// Implements class IntList
// PAVANI KSHIRSAGAR 01/11/2026

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) : head(nullptr) {
    //IMPLEMENT THIS
    if(source.head == nullptr){
        return;
    }
    head = new Node;
    head->info = source.head->info;
    head->next = nullptr;

    Node* desCurr = head; 
    Node* srcCurr = source.head->next;

    while(srcCurr != nullptr){
        desCurr->next = new Node;
        desCurr = desCurr->next;
        desCurr->info = srcCurr->info;
        desCurr->next = nullptr; 
        srcCurr = srcCurr->next;
    }
    tail = desCurr;
}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
    Node* curr = head;
    while (curr){
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    // REPLACE THIS NON-SOLUTION
    int total = 0;
    Node* curr = head;
    while(curr){
        total += curr->info;
        curr = curr->next;
    }
    return total;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = head;
    while(curr){
        if(curr->info == value) return true;
        curr = curr->next;
    } 
    
    return false;// REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    // REPLACE THIS NON-SOLUTION
    if(!head){
        return 0;
    }
    int max = head->info;
    Node* curr = head;
    while(curr){
        if(curr->info > max) max = curr->info;
        curr = curr->next;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    // REPLACE THIS NON-SOLUTION
    int n = count();
    if(n==0) return 0.0;
    return static_cast<double>(sum())/n;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    // IMPLEMENT
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = head;
    head = newNode;
    if(tail == nullptr){
        tail = newNode;
    }
}

// append value at end of list
void IntList::push_back(int value) {
    // IMPLEMENT
    Node* newNode = new Node;
    newNode ->info = value;
    newNode->next = nullptr;

    if(!head){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

// return count of values
int IntList::count() const {
   int result = 0;
   Node* curr = head;
   while(curr){
    result++;
    curr = curr->next;
   }
   return result;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if(this != &source){
        Node *curr = head;
        while(curr){
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        head = nullptr;
    

    if(source.head){
        head= new Node;
        head->info = source.head->info;
        head->next = nullptr;

        Node* desCurr = head;
        Node* srcCurr = source.head->next;
        while(srcCurr){
            desCurr->next = new Node;
            desCurr = desCurr->next;
            desCurr->info = srcCurr->info;
            desCurr->next = nullptr;
            srcCurr = srcCurr->next;
        }
        tail = desCurr;
    }
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList() : head(nullptr), tail(nullptr){ 
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

