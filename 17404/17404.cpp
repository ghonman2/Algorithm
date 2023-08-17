#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
#define print(a) cout << a << "\n";
#define vprint(a) REP(i,0,a.size()) cout << a[i] << " "; cout << "\n";
#define INF 1000*1000+1
using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;

int n = 0 ;
vector<vi>costs;
vector<vi> dp;
void init()
{
	cin >> n;
	costs = vector<vi>(n+1);
	REP(i,1,n+1){
		int r,g,b;
		cin >> r >> g >>b;
		costs[i] = {r,g,b};
	}
	dp = vector<vi>(n+1,vi(3,0));
}

void sol()
{
	int ans = INT_MAX;
	for(int  color = 0; color < 3 ; color++){
		for(int i = 0 ; i < 3 ; i++){
			if(i == color) dp[1][i] = costs[1][i];
			else dp[1][i] = INF;
		}
		for(int i = 2; i <= n; i ++){
			dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + costs[i][0];
			dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + costs[i][1];
			dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + costs[i][2];
		}

		for(int i = 0; i < 3 ;i ++){
			if(i == color) continue;
			ans = min(ans,dp[n][i]);
		}
	}
	cout << ans << "\n";
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

