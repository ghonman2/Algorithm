#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
#define print(a) cout << a << "\n";
#define vprint(a) REP(i,0,a.size()) cout << a[i] << " "; cout << "\n";

using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;

long long n;
vector<long long> students;
long long b,c;

void init()
{
	cin >> n ;
	students = vector<long long>(n,0);
	REP(i,0,n) cin >> students[i];
	cin >> b >> c;
}

void sol()
{
	long long ret = n;
	for (int i = 0; i < n ; i ++)
	{
		students[i] -= b;
		if (students[i] > 0)
		{
			ret += students[i] / c + (students[i]% c == 0 ? 0 :1);
		}
	}
	cout << ret << "\n";
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

