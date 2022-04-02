//A program to findout a missing term.
//Numerical Analysis
//Code by : Iftikhar Ahammad Sikder
//Language: C++

#include<iostream>
#include<conio.h>
using namespace std;
int fact(int f)
{
    int sum=1;
    for(int i=1;i<=f;i++)
    {
        sum=sum*i;
    }
    return sum;
}
int main()
{
    cout<<" How many values are given : ";
    int N;
    cin>>N;
    int x[N+1],cnt=0;
    cout<<" Combinations are : ";
    for(int i=N;i>=0;i--)
    {
        cnt++;
        int n=N,r=i,nCr;
        nCr=fact(n)/(fact(r)*fact(n-r));
        if(cnt%2==0)
            nCr=nCr*(-1);//Making odd positions negative
        cout<<nCr<<"  ";
        x[i+1]=nCr;
    }
    cout<<endl<<endl<<" Enter the missing position : ";
    int pos;
    cin>>pos;
    float f[N+2];
    for(int i=1;i<=N+1;i++)
    {
        if(i==pos)
            continue;
        cout<<" f["<<i<<"] = ";
        cin>>f[i];
    }
    int sum=0;
    for(int i=N+1;i>0;i--)
    {
        if(i==pos)
            continue;
        f[i]=f[i]*x[i];
        sum=sum+f[i];
    }
    sum=sum*(-1);//For changing the side of sum to right side
    cout<<endl<<" Missing term,f["<<pos<<"] = "<<(float)sum/x[pos];
    getch();
}


