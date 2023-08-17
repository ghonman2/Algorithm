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

int n = 0;
vi numbers;

void init()
{
	cin >> n;
	numbers = vi(n,0);
	REP(i,0,n) cin >> numbers[i];
}

int search(int n)
{	
	cout << n << "\n";
	if(n == 2 || n == 1) return 1;
	if(n % 2){
		return 1+ search(n/2+1);
	}
	else if(n % 2 == 0 && (n/2) % 2 == 1){
		return search(n/2);
	}
	else return 0;

}

void sol()
{
	//for(auto num : numbers){
		cout << search(numbers[1]) << "\n";
	//}
}


int main(){
	FAST;
	init();
	sol();
	return 0;
}

