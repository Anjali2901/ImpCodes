#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n;
int t[2*N];

void build(){
	for(int i=n-1;i>0;i--)	t[i]=t[i<<=1] + t[i<<1|1];
}

void modify(int i, int value){
	for(t[i+=n]=value; i>1; p>>=1)	t[i>>1]=t[i]+t[i^1];
}

int query(int l, int r){
	int result=0;
	for(l+=n, r+=n; l<r; l>>=1, r>>=1){
		if(l&1) result+=t[l++];
		if(r&1)	result+=t[r--];
	}
	return result;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", t+i+n);	
	
	build();
	modify();
	query();


}