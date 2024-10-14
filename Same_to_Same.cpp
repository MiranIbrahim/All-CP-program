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

void insertToList(Node * &head, Node * &tail) {
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
}

int main() {
    Node *head1 = NULL;
    Node *tail1 = NULL;

    Node *head2 = NULL;
    Node *tail2 = NULL;

    insertToList(head1, tail1);
    insertToList(head2, tail2);

    Node *temp1 = head1;
    Node *temp2 = head2;
    bool flag = true;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->val != temp2->val) {
            flag = false;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if (temp1 != NULL || temp2 != NULL) {
        flag = false;
    }

    if (!flag) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

    return 0;
}
