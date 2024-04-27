#include <iostream>
#include <conio.h>
#include <stdio.h>
#include<string.h>
using namespace std;

int main()
{
    jump:
    char str[100];
    int i,p=0;
    float time=0;
    unsigned long long po=1,pos=0;
    int CAlphabets=0,SAlphabets=0,num=0,special=0;
    cout<<"Please enter the string (Space is not valid in the password)\n";
    gets(str); 
    for(i=0; str[i] != '\0'; i++){
        //check for Aphabets
            if((str[i]>='A' && str[i]<='Z')) {  //check Alphabets
                CAlphabets++;
    }
    else if( (str[i]>='a' && str[i]<='z')){SAlphabets++;}
    else if(str[i]>='0' && str[i]<='9') {  //check numbers
                num++;
    }
    else if(str[i]==' '){
    goto jump; }
    else{
        special++;
    }
    }
    cout<<"\nSmall Alphabet letters: "<<SAlphabets;
    cout<<"\nCapital Alphabet letters: "<<CAlphabets;
    cout<<"\nTOtal numbers: "<<num;
    cout<<"\nSpecial characters: "<<special;
    cout<<"\nLenght of string is: "<<strlen(str);
    if(CAlphabets>0){p=p+26;}
    if(SAlphabets>0){p=p+26;}
    if(special>0){p=p+33;}
    if(num>0){p=p+10;}
    for(int i=0;i<strlen(str);i++){po=po*p;}
    for(int i=0;i<strlen(str);i++)
    {   if(po!=1){pos=pos+po;
        po=po/p;}
    }
    cout<<"\nYour total possibility is: "<<pos<<endl;
    time=pos/1000.0;
    if(time>0 && time<60){cout<<time<<" seconds";}
    else if(time>=60 && time<86400 ){time=time/3660.0;
    cout<<time<<" hours";}
    else if(time>=86400 && time<604800 ){time=time/3600.0;
    cout<<time<<" day";}
    else if(time>=86400 && time<604800 ){time=time/86400.0;
    cout<<time<<" week";}
    else if(time>=604800 && time<2592000){time=time/604800.0;
    cout<<time<<" month";}
    else if(time>=2592000 && time<3153600){time=time/2592000.0;
    cout<<time<<" year";}

    return 0;
}