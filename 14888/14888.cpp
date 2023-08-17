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
typedef vector<ll> vl;

ll minA = LLONG_MAX;
ll maxA  =-1000000001;
int n = 0;
char oper[] = "+-*/";
int nr_oper[4] = {0,0,0,0};
vl numbers;

ll cal(ll number,char op,int idx)
{
	ll other = numbers[idx];
	ll ret = 0 ;
	switch(op){
		case '*' : 
			ret = number*other;
			break;
		case '+' :
			ret = number + other;
			break;
		case '-' :
			ret = number - other;
			break;
		case '/' : 
			ret = number/other;
	}
	return ret;
}

void search(ll number, int idx)
{
	if (idx == n){
		minA = min(number,minA);
		maxA = max(number,maxA);
		return;
	}

	for(int k = 0 ; k < 4 ; k++){
		if(nr_oper[k] > 0){
			nr_oper[k] -- ;
			search(cal(number,oper[k],idx),idx+1);
			nr_oper[k] ++ ;
		}
	}
}

void init()
{
	cin >> n ;
	numbers = vl(n,0);
	REP(i,0,n)cin >> numbers[i];
	REP(i,0,4)cin >> nr_oper[i];
}

int main(){
	FAST;
	init();
	search(numbers[0],1);
	print(maxA);
	print(minA);
	return 0;
}

