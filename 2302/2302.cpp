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

int n = 0 , m = 0;
set<int>vip;
void init()
{
	cin >> n >> m;
	for (int i = 0 ; i < m; i ++)
	{
		int num = 0;
		cin >> num;
		vip.insert(num);
	}
}

void sol()
{
	vector<int>dp(n+1 , 0);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	if (vip.find(2) != vip.end())
		dp[2] = 1;
	for (int i = 3; i <= n ; i ++)
	{
		if (vip.find(i) == vip.end())
			dp[i] = dp[i-2] + dp[i - 3];
	}
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

