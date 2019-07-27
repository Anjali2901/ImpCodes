//dp + bitmasking solution 

#include <bits/stdc++.h>
using namespace std;
int dp[1024][101];
#define mod 1000000007
int convert(string str){
    int len = str.length();
    int i, num = 0;
    for (i=0;i<len;i++){
        num=num+((str[len-(i+1)]-'0')*pow(10,i));
    }
   return num;
}
int funct(int tot , int mask,int bit,vector<int> rev[]){
    if(tot == mask)
        return 1;
    if(bit == 101)
        return 0;
    if(dp[tot][bit] != -1)
        return dp[tot][bit];
    int ways = funct(tot,mask,bit+1,rev);
    int sz = rev[bit].size();
    for(int i=0;i<sz;i++){
        if(tot & (1<<rev[bit][i]))continue;
        else ways+=funct(tot|(1<<rev[bit][i]),mask,bit+1,rev);
        ways %= mod;
    }
    return dp[tot][bit] = ways;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n;
	    k=n;
	    cin.ignore();
	    vector<vector<int> > v;
	    vector<int> rev[101];
	    while(k--){
	       string st,tmp="";
	       getline(cin,st);    
	       st += " ";
	       vector<int> vv;
	       for(int i=0;i<st.length();i++){
	           if(st[i]==' '){
	               int xx = convert(tmp);
	               vv.push_back(xx);
	               tmp = "";
	           }
	           else {
	               tmp+=st[i];
	           }
	       }
	       v.push_back(vv);
	    }
	    for(int i=1;i<=100;i++){
	        for(int j=0;j<v.size();j++){
	            for(int k=0;k<v[j].size();k++){
	               if(v[j][k] == i){
	                   rev[i].push_back(j);
	               }
	            }
	        }
	    }
	    int mask = (1<<n)-1, bit = 1;
	    memset(dp,-1,sizeof(dp));
	    cout<<funct(0,mask,bit,rev)<<"\n";
	}
	return 0;
}
