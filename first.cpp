#include<bits/stdc++.h>
using namespace std;

int main(){

	string s;
	cin>>s;
	
	int n=s.length(), count_a=0, count_b=0, count_c=0;
	
	map<pair<int, int>, int > m;
	m[make_pair(0,0)]=1;

	long long result=0;
	
	for(int i=0;i<n;i++){
		if(s[i]=='A')
			count_a++;
		else if(s[i]=='B')
			count_b++;
		else if(s[i]=='C')
			count_c++;

		pair<int, int> p=make_pair(count_a-count_b, count_c-count_b);
		
		result+=m[p];
		m[p]++;
	}
	cout<<result;
}