//Written by Anjali Kumari (LIT2016033) '
//takes input from file ,uses hashing on it and removes unwanted characters like @,'.: etc and outputs word and their frequencies . 
 
#include<bits/stdc++.h>
using namespace std;

string removeExtra(string str){
	
	int ind;			
	ind = str.find("@");
	if(ind != std::string::npos)
		str[ind] = '\0';
		
	ind = str.find("%");
	if(ind != std::string::npos)
		str[ind] = '\0';	
		
	ind = str.find("$");
	if(ind != std::string::npos)
		str[ind] = '\0';
			
	ind = str.find("^");
	if(ind != std::string::npos)
		str[ind] = '\0';
	
	ind = str.find(";");	
	if(ind != std::string::npos)
		str[ind] = '\0';
	
	ind = str.find("[");	
	if(ind != std::string::npos)
		str[ind] = '\0';
		
	ind = str.find("|");	
	if(ind != std::string::npos)
		str[ind] = '\0';
		
	ind = str.find("\"");
	if(ind != std::string::npos)
		str[ind] = '\0';
		
	ind = str.find("\'");
	if(ind != std::string::npos)
		str[ind] = '\0';
		
	ind = str.find("*");	
	if(ind != std::string::npos)
		str[ind] = '\0';
	
	ind = str.find("{");	
	if(ind != std::string::npos)
		str[ind] = '\0';
		
	ind = str.find(".");
	if(ind != std::string::npos)
		str[ind] = '\0';
		
	ind = str.find(",");
	if(ind != std::string::npos)
		str[ind] = '\0';
		
	ind = str.find("\?");
	if(ind != std::string::npos)
		str[ind] = '\0';
		
	ind = str.find("!");
	if(ind != std::string::npos)
		str[ind] = '\0';
		
	ind = str.find("(");
	if(ind != std::string::npos)
		str[ind] = '\0';
		
	ind = str.find(")");
	if(ind != std::string::npos)
		str[ind] = '\0';
		
	ind = str.find(":");
	if(ind != std::string::npos)
		str[ind] = '\0';
						
	ind = str.find(" ");
	if(ind != std::string::npos)
		str[ind] = '\0';							
	return str;
}
int main()
{
    int ct = 0;
    string word,w;
    map<string, vector<int> >m;
     map<string, vector<int> >::iterator it;
    ifstream file;
    file.open("file2.txt");
    while(file >> word)
    {
	w = removeExtra(word);
                if(m.find(w)==m.end())
                {
                    vector<int>v;
                    v.push_back(++ct);
                    m.insert(pair< string,vector<int> >(w,v));
                }
                else
                    m[w].push_back(++ct);
    }
    it = m.begin();
    while(it!=m.end())
    {
        cout<<it->first<<" ";
        vector<int>v = it->second;
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<'\n';
        it++;
    }
}
