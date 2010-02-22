/*
 * Feynman (LARC 2008-2009)
 * http://acmicpc-live-archive.uva.es/nuevoportal/data/problem.php?p=4215
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

void solve (int x) {
	int squares = 0;
	while (x > 0) {
		squares += x * x;
		x--;
	}
	printf("%d\n", squares);
}

int main(){
	int side;
	scanf("%d",&side);
	while(side != 0)
	{
	    solve(side);
		scanf("%d",&side);
	}
}
