//http://codeforces.com/contest/918/problem/B

#include<bits/stdc++.h>
#define ll long long
using namespace std;

map <string,string> mp;
int main()
{
    ll n,x,i,j,k,q,l,t,m;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    string str,str2;
    for (i=0;i<n;i++)
    {
        cin>>str>>str2;
        str2+=';';
        mp[str2]=str;
    }
    for (i=0;i<m;i++)
    {
        cin>>str>>str2;
        cout<<str<<' '<<str2<<" #"<<mp[str2]<<'\n';
    }
     return 0;
}
