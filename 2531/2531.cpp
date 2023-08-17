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
int d;
int k;
int c;

vector<int> sushies;

void input()
{
	cin >> n >> d >> k >> c;
	sushies = vector<int>(n);
	for (auto &s : sushies)
		cin >> s;
}

bool v[30001];

void sol()
{
	int answer = 0;
	vector<int> tmp;
	int left = 0;
	
	while (left < n){
		int cnt = 0, flag = 0, coupon = 0;
		while (cnt < k){
			if (!v[sushies[(left + cnt) % n]])
				v[sushies[(left + cnt) % n]] = 1;
			else
				flag ++;
			cnt ++;
		}
		if (!v[c]) coupon = 1;
		answer = max(cnt - flag + coupon, answer);
		left ++;
		bzero(v, sizeof(v));
	}
	cout << answer << endl;
}

int main()
{
	input();
	sol();
	return (0);
}
