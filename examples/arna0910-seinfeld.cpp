/*
 * Seinfeld (ARNA 2009-2010)
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/p4734.pdf
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

int solve (string s) {
	int n=0, q=0;
	REP (i, s.length()) {
		if (q < s.length() - i) {
			if (s[i] == '}') {
				if (q == 0) {
					n++; q++;			// een sluithaakje zonder open haakje, switch naar open haakje
				} else {
					q--;				// sluit een haakje
				}
			} else {
				q++;					// open een haakje
			}
		} else {
			if (s[i] == '{') { n++; }	/* q haakjes open, maar slechts q chars meer over in s. */
			q--;						/* dan zijn deze zeker allemaal sluithaakjes! */
		}
	}
	return n;
}

int main () {
	int i = 1;
	char brackets[2001];
	scanf ("%s", brackets);
	while (brackets[0] != '-') {
		printf ("%d. %d\n", i, solve(brackets));
		scanf("%s", brackets);
		i++;
	}
	return 0;
}
