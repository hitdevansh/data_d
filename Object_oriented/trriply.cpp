#include<iostream>
using namespace std;
int main()
{ 
    int a[]={-2,-1,0,1,2};
    int tripple=0;
    for(int i=0;i<3;i++)
    {for(int j=i+1;j<4;j++)
    {
        for(int k=j+1;k<5;k++)
        {
            if(a[i]+a[j]+a[k]==0)
            {
                tripple++;
            }
        }
    }

    }
    cout<<tripple;
}
//#include <bits/stdc++.h>
using namespace std;

int main()
{
	clock_t start, end;
	start = clock();
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int tripple=0;
    for(int i=0;i<n-2;i++)
    {for(int j=i+1;j<n-1;j++)
    {
        for(int k=j+1;k<n;k++)
        {
            if(a[i]+a[j]+a[k]==0)
            {
                tripple++;
            }
        }
    }
    }
    cout<<tripple<<endl;;
	// Recording the end clock tick.
	end = clock();

	// Calculating total time taken by the program.
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Time taken by program is : " << fixed
		<< time_taken << setprecision(5);
	cout << " sec " << endl;
	return 0;
}
