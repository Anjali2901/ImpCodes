#include <bits/stdc++.h>
using namespace std;

int main() 
{
     int testcases;
     cin>>testcases;
     for(int t=1;t<=testcases;t++)
     {
         bool marker = true;
         string str;
         cin>>str;
         int  bs = 0, dots = 0 , len = str.length();
         for(int i = 0 ;i < len; i++){
             if(str[i] == 'B')
             bs++;
             else if(str[i]== '.')
             dots++;
         }
         if(bs == len-1 || dots == len-1)
           marker = false;
         else if(bs >= dots)
           marker = true;
         else 
           marker = false;
         
         if(marker)
           cout<<"Case #"<<t<<": Y\n";
         else 
           cout<<"Case #"<<t<<": N\n";
     }
	return 0;
}
