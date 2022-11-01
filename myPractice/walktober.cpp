// Code Written by : John Nixon
// Date: 29:10:2022  Time: 09:50:55
// Copyrights are applicable
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long int>
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);

    int t;
    cin >> t;
    int cases = 1;
    while (cases <=t)
    {
        int m, n, p;
        cin >> m >> n >> p;

        map<int, vi> mp;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int x;
                cin >> x;
                mp[i].push_back(x);
            }
        }

        int req = 0;

        vi john = mp[p];

        // print(john);
        for (int day = 0; day < n; day++)
        {
            int day_max = 0;
            for (int player = 1; player <= m; player++)
            {
                if (player == p)
                    continue;
                day_max = max(day_max, mp[player][day]);
            }
            int johns_score = john[day];
            // cout<<johns_score<<" "<<day_max<<endl;
            if (johns_score < day_max)
            {
                req += abs(johns_score - day_max);
            }
        }

        // return req;
        cout << "Case #" << cases << ": " << req << endl;
        cases++;
    }
}