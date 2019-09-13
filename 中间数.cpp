#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 4010;
const int INF = 0x3f3f3f3f;

int main(int argc, char **argv)
{
	int i,j,n;
	int a[N];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int ans = -1;
	for(i=0;i<n;i++){
		int cnt1=0, cnt2=0;
		for(j=0;j<n;j++){
			if(a[i] < a[j]){
				cnt1++; 
			} else if(a[i] > a[j]){
				cnt2++;
			}
		}
		if(cnt1 == cnt2){
			ans = a[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}

/*

第一次数组开小了，
以后还是直接写数字吧，直观一点

*/
