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

int n,k;
uint64_t answer = 0;

void init()
{
	cin >> n >> k;
}

int dp(int a, int b, int depth)
{
	int count = 2;
	if (a == b)
		count = 1;
	if (depth == k)
		return (count);
	if (a) count += dp(a - 1, b, depth + 1);
	if (b)  count += dp(a, b - 1, depth + 1);
	return (count);
}

void sol()
{
	if (k == 1)
	{
		answer = 1;
		return ;
	}
	for (int i = 0 ; i < n ; i ++)
	{
		answer = (answer + dp(i, n - i, 2)) % 1000000000;
		cout << i << " " << answer << endl;
	}
}

int main(){
	FAST;
	init();
	sol();
	cout << answer << endl;
	return 0;
}

