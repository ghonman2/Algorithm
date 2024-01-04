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
vector<pi> schedules;

int cmp(pi &a, pi &b)
{
	return (a.second > b.second);
}

void input()
{
	cin >> n;
	schedules = vector<pi>(n);
	for (auto &s :schedules)
		cin >> s.first >> s.second;
	sort(schedules.begin(), schedules.end(), cmp);
}

// 4
//3 5
//8 14
//5 20
//1 16

void sol()
{
	int left = 0;

	for (size_t i = 0; i < schedules.size();i ++){
		auto &s =  schedules[i];

	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	input();
	sol();
	return (0);
}
