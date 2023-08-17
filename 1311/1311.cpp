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

int n;
vector<bitset<20>>people;

void init()
{
	cin >> n;
	people = vector<bitset<20>>(n);
	REP(i,0,n){
		people[i].reset();
		REP(j,0,n){
			int tmp = 0 ;
			cin >> tmp;
			people[i].set(tmp-1,true);
		}
	}
}

void sol()
{

}

int main(){
	FAST;
	init();
	return 0;
}

