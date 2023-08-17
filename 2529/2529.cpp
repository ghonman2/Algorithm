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

int k = 0 ;
vector<char> oper;
vi maxAnswer = {0};
vi minAnswer = {9,9,9,9,9,9,9,9,9,9};
int calOper(int prev, char oper, int cmp)
{
	if (prev == cmp) return 0;
	if(oper == '<') return prev < cmp;
	else return prev > cmp;

}

int isIn(vi numbers, int idx)
{
	REP(i,0,numbers.size())if(numbers[i] == idx) return 1;
	return 0;
}

void init()
{

	cin >> k ;
	oper = vector<char>(k,0);
	REP(i,0,k) cin >> oper[i];
}

int makeInt(vi numbers)
{
	int ret = 0 ;
	for(int i = 0 ; i < numbers.size(); i++)
	{
		ret *= 10;
		ret += numbers[i];
	}
	return ret;
}

void search(vi numbers)
{
	if(numbers.size() == (k+1)) 
	{
		int answer = makeInt(numbers);
		if(makeInt(maxAnswer) < answer){
			maxAnswer = numbers;
		}
		if(makeInt(minAnswer) > answer){
			minAnswer = numbers;
		}
		return;	
	}
	int prev = numbers.back();
	for(int i = 0 ; i < 10; i ++){
		if(calOper(prev,oper[numbers.size()-1],i) && !isIn(numbers,i)){
			numbers.push_back(i);
			search(numbers);
			numbers.erase(find(numbers.begin(),numbers.end(),i),numbers.end());
		}
	}

}



int main(){
	FAST;
	init();
	REP(i,0,10){search({i});}

}

