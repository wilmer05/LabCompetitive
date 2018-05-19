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

long long U,V,W, T;
const long long mn = 2.5e6;
const int oo = 1e9;

bool check_sol(long long x, long long y, long long z) {
    return x < y && y < z && x + y + z == U && x * y * z == V && x * x + y * y + z * z == W ;
}
vector< long long > divs;
void preprocess() {
    divs.clear();
    
    double bound = (long long )pow(V, 1.0/3) + 10LL;
    for(int i =1 ; i <  bound; i++) {
        if(V % i == 0) {
            divs.push_back(i);
            divs.push_back(-i);
            divs.push_back(V / i);
            divs.push_back(- V / i);
        }
    }

    sort(divs.begin(), divs.end());

}

int main(){

    scanf("%lld", &T);
    FOR(t,T) {
        scanf("%lld %lld %lld", &U, &V, &W);
        bool found = false;
        long long x,y,z;
        preprocess();
        for(int k =0 ; k < divs.size(); k++) {
            long long i = divs[k];
            if(!i) continue;
            long long tmp_u = U - i;

            long long  tmp_v = V/i;
            if (tmp_u * tmp_u < 4*tmp_v) continue;
            long long det = tmp_u * tmp_u - 4 * tmp_v;
            if(floor(sqrt(det)) != sqrt(det)) continue;

            double root_1 = (tmp_u - sqrt(det)) / 2.0;

            double root_2 = (tmp_u + sqrt(det)) / 2.0;

            if (floor(root_1) == root_1 && root_1 > i) {
                long long k = tmp_u - root_1;
                if (check_sol(i, root_1, k)){
                   x = i;
                   y = root_1;
                   z = k;
                   found= true;
                   break;
                }
            }

            if (floor(root_2) == root_2 && root_2 > i) {
                long long k = tmp_u - root_2;
                if (check_sol(i, root_2, k)) {
                   x = i;
                   y = root_2;
                   z = k;
                   found = true;
                   break;
                }
            }
                        

        }
        if(!found) cout << "empty set" << endl;
        else cout << x <<" " << y << " " << z << endl;

    }

	return 0;
}
