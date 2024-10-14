#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *prev, * next;
    Node(int val){
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insert_at_tail(Node * &head, int val, Node *& tail){
    Node * newNode = new Node(val);

    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

void print_list (Node * head){
    Node *temp = head;
    while(temp!= NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void print_list_reverse (Node * tail){
    Node *temp = tail;
    while(temp!= NULL){
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}
int size(Node * head){
    int sz = 0;
    Node * temp = head;
    while(temp != NULL){
        sz++;
        temp = temp->next;
    }
    return sz;
}
void insert_at_position(Node * &head,Node * & tail, int pos, int val){
    Node *newNode = new Node(val);
    if(pos <= 1){
        newNode->next = head;
        head->prev = newNode;
        head = newNode; 
    }
    else if(pos > size(head)){
        cout << "\nInvalid position\n";
    }
    // else if (pos == size(head)){
    //     newNode->prev = tail;
    //     tail->next = newNode;
    //     tail = newNode;
    // }
    else{
        Node * temp = head;
        for(int i = 1; i< pos-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->next->prev = newNode;
        newNode->prev = temp;
    }
}

void delete_nth_node(Node * & head, Node * & tail, int pos){
    if( pos <=1){
        Node * delNode = head;
        head = head->next;
        if(head == NULL){
            tail = NULL;
            return;    
        }
        head->prev = NULL;
        delete delNode;
    }
    else if( pos == size(head)){
        Node * delNode = tail;
        tail = tail->prev;
        if(tail == NULL){
            head = NULL;
            return;
        }
        tail->next = NULL;
        delete delNode;
    }
    else if ( pos > size(head)){
        cout << "Invalid position\n";
    }
    else {
        Node * temp = head;
        for(int i = 1; i< pos-1; i++){
            temp = temp->next;
        }
        Node * delNode = temp->next;
        temp->next = temp->next->next;
        delNode->next->prev = temp;
        delete delNode;
    }
}
void reverse_list(Node * & head, Node * tail){
    Node * i = head;
    Node * j = tail;
    while(i != j && i->next != j){
        swap(i->val , j->val);
        i = i->next;
        j = j->prev;
    }
    swap(i->val, j->val);
    
}
int main(){
    Node * head = NULL;
    Node * tail = NULL;

    while(1){
        cout << "Welcome to Linked List\nPlease choose an option\n1. Insert elements at tail\n2. Size\n3. Insert at specific position\n4. Delete nth node\n5. Reverse List\n6. Print Middle\n7. Print Recursive order\n8. Exit\n";
        int x;
        cout << "Enter an your option:";
        cin >> x;
        cout << endl;

        if( x == 1 ){
            int val; 
            cout << "Enter values: ";
            while(1){
                cin >> val;
                if(val == -1){
                    break;
                }
                insert_at_tail(head, val, tail);
            }
            print_list(head);
            print_list_reverse(tail);
        }
        if(x == 2){
            cout <<"size of the list: " << size(head) << endl;
        }
        if(x == 3){
            int pos , val;
            cout << "Enter Position and value: ";
            cin >> pos >> val;
            insert_at_position(head, tail, pos, val);
            print_list(head);
            print_list_reverse(tail);
        }
        if(x == 4){
            int n;
            cout << "Enter the index that you want to delete: ";
            cin >> n;
            delete_nth_node(head, tail, n);
            print_list(head);
            print_list_reverse(tail);
        }
        if(x == 5){
            reverse_list(head, tail);
            print_list(head);
            print_list_reverse(tail);
        }
        if(x == 8){
            break;
        }
    }
    return 0;
}