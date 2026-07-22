// This is a test file given for reference.

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){
    List l;
    l.push_front(2);
    l.push_front(1);
    l.push_back(3);
    l.push_back(5);
    l.displayLL();

    l.insert(4, 4);
    l.displayLL();
    
    return 0;
}
