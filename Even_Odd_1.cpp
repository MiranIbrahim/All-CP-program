#include <bits/stdc++.h>
using namespace std;

// Reads two integers and prints their sum
void basicIO() {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
}

int main() {
    int t;
    cin >>t;
    while(t--){
        string s;
        cin >> s;
        
        int len = s.length();
        int lastDigit = s[s.length()-1] - '0';
        if(lastDigit %2 == 0) 
            cout << "even\n";
        else 
            cout << "odd\n";
        
    }
    return 0;
}
