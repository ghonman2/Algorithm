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

void input()
{
	cin >> n;
	words = vector<string>(n);
	for (auto &w: words)
		cin >> w;
}

void sol()
{
	sort(words.begin(), words.end());
	int cnt = n;
	for (int i = 0 ; i < n ; i ++){
		for (int j = i + 1; j < n ; j ++){
			if (words[j].substr(0, words[i].size()) == words[i]){
				cnt --;
				break;
			}
		}
	}
	cout << cnt << endl;
}

int main()
{
	input();
	sol();
	return (0);
}
