#include "Linkedlist.cpp"
#include <iostream>
#include <cstring>

using namespace std;

int main ()
{
 Linkedlist clear_list(3);

clear_list.clear();
clear_list.check();
clear_list.rcheck();
cout << "this is the clear test" << endl;
cout<< endl;

Linkedlist l_erase;
l_erase.erase(45);
l_erase.check();
cout << "erase test" << endl;
cout<< endl;

Linkedlist l1(5);
l1.check();
l1.pop_back();
l1.check();
cout << "this is the pop back test" << endl;
cout<< endl;

Linkedlist l2(3);
l2.check();
l2.pop_front();
l2.check();
cout << "this is the pop front test" << endl;
cout<< endl;

Linkedlist l3(4);
l3.check();
l3.push_back(11);
l3.check();
cout << "this is the push back test" << endl;
cout<< endl;

Linkedlist l4(4);
l4.check();
l4.push_front(9);
l4.check();
cout << "this is the push front test" << endl;
cout<< endl;

Linkedlist l5(5);
l5.check();
l5.erase(4);
l5.check();
cout << "this is the erase test" << endl;
cout<< endl;

Linkedlist l10(6);
l10.check();
l10.push_back(-3);
l10.check();
cout << "pre sort method, added an element of -3" << endl;
l10.sort();
l10.check();
cout << "this is the sort test" << endl;
cout<< endl;

Linkedlist l6(1);
Linkedlist l7(5);                                                                      
l6 = l7;
l6.check();
cout << "equal check" << endl;
cout << endl;

const Linkedlist l8(5);
l8.front();
l8.check();
cout << "const check" << endl;

return 0;
}

