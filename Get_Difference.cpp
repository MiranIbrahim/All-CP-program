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

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    int min = INT_MAX;
    int max = INT_MIN;

    while (1) {
        int x;
        cin >> x;
        if (x == -1) {
            break;
        }
        if (x < min) {
            min = x;
        }
        if (x > max) {
            max = x;
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
    
    if (head == NULL) {
        cout << 0 << endl;
    } else {
        cout << max - min << endl;
    }

    return 0;
}
