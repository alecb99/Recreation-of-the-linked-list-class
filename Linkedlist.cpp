#include "Linkedlist.h"
#include <iostream>
#include <iomanip>
using namespace std;


struct Linkedlist::Node
{
    element_type elem;  
    Node * next;
    Node * prev; 
};

Linkedlist::Linkedlist()
{
    head = NULL;
    tail = NULL;
}

Linkedlist::~Linkedlist()
{
    Node * current = head;
    while(current != NULL)
     {
        Node* next = current->next;
        delete current;
        current = next;
    }
head = NULL;
tail = NULL;
}

Linkedlist::Linkedlist(unsigned int n)
{
        head = new Node();
        head-> next = NULL;
        head-> prev = NULL;
        head-> elem = 0;
        tail = head;
        for(int i = 1; i < n; i++){
            Node * temp = new Node();
            temp -> elem = i;
            temp->prev = tail;
            temp -> next = NULL;
            tail -> next = temp;
            tail = temp;
    }
}
bool Linkedlist::empty() const
{
    
    if(head == NULL)
    return true;

    else
    {
        return false;
    }
    
}

void Linkedlist::check() const
{
    Node* current = head;
    if (current == NULL)
    cout << "It is an empty list!" << endl;

        int i = 0;
        while (current != NULL) 
         {
             cout << "Node "     << setw(3) << i  << "   "
             << "Elem: "         << setw(3) << current->elem << "   "
             << "Address: "      << setw(8) << current       << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;

        current = current->next;

        i++;
    }
    cout << "----------------------------------------------------" << endl;
}
void Linkedlist::clear()
{   
   Node* current = head;
   Node* temp = head;
   delete temp;
   head = NULL;
   tail = NULL;
}

void Linkedlist::rcheck() const
{

    Node* current = tail;    

    if (current == NULL)
    cout << "It is an empty list!" << endl;
    
    int i = 0;
    while (current != NULL) 
    {
        cout << "Node "          << setw(3) << i             << "   "
             << "Elem: "         << setw(3) << current->elem << "   "
             << "Address: "      << setw(8) << current       << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;
        current = current->prev;
        i++;

    }
}

void Linkedlist::pop_back()
{
    Node* temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete temp;
}

void Linkedlist::pop_front()
{
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}

void Linkedlist::push_back(const element_type& x)
{
    Node* temp = new Node();
    temp->elem = x;
    temp->prev = tail;
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
}

void Linkedlist::push_front(const element_type& x)
{
    Node* temp = new Node();
    temp->elem = x;
    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void Linkedlist::erase(unsigned int pos)
{
    Node * key = new Node();
    key = head;
    int counter = 0;

    if(this -> empty() == true)
    return;

    while(key != NULL )
    {
        counter++;
        key = key -> next;
    }
    key = NULL;
    delete key;

    if(head == tail)
    {
        delete head;
        head = NULL;
        tail = head;
        return;
    }


    if(pos > counter)
    {
        Node * temp = tail;
        tail = tail -> prev;
        tail -> next = NULL;
        delete temp;
    }

    if(pos <= counter && pos >= 0)
    {
        Node* pen = head;
        if (pos != 0 && pos!= counter -1){
        for(int i = 0; i < pos; i++)
        {
            pen = pen -> next;
        }
        pen -> prev -> next = pen -> next;
        pen -> next -> prev = pen -> prev;
        }
        if (pos == 0)
        {
            head = pen -> next;
            head -> prev = NULL;
        }
        if(pos == counter -1)
        {
            pen = tail;
            tail = pen -> prev;
            tail -> next = NULL;
        }
        delete pen;
    }
}

void Linkedlist::sort() 
{
    Node *ptr = new Node();
    Node *temp = new Node();

    if (head == NULL)
     return;

    if (head->next == NULL) 
     return;

    int swapped = 1;
    while (swapped) {
        swapped = 0;
        ptr = head;
        while (ptr->next != NULL) {
            if (ptr->elem > ptr->next->elem) {

                swapped = 1;

                temp->elem = ptr->elem;
                ptr->elem = ptr->next->elem;
                ptr->next->elem = temp->elem;
            }
            ptr = ptr->next;
        }
    }
}

Linkedlist& Linkedlist::operator=(const Linkedlist& l)
{   cout << " I have copied it" << endl;
    if (this == &l) {
        return *this;
    }
    Node *temp;
    temp = l.head;
    this ->clear();
    Node* copy = new Node();
    copy -> prev = NULL;
    copy -> next = NULL;
    copy -> elem = temp -> elem;
    head = copy;
    tail = copy;
    temp = temp -> next;
    while(temp != NULL)
    {   Node* copy = new Node();
        this->push_back(temp -> elem);
        temp = temp -> next;
    }
    return *this;
}

reference Linkedlist::back()
{
    return tail -> elem;
}

reference Linkedlist::front()
{
    return head -> elem;
}

const_reference Linkedlist::back() const
{
    return tail -> elem;
}

const_reference Linkedlist::front() const
{
    return head -> elem; 
}

