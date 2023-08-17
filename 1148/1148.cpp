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

#include <string.h>
#include <vector>
#include <iostream>


using namespace std;

typedef vector<char> vc;
vector<string> word;
vector<vc>puzzles;


void input()
{
	vector<string> words;
	string tmp;
	while (cin >> tmp)
	{
		if (tmp == "-")
			break;
		words.push_back(tmp);
	}
	int cnt = 0;
	while (cin >>tmp)
	{
		if (tmp == "#")
			break;
		for (auto ch : tmp)
			puzzle[cnt].push_back(ch);
		cnt += 0 ;
	}
}

void sol()
{

}


int main()
{
	cin.tie(NULL);
	ios::snyc_with_stdio(false);
}
