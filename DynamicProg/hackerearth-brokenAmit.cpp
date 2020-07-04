DP + Bitmasking

#include <bits/stdc++.h>
using namespace std;
#define N 18
int n,l[N],d[N],dp[N][1<<N];
int glv(int step,int mask) {
    if(step>=n)
       return 0;
    if(dp[step][mask]!=-1)
       return dp[step][mask];
    int mx = INT_MIN; 
    for(int i=0;i<n;i++){
       int check=mask&(1<<i);
        if(check == 0 ) {  
            int new_mask=mask | (1<<i);
            int last_ap_term = l[i] - step*i*d[i];
            //an AP is formed for ith girl till it takes amit to reach her,and terms after that will remain constant             
            int new_sum = ((step+1)*(l[i]+last_ap_term)/2 + (last_ap_term*(n-1-step)) ; 
            mx = max(mx, new_sum+glv(step+1, new_mask));
            
        }
    }
    dp[step][mask] = mx;
    return mx;
}
int main() {
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++) {
        cin>>l[i];
        sum+=l[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<(1<<N);j++){
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++)
    cin>>d[i];
    cout<<glv(0,0);
    return 0;
}
