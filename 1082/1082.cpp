#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef pair<int, string> pi;

int n,m;
vector<pi> p;

int cmp(pi &a, pi &b)
{
	return a.first != b.first ? a.first < b.first : a.second < b.second;
}

void input()
{
	cin >> n;
	p = vector<pi>(n);
	for (int i = 0; i < n; i++){
		cin >> p[i].first;
		p[i].second += (char)(i + '0');
	}
	cin >> m;
	sort(p.begin(), p.end(),cmp);
}

int scmp(char &a, char &b){
	return a > b;
}

int cmpMaxStr(string &a, string &b)
{
	if (a.length() != b.length())
		return (a.length() < b.length());
	for (size_t i = 0; i < a.length(); i++){
		if (a[i] != b[i])
			return a[i] < b[i];
	}
	return (0);
}

string getMax(string &from, string &to, pi &t)
{
	string ret;
	if (to == "0" && t.second == "0")
		ret = "0";
	else 
		ret = to + t.second;
	sort(ret.begin(), ret.end(), scmp);
	return (cmpMaxStr(from, ret) ? ret : from);
}

void sol()
{
	vector<string>dp(m+1);

	for (int i = m; i >= 0; i--){
		for (auto &t: p){
			if (i >= t.first)
				dp[i - t.first] = getMax(dp[i - t.first], dp[i], t);
		}
	}

	printf("%s\n",dp[0].c_str());
	return ;
}

int main()
{
	input();
	sol();
	return (0);
}
