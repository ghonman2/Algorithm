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

int n,k;
typedef long ll;

void input()
{
	cin >> n >> k;
}

ll getWater(ll n)
{
	ll cnt = 0;
	while (n)
	{
		if (n % 2 == 1)
			cnt ++;
		n /= 2;
	}
	return cnt;
}

void sol()
{
	ll answer = -1;
	ll num = n;
	while (1)
	{
		ll t = getWater(n);
		if (t <= k) break;
		n ++;
	}
	cout << n - num << endl;
}

int main()
{
	input();
	sol();
	return (0);
}
