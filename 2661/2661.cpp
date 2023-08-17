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

int n = 0 ;
string answer = "4";
vi numbers(80,0);

void init()
{
	cin >> n;
}

void search(int cnt)
{

	for(int i = 1; i <= cnt/2; i ++){
		if(equal(numbers.begin() + cnt - i,numbers.begin()+cnt,numbers.begin()+cnt-i*2))return;
	}

	if(cnt == n){
		for(int i = 0 ; i < n; i++)cout << numbers[i];
		cout << "\n";
		exit(0);
	}

	for(int i = 1 ; i <= 3; i++){
		numbers[cnt] = i;
		search(cnt+1);
	}
}


void sol()
{
	search(0);
}


int main(){
	FAST;
	init();
	sol();
	return 0;
}

