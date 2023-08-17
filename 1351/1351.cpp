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

typedef long long ll;

ll n,p,q;
map<ll, ll>numbers;

void input()
{
	cin >> n >> p >> q;
}

ll recur(ll input)
{
	if (numbers.find(input) != numbers.end())
		return numbers[input];
	numbers[input] = recur(input / p) + recur(input / q);
	return numbers[input];
}

void sol()
{
	numbers[0] = 1;
	cout << recur(n) << endl;
}

int main()
{
	input();
	sol();
	return (0);
}
