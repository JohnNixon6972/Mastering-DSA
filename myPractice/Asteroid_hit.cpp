// Code Written by : John Nixon
// Date: 19:10:2022  Time: 12:26:53
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
    cin >> n;
    vector<pii> asteroids;
    for (int i = 0; i < n; i++)
    {
        int dir, rad;
        cin >> dir >> rad;

        if (dir == 0)
        {
            rad = -rad;
        }

        asteroids.pb({rad, i + 1});
    }

    stack<pii> stk;
    for (auto asteroid : asteroids)
    {
        if (stk.empty())
        {
            stk.push(asteroid);
        }
        else
        {
            pii curr_ast = asteroid;
            pii top_ast = stk.top();
            // cout<<asteroid.F<<endl;
            if (curr_ast.F < 0 && top_ast.F > 0)
            {
                while (!stk.empty() && curr_ast.F < 0 && top_ast.F > 0)
                {
                    stk.pop();
                    if (abs(curr_ast.F) > abs(top_ast.F))
                    {
                        curr_ast.F = -(abs(curr_ast.F) + abs(top_ast.F));
                    }
                    else if (abs(curr_ast.F) < abs(top_ast.F))
                    {
                        curr_ast.F = abs(curr_ast.F) + abs(top_ast.F);
                        curr_ast.S = top_ast.S;
                    }
                    else
                    {
                        break;
                    }
                    if (stk.size() < 1)
                    {
                        stk.push(curr_ast);
                        break;
                    }
                    else
                    {
                        top_ast = stk.top();
                    }
                }
            }
            else
            {
                stk.push(asteroid);
            }
        }
    }
    vi ans;
    // cout << stk.empty() << endl;

    while (!stk.empty())
    {

        int ast = stk.top().S;
        ans.pb(ast);
        stk.pop();
    }

    cout << ans.size() << endl;
    sort(all(ans));
    if (ans.size())
    {
        print(ans);
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
    cin >> t;
    while (t--)
        solve();
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}