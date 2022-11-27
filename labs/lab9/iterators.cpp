#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

void print(vector<int>::const_iterator begin, vector<int>::const_iterator end) {
    cerr << "call: void print(vector<int>::const_iterator begin, vector<int>::const_iterator end)" << endl;
}

template<typename Iterator>
void print(Iterator begin, Iterator end) {
    cerr << "call: void print(Iterator begin, Iterator end)" << endl;
}

void bubblesort(vector<int>::iterator begin, vector<int>::iterator end) {
    cerr << "call: void bubblesort(vector<int>::iterator begin, vector<int>::iterator end)" << endl;
}

template<typename Iterator>
void bubblesort(Iterator begin, Iterator end) {
    cerr << "call: void void bubblesort(Iterator begin, Iterator end)" << endl;
}

struct S {
    int i;
};

int main(void) {
#if 1
    {
        cout << "Task 1: print vector of ints" << endl;
    }
#endif
#if 0
    {
        cout << "Task 2: bubblesort vector of ints" << endl;
    }
#endif
#if 0
    {
        cout << "Task 3: print vector of floats as well as set of ints" << endl;
    }
#endif
#if 0
    {
        cout << "Task 4: bubblesort on different vectory type" << endl;
    }
#endif
#if 0
    {
        cout << "Task 5: histogram (need input, cancel with <Ctrl-d> on UNIX" << endl;
    }
#endif
#if 0
    {
        cout << "Task 6: set of custom type" << endl;
    }
#endif
}
