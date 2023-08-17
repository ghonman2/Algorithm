#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)

using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;


int main(){
	FAST;
	int n,k = 0 ; 
	cin >> n >> k;
	vi coins(n);
	for(int i = 0 ; i < n ; i++)
		cin >> coins[i];
	sort(coins.begin(),coins.end());
	vi dp(k+1,0);
	dp[0] = 1;

	for(auto coin : coins){
		for(int i = 0 ; i <= k; i++)
			if(i-coin >=0) dp[i] += dp[i-coin];
	}

	cout << dp[k] << "\n";
	return 0;
}
