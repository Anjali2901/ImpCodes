//http://codeforces.com/contest/978/problem/C
//written by Anjali Pandey

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int n,m;
	cin>>n>>m;
	long long int a[n+1],sum[n+1],b[m+1];
	vector<long long int >v;
	vector<long long int > :: iterator it;
	    for(long long int i=0;i<n;i++)
	    {
	    	cin>>a[i];
	    }
	    sum[0]=a[0];
	    v.push_back(sum[0]);
	    for(long long int i=1;i<n;i++)
	    {
	    	sum[i]=sum[i-1]+a[i];
		v.push_back(sum[i]);
	    }
	    
	    for(long long int i=0;i<m;i++)
	    {
	    	cin>>b[i];
	    	it=upper_bound(v.begin(),v.end(),b[i]);
	    	auto pos=it-v.begin();
	    	if(it!=v.end()){
	    	  pos++;
	    	}
	            long long int l=(long long int)pos;
	            long long int r=b[i]-(sum[l-1]-a[l-1]);
	            if(r==0)
	            {
	            	l=l-1;
	            	r=a[l-1];
	            }
	            cout<<l<<" "<<r<<"\n";
	    }
	return 0;
}
