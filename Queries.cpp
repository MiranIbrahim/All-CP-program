#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertHead(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insertTail(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node(value);
    if (tail == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteIndex(Node*& head, Node*& tail, int index) {
    if (index < 0 || head == NULL) return;

    if (index == 0) {
        Node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        delete temp;
        return;
    }

    Node* current = head;
    for (int i = 0; i < index - 1; ++i) {
        if (current->next == NULL) return;
        current = current->next;
    }

    if (current->next == NULL) return;

    Node* temp = current->next;
    current->next = current->next->next;
    if (current->next == NULL) {
        tail = current;
    }
    delete temp;
}

int main() {
    int Q;
    cin >> Q;

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < Q; ++i) {
        int X, V;
        cin >> X >> V;
        
        if (X == 0) {
            insertHead(head, V);
            if (tail == NULL) tail = head;
        } else if (X == 1) {
            insertTail(head, tail, V);
        } else if (X == 2) {
            deleteIndex(head, tail, V);
        }

        printList(head);
    }
    return 0;
}
