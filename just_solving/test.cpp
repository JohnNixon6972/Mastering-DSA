// Code Written by : John Nixon
// Date: 26:10:2022  Time: 11:17:37
// Copyrights are applicable
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long int>


// check if balanced backets are present or not
bool checkBalanced(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(st.empty() || st.top()!='('){
                return false;
            }
            st.pop();
        }
        else if(s[i]=='}'){
            if(st.empty() || st.top()!='{'){
                return false;
            }
            st.pop();
        }
        else if(s[i]==']'){
            if(st.empty() || st.top()!='['){
                return false;
            }
            st.pop();
        }
    }
    if(st.empty()){
        return true;
    }
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    string str;
    cin>>str;
    if(checkBalanced(str)){
        cout<<"Balanced";
    }
    else{
        cout<<"Not Balanced";
    }
}