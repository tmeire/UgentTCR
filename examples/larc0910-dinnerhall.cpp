/*
 * Dinner Hall (LARC 2009-2010)
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=4475
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

class Event {
	public:
		int h, m, s;
		char action;
		Event (int h, int m, int s, char a) {
			this->h = h;
			this->m = m;
			this->s = s;
			this->action = a;
		}
		bool operator< (const Event& e) const {
			if (e.h == h) {
				if (e.m == m) {
					return e.s > s;
				}
				return e.m > m;
			}
			return e.h > h;
		};
};

void solve (int eventc) {
	list<Event> events;

	int enters = 0;
	int exits = 0;
	int unknowns = 0;

	// read everything
	REP (i, eventc) {
		int h, m, s;
		char a;
		scanf ("%d:%d:%d %c", &h, &m, &s, &a);
		events.PB (Event (h, m, s, a));
		if (a == 'E') {
			enters++;
		} else if (a == 'X') {
			exits++;
		} else {
			unknowns++;
		}
	}
	events.sort();

	// calculate limit to switch unknowns
	int limit = 0;
	if (enters < exits) {
		limit = exits - enters;
	} else if (exits < enters) {
		unknowns -= (enters - exits);
	}
	limit += (unknowns - limit) / 2;

	// loop over everything to calculate the max
	int j = 0, size = 0, maxsize = 0;
	for(list<Event>::iterator i = events.begin(); i != events.end(); i++) {
		if (i->action == 'E') {
			size++;
			if (size > maxsize) {
				maxsize = size;
			}
		} else if (i->action == 'X') {
			size--;
		} else {
			if (j < limit) {
				size++;
				if (size > maxsize) {
					maxsize = size;
				}
			} else {
				size--;
			}
			j++;
		}
	}
	printf("%d\n", maxsize);
}

int main () {
	int events;
	scanf("%d",&events);
	while(events != 0) { 
		solve(events);
		scanf("%d",&events);
	}
}
