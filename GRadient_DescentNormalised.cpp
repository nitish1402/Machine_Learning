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
double oldtheta[7]={0.0};
static double eps=0.1;
vector< vector<double> > h;



//function which return the hypothesis according to instance
//h(k)=theta[0]+theta[1]*x[1]+...........+theta[6]*x[6]  for kth instance
double hypo(int k)
{
	double val=theta[0];
	
	for(int j=1;j<7;j++)
	{
		val+=h[k][j-1]*theta[j];
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
    
    vector<vector<double> > copy=h;
    
    double max[7]={0.0};
    double min[7]={9999999999.00};
    
    for(i=0;i<6;i++)
    {
		for(j=0;j<209;j++)
		{
		//	cout<<copy[i].size()<<endl;
			if(h[j][i]>max[i])
			{
				max[i]=h[j][i];
			}
			if(h[j][i]<min[i])
			{
				min[i]=h[j][i];
			}
		}
	}
    
    //now need to normalise
    for(j=0;j<(signed)h.size();j++)
    {
		for(i=0;i<6;i++)
		{
		   h[j][i]=(h[j][i]-min[i])/(max[i]-min[i]);
		}
	}
	
	
    
    //now we done with getting data in vectors now need to train 
    
    double alpha=0.0000005; //sensitivity
    double d[7]={0.0};
   
    int m=h.size();  //no. of training examples
    int n=h[0].size();  //no. of parametrs
    
    
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"------------------PROCEDURE BEGINS--------------------------------"<<endl;
    cout<<"----------Gradient Descent Linear Regression----------------------"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    
    cout<<"This will stop when convergence ocuuered\n"<<endl;
    double cost=0.0;
    for(i=0;i<200000;i++)
    {
		for(j=0;j<7;j++)
		{
			d[j]=0.0;
		}
		cost=0.0;
		for(k=0;k<m;k++)
		{
			d[0]+=hypo(k)-f[k];
			cost+=pow((hypo(k)-f[k]),2);
			for(j=1;j<7;j++)
			{
				//cout<<h[k][j-1]<<" "<<k<<" "<<j<<endl;
				d[j]+=(hypo(k)-f[k]) * h[k][j-1];

			}
		}
		int mx=0;
		for(int l=0;l<7;l++)
		{
			if(abs(d[l])>mx)
			  mx=abs(d[l]);
		}
		for(j=0;j<7;j++)
		{
			theta[j]-=alpha*d[j]/(m);   //updating simultaneously
		}
		
		if(i==0)
		{
		   for(j=0;j<7;j++)
		   {
			  oldtheta[j]=theta[j];
		   }
	    }
		
		//cout<<theta[1]-oldtheta[1]<<endl;
		//checking for convergence
		if(theta[0]-oldtheta[0]>eps && theta[1]-oldtheta[1]>eps && theta[2]-oldtheta[2]>eps && theta[3]-oldtheta[3]>eps 
		 && theta[4]-oldtheta[4]>eps && theta[5]-oldtheta[5]>eps && theta[6]-oldtheta[6]>eps)
		{
			cout<<"Convergennce occured\n";
			cout<<"Itearation="<<i<<endl;
			break;
		}
	
		for(j=0;j<7;j++)
		{
		//	cout<<theta[j]<<" ";
		}
		//cout<<endl;
	}
	for(j=0;j<7;j++)
	{
	  theta[j]/=100;
    }	
    cout<<endl;
    cout<<"As Convergennce occured\n";
	cout<<"WE can use these value for inference\n"<<endl;
	
	cout<<"------------------------------------------------------"<<endl;
	cout<<"---------------PRINTING RESULTS-----------------------"<<endl;
	cout<<"------------------------------------------------------"<<endl;
	
	cout<<endl;
	
	cout<<"Learning Rate:- "<<alpha<<endl;
	cout<<"No. of instances are :-"<<i<<endl;
	cout<<"Values of thetas are as follows:-"<<endl;
	for(j=0;j<7;j++)
	{
	   cout<<"theta["<<j<<"]:="<<theta[j]<<endl;
    }				
 
    
     cout<<endl;
   
    cout<<"------------------------------------------------------"<<endl;
	cout<<"---------------INFERENCE-----------------------"<<endl;
	cout<<"------------------------------------------------------"<<endl;
    double ans=theta[0];
    vector<double> an;
    for(j=0;j<209;j++)
    {
		ans=theta[0];
        for(i=1;i<7;i++)
        {
		  ans+=theta[i]*copy[j][i-1];
	    }
	    an.pb(ans);
	}
	cout<<"No."<<" Calculate value"<<" "<<"Original Value"<<endl;
	for(i=0;i<209;i++)
	  cout<<i<<"        "<<(int)an[i]<<"      "<<f[i]<<endl;
	h.clear();
	return 0;
}
