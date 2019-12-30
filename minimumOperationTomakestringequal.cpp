 //  https://www.geeksforgeeks.org/minimum-number-of-given-operations-required-to-make-two-strings-equal/


#include <bits/stdc++.h>
using namespace std;
int funct(string s1,string s2)
{
    unordered_map<string,int> vis;
    if(s1.compare(s2) == 0)
      return 0;
    int pos = 0,n = s1.length();
    for(int i=0;i<n;i++){
        if(s1[i] == '_'){
            pos = i;
            break;
        }
    }
    queue<pair<string,int> > q;
    q.push({s1,pos});
    vis[s1] = 0;
    while(!s1.empty()) {
        string ss = q.front().first;
        int pp = q.front().second;
        int dis  = vis[ss];
        q.pop();
        if(pp>0){
            swap(ss[pp],ss[pp-1]);
            if(!vis.count(ss)){
                if(ss == s2){
                    return dis+1;
                    break;
                }
                vis[ss] = dis+1;
                q.push({ss, pp-1});
            }
            swap(ss[pp-1],ss[pp]);
        }
        if(pp < n-1){
            swap(ss[pp],ss[pp+1]);
            if(!vis.count(ss)){
                if(ss == s2) {
                    return dis+1;
                    break;
                }
                vis[ss] = dis+1;
                q.push({ss,pp+1});
            }
            swap(ss[pp],ss[pp+1]);
        }
        if(pp>1 && ss[pp-1]!=ss[pp-2]) {
            swap(ss[pp],ss[pp-2]);
            if(!vis.count(ss)){
                if(ss == s2) {
                    return dis+1;
                    break;
                }
                vis[ss] = dis+1;
                q.push({ss,pp-2});
            }
            swap(ss[pp],ss[pp-2]);
        }
        if(pp<n-2 && ss[pp+1]!=ss[pp+2]) {
            swap(ss[pp],ss[pp+2]);
            if(!vis.count(ss)) {
                if(ss == s2){
                    return dis+1;
                    break;
                }
                vis[ss] = dis+1;
                q.push({ss,pp+2});
            }
            swap(ss[pp],ss[pp+2]);
        }
    }
    return -1;
}
int main()
{   
    string s1,s2;
    cin>>s1>>s2;
    cout<<funct(s1,s2)<<"\n";
}

