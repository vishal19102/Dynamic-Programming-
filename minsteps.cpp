#include<iostream>
#include<string.h>
using namespace std;
//recursive approach
int minsteps(int n){
    int mn=n,opt1=n,opt2=n,opt3=n;

    if(n==0||n==1)
        return 0;

    if(n%3==0)
         opt1= minsteps(n/3)+1;
    if(n%2==0)
         opt2= minsteps(n/2)+1;
    
    opt3= minsteps(n-1)+1;

    mn = min(opt1,min(opt2,opt3));
    return mn;
}

//dynamic prograamming approach
long minstepsdp(int n,int *dp){

    long mn=n,opt1=n,opt2=n,opt3=n;

    if(n==0||n==1)
        return 0;

    if(dp[n]!=0)
        return dp[n];
    
    if(n%3==0)
         opt1= minstepsdp(n/3,dp)+1;
    if(n%2==0)
         opt2= minstepsdp(n/2,dp)+1;
    
    opt3= minstepsdp(n-1,dp)+1;

    mn = min(opt1,min(opt2,opt3));
    dp[n]=mn;

    return dp[n];
}
int main(){

    int n;
    cin>>n;
    int dp[100] ={0};
    //memset(dp,-1,sizeof(int)*n);
    cout<<minstepsdp(n,dp)<<endl;
    cout<<minsteps(n)<<endl;

    return 0;
}