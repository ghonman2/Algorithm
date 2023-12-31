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
void input()
{
	cin >> line;
}


int cntOtherA(int pos, string &line, int len)
{
	int cnt = 0;
	for (int i = 0; i < len ; i++)
		if (line[(i+pos) % len] == 'b')
			cnt ++;
	return (cnt);
}

void sol()
{
	int lineLen = line.length();
	int ret = INT_MAX;
	int aCnt = count(line.begin(),line.end(), 'a');

	for (int i = 0; i < lineLen; i++){
		ret = min(ret, cntOtherA(i,line, aCnt));
	}

	printf("%d\n",ret);

}

int main()
{
	input();
	sol();
	return (0);
}
