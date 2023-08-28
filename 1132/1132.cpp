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
vector<string> ins;
map<int, ll> dict;

void input()
{
	cin >> n;
	ins = vector<string>(n);
	for (auto &in : ins)
		cin >> in;
	ll num = 9;
	for (auto & in: ins){
		for (char &ch : in){
			if (dict.find(ch) == dict.end())
				dict[ch] = num --;
		}
	}
}

ll transToBase(string &str, vector<int> &nums)
{
	ll ret = 0;
	if (nums[str[0] - 'A'] == 0)
		return (-1);
	for (auto &ch : str)
		ret = ret * 10 + nums[ch - 'A'];
	return (ret);
}

void sol()
{
	ll answer = 0;

	for (int i = 0; i < 10 - num; i ++){

	}

	cout << answer << endl;
}


int main()
{
	//input();
	myInput();
	sol();
	return (0);
}
