Q1)
#include <bits/stdc++.h>
using namespace std;

int main() { 
    int t;
    cin>>t;
    while(t--){
        int n,x;
        priority_queue<int> p;
        cin>>n;
        for(int i=0;i<n;i++) {
            cin>>x;
            p.push(x);
        }
        if(n==1) cout<< p.top() <<"\n";
        else {
            long long sum = 0ll;
            while(p.size()>=2){
                int x = p.top();
                p.pop();
                int y = p.top();
                p.pop();
                
                int mn= min(x,y);
                sum+=mn;
                if(x!=y){
                    if(x==mn){
                        y-=mn;
                        p.push(y);
                    }else {
                        x-=mn;
                        p.push(x);
                    }
                }
            }
            if(p.size()>=1){
                int xx  = p.top();
                p.pop();
                if(p.size()>=1) {
                    sum += max(xx,p.top());
                }
                else {
                    sum += xx;
                }
            }
            cout<<sum<<"\n";
        }
    }
	return 0;
}
______________________________________________________________________________________________________________________________________________________________________________
Q2)
#include <bits/stdc++.h>
using namespace std;

# Solution failed , need to recheck

int main() { 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n+1];
        map<int,int> vis;
        map<int,vector<int> > mp;
        for(int i=0;i<n;i++){
            cin>>a[i];
            vector<int> v = mp[a[i]];
            v.push_back(i);
            mp[a[i]] = v;
        }
        int curr = 2,arr_ind = 0;
        for(auto it=mp.begin();it!=mp.end();it++){
            int ind = 1;
            vector<int> v = it->second;
            for(int i=0;i<v.size();i++){
                int val = curr*ind;
                while(vis.find(val)!=vis.end()){
                    ind++;
                    val = curr*ind;
                }
                a[arr_ind] = val;
                vis[val] = 1;
                arr_ind++;
            }
            curr++;
        }
        for(int i=0;i<n;i++)cout<<a[i]<<" ";
        cout<<"\n";
    }
	return 0;
}
