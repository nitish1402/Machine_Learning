/* @author :nitish bhagat */
/**
 * This code asks user to input the values according to
 * Machine CPU file
 * and output the expected value
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

double theta[7];
double x[7];

int main()
{
	// as from ridge regression code the calculated value of theta are
	
	theta[0]=0.0250983;
    theta[1]=0.00100007;
    theta[2]=0.00583144;
    theta[3]=0.0105819;
    theta[4]=0.00639119;
    theta[5]=0.00521714;
    theta[6]=0.00592248;
    
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"------------------PROCEDURE BEGINS--------------------------------"<<endl;
    cout<<"----------Gradient Descent Inference Algorithm--------------------"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    

    /**
     * MYCT: machine cycle time in nanoseconds (integer)
       MMIN: minimum main memory in kilobytes (integer)
       MMAX: maximum main memory in kilobytes (integer)
       CACH: cache memory in kilobytes (integer)
       CHMIN: minimum channels in units (integer)
       CHMAX: maximum channels in units (integer)
       PRP: published relative performance (integer) (target variable)
       
       **/
     char response; 
     while(1)
     {
       cout<<"if you want to continue type (y) else type (n) without quotes\n";  
       cin>>response;
       if(response =='n') 
       {
		   cout<<"Good Bye"<<endl;
		   exit(0);
	   }
	   cout<<"------------------------------------------------------------------"<<endl;
       cout<<"------------------------------------------------------------------"<<endl;
       cout<<"Welcome USER----------------------|||||"<<endl;
       cout<<"Now you can predict the published relative performance of CPU"<<endl;
       cout<<"------------------------------------------------------------------"<<endl;
     
       cout<<endl;
     
       cout<<"Enter machine cycle time in nanoseconds:-";
       cin>>x[1];
       cout<<endl;
       
       cout<<"Enter minimum main memory in kilobytes :-";
       cin>>x[2];
       cout<<endl;
     
       cout<<"Enter maximum main memory in kilobytes:-";
       cin>>x[3];
       cout<<endl;
     
       cout<<"Enter cache memory in kilobytes:-";
       cin>>x[4];
       cout<<endl;
     
       cout<<"Enter minimum channels in units:-";
       cin>>x[5];
       cout<<endl;
     
       cout<<"Enter maximum channels in units:-";
       cin>>x[6];
       cout<<endl;
     
       double val=theta[0];
     
       for(int i=0;i<7;i++)
       {
		   val+=theta[i]*x[i];
	   }
	 
	   cout<<"The estimated published relative performance is :="<<(int)val<<endl;
     }
}
	 
	 
     
         
