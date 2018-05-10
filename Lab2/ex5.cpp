#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>

#define ri(X) scanf("%d",&X)
#define rii(X,Y) scanf("%d %d",&X,&Y)
#define rf(X) scanf("%lf",&X)
#define rff(X,Y) scanf("%lf %lf",&X,&Y)
#define mp(X,Y) make_pair(X,Y)
#define pii pair<int,int>
#define FOR(i,j) for(int i=0;i<j;i++)
#define FORC(i,j,c) for(int i=0;i<j;i+=c)

using namespace std;

const int oo = 1e9 + 10;
int n, q;
vector<int> as;
vector<int> counter;
vector<int> s_tree;
vector<int> start, end_at;

int build(int nod, int l, int r) {
    if(l > r) return -oo;
    if(nod >= s_tree.size()) return -oo;

    if(l == r) 
        return s_tree[nod] = counter[l]; 

    int c1, c2;
    c1 = build(2 * nod, l, (l + r) / 2);
    c2 = build(2 * nod + 1, (l + r) / 2 + 1, r);

    return s_tree[nod] = max(c1, c2);
}

int query_t(int nod, int l, int r, int ql, int qr) {
    if(l > r) return -oo;
    if(nod >= s_tree.size() || qr < l || ql > r) return -oo;
    
    if(l >= ql && r <= qr) return s_tree[nod];

    int c1, c2;
    c1 = query_t(2 * nod, l, (l + r) / 2, ql, qr);
    c2 = query_t(2 * nod + 1, (l + r) / 2 + 1, r, ql, qr);

    return max(c1, c2);
}

void build_seg_tree() {
    int cnt = counter.size();
    s_tree = vector<int>(4 * cnt + 10);
    build(1, 0, cnt - 1);
}

void process() {
    int last = -oo;
    int cnt = -1;
    FOR(i,n) {
        if (last != as[i]) {
            last = as[i];
            as[i] = ++cnt;
        } else as[i] = cnt;
    }
    counter = vector<int>(cnt + 1,0); 
    start = vector<int>(cnt + 1,0); 
    end_at = vector<int>(cnt + 1,0); 
    FOR(i,n) { 
        counter[as[i]] ++;
        if(!i || as[i] != as[i-1]) start[as[i]] = i;
        if(!i || as[n-1-i] != as[n-i]) end_at[as[n-1-i]] = n-1-i;
    }
    build_seg_tree();
}

int query(int l, int r) {
    if(as[l] == as[r]) return r - l + 1;
    
    int c1 = end_at[as[l]] - l + 1;
    int c2 = r - start[as[r]] + 1;
    if(as[l] + 1 != as[r]) 
        c2 = max(c2, query_t(1, 0, counter.size() - 1, as[l] + 1, as[r] - 1));

    return max(c1,c2);
}

int main(){
    while(cin >> n && n) {
        cin >> q;
        as = vector<int>(n);
        FOR(i, n) 
            cin >> as[i];

        process();

        int l,r;
        FOR(i, q) {
            cin >> l >> r;
            l--,r--;
            cout << query(l,r) << endl;        
        }
    }

	return 0;
}
