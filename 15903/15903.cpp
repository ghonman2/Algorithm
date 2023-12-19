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

uint64_t n,m;
priority_queue<uint64_t,vector<uint64_t>,greater<uint64_t>>q;
void input()
{
	cin >> n >> m;
	for (uint64_t i = 0; i < n; i++)
	{
		uint64_t tmp;
		cin >> tmp;
		q.push(tmp);
	}
}

void sol()
{
	uint64_t t = 0;
	while (t++ < m){
		uint64_t fnum = q.top(); q.pop();
		uint64_t snum = q.top(); q.pop();
		q.push(fnum + snum); q.push(fnum + snum);
	}
	uint64_t sum = 0;
	while (!q.empty()){
		sum += q.top(); q.pop();
	}
	printf("%llu\n",sum);
}

int main()
{
	input();
	sol();
	return (0);
}
