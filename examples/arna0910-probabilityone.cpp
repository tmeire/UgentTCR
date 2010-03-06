/*
 * Land Division (ARNA 2009-2010)
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/p4736.pdf
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

int solve (int n0) {
	int n1 = 3 * n0;
	ent n2,n3,n4;

	if (n1 % 2 == 1) {
		printf("odd ");	
		n2 = n1 / 2;
	} else {
		printf("even ");
		n2 = (n1 + 1) / 2;
	}
	printf("%lld\n", n2 / 3);
}

int main () {
	int n, i = 1;
	scanf ("%d", &n);
	while (n != 0) {
		printf ("%d. ", i);
		solve(n);
		scanf ("%d", &n);
		i++;
	}
	return 0;
}
