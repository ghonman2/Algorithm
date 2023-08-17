#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
#define print(a) cout << a << "\n";
using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;
typedef vector<ll> vl;

ll n ,s; 
vl number;


void init()
{
	cin >> n >> s;
	REP(i,0,n) 
	{
		int num ;
		cin >> num;
		number.push_back(num);
	}

	sort(number.begin(),number.end());
}

void search(int num,int idx,int dst, map<ll,ll> &sums)
{

	if(sums.find(num) == sums.end()) sums[num] = 1;
	else sums[num] += 1;

	if(idx == dst) return;

	for(int i = idx+1; i < dst ; i++)
		search(num + number[i],i,dst,sums);
}

void sol()
{
	ll answer = 0 ;
	map<ll,ll>sums;
	map<ll,ll>other;

	for(int i = 0 ; i < n/2; i ++){
		search(number[i],i,n/2,sums);
	}
	for(int i = n/2 + !n %2; i < n ; i ++){
		search(number[i],i,n,other);
	}
	if(sums.find(s) != sums.end()) answer += sums[s];
	if(other.find(s) != other.end()) answer += other[s];
	for(auto iter = sums.begin(); iter != sums.end(); iter++){
		if(other.find(s- iter->first) !=other.end()){
			answer += (other[s-iter->first])*(iter->second);
		}
	}

	cout <<answer << "\n";
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}
