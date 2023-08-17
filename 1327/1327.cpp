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

typedef pair<string, int> psn;

int n,k;
vector<int> number;

void input()
{
	cin >> n >> k;
	number = vector<int>(n);
	for (auto &num : number)
		cin >> num;
}

string vectorToString(vector<int> &v)
{
	string ret;
	for (int &n : v)
		ret += (char)(n + '0');
	return (ret);
}

void sol()
{
	string begin = vectorToString(number);
	string correct;
	queue<psn>q;
	int answer = -1;
	set<string>visited;

	for (int i = 1; i <= n; i++)
		correct += ('0' + i);
	q.push(make_pair(begin, 0));

	while(!q.empty()){
		string now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (now == correct){answer = cnt; break;}
		for (int i = 0 ; i <= n - k; i ++){
			string next = now.substr(0, i);
			string rev = now.substr(i, k);
			reverse(rev.begin(), rev.end());
			next += rev + now.substr(i + k);
			if (visited.count(next)) continue;
			visited.insert(next);
			q.push(make_pair(next, cnt + 1));
		}
	}
	cout << answer << endl;
}

int main()
{
	input();
	sol();
	return (0);
}
