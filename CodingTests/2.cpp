// questions of hiring coding contest
//1
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
char s[405][405];
int n,m;
int check(int x,int y) {
int c=0;
if(x-1>=0 && s[x-1][y]=='g')
c++;
if(y-1>=0 && s[x][y-1]=='g')
c++;
if(x+1<n && s[x+1][y]=='g')
c++;
if(y+1<m && s[x][y+1]=='g')
c++;
return c;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>m;
for(int i=0;i<n;i++)
cin>>s[i];
int m=4;
for(int i=0;i<n;i++) {
for(int j=0;j<m;j++) {
if(s[i][j]=='g') {
int c=check(i,j);
m=min(m,c);
}
}
}
cout<<m;
return 0;
}

//2 
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int n,m;
cin>>n>>m;
char s[n][m];
for(int i=0;i<n;i++)
cin>>s[i];
map<int,int>d1,d2;
for(int i=0;i<n;i++) {
int c=0,j,k;
for(j=0,k=i;j<m && k<n;j++,k++) {
if(s[k][j]=='.')
c++;
}
d1[k-j]=c;
//cout<<k-j<<" "<<c<<"\n";
c=0;
for(j=m-1,k=i;j>=0 && k>=0;j--,k--) {
if(s[k][j]=='.')
c++;
}
d1[k-j]=c;
//cout<<k-j<<" "<<c<<"\n";
}
for(int j=0;j<m;j++) {
int c=0,i,k;
for(i=n-1,k=j;i>=0 && k<m;i--,k++) {
if(s[i][k]=='.')
c++;
}
d2[k+i]=c;
//cout<<i+k<<" "<<c<<"\n";
c=0;
for(i=0,k=j;i<n && k>=0;i++,k--) {
if(s[i][k]=='.')
c++;
}
d2[i+k]=c;
//cout<<i+k<<" "<<c<<"\n";
}
int s1[n],s2[m];
for(int i=0;i<n;i++) {
int c=0;
for(int j=0;j<m;j++) {
if(s[i][j]=='.')
c++;
}
s1[i]=c;
}
for(int j=0;j<m;j++) {
int c=0;
for(int i=0;i<n;i++) {
if(s[i][j]=='.')
c++;
}
s2[j]=c;
}
ll cnt=0;
for(int i=0;i<n;i++) {
for(int j=0;j<m;j++) {
if(s[i][j]=='R' || s[i][j]=='Q')
cnt+=(s1[i]+s2[j]);
if(s[i][j]=='B' || s[i][j]=='Q')
cnt+=(d1[i-j]+d2[i+j]);
//cout<<i<<" "<<j<<" "<<cnt<<"\n";
}
}
cout<<cnt;
return 0;
}

//3

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
vector<int>v;
vector<int> lengthEachScene(vector<char> inputList) {
vector<int>last(26,-1);
int n=inputList.size();
for(int i=n-1;i>=0;i--) {
int x=inputList[i]-97;
if(last[x]==-1)
last[x]=i;
}
int k=0,s=0;
for(int i=0;i<n;i++) {
int x=inputList[i]-97;
k=max(k,last[x]);
if(i==k) {
v.push_back(k-s+1);
k=i+1;
s=i+1;
}
}
return v;
}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int n;
cin>>n;
vector<char>inputList(n);
for(int i=0;i<n;i++)
cin>>inputList[i];
vector<int>v=lengthEachScene(inputList);
for(int i=0;i<v.size();i++)
cout<<v[i]<<" ";
return 0;
}

