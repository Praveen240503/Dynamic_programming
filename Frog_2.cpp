#include<bits/stdc++.h>
using namespace std;
int dp[100001];

int Fun(int ind, int n, int arr[],int k){
	//base case 
	if(ind==n-1)return 0;
	if(dp[ind]!=-1)return dp[ind];
	//recursive call
	int ans=INT_MAX;
	for(int i=1;i<=k;i++){
		if(ind+i<n){
			int temp=abs(arr[ind]-arr[ind+i])+Fun(ind+i,n,arr,k);
			ans=min(ans,temp);
		}
	}
	return dp[ind]=ans;
}
int main(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)cin>>arr[i];
	cout<<Fun(0,n,arr,k);

}
