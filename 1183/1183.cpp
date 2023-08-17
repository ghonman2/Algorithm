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

int n;

vector<int>A;
vector<int>B;
vector<int> sub;

void input(){
	cin >> n;
	A = vector<int>(n);
	B = vector<int>(n);
	sub = vector<int>(n);
	for (int i = 0 ; i < n; i++)
	{
		cin >> A[i] >> B[i];
		sub[i] = (A[i]) - B[i];
	}
	sort(sub.begin(), sub.end());
}

void sol()
{
	if (sub.size() % 2 == 1)
		cout << 1 << endl;
	else 
		cout << sub[n / 2]  - sub[n/2 - 1] + 1<< endl;
}

int main(){
	input();
	sol();
	return (0);
}
