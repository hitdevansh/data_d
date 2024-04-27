#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	cin>>n;
	int a[n];
	int arr[n][100000];
	for(int i=0;i<n;i++)
	{
	    cin>>a[i];
	    for(int j=0;j<a[i];j++){
	        cin>>arr[i][j];
	    }
	sort(arr[i],arr[i]+a[i]);
	int sa=0,p=1;
	for(int l=0;l<a[i];l++)
	{   
	    if(arr[i][l]>l){sa++;}
        else{break;}
	}
	    int np=0;
	for(int l=0;l<a[i];l++)
	{   
        if(arr[i][l]<=np){p++;np=0;l=l-1;}
        else{np++;}
	}
    //cout<<"sa is "<<sa<<endl;
	//cout<<a[i]<<endl;
    if(sa==a[i]){cout<<"1"<<endl;}
	else{cout<<p<<endl;}
	}
	return 0;
}
