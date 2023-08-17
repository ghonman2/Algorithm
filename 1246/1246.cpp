#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;

int n = 0 , m = 0;
vector<int>eggs;

void init()
{
	cin >> n >> m;
	eggs = vector<int>(m);
	for (int i = 0 ; i < m; i ++)
		cin >> eggs[i];
	sort(eggs.begin(), eggs.end());
}

void sol()
{
	int price = 0;
	int total = 0;

	for (int i = 0 ; i < (int)eggs.size(); i ++)
	{
		int tmp;
		int egg = eggs[i];
		if (m - i < n)
			tmp = egg * (m - i);
		else
			tmp = egg * n;
		if (tmp > total)
		{
			total = tmp;
			price = egg;
		}
	}
	cout << price << " " << total << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	sol();
	return 0;
}

