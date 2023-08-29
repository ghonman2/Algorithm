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

typedef pair<string, string> ps;

string s1, s2;

void input()
{
	cin >> s1 >> s2;
}

ps makePs(string &s)
{
	return make_pair(s.substr(0, s.find('*')), s.substr(s.find('*') + 1));
}

string cmpxchg(string &s1, string &s2)
{
	string ret;
	size_t l1 = s1.length(), l2 = s2.length();
	if (l1 > l2){
		if (l2 == 0)
			return s1;
		size_t pos = -1;
		if ((pos = s1.find(s2)) == string:npos)
			return ret;
		else if (pos != )
	}
	else {
	}
}

void sol()
{
	string answer = "-1";
	string left, right;

	if (s1.length() < s2.length())
		swap(s1, s2);
	ps sp1 = makePs(s1), sp2 = makePs(s2);
	left = cmpxchg(sp1.first, sp2.first);
	right = cmpxchg(sp1.second, sp2.second);
	if (left.length() == 0 || right.length() == 0)
		cout << answer << endl;
	else 
		cout << left + right << endl;
}

int main() 
{
	input();
	//string s1 = "A", s2 = "";
	//cout << cmpxchg(s1,s2) << endl;
	sol();
    return 0;
}

