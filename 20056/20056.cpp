#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

#define FAST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define REP(i,a,b) for(int i = a ; i < b ; i ++)
using namespace std;

typedef vector<int> vi;
typedef pair<int,int>pi;

int n,m,k;

vector<vi>fireBalls;

vector<vi>nr_field;
vector<vi>m_field;
vector<vi>s_field;

void init()
{
	cin >> n >> m >> k;
	REP(i,0,m)
	{
		int r,c,m,s,d;
		cin >> r >> c >>m >>s >>d;
		fireBalls.push_back({r,c,m,s,d});
	}
	nr_field = vector<vi>(n,vi(n,0));
	m_field = vector<vi>(n,vi(n,0));
	s_field = vector<vi>(n,vi(n,0));
}


int main()
{
	FAST;
	init();
	return 0;
}
