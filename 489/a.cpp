/* Written by Anjali Pandey
   Language : C++
*/

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main()
{

	IOS
	int n;
	cin>>n;
	set<int> s;
	set<int> ::iterator it;
	int a[n+1],mx=-100005,ct=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		s.insert(a[i]);
	}
	for(it =s.begin();it!=s.end();it++)
	{
		if((*it)!=0)
		ct++;
	}
	cout<<ct;
}
