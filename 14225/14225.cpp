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

vi numbers;
int n = 0 ;
vi check;
int maxn;
void init()
{
	cin >> n;
	numbers = vi(n,0);
	REP(i,0,n)cin >> numbers[i];
	maxn = accumulate(numbers.begin(),numbers.end(),0);
	check = vi(maxn+2,0);
}


void search(int number,int idx)
{

	check[number] = 1;
	if(idx == numbers.size())
		return;
	for(int i = idx; i < numbers.size(); i++){
		search(number+numbers[i],i+1);
	}
}
void sol()
{

	search(0,0);
	REP(i,1,check.size()){
		if(check[i] == 0){
			cout << i << "\n";
			break;
		}
	}
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

