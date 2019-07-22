// https://www.geeksforgeeks.org/count-number-of-integers-less-than-or-equal-to-n-which-has-exactly-9-divisors/

#include <bits/stdc++.h>
using namespace std;
int FactNineCount(int n)
{
    int p = sqrt(n);
    int prime[p+1],cnt=0;
    for(int i=1;i<=p;i++)
        prime[i]=i;
    for(int i=2;i*i<=p;i++){
        if(prime[i]==i){
            for(int j=i*i;j<=p;j+=i){
                if(prime[j]==j)
                  prime[j]=i;
            }
        }
    }
    for(int i=2;i<=p;i++){
        int x=prime[i];
        int y=prime[i/prime[i]];
        if(x*y==i && y!=1 && x!=y)
          cnt++;
        else if(prime[i]==i){
            if(pow(i,8)<=p)
              cnt++;
        }
    }
    return cnt;
}
int main()
{   
    int n;
    cin>>n;
    cout<<FactNineCount(n)<<"\n";
}
