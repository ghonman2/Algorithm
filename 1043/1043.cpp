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

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int n,m,k;
vector<int> truth;
vector<vi> party;
vector<int> parent;

void input()
{
	cin >> n >> m >> k;
	parent = vector<int>(n+1,0);
	truth = vector<int>(k);
	party = vector<vi>(n+1);
	for (auto &t: truth)
		cin >> t;
	for (int i = 0; i < m; i ++){
		int nrParty, p;
		cin >> nrParty;
		for (int j = 0; j < nrParty; j++){
			cin >> p;
			party[i].push_back(p);
		}
	}
	for (int i = 1; i < n+1;i++)
		parent[i] = i;
}

inline int find(int a)
{
	return a == parent[a] ? a : find(parent[a]);
}

void unions(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b) parent[b] = a;
}

void sol()
{
	int answer = m;

	for (auto &p: party)
		for (auto &k: p)
			unions(p[0],k);

	for (int i = 0; i < m; i++){
		int isTruth = 0;
		for (auto &p : party[i]){
			for (auto &t : truth)
				if (find(t) == find(p)) {isTruth = 1; break;}
			if (isTruth) break;
		}
		if (isTruth) answer --;
	}
	printf("%d\n",answer);
}

int main()
{
	input();
	sol();
	return (0);
}
