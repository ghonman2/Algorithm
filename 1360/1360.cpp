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


typedef struct {
	char c[4];
	string line;
	int time;
}Cmd;

map<int, string>history;

vector<Cmd>cmds;

void input()
{
	int n;
	cin >> n;
	cmds = vector<Cmd>(n);

	for (auto &c : cmds)
		cin >> c.c >> c.line >> c.time;
}

void sol()
{
	int now = 0;
	string nowStr = "";

	for (auto &cmd : cmds){
		if (cmd.c[0] == 't')
			nowStr += cmd.line;
		else {
			int undoTime = cmd.time - stoi(cmd.line) - 1;
			auto iter = history.lower_bound(undoTime);
			
			if (iter == history.end());
			else if (undoTime < iter->first) nowStr = "";
			else if (iter == history.end()) ;
			else nowStr = iter->second;
		}
		history[cmd.time] = nowStr;
		now = cmd.time;
	}
	cout << nowStr << endl;
}

int main()
{
	input();
	sol();
	return (0);
}
