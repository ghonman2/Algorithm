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

string line;
size_t len;
int answer = 0;
vector<int> visited;
vector<int> check(26, 0);

void input()
{
	cin >> line;
	len = line.length();
	visited = vector<int> (len, 0);
	for (auto &c : line)
		check[c - 'a'] += 1;
}


int isLucky(string &line)
{
	for (int i = 0 ; i < (int)line.length() - 1 ; i++)
		if (line[i] == line[i+1]) return (0);
	return (1);
}

void dfs(string &str)
{
	if (str.length() == len){
		answer += isLucky(str);
		return ;
	}

	for (int i = 0; i < (int)len; i ++){
		if (visited[i]) continue;
		visited[i] = 1;
		str += line[i];
		dfs(str);
		str.pop_back();
		visited[i] = 0;
	}
}

int factorial(int c)
{
	int ret = 1;
	for (int i = 1 ; i <= c ; i++)
		ret *= i;
	return (ret);
}

void sol()
{
	string str;
	dfs(str);
	for (auto &c : check)
		answer /= factorial(c);
	cout << answer << endl;
}

int main()
{
	input();
	sol();
	return (0);
}
