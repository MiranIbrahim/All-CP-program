#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long x, y, k;
        cin >> x >> y >> k;

        double mvx = ceil((double)x / (double)k);
        double mvy = ceil((double)y / (double)k);

        long long ans = mvx + mvy + abs(mvx - mvy);
        
        if (mvx > mvy)
            ans--;

        cout << ans << endl;
    }

    return 0;
}
