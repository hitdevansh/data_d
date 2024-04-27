//******************************************************************************************
// 1st one binary search
// #include<iostream>
// using namespace std;
// bool search(int a[],int s,int e,int k)
// {
//     int mid=(e+s)/2;
//     if(s>e){return false;}
//     else if(a[mid]==k){return true;}
//     else if(a[mid]>k){
//     bool p=search(a,s,mid-1,k);
//     return p;}
//     else if(a[mid]<k){
//     bool p=search(a,mid+1,e,k);
//     return p;}
// }
// int main()
// {
// int arr[5]={0,5,6,8,10};
// int key=9;
// bool ans=search(arr,0,4,key);
// if(ans){cout<<"Your key is present here ."<<endl;}
// else{cout<<"key is not present"<<endl;}
// return 0;
// }

//******************************************************************************************
// 2nd reverse string using recurance
// #include<iostream>
// #include<string>
// using namespace std;
// void swapt(char &a,char &b){char p=a;
// a=b;
// b=p;}
// void rever(string &a,int s)
// {
    
//     if(s>(a.length()-s-1)){return ;}
//     swapt(a[s],a[(a.length()-s-1)]);
//     s++;
//     //a.length()--;
//     rever(a,s);
// }
// int main()
// {
// string a="DEVANSH";
// rever(a,0);
// cout<<"final reverse is "<<a<<endl;
// return 0;
// }

//******************************************************************************************
// 3rd <<<<<<<<<<<<<<<<selection sort>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> using recurance
//Here one by one on next indexes the shorted element whill take a place thats it.
// #include<iostream>
// using namespace std;
// void sorti(int a[],int size)
// {   int p=0;
//     if(size==0 || size==1){return ;}
//     else
//     {
//         for(int i=0;i<size;i++)
//         {if(a[p]>a[p+i])
//         {int temp=a[p+i];
//         a[i+p]=a[p];
//         a[p]=temp;
//         cout<<"for this it done "<<a[i]<<endl;}
//         }
//         p++;
//         sorti(a+1,size-1);
//     }
// }
// int main()
// {
// int arr[5]={5,6,3,4,9};
// sorti(arr,5);
// cout<<endl;
// for(int i=0;i<5;i++){cout<<arr[i]<<" ";}
// return 0;
// }

//<<<<<<<<.........NOTE INSERTION SORT IS NOT POSSIBLE BY RECURSION.................>>>>>>>>
//******************************************************************************************
// 4th insertion  sort using recurance
//==>Here its startesd by quite first index first check 2nd to first index then 3 
//   to first 2 index then 4 to first 3 index and continue...
// #include<iostream>
// using namespace std;
// void sorti(int a[],int size,int p)
// {   
//     if(size==0 || size==1){return ;}
//     else if(p==4){return ;}
//     else
//     {   int i=p-1;
//         int current=a[p];
//         while (a[i]>current && i>=0)
//         {
//             a[i+1]=a[i];
//             i--;
//         }
//         a[i+1]=current;
//         sorti(a,size-1,p++);
//     }
// }
// int main()
// {
// int arr[5]={5,6,3,4,9};
// sorti(arr,5,1);
// cout<<endl;
// for(int i=0;i<5;i++){cout<<arr[i]<<" ";}
// return 0;
// }
