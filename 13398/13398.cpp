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
	vector<int>dp(n, 0);
	int lo = 0 ,hi = 0, sum = 0;
	while (hi< n){
		if (nums[hi] > 0) sum += nums[hi++];
		else sum -= nums[lo ++];
		dp[lo] = max(dp[lo], sum);
	}
	for (auto &n : dp)
		cout << n << " ";
	cout << endl;
}

int main()
{
	input();
	sol();
	return (0);
}
