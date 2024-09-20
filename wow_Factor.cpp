#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        long long x;
        cin >> s >> x;
        int n = s.size();
        vector<int> wow_count(n + 1, 0);

        // Calculate how many "wow" subsequences end at each index
        for (int i = 2; i < n; i++) {
            wow_count[i + 1] = wow_count[i];
            if (s[i - 2] == 'w' && s[i - 1] == 'o' && s[i] == 'w') {
                wow_count[i + 1]++;
            }
        }

        // Sliding window to find the largest substring with exactly x "wow" subsequences
        int left = 0, right = 0;
        int start = -1, end = -1;
        while (right < n) {
            long long count_wow = wow_count[right + 1] - wow_count[left];
            
            if (count_wow < x) {
                right++;
            } else if (count_wow > x) {
                left++;
            } else {
                if (start == -1 || right - left > end - start) {
                    start = left;
                    end = right;
                }
                right++;
            }
        }

        if (start == -1) {
            cout << "-1" << endl;
        } else {
            cout << start + 1 << " " << end + 1 << endl;
        }
    }
    
    return 0;
}
