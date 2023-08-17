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

typedef pair<int, string> pis;

bool myCmp (const pis &a, const pis &b){
	return a.first < b.first;
}

void inputAndSol()
{
	int N, n = 0;
	int t;
	string nowStr;
	vector<pis> history = {pis(0, "")};
	cin >> N;
	while (n ++ < N){
		string cmd, middle;
		cin >> cmd >> middle >> t;
		if (cmd[0] == 't')
			nowStr += middle;
		else {

		}
		history.push_back({t, nowStr});
	}
	cout << history.back().second << endl;
}

int main()
{
	inputAndSol();
	return (0);
}
