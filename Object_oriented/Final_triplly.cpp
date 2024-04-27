#include <bits/stdc++.h>
#include<sys/time.h>
using namespace std;
void ctriple();
int main()
{
	clock_t start, end; //This portion will count the time for exicution.
	start = clock();
    ctriple();
	end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Time taken by program is : " << fixed<< time_taken << setprecision(5);
	cout << " sec " << endl;
	return 0;
}
void ctriple()
{ int n,c=1;                    
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)    // This loop will take input.
    {                                                 
       if(i<n/2)        //some time it will be a[i]=i+2; or a[i]=i+3;
       {a[i]=i;}                
       else
       {
           a[i]=-c ;    // some time it will be c=c+2; or c=c+3;
           c++;                 
       }
    }
    int triples=0;
    for(int i=0;i<n-2;i++) //This loop will check how many triples will posible. 
    {for(int j=i+1;j<n-1;j++)        
    {
        for(int k=j+1;k<n;k++)
        {
            if(a[i]+a[j]+a[k]==0)
            {
                triples++; }
        }
    }
    }
    cout<<triples<<endl;     
}
