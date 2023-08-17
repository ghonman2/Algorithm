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


vector<int>boxes;
int n = 0;

void init()
{
	cin >> n;
	boxes = vector<int>(n);
	for(int i = 0 ; i < n ; i++)
		cin >> boxes[i];
}

void sol()
{
	int answer = 0;
	vector<int>dp(n, 0);
	for (int  i = 0 ; i < n; i++)
	{
		int tmp = 0;
		for (int j = 0; j < i; j ++)
		{
			if (boxes[j] < boxes[i])
				tmp = max(tmp, dp[j]);
		}
		dp[i] = tmp + 1;
		answer = max(dp[i], answer);
	}
	cout << answer << endl;
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

