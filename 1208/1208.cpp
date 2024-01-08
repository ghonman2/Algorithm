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
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
using namespace std;

typedef long long ll;


int n,s;
vector<int> nums;
unordered_map<ll, int> cnts;
ll ans = 0;

void input()
{
	cin >> n >> s;
	nums.assign(n, 0);

	for (auto &t : nums)
		cin >> t;
}

void leftSum(int idx, ll sum)
{
	if (idx == n/2){
		cnts[sum] ++;
		return ;
	}
	leftSum(idx + 1, sum);
	leftSum(idx + 1, sum + nums[idx]);
}

void rightSum(int idx, ll sum)
{
	if (idx == n){
		ans += cnts[s-sum];
		return ;
	}
	rightSum(idx + 1, sum + nums[idx]);
	rightSum(idx + 1, sum);
}

void sol()
{
	leftSum(0,0);
	rightSum(n/2,0);

	if (!s) ans -= 1;
	cout << ans << '\n';
}

int main(){
	FAST;
	input();
	sol();
	return 0;
}
