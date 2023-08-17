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

#define NO_ANSWER "I'm Sorry Hansoo"

string _name, name;
size_t n;
unordered_map <char, int> counter;

void input()
{
	cin >> _name;
	name = _name;
	n = name.length();
	sort(name.begin(), name.end());
	for (auto & c : name)
		counter[c] ++;
	name.erase(unique(name.begin(), name.end()), name.end());
	reverse(name.begin(), name.end());
}

void sol()
{
	string ans;
	for (auto &cnt : counter){
		if (cnt.second == 0) continue;
		else if (cnt.second % 2 == 1 && ans.length() == 0)
			ans += cnt.first;
		else if (cnt.second % 2 == 1 && ans.length() != 0){
			cout << NO_ANSWER << endl;
			return ;
		}
	}
	if (ans.length())
		counter[ans[0]] -= 1;
	for (auto &c : name){
		string tmp(1,c);
		while (counter[tmp[0]]){ans = tmp + ans + tmp; counter[tmp[0]] -= 2;}
	}
	cout << ans << endl;
}

int main()
{
	input();
	sol();
	return (0);
}
