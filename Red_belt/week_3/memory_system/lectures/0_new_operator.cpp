//
// Created by General on 28.08.2020.
//


#include <iostream>
#include <string>
using namespace std;

// Compiled program is stored in text segment (RO usually)
// Uninitialized global and static variables are stored in bss segment
// Initialized global and static variables are stored data_ segment
// Dynamic structures are stored in heap
// All local variables are stored in call-stack


int main() {

    // Video about "new"
    int* pInt = new int;

    *pInt = 7;

    // String initially have const_size and relocates, if it is necessary
    // For class types default constructor is called with new
    string* s = new string;
    *s = "Hello";
    cout << *s << s->size() << endl;
    string& ref_to_str = *s;
    ref_to_str += ", world";
    cout << *s << endl;

    // *ptr inits with 42
    int* ptr = new int(42);

    return 0;
}