// Code Written by : John Nixon
// Date: 19:10:2022  Time: 01:59:14
// Copyrights are applicable
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1e9 + 7
#define F first
#define S second
#define pb push_back
#define si set<int>
#define vi vector<int>
#define pii pair<int, int>
#define vpi vector<pii>
#define vpp vector<pair<int, pii>>
#define mii map<int, int>
#define mpi map<pii, int>
#define spi set<pii>
#define endl "\n"
#define sz(x) ((int)x.size())
#define all(p) p.begin(), p.end()
#define double long double
#define que_max priority_queue<int>
#define que_min priority_queue<int, vi, greater<int>>
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define print(a)          \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl
#define print1(a)    \
    for (auto x : a) \
    cout << x.F << " " << x.S << endl
#define print2(a, x, y)         \
    for (int i = x; i < y; i++) \
        cout << a[i] << " ";    \
    cout << endl
inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1)
            x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
const int N = 200005;
void solve()
{
    int n;
    vi asteroids;
    vi dirs;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int rad, d;
        cin >> d >> rad;
        dirs.pb(d);
        asteroids.pb(rad);
    }

    stack<pii> st;
    for (int i = 0;i<n;i++)
    {
        // stack is not empty and,
        // current element and top of stack have opposite signs
        while (!st.empty() && dirs[i] == 0 && st.top().F == 1)
        {
            int diff = -asteroids[i] + st.top().S;
            // diff is positive negative then current element value is greater
            // so element on top of stack gets destroyed.
            if (diff < 0)
                st.pop();
            // diff obtained is +ve then element at the top of the stack is greater
            // current element gets destroyed
            // we set x = 0 to exit from while loop and not add the current element to stack
            else if (diff > 0)
                break;
            // diff is zero then element at the top of the stack and current element is equal
            // hence both are destroyed hence pop from stack and set curr ele as zero
            else if (diff == 0)
            {
                
                st.pop();
                break;
            }
        }
        // only is x is not destroyed it is added to the stack
        if (asteroids[i])
            st.push({i,asteroids[i]}); 
    }
    vector<int> afterCollision;
    while (!st.empty())
    {
        afterCollision.push_back(st.top().F);
        st.pop();
    }
    reverse(afterCollision.begin(), afterCollision.end());
    cout << afterCollision.size() << endl;
    if (afterCollision.size())
    {
        print(afterCollision);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    clock_t z = clock();
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}