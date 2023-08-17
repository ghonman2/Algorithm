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

typedef map<int, int> mi;

int n,m;
int answer;
vector<int>truthPeople;
vector<mi>parties;

void input()
{
	cin >> n >> m;
	parties = vector<mi>(m);
	int nrTruth = 0;
	truthPeople = vector<int>(n + 1, 0);
	cin >> nrTruth;
	for (int i = 0 ; i < nrTruth; i++){
		int p;
		cin >> p;
		truthPeople[p] = 1;
	}
	for (auto &party : parties){
		cin >> nrTruth;
		int  p;
		for (int i = 0 ; i < nrTruth; i ++){
			cin >> p;
			party[p] = 1;
		}
	}
}

int canLie(map<int,int> &party)
{
	for (auto &node : party){
		if (!node.second) continue;
		if (truthPeople[node.first])
			return (0);
	}
	return (1);
}

void setTruth(map<int, int> &party, int item)
{
	for (auto &node :party){
		truthPeople[node.first] = item;
	}
}

void dfs(int idx, int ret)
{
	if (idx == m - 1){
		answer = max(answer, ret);
		return;
	}
	for (int i = idx + 1; i < m; i ++){
		if (canLie(parties[i]))
			dfs(idx + 1, ret + 1);
		setTruth(parties[i], 1);	
		dfs(idx + 1, ret);
		setTruth(parties[i], 0);
	}
}

void sol()
{
	dfs(-1, 0);
	cout << answer << endl;
}


int	main(){
	input();
	sol();
	return (0);
}
