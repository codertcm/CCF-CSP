
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 4e2 + 10;
const int INF = 0x3f3f3f3f;

int get(int s){
	int a = s - 3500;
	int sum = 0;
	if(a <= 1500){
		sum = a / 100 * 3;
	} else if( a <= 4500){
		sum = 45 + (a - 1500) / 100 * 10;
	} else if( a <= 9000){
		sum = 45 + 300 + (a - 4500) / 100 * 20; 
	} else if( a <= 35000){
		sum = 45 + 300 + 900 + (a - 9000) / 100 * 25;
	} else if(a <= 55000){
		sum = 45 + 300 + 900 + 6500 + (a - 35000) / 100 * 30; 
	} else if(a <= 80000){
		sum = 45 + 300 + 900 + 6500 + 6000 + (a - 55000) / 100 * 35;
	} else {
		sum = 45 + 300 + 900 + 6500 + 6000 + 8750 + (a - 80000) / 100 * 45;
	} 
	return s - sum;
}


int main(int argc, char **argv)
{
	map<int,int> mp;
	
	for(int i=0;i<=100000;i++){
		mp[ get(i*100) ] = i * 100;
	}
	
	int n;
	cin >> n;
	cout << mp[n] << endl;
	return 0;
}

/*

第一次提交忘了考虑工资小于3500的情况，应该不改变

*/