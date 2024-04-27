// #include<iostream>
// using namespace std;
// void merge(int a[],int l,int mid,int h){
//     //cout<<"A"<<endl;
//     int n1=mid-l+1;
//     int n2=h-mid;

//     int a1[n1],b1[n2];
//     for(int i=0;i<n1;i++){a1[i]=a[l+i];}
//     for(int i=0;i<n2;i++){b1[i]=a[mid+1+i];}
//     int i=0,j=0;
//     int k=l;
//     while (i<n1 && j<n2)
//     {
//         /* code */
//         if(a1[i]<b1[j]){a[k]=a1[i];k++;i++;}
//         else{a[k]=b1[j];k++;j++;}
//     }
//     while (i<n1)
//         {
//         /* code */
//         a[k]=a1[i];
//         k++;i++;
//         }
//         while (j<n2)
//         {
//             /* code */
//             a[k]=b1[j];
//             k++;j++;
//         }
    
// }
// void mergesort(int a[],int l,int h)
// {   //cout<<"MSC"<<endl;
//     if(l<h){
//     int mid=(l+h)/2;
//     mergesort(a,l,mid);
//     mergesort(a,mid+1,h);
//     merge(a,l,mid,h);
//     }
// }
// int main()
// {
// cout<<"Enter a numbers of arrays"<<endl;
// int n;
// cin>>n;
// int a[n];
// for(int i=0;i<n;i++)
// {
//     cin>>a[i];
// }
// mergesort(a,0,n-1);
// for(int p=0;p<n;p++)
// {cout<<a[p]<<" ";}
// cout<<endl;
// return 0;
// }
#include<iostream>
using namespace std;
void merge(int a[],int l,int mid,int h){
    
    int i=0,j=0;
    int k=l;
    while (i<mid-l+1 && j<h-mid)
    {
        /* code */
        if(a[l+i]<a[mid+1+i]){a[k]=a[l+i];k++;i++;}
        else{a[k]=a[mid+1+i];k++;j++;}
    }
    while (i<mid-l+1)
        {
        /* code */
        a[k]=a[l+i];
        k++;i++;
        }
        while (j<h-mid)
        {
            /* code */
            a[k]=a[mid+1+i];
            k++;j++;
        }
    
}
void mergesort(int a[],int l,int h)
{   //cout<<"MSC"<<endl;
    if(l<h){
    int mid=(l+h)/2;
    mergesort(a,l,mid);
    mergesort(a,mid+1,h);
    merge(a,l,mid,h);
    }
}
int main()
{
cout<<"Enter a numbers of arrays"<<endl;
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
mergesort(a,0,n-1);
for(int p=0;p<n;p++)
{cout<<a[p]<<" ";}
cout<<endl;
return 0;
}