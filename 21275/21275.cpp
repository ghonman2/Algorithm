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

string firstN, secondN;
map<char,int> numbers;

void init()
{
	cin >> firstN >> secondN;
	for (int i = 0 ; i < 10; i ++)
	{
		numbers.insert(make_pair(i + '0',i));
	}
	for (int i = 10 ; i < 36; i ++)
	{
		numbers.insert(make_pair(i - 10 + 'a', i));
	}
}

int x,a,b;
int minA = 36;
int minB = 36;

long long makeNumber(string &str,int nr)
{
	long long ret = 0;
	
	for(auto ch :str)
		ret = ret * nr + numbers[ch];
	return (ret);
}

int fillZ()
{
	for (auto ch : secondN )
	{
		if (ch != 'z')
			return (0);
	}
	return (1);
}

void sol()
{
	for (auto ch : firstN)
	{
		if (minA > numbers[ch])
			minA = numbers[ch];
	}
	for (auto ch : secondN)
	{
		if (minB > numbers[ch])
			minB = numbers[ch];
	}
	int count = 0;
	long long A, B;
	long long answer;
	for (int i = minA; i < 36; i++)
	{
		A = makeNumber(firstN, i);
		B = 0;
		for (int j = minB ; j < 36; j ++)
		{
			B = makeNumber(secondN, j);
			if (A == B)
			{
				count += 1;
				answer = A;
				a = i , b = j;
			}
		}
	}
	if (count == 0 || (fillZ() && firstN == secondN))
		cout << "Impossible\n";
	else if (count == 1)
		cout << answer << " " << a << " " << b << "\n";
	else
		cout << "Multiple\n";
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}
