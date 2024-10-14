#include <bits/stdc++.h>
using namespace std;

void printList(const list<int>& lst) {
    cout << "L -> ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "R -> ";
    for (auto it = lst.rbegin(); it != lst.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    int q;
    cin >> q;
    list<int> lst;
    
    while(q--) {
        int x, v;
        cin >> x >> v;
        
        if (x == 0) 
            lst.push_front(v);
         
        else if (x == 1) 
            lst.push_back(v);

        else if (x == 2)
        {
            if (v >= 0 && v < static_cast<int>(lst.size())) {
                auto it = lst.begin();
                advance(it, v);
                lst.erase(it);
            }
        }
        printList(lst);
    }
    
    return 0;
}
