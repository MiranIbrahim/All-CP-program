#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> trainingTime(n);
    vector<int> selfLearningTime(n);
    
    for (int i = 0; i < n; i++) {
        cin >> trainingTime[i]; 
    }
    
    for (int i = 0; i < n; i++) {
        cin >> selfLearningTime[i]; 
    }
    
    vector<pair<int, int>> joiners;
    for (int i = 0; i < n; i++) {
        joiners.push_back({selfLearningTime[i], trainingTime[i]});
    }

    sort(joiners.rbegin(), joiners.rend());

    int currentDay = 0;
    int totalDays = 0;

    for (int i = 0; i < n; i++) {
        currentDay += joiners[i].second;
        totalDays = max(totalDays, currentDay + joiners[i].first)+1;
    }

    cout << totalDays << endl;

    return 0;
}
