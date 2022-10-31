// Code Written by : John Nixon
// Date: 26:10:2022  Time: 20:32:19
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

// Chef has an array AA of length NN. In one operation, Chef can:

// Choose any subarray [L, R][L,R] (1 \leq L \leq R \leq N)(1≤L≤R≤N);
// Add 11 to A_LA
// L
// ​
//  , subtract 11 from A_{L+1}A
// L+1
// ​
//  , add 11 to A_{L+2}A
// L+2
// ​
//  , subtract 11 from A_{L+3}A
// L+3
// ​
//   and so on, till A_RA
// R
// ​
//  .

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
    int n, q;
    cin>>n>>q;
    // cout << n << " " << q << endl;
    vi arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.pb(x);
    }

    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        int total = abs(l-(r+1));

        if(!(total%2==0)){
            sum++;
        }
        
        
    }

    cout << sum << endl;
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
    cin >> t;
    while (t--)
        solve();
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}