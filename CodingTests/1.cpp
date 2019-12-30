#include <bits/stdc++.h>
using namespace std;
void fun(int n,string str,string &ss){
    int lev = 0 , x= str.length();
    for(int i=0;i<x;i++){
        if(str[i]=='(')
          lev++;
        else if(str[i]==')')
          lev--;
        else {
            if(lev == n && str[i]!='.')
             ss += str[i];
        }
    }
}
int main() {
    int n;
    cin>>n;
    string str,res = "";
    cin>>str;
    fun(n,str,res);
    cout<<res<<"\n";
	return 0;
}
// Input :2
// 10(8(..)7(6(..)5(4(..)3(..))))
//output : 65 
//qstn : to find nodes at level given , here 2 .

//asked in Directi
