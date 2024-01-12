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

int n,k;
vector<int> stream;

void input()
{
	cin >> n >> k;
	stream.assign(k,0);
	for (auto &s: stream)
		cin >> s;
}

void sol()
{
	int answer = 0;
	set<int> inTab;
	set<int> outTab;

	for (int i = 0; i < n; i ++)
		outTab.insert(i);

	for (size_t i = 0; i < stream.size(); i ++){
		auto &s = stream[i];
		if (inTab.find(s) != inTab.end()) continue;
		if (outTab.size() != 0) {outTab.erase(outTab.begin()); inTab.insert(s); continue;}

		int outTab = -1, dist = 0;
		for (auto &t: inTab){
			outTab = outTab== -1 ? t : outTab;
			int tdist = INT_MAX;
			for (size_t j = i + 1; j < stream.size(); j ++){
				if (stream[j] == t) tdist = min(tdist, (int)j);
			}
			if (dist < tdist)
				outTab = t, dist = tdist;
			//printf("{t:%d tdist:%d}-> ",t,tdist);
		}
		//printf("\n");
		//printf("inTab:%d outTab:%d\n",s,outTab);
		inTab.erase(outTab);
		inTab.insert(s);
		answer += 1;
	}
	cout << answer << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	sol();
	return (0);
}
