//http://codeforces.com/contest/978/problem/A
//written by Anjali Pandey

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int a[n+1],vis[1005]={0},size=0;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		 cin>>a[i];
	             vis[a[i]]++;
	}
            for(int i=0;i<1005;i++)
            {
            	if(vis[i]>0)size++;
            }
            cout<<size<<endl;
            for(int i=n-1;i>=0;i--)
            {
            	if(vis[a[i]]>0){
            		v.push_back(a[i]);
            		vis[a[i]]=-1;
            	}
            }
            vector<int> :: iterator it;
            it=v.end();
            it--;
            while(it!=v.begin()){
            cout<<(*it)<<" ";
            it--;
            }
            cout<<(*it);
	return 0;
}
