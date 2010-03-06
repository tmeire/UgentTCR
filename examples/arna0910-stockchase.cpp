/*
 * Stock Chase (ARNA 2009-2010)
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/p4379.pdf
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

class Class { //edge voor grafen
	public:
		bool operator< (const Class& e) const { return 1; };
};

/* ALT: create directed graph. Reject transactions when they create a cycle. */

int solve (int N, int T) {
	bitset<235> companies[N];
	int rejects = 0;

	REP (i, N) {
		companies[i].reset();
		companies[i].set(i);
	}

	REP (i, T) {
		int a,b;
		scanf ("%d %d", &a, &b);
		if (companies[a-1][b-1]) {
			rejects++;
		} else {
			REP (j, N) {
				// companies that can't buy b, can't buy anything that a can't buy
				if (companies[j][b-1]) {
					companies[j] |= companies[a-1];
				}
			}
		}
	}	

	return rejects;
}

int main () {
	int companies, transactions, i = 1;
	scanf ("%d %d", &companies, &transactions);
	while (companies != 0 && transactions != 0) { 
		int r = solve(companies, transactions);
		printf("%d. %d\n", i, r);
		scanf ("%d %d", &companies, &transactions);
		i++;
	}
	return 0;
}
