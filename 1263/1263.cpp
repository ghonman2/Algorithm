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

typedef pair<int, int> pi;

int n;
vector<pi> t;

int cmp(pi &a, pi &b)
{
	if (a.second != b.second) return a.second > b.second;
	return a.first < b.first;
}

void input()
{
	cin >> n;
	t = vector<pi>(n);
	for (int i = 0 ; i < n ; i++)
		cin >> t[i].first >> t[i].second;
	sort(t.begin(), t.end(), cmp);
}

void sol()
{
	int endTime = t.front().second ;
//	for (auto &time : t)
//		cout << time.second << " | " << time.first << endl;

	for (int i = 0; i < (int)t.size(); i ++){
		//printf("endTime %d : checkTIme : %d\n",endTime, t[i].second - t[i].first);
		if (endTime < t[i].second - t[i].first){
			cout << -1 << endl;
			return ;
		}
		endTime = min(t[i].second - t[i].first, endTime - t[i].first);
	}
	cout << min(t.back().second - t.back().first, endTime) << endl;
}

int main(){
	input();
	sol();
	return (0);
}
