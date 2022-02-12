#include<iostream>
using namespace std;
int main()
{
    int n,k,b[100000],bch,co,tb=0,htb,op,i;
    cout<<"enter the number of orders and which order is cancelled : \n";
    cin>>n>>k;
    cout<<"enter the bills of oders : \n";
    for(i=0;i<n;i++)
    {
        cin>>b[i];
        tb=tb+b[i];
    }
    cout<<"the bill charged : \n";
    cin>>bch;
    co=b[k];
    htb=(tb-co)/2;
    if(htb==bch)
        cout<<"bill is same";
    else 
    {
        op=bch-htb;
        cout<<"difference betwen the original bill and bill charged "<<op;
    }
    return(0);
}