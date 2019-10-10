#include<iostream>
#include<limits.h>
using namespace std;


//recursive approach 
int minCoinsChange(int n,int coins[],int totCoins){
    int finalans=INT_MAX;
    if(n<0)
        return 0;
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    for(int i=0;i<totCoins;i++){
        if(n-coins[i]>=0){
        int smallans =minCoinsChange(n-coins[i],coins,totCoins)+1;
        finalans=min(smallans,finalans);
        }
    }
    return finalans;
}

//top down dp approach 
int minCoinsChangeDP(int n,int coins[],int totCoins,int* dp){
    int finalans=INT_MAX;
    if(dp[n]!=0)
        return dp[n];
    if(n<0)
        return 0;
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    for(int i=0;i<totCoins;i++){
        if(n-coins[i]>=0){
        int smallans =minCoinsChange(n-coins[i],coins,totCoins)+1;
        finalans=min(smallans,finalans);
        }
    }
    dp[n]=finalans;
    return dp[n];
}

int main(){


    int n;
    cin>>n;
    int coins[] = {1,7,10};
    int* dp = new int[n+1];
    for(int i=0;i<=n;i++)
        dp[i]=0;
    cout<<minCoinsChangeDP(n,coins,3,dp)<<endl;
    cout<<minCoinsChange(n,coins,3)<<endl;
    return 0;
}