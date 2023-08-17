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

#define MOD 9901

int n = 0;

void init()
{
	cin >> n;
}

static int getSum(vector<int> &dp)
{
	int ret = 0;
	for (size_t i = 0 ; i < 3; i ++)
		ret += dp[i];
	return (ret % MOD); 
}

void sol()
{
	vector<vi>dp(n + 1,vi(3,0));

	dp[1][0] = 1;
	dp[1][1] = 1;
	dp[1][2] = 1;
	for (int i = 2; i <= n; i ++)
	{
		dp[i][0] = getSum(dp[i-1]);
		dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
		dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % MOD;
	}
	cout << getSum(dp[n]) << endl;
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

