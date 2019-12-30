#include<bits/stdc++.h>
using namespace std;
double a[50005],b[50005],c[50005];
int cnt=0;

vector<double> temp;

double dist(double a,double b,double c,double x,double y,double z)
{
    double ans = (a-x)*(a-x);
    ans += (b-y)*(b-y);
    ans += (c-z)*(c-z);
 
    return sqrt(ans);
}

void kmean(int samples)
{
    double sample_mean[samples+1][5];
    bool chosen[50005];
    memset(chosen, false, sizeof(chosen));
    for(int i=0;i<samples;i++)    {   
         int random = rand();
         random = random%50000;
         while(chosen[random] == true)
         {  
            random = rand();
            random = random%50000;
         }
         chosen[random] = true;
         sample_mean[i][0] = a[random];
    	 sample_mean[i][1] = b[random];
	 sample_mean[i][2] = c[random];
         sample_mean[i][3] = random;
         sample_mean[i][4] = 0;
       
     }
	    for(int i=0;i<cnt;i++)
	    {
		    int classs = -1;
		    double distance = 90000000.0,dd;
                    if(chosen[i] == false){
			    for(int j=0;j<samples;j++)
			    {
                                dd = dist(sample_mean[j][0],sample_mean[j][1],sample_mean[j][2],a[i],b[i],c[i]);
			        if(distance  > dd) 
				{ 
                                   distance = dd;
                                   classs =  sample_mean[j][3]; 
                                }
			    }
		   }
                   for(int j=0;j<samples;j++)
 		   { 
                      if(sample_mean[j][3] == classs) 
                      {
                             sample_mean[j][4] += 1;                             
                             sample_mean[j][0] = (sample_mean[j][0] + a[i])/(sample_mean[j][4] *1.0), sample_mean[j][1] = (sample_mean[j][1] + b[i])/(sample_mean[j][4] *1.0),  sample_mean[j][2] = (sample_mean[j][2] + c[i])/(sample_mean[j][4] *1.0); 
                      }
                   }                   
	    }

       // second pass
        for(int i=0;i<cnt;i++)
	    {
		    int classs = -1;
		    double distance = 9000000.0,dd;
                    if(chosen[i] == false){
			    for(int j=0;j<samples;j++)
			    {
                                dd = dist(sample_mean[j][0],sample_mean[j][1],sample_mean[j][2],a[i],b[i],c[i]);
			        if(distance  > dd) 
				{ 
                                   dd = distance;
                                   classs =  sample_mean[j][3]; 
                                }
			    }
		   }
                   for(int j=0;j<samples;j++)
 		   { 
                      if(sample_mean[j][3] == classs) 
                      {
                             sample_mean[j][4] += 1; 
                      }
                   }                   
	    }
        double tot = 0.0;
        for(int j=0;j<samples-1;j++)
        {
            double ans = (sample_mean[j][4] / 500.0);
              tot += ans;
             cout<<"cluster"<<j<<" contains "<< ans<<"%"<<" data\n";   
        } 
        tot = 100.0-tot;
        cout<<"cluster"<<samples-1<<" contains "<< tot<<"%"<<" data\n"; 
             
}

void input(){
	double x,y,z;
	while(cin>>x && cin>>y && cin>>z){
		a[cnt] = x,b[cnt]=y,c[cnt]=z;
		cnt++;
	}
   // cout<<cnt;
        int num_samples = 3;
       kmean(num_samples);
}

int main()
{
	input();
	cout<<endl;
}
