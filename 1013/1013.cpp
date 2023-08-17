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
vector<string> words;
regex re("(100+1+|01)+");
void input()
{
	cin >> n;
	words = vector<string>(n);
	for (int i = 0 ; i < n; i ++)
		cin >> words[i];
}

void sol()
{
	for (auto &word : words)
	{
		if (regex_match(word, re))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	input();
	sol();
	return (0);
}
