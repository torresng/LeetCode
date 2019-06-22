#include <iostream>
#include <set>

using namespace std;

int main(void) {
    set<int> s{{1, 5, 3}};
    cout << *(s.lower_bound(2)) << endl;
    if(s.lower_bound(2) == s.end()) {
        cout << "test" << endl;
    }


    return 0;
}
