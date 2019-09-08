
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const LL N = 1010;
const LL INF = 0x3f3f3f3f;


int main(int argc, char **argv)
{
	int i,n,m;
	int a[N];
	cin >> n >> m;
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	int ans = 0,sum = 0;
	for(i=0;i<n;i++){
		sum += a[i];
		if(sum >= m){
			sum = 0;
			ans++;
		}
	}
	if(sum != 0)
		ans++;
	printf("%d\n",ans);
	return 0; 
}
