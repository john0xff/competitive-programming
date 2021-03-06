//============================================================================
// Author       : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name : 
// Time Limit   : .000s
// Description  : 
//============================================================================
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100111

const int size = 36;
struct Matrix {
    unsigned int a[size][size];
    Matrix() {
        rep(i, size) rep(j, size) a[i][j] = 0;
    }
    Matrix multi(Matrix mat) {
        Matrix res;
        rep(i, size) rep(j, size) rep(k, size)
            res.a[i][j] += a[i][k] * mat.a[k][j];
        return res;
    }
} base;

Matrix power(Matrix mat, int k) {
    if (k == 1) return mat;
    Matrix res = power(mat, k / 2);
    res = res.multi(res);
    if (k % 2) return res.multi(mat);
    return res;
}

vector<ii> stat;

bool ok(int x1, int x2) { return abs(x1 - x2) >= 2; }

void init() {
    base = Matrix();
    rep(i, 10) fr(j, i + 2, 9)
        stat.pb(mp(i, j));
    rep(i, stat.size()) rep(j, stat.size()) {
        base.a[i][j] = ok(stat[i].ff, stat[j].ff) && ok(stat[i].ff, stat[j].ss) && ok(stat[i].ss, stat[j].ff) && ok(stat[i].ss, stat[j].ss);
    }
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		//freopen("test.out", "w", stdout);
	#endif
	init();
	int cases, caseNo = 0, n;
	for (scanf("%d", &cases); cases--; ) {
	    scanf("%d", &n);
	    unsigned int res = 0;
	    if (n == 1) res = 36;
	    else {
	        Matrix mat = power(base, n - 1);
	        rep(i, size) rep(j, size)
                res += mat.a[i][j];
	    }
	    printf("Case %d: %u\n", ++caseNo, res);
	}
	return 0;
}
