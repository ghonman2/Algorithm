#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string>board;

int n,r1,r2,c1,c2;


void init()
{
	cin >> n >> r1 >> r2 >> c1 >> c2; 
	board = vector<string>(r2 - r1 + 1, string(c2 - c1 + 1, '.'));
}

void sol()
{
	for (auto b : board)
		cout << b << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	sol();
	return (0);
}
