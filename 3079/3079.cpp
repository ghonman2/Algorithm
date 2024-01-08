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
#define FAST cin.tie(NULL);ios::sync_with_stdio(false)

using namespace std;

typedef long long ll;

ll n,m;
vector<ll> t;

void input()
{
	cin >> n >> m;
	t = vector<ll>(n);
	for (auto &tmp : t)
		cin >> tmp;
}

int valid(ll &x)
{
	ll p = 0;

	for (auto &time: t){
		p += x / time;
		if (p >= m) return (1); 
	}
	return (p >= m);
}

void sol()
{
	ll l = 0, r = *max_element(t.begin(),t.end()) * m;

	while (l < r){
		ll mid = (l + r) / 2;
		if (valid(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << l << "\n";
}

int main(){
	FAST;
	input();
	sol();
	return 0;
}
