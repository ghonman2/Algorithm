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


int n;
vector<string> stringNumbers;

void input()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	stringNumbers = vector<string>(n);
	for (auto &str : stringNumbers)
		cin >> str;
}

inline ll transStrToNum(string &str, vector<ll> &dict)
{
	ll ret = 0;

	if (dict[int(str[0] - 'A')] == 0)
		return (ret);
	for (auto &ch : str)
		ret = ret * 10 + dict[(int)(ch - 'A')];
	return (ret);
}


void sol()
{
	vector<ll> dict(10,0);
	for (ll i = 0; i < 10; i ++)
		dict[i] = i;
	ll ret = 0;

	do {
		ll tmp = 0;
		int check = 0;
		for (auto &strNumber : stringNumbers){
			ll t = transStrToNum(strNumber,dict);
			if (!t){check = 1; break;}
			tmp += t; 
		}
		if (!check)
			ret = max(ret, tmp);
	}while(next_permutation(dict.begin(), dict.end()));
	printf("%lld\n",ret);
}

int main()
{
	input();
	//myInput();
	sol();
	return (0);
}
