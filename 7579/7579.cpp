#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
#define print(a) cout << a << "\n";
#define vprint(a) REP(i,0,a.size()) cout << a[i] << " "; cout << "\n";

using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;
typedef vector<ll> vl;
int n,m;
vl costs;
vl memory;
vector<vl> dp;
ll sum = 0 ;
void init()
{
	cin >>n >>m ;
	costs = vl(n+1);
	memory =  vl(n+1);
	costs[0] = 0;
	memory[0] = 0;
	REP(i,1,n+1) cin >> memory[i];
	REP(i,1,n+1) {cin >> costs[i]; sum += costs[i]; }
	dp = vector<vl>(n+1,vl(sum+1,0));

}

void sol()
{
	
	for(int i = 1; i <= n ; i ++ ){
		for(int  j = 0 ; j <= sum; j++){
			if(j>=costs[i]) 
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-costs[i]] + memory[i]);
			dp[i][j] = max(dp[i-1][j],dp[i][j]);
		}
	}
	for(int i = 1; i <=sum ; i++){
		if(dp[n][i] >= m){ 
			cout << i << "\n";
			break;
		}
	}
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

