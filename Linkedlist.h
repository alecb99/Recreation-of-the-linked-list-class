#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef int element_type;
typedef element_type& reference;
typedef const element_type& const_reference;

class Linkedlist {

public:
Linkedlist(); //default constructor for empty list
~Linkedlist(); //destructor to free nodes dynamically created to support the linklist
bool empty() const;
void clear();
reference back();
const_reference back() const;
reference front();
const_reference front() const;
Linkedlist& operator=(const Linkedlist& l);
void pop_back ();
void pop_front ();
void push_back (const element_type& x);
void push_front (const element_type& x);
void sort ();
void erase(unsigned int pos);
explicit Linkedlist(unsigned int n);
void check() const;
void rcheck() const;
void insert(unsigned int pos, const element_type& x);
private:
struct Node; 
Node * head;
Node * tail;
}; 
#endif /* LINKEDLIST_H */
