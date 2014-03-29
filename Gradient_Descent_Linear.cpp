/* @author :nitish bhagat */
/**
 * this code takes Machine CPU as a input file and train the data set
 * according to gradient descent algorithm
 * data is of the form as with 7 parameters and 1 target value
 * 
 * */
 
//header files
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <complex>
#include <vector>
#include <fstream> 
#include <cmath>
#include <ctime>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <iomanip>
#include <utility>
#include <locale>
#include <sstream>
#include <string> // this should be already included in <sstream>

//short lazieeeeeee
#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<n;i++)
#define FORC(it,C) for(it=C.begin();it!=C.end();it++)
#define scanI(x) scanf("%d",&x)
#define scanD(x) scanf("%lf",&x)
#define print(x) printf("%d\n",x)
#define ll  long long
#define number32 4294967296ull
#define MAX 100001
#define len(s) s.length()
#define pb(x) push_back(x)

using namespace std;

double theta[7]={0.0};  //array for parameters as theta


double hypo(vector<double> h)
{
	double val=theta[0];
	
	for(int i=0;i<h.size();i++)
	{
		val+=theta[i+1]*h[i];
	}
	
	return val;
}
	


int main()
{
	fstream file; //using fstream for reading data from a file 
	string data,token;
	file.open("machine.data");  //Machine CPU file with dataset
	
	//variables for dataset
	int i,j,k,counter;
	vector< vector<double> > h;
	vector<double> f  ;// for target value
	vector<double> temp; //just for holding
	while(file>>data)
	{
	  // cout<<data<<endl;  //data is in the form 125,256,6000,256,16,128,198
	   
	   //need to sepearte the data by comma using isstringstream
	   //token as comma
	   istringstream ss(data);
	   counter=0;
	   temp.clear();
	   while(getline(ss,token,','))
	   {
		   //cout<<token<<endl;
		   if(counter==6)
		   {
			   f.pb(atof(token.c_str()));
		   }
		   
		   else
		   {
			   temp.pb(atof(token.c_str()));
		   }
		   
		   counter++;
	   }
	   h.pb(temp); //pushing vector in h
	 
    }
    //now we done with getting data in vectors now need to train
    
    double alpha=0.0000008; //sensitivity
    double d[7]={0.0};
   
    int m=h.size();  //no. of training examples
    int n=h[0].size();  //no. of parametrs
    
    //gradient Descent procedure
    for(i=0;i<100;i++)
    {
		for(j=0;j<7;j++)
		{
			d[j]=0.0;
		}
		for(k=0;k<n;k++)
		{
			d[0]=hypo(h[k])-f[k];
			for(j=1;j<7;j++)
			{
				//cout<<h[k][j-1]<<" "<<k<<" "<<j<<endl;
				d[j]=(hypo(h[k])-f[k]) * h[k][j-1];
			}
		}
		
		for(j=0;j<7;j++)
		{
			theta[j]-=alpha*d[j];
		}
		
		for(j=0;j<7;j++)
		{
			cout<<theta[j]<<" ";
		}
		cout<<endl;
	}
				
   // 0.0001584 0.0198 0.0405504 0.9504 0.0405504 0.0025344 0.0202752
   
    double ar[7]={0.0001584,0.0198,0.0405504,0.9504,0.0405504,0.0025344,0.0202752};
    double ans=ar[0];
    for(i=1;i<7;i++)
    {
		ans+=ar[i]*h[208][i];
	}
	cout<<h[208][0]<<" "<<h[208][1]<<endl;
	cout<<ans<<endl;
	return 0;
}
