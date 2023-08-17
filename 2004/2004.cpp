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

void input()
{
	cin>> n >> m;
}

uint64_t cntNum(uint64_t n, uint64_t div)
{
	uint64_t ret = 0;

	for (uint64_t i = div; n /i >= 1; i *= div )
		ret += n / i;
	return (ret);
}

void sol()
{
	uint64_t countTwo = cntNum(n,2) - cntNum(m,2) - cntNum(n-m, 2);
	uint64_t countFive = cntNum(n,5) - cntNum(m,5) - cntNum(n-m, 5);
	cout << min(countTwo,countFive) << endl;
}

int main()
{
	input();
	sol();
	return (0);
}

