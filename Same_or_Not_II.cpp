#include<bits/stdc++.h>
using namespace std;
class Stack{
    public:
        list <int> li;
    void pb(int val){
        li.push_back(val);
    }
    int top(){
        return li.back();
    }
    void pop(){
        li.pop_back();
    }
    bool empty(){
        return li.empty();
    }
};
class Queue{
    public:
        list <int> li;
    void pb(int val){
        li.push_back(val);
    }
    int front(){
        return li.front();
    }
    void pop(){
        li.pop_front();
    }
    bool empty(){
        return li.empty();
    }
};
int main(){
    Stack stk;
    Queue q;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        stk.pb(x);
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        q.pb(x);
    }
    
    if (n != m) {
        cout << "NO" << endl;
        return 0;
    }

    bool same = true;
    while (!stk.empty() && !q.empty()) {
        if (stk.top() != q.front()) {
            same = false;
            break;
        }
        stk.pop();
        q.pop();
    }

    if (same && stk.empty() && q.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}