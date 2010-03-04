/*
 * Eeny Meenies (Testcontest VPW 2009-2010)
 */

#include <cstdio>
#include <bitset>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
// FIXME: FOREACH DOESN'T WORK ON EVERY SYSTEM! Check before contest!
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define LET(i,c) typeof(c) i = (c)
#define MP make_pair
#define PB push_back
#define SORT(x) sort((x).begin(),(x).end())
#define ALL(x) (x).begin(),(x).end()
#define UNIQUE(x) remove(unique((x).begin(),(x).end()),(x).end())
#define CLEAR(x,v) memset((x),(v),sizeof((x)))
#define FORS(i,x) for(int i=0;i<(int)(x).size();i++)
#define X first
#define Y second
typedef long long ent;
typedef pair<int,int> ii;

//Debug info
#define DEBUG !true

//=========================================END OF HEADER=========================================================

int josephus (int n, int k) {
	if (n == 1) {return 0;}
	return (josephus (n - 1, k) + k) % n;
}

void solve () {
	int upper, lower;
	scanf("%d", &lower);
	scanf("%d", &upper);

	bitset<500> positions;
	positions.reset();

	FOR (i, lower, upper+1) {
		// FIXME: can be improved using DP
		int x = josephus(i, 15);
		positions.set(x);
		if (x != 0) {
			positions.set(i-x);
		}
	}

	int i = 1;
	while (i < lower && positions.test(i)) {
		i++;
	}
	if (i < lower) {
		printf("%d\n", i);
	} else {
		printf("Een betere schatting is nodig\n");
	}
}

int main () {
	int cases;
	scanf ("%d",&cases);
	while (cases--) { 
		solve();
	}
	return 0;
}
