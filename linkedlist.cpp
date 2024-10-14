#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node * next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void insertData(Node * &head, int data){
    Node *newNode = new Node(data);
    if(head == NULL){
        head = newNode;
    }
    else{
    Node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
       
    }
    temp->next = newNode;
    }
}
void printList(Node * head){
    if(head == NULL){
        cout << "No data in the list\n";
        return;
    }
    Node * temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insert_at_position(Node * &head, int pos, int val){
    Node *newNode = new Node(val);
    if(pos <=1 ){
        newNode->next = head;
        head = newNode;
        return; 
    }
    Node *temp = head;
    for(int i = 1; i< pos-1; i++){
        temp = temp->next;
        if(temp == NULL){
            cout << "Invalid position\n";
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void delete_nth_node(Node * &head, int pos){
    if(pos <=1 ){
        Node *deleteNode = head;
        head = head->next;
        delete deleteNode;
        return; 
    }
    Node *temp = head;
    for(int i = 1; i< pos-1; i++){
        temp = temp->next;
        if(temp == NULL){
            cout << "Invalid position\n";
            return;
        }
    }
    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
}
void list_size(Node * &head){
    Node *temp = head;
    int c = 0;
    while(temp!=NULL){
        c++;
        temp = temp->next;
    }
    cout << endl << c << endl;
}
bool contains_duplicates(Node* head) {
    bool seen[101] = { false }; 
    Node* temp = head;
    while (temp != NULL) {
        if (seen[temp->val]) {
            return true; 
        }
        seen[temp->val] = true;
        temp = temp->next;
    }
    return false; 
}
void printMiddle(Node* head) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast == NULL) {
        Node* temp = head;
        while (temp->next != slow) {
            temp = temp->next;
        }
        cout << "The middle elements are: " << temp->val << " and " << slow->val << endl;
    } else {
        cout << "The middle element is: " << slow->val << endl;
    }
}
void print_recursive(Node * n){
    if(n == NULL){
        return;                                                 
    }
    print_recursive(n->next);
    cout << n->val << " ";
}

void reverse_list(Node * & head, Node * curr){
    if( curr->next == NULL){
        head = curr;
        return;
    }
    reverse_list(head, curr->next);
    curr->next->next = curr;
    curr->next = NULL;

}
int main(){
    Node * head = NULL;
    while (1){
        cout << "Welcome to Linked List\nPlease choose an option\n1. Insert an element\n2. Print list\n3. Insert at specific position\n4. Delete nth node\n5. Size\n6. Check for duplicates\n7. Print Middle\n8. Print Recursive order\n9. Reverse List\n10. Exit";
        int x;
        cout << "Enter an your option:";
        cin >> x;
        cout << endl;
        if(x == 1){
            cout << "\nhow many data do you want to insert?: ";
            int n;
            cin >> n;
            cout << "\nEnter values: ";
            for(int i = 0; i<n; i++){
                int data;
                cin >> data;
                cout << endl;
                insertData(head, data);     
            }
        }
        if(x == 2){
            printList(head); 
        }
        if(x == 3){
            int pos, val;
            cout << "Enter position: ";
            cin >> pos;
            cout << "\nEnter value: ";
            cin >> val;
            insert_at_position(head, pos, val);
        }
        if(x == 4){
            cout << "Insert which position you want to delete: ";
            int n;
            cin >> n;
            delete_nth_node(head, n);
        }
        if(x == 5){
            list_size(head);
        }
        if (x == 6) {
            if (contains_duplicates(head)) {
                cout << "The list contains duplicates.\n";
            } else {
                cout << "The list does not contain any duplicates.\n";
            }
        }
        if(x == 7){
            printMiddle(head);
        }
        if(x==8){
            print_recursive(head);
        }
        if(x == 9){
            reverse_list(head, head);
        }
        if(x == 10){
            break;
        }
    }
    
    return 0;
}