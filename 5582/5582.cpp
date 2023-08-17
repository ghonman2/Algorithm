/**********************************************************************
 * Copyright (c) 2023
 *  Joowon park <ghonman2@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTIABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 **********************************************************************/

#include <bits/stdc++.h>

using namespace std;

string big,small;

void input()
{
	cin >> big >> small;
	if (big.length() < small.length())
		swap(big, small);
}

void sol()
{
	size_t n = big.length();
	size_t m = small.length();
	size_t ans = 0;

	vector<vector<size_t>> dp(n, vector<size_t>(m, 0));
	for (size_t i = 0; i < n; i ++){
		for (size_t j = 0; j < m; j++){
			if (big[i] == small[j]) {dp[i][j] = 1; if (i && j) dp[i][j] += dp[i-1][j-1];}
			ans = max(dp[i][j], ans);
		}
	}
	cout << ans << endl;
	return ;
}

int main()
{
	input();
	sol();
	return (0);
}
