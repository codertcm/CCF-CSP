

#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const LL N = 1e5 + 10;
const LL INF = 0x3f3f3f3f;

LL fa[N];
LL ans;
struct Node{
	LL l,r,v;
	LL mid(){
		return (l+r)/2;
	}
};

Node node[N << 2];

void build(LL l, LL r, LL i){
	node[i].l = l;
	node[i].r = r;
	node[i].v = 0;
	if(l == r){
		fa[l] = i;
		return ;
	}
	LL m = node[i].mid();
	build(l,m,i<<1);
	build(m+1,r,i<<1|1);
}

void update(LL ri){
	if(ri == 1)
		return ;
	LL fi = ri / 2;
	node[fi].v = node[fi<<1].v + node[fi<<1|1].v;
	update(fi);
}

void query(LL l, LL r, LL i){
	if(node[i].l == l && node[i].r == r){
		ans += node[i].v;
		return ;	
	}
	LL m = node[i].mid();
	if(r <= m){
		query(l, r, i<<1);
	} else {
		if(l > m){
			query(l, r, i<<1|1);
		} else {
			query(l, m, i<<1);
			query(m+1, r, i<<1|1);
		}
	}
	return ;
}

int main(int argc, char **argv)
{
	LL i,op,v,n,q,l,r,d;
	scanf("%lld%lld",&n,&q);
	build(1,n,1);
	for(i=1;i<=n;i++){
		scanf("%lld",&v);
		node[fa[i]  ].v = v;
		update(fa[i]); 
	}
	while(q--){
		scanf("%lld",&op);
		if(op == 1){
			scanf("%lld%lld%lld",&l,&r,&d);
			for(i=l;i<=r;i++){
				if(node[fa[i] ].v % d == 0){
					node[fa[i] ].v /= d;
					update(fa[i]);
				}
			}
		} else {
			ans = 0;
			scanf("%lld%lld",&l,&r);
			query(l,r,1);
			printf("%lld\n",ans);
		}
	}
    return 0; 
}


// 题解: https://blog.csdn.net/vcvycy/article/details/78236424