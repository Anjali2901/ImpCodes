#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#define ll long long
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
    cin>>n>>m;
    char a[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		cin>>a[i][j];
		}
	}
	int f=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
        {
          if(a[i][j]=='*')continue;
		  else if(a[i][j]=='.')
		  {
		  	
			  	if(i-1>=1 && j-1>=1 && a[i-1][j-1]=='*')
			  	{
	             f=1;
					break;	
				}
				else if(i-1>=1 && a[i-1][j]=='*'){
				   f=1;
					break;
				}
				else if(i-1>=1 && j+1<=m && a[i-1][j+1]=='*'){
					f=1;
					break;
				}
				else if(j-1>=1 && a[i][j-1]=='*'){
					f=1;
					break;
				}
				else if(j+1<=m && a[i][j+1]=='*'){
				f=1;
					break;
				}
				else if(i+1<=n && j-1>=1 && a[i+1][j-1]=='*'){
				f=1;
					break;
				}
				else if(i+1<=n && a[i+1][j]=='*'){
				f=1;
					break;
				}
				else if(i+1<=n && j+1<=m && a[i+1][j+1]=='*'){
				f=1;
					break;
				}			
	    	}
	    	else {
	    		int num = (int)a[i][j]-'0';
			    		int bct=0;
			      	if(i-1>=1 && j-1>=1 && a[i-1][j-1]=='*')
				  	{
				  	  bct++;
					}
					if(i-1>=1 && a[i-1][j]=='*'){
				      bct++;
					}
					if(i-1>=1 && j+1<=m && a[i-1][j+1]=='*'){
					  bct++;
					}
					if(j-1>=1 && a[i][j-1]=='*') 	{
					 bct++;
					}
					if(j+1<=m && a[i][j+1]=='*'){
					bct++;
					}
					if(i+1<=n && j-1>=1 && a[i+1][j-1]=='*'){
					bct++;
					}
					if(i+1<=n && a[i+1][j]=='*'){
					bct++;
					}
					if(i+1<=n && j+1<=m && a[i+1][j+1]=='*'){
					bct++;
					}
					
			if(bct!=num){
				f=1;
				break;
			}
		  }
     	}
   }
   if(f==1)cout<<"NO";
   else cout<<"YES";
}
