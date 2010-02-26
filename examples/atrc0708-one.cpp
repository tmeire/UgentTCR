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

int josephus (int n, int k) {
	if (n == 1) {return 0;}
	return (josephus (n - 1, k) + k) % n;
}

bool solve () {
	int n, m, k;
	scanf ("%d %d %d", &n, &k, &m);
	
	if (n == 0 && m == 0 && k == 0) {
		return false;
	}
	printf ("%d\n", ((josephus (n-1,k) + m) % n) + 1);
	return true;
}

/* THIS IS TOO SLOW!
typedef struct _Node Node;
struct _Node {
	int i;
	Node *next;
};

bool solve () {
	int n, m, k;
	scanf ("%d %d %d", &n, &k, &m);
	
	if (n == 0 && m == 0 && k == 0) {
		return false;
	}

	//printf ("%d %d %d\n", n, k, m);

	Node start = {1,NULL};
	Node *previous = &start;
	FOR (i, 2, n+1) {
		previous->next = new Node();
		previous->next->i = i;
		previous = previous->next;
	}
	previous->next = &start;
	Node *current = previous;

	// skip m-1 places and remove 1
	REP (i,m-1) {
		current = current->next;
	}
	//printf("R%d\n", current->next->i);
	current->next = current->next->next;

	// while more than 1 element left, skip k-1 places and remove 1
	while (current->next != current) {
		REP (i,k-1) {
			//printf ("S%d\n", current->next->i);
			current = current->next;
		}
		//printf("R%d\n", current->next->i);
		current->next = current->next->next;
	}
	printf ("%d\n", current->i);
	return true;
}*/

int main () {
	while (solve());
}
