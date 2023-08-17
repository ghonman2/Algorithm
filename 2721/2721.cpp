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

int t =0;

long long T(int k)
{
	long long ret = 0;
	for(int i = 1; i <=k ; i++)
		ret += i;
	return ret;
}

void sol()
{
	while(t--)
	{
		int n = 0 ;
		cin >> n;
		long long ret = 0;
		for(int i = 1; i <=n ;i ++)
			ret += i * T(i+1);
		cout << ret << "\n";
	}
}


int main(){
	FAST;
	cin >> t;
	sol();
	return 0;
}

