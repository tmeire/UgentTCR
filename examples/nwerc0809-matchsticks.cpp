/*
 * Matchsticks (NWERC 2008-2009)
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=4292
 */

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <vector>
#include <stdexcept>
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

class Class { //edge voor grafen
	public:
		bool operator< (const Class& e) const { return 1; };
};
		    //0, 1, 2, 3, 4, 5, 6, 7,  8,  9, 10, 11, 12, 13, 14,  15,  16,  17
int dp[18] = {0, 0, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200};

void solve () {
	int sticks;
	int remaining;
	scanf ("%d", &sticks);
	
	// print the minimum value
	remaining = sticks;
	ent result = 0;
	ent i = 1;
	while (remaining > 17) {
		result += i * 8;
		remaining -= 7;
		i *= 10;
	}
	result += i * dp[remaining];
	printf("%lld ", result);

	// print the maximum value
	remaining = sticks;
	if (sticks % 2 == 1) {
		printf ("7");
		remaining -= 3;
	}
	while (remaining > 0) {
		printf ("1");
		remaining -= 2;
	}
	printf("\n");
}

int main () {
	int cases;

	scanf ("%d",&cases);
	while (cases--) { 
		solve();
	}
}
