#include <iostream>
#include <map>
#include <set>

using namespace std;

struct S {
    int i;

    bool operator<(S other) const {
        return this->i < other.i;
    }
};

int main(void) {
    {
        cout << "Task 1: histogram (need input, cancel with <Ctrl-d> on UNIX" << endl;
        map<char, int> m;

        char c;
        while(cin >> c) {
            ++m[c];
        }

        map<char, int>::iterator it;
        for(it = m.begin(); it != m.end(); ++it) {
            cout << it->first << " : " << it->second << endl;
        }

        for(auto && pair : m) {
            cout << pair.first << " " << pair.second << endl;
        }

        for(auto && [c, count] : m) {
            cout << c << " " << count << endl;
        }

    }
    {
        cout << "Task 2: set of custom type" << endl;
        set<S> s{};
        s.insert(S{1});


        for(auto && el : s) {
            cout << el.i << endl;
        }
    }
}
