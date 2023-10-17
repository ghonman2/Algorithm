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

priority_queue<int, vector<int>, greater<int>> minQueue;
priority_queue<int, vector<int>, less<int>> maxQueue;
int n;

typedef priority_queue<int, vector<int>, greater<int>> pqg;
typedef priority_queue<int, vector<int>, less<int>> pql;

void input()
{
	cin >> n;
}

void swapQueueTop(pqg &a, pql& b)
{
	int numA = a.top(), numB = b.top();
	a.pop(), b.pop();
	a.push(numB), b.push(numA);
}

void sol()
{
	int num;
	for (int i = 0 ; i < n; i ++){
		cin >> num;
		if (maxQueue.empty() || maxQueue.size() == minQueue.size())
			maxQueue.push(num);
		else
			minQueue.push(num);
		if (!minQueue.empty() && !maxQueue.empty() && maxQueue.top() > minQueue.top()){
			int a = minQueue.top() ,b = maxQueue.top();
			minQueue.pop(), maxQueue.pop();
			maxQueue.push(a);
			minQueue.push(b);
		}
		cout << maxQueue.top() << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	input();
	sol();
	return (0);
}
