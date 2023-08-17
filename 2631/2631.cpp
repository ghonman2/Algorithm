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

int n;
vector<int> child;

void init()
{
	cin >> n;
	child = vector<int>(n,0);
	for (int i = 0 ; i < n ; i++)
		cin >> child[i];
}

void sol()
{
	vector<int>dp(n+1,0);

	for (int k = 0 ; k < n; k ++)
	{
		dp[k] = 1;
		for (int i = 0 ; i < k; i ++)
		{
			if (child[i] < child[k])
				dp[k] = max(dp[k] , dp[i] + 1);
		}
	}
	cout << n - *max_element(dp.begin(),dp.end()) << endl;
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

