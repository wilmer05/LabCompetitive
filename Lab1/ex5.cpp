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
int T;
int n;
int ps[5][5];
const long long oo = 1e18;

long long get_manhattan(long long  idx1, long long idx2){
    long long r1,r2,c1,c2;
    r1 = idx1 / 5;
    r2 = idx2 / 5;
    c1 = idx1 % 5;
    c2 = idx2 % 5;

    return abs(r1 - r2) + abs(c1 - c2);
}

long long get_sol(int i1, int i2, int i3, int i4, int i5) {

    long long ans = 0;
    FOR(i, 25) {
        long long people = ps[i/5][i%5];
        if (people) {
            long long min_dist = get_manhattan(i, i1);
            long long m2 = get_manhattan(i, i2);
            long long m3 = get_manhattan(i, i3);
            long long m4 = get_manhattan(i, i4);
            long long m5 = get_manhattan(i, i5);
            
            min_dist = min(min_dist, min(m2, min(m3, min(m4, m5))));
            ans += min_dist * people;
        }
    }

    return ans;
}

int main(){
    cin >> T;

    FOR(t, T){
        cin >> n;
        memset(ps, 0, sizeof ps);
        long long best_sol = oo;
        FOR(i, n){
            int x,y,q;
            cin >> x >> y >> q;
            ps[x][y] = q;
        }

        FOR(i1, 25)
            for(int i2 = i1 + 1; i2 < 25; i2 ++)
                for(int i3 = i2 + 1; i3 < 25; i3 ++)
                    for(int i4 = i3 + 1; i4 < 25; i4 ++)
                        for(int i5 = i4 + 1; i5 < 25; i5 ++)
                            best_sol = min(best_sol, get_sol(i1, i2, i3, i4, i5));
                        
        cout << best_sol << endl;
    }

	return 0;
}
