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
vector<uint64_t> nums;
vector<uint64_t> k;
void input()
{
	cin >> n;
	nums = vector<uint64_t>(n);
	for (auto &num : nums)
		cin >> num;
}

int isPrime(uint64_t &n){
	if (n < 2)
		return (0);
	uint64_t line = (uint64_t)sqrt(n) + 1;
	for (uint64_t i = 2; i < line; i ++){
		if (n % i == 0)
			return (0);
	}
	return (1);
}

void sol()
{
	vector<uint64_t>dp;
	//uint64_t maxNum = *max_element(nums.begin(), nums.end());

	for (auto &num:nums){
		auto primeNum = num;
		while (!isPrime(primeNum)) primeNum ++;
		cout << primeNum << endl;
	}
}

int main()
{
	input();
	sol();
	return (0);
}
