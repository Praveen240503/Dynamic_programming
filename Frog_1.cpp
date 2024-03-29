#include<bits/stdc++.h>
using namespace std;
int dp[100001];

int Fun(int ind, int n, int arr[]){
	//base case 
	if(ind==n-1)return 0;
	if(dp[ind]!=-1)return dp[ind];
	//recursive call
	int left=abs(arr[ind]-arr[ind+1])+Fun(ind+1,n,arr);

	int right=INT_MAX;
	if(ind+2<=n-1){
		right = abs(arr[ind]-arr[ind+2])+Fun(ind+2,n,arr);
	}

	return dp[ind]=min(left,right);
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)cin>>arr[i];
	cout<<Fun(0,n,arr);

}
