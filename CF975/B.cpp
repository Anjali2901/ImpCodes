#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int a[14],sum=0,max=-1,ind;
	for(int i=0;i<14;i++)
	{
		cin>>a[i];
		if(a[i]>max){
		   max=a[i];
           ind=i;
       }
	}
	int k=1;
	while(max!=0)
	{
		max--;
		a[(ind+k)%14]++;
		k++;
	}
	for(int i=0;i<14;i++)
	{
		if(a[i]%2==0)sum+=a[i];
	}
	cout<<sum;
}
