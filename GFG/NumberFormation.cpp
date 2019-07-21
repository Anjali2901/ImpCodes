// https://practice.geeksforgeeks.org/problems/number-formation/0?fbclid=IwAR2Td8wYXZebut5dD7WFGhVwsb1I_DxVxUqNMNZje3bWiPPWAvFYXVP2DRg

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 101;
ll f[N][N][N], cnt[N][N][N];
#define mod 1000000007
int main(){
    int t ;
    cin>>t;
    while(t--){
    memset(f,0,sizeof(f));
    memset(cnt,0,sizeof(f));
    int x, y, z ;
    cin>>x>>y>>z;
    ll ans = 0;
    cnt[0][0][0] = 1;
    for (int i = 0; i <= x; ++ i)
        for (int j = 0; j <= y; ++ j)
            for (int k = 0; k <= z; ++ k){
                if (i){
                    f[i][j][k] = ( f[i][j][k] + f[i - 1][j][k] * 10 + 4 * cnt[i - 1][j][k])%mod;
                    cnt[i][j][k] = ( cnt[i][j][k]+cnt[i - 1][j][k]) %mod;
                }
                if (j){
                    f[i][j][k] = (    f[i][j][k] + f[i][j - 1][k] * 10 + 5 * cnt[i][j - 1][k])%mod;
                    cnt[i][j][k] = ( cnt[i][j][k]+cnt[i][j - 1][k])%mod;
                }
                if (k){
                    f[i][j][k] = (    f[i][j][k] +f[i][j][k - 1] * 10 + 6 * cnt[i][j][k - 1])%mod;
                    cnt[i][j][k] = ( cnt[i][j][k]+cnt[i][j][k - 1]) %mod;
                }
                ans = (ans+f[i][j][k])%mod;
            }
    cout << ans%mod <<"\n";
    }
}
