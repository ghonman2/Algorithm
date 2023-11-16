#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long ll;

string n;
ll k;

void input()
{
	cin >> n >> k;
}

void sol()
{
	int dp[k];
	memset(dp,0,sizeof(dp));
	int reminder = stol(n) % k;
	int ans = 1;

	while (reminder)
	{
		printf("reminder %d\n",reminder);
		if (dp[reminder])
			break;
		dp[reminder] = 1;
		ans ++;
		reminder = stol(n+n) % k;
	}

	if (reminder)
		cout << -1 << endl;
	else
		cout << ans << endl;
}

int main()
{
	input();
	sol();
	return (0);
}
