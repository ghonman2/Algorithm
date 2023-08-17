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

typedef vector<int> vi;
typedef vector<char> vc;

int n;
vector<vc>graph;
vector<int>getFriend;

void input()
{
	cin >> n;
	graph = vector<vc>(n,vc(n));
	getFriend = vector<int>(n,0);
	for (auto &g : graph)
	{
		for (auto &c : g)
			cin >> c ;
	}
}

void sol()
{
	vector<vc>oneRound = graph;

	for (int i = 0 ; i < n ; i ++){
		for (int j = 0; j < n ; j ++){
			for (int k = 0; k < n; k ++){
				if (k == i || k == j || i == j) continue;
				if (graph[i][k] == 'Y' && graph[k][j] == 'Y')
					oneRound[i][j] = 'Y';
			}
		}
	}
	int maxElement = 0;
	for (int i = 0 ; i < n; i ++)
		maxElement = max(maxElement, (int)count(oneRound[i].begin(),oneRound[i].end(), 'Y'));
	cout <<  maxElement << endl;
}

int main()
{
	input();
	sol();
	return (0);
}
