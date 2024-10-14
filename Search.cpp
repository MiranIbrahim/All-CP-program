#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void solve() {
    Node *head = NULL;
    Node *tail = NULL;

    while (1) {
        int x;
        cin >> x;
        if (x == -1) {
            break;
        }
        Node *newNode = new Node(x);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    int target;
    cin >> target;

    if (head == NULL) {
        cout << -1 << endl;
    } else {
        Node *temp = head;
        int idx = 0;
        bool flag = false;
        while (temp != NULL) {
            if (temp->val == target) {
                cout << idx << endl;
                flag = true;
                break;
            }
            idx++;
            temp = temp->next;
        }
        if (!flag) {
            cout << -1 << endl;
        }
    }
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}
