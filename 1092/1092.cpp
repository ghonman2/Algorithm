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

int n,m;
deque<int> crains;
deque<int> boxes;

void input()
{
	cin >> n;
	crains = deque<int>(n);
	for (auto & c : crains)
		cin >> c;
	cin >> m;
	boxes = deque<int>(m);
	for (auto &m : boxes)
		cin >> m;
	sort(crains.begin(), crains.end());
	sort(boxes.begin(), boxes.end());
}

void print(vector<int> &boxes)
{
	for (auto &b: boxes)
		printf("%d ",b);
	printf("\n");
}

void solution()
{
	int cnt = 0;
	if (crains.back() < boxes.back())
	{
		cout << -1 << endl;
		return;
	}
	while (!boxes.empty())
	{
		deque<int> tmp;
		while (!crains.empty() && !boxes.empty())
		{
			int crain = crains.front(); crains.pop_front();
			int idx = upper_bound(boxes.begin(), boxes.end(), crain) - boxes.begin();
			if (idx > 0){
				idx -= 1;
				boxes.erase(boxes.begin() + idx);
			}
			tmp.push_back(crain);
		}
		crains = tmp;
		cnt ++;
	}
	cout << cnt << endl;
}

int main()
{
	//FILE *f = freopen("log","r", stdin);
	input();
	solution();
	//fclose(f);
	return (0);
}
