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

int n;
vector<int> nums;

void input()
{
	cin >> n;
	nums = vector<int>(n);
	for (auto &n : nums)
		cin >> n;
}

void sol()
{
	int answer = nums[0];
	vector<int> dp[2];
	dp[0] = vector<int>(n,0); // 원래대로 
	dp[1] = vector<int>(n,0); // 하나 뺀것 
	
	dp[0][0] = nums[0];
	dp[0][1] = nums[0];
	for (int i = 1; i < n; i++){
		dp[0][i] = max(dp[0][i-1] + nums[i], nums[i]);
		dp[1][i] = max(dp[0][i-1], dp[1][i-1] + nums[i]);
		answer = max(answer,max(dp[0][i],dp[1][i]));
	}
	cout << answer << endl;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); 
	input();
	sol();
	return (0);
}
