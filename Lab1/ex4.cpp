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
#include<cassert>

#define ri(X) scanf("%d",&X)
#define rii(X,Y) scanf("%d %d",&X,&Y)
#define rf(X) scanf("%lf",&X)
#define rff(X,Y) scanf("%lf %lf",&X,&Y)
#define mp(X,Y) make_pair(X,Y)
#define pii pair<int,int>
#define FOR(i,j) for(int i=0;i<j;i++)
#define FORC(i,j,c) for(int i=0;i<j;i+=c)

using namespace std;

const int mn = 500000;

int T;
int n;
priority_queue<long long> q;
long long a;
int main(){

    while(cin >> n && n) {

        assert(q.size() == 0);

        FOR(i, n) {
            cin >> a;
            q.push(-a);
        }
        long long sum = 0LL;
        while(q.size() > 1){
           long long a, b;
           a = q.top(); q.pop();
           b = q.top(); q.pop();
           sum += -a + -b;
           q.push(a + b);
        }

        q.pop();

        cout << sum << endl;
        
    }

	return 0;
}
