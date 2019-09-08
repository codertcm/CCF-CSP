
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const LL N = 1010;
const LL INF = 0x3f3f3f3f;

int main(int argc, char **argv)
{
	
	int a[N];
	int pos[N];
	int i,l,r,n, t,op, id, len;
	cin >> n;
	for(i=1;i<=n;i++){
		a[i] = i;
		pos[i] = i;
	}
	cin >> op;
	while(op--){
		cin >> id >> len;
		l = pos[id];
		if(len > 0){
			r = l + len;
			t = a[l];
			for(i=l+1; i<=r;i++){
				a[i-1] = a[i];
				pos[ a[i] ]--;
			}
			a[r] = t;
			pos[t] = r;	
		} else {
			r = l + len;
			t = a[l];
			for(i=l-1; i>=r; i--){
				a[i+1] = a[i];
				pos[ a[i] ]++;
			}
			a[r] = t;
			pos[t] = r;
		}
	}
	for(i=1;i<=n;i++){
		printf("%d%c",a[i],i==n?'\n':' ');
	}
	return 0; 
}
