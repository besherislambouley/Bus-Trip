/*
 * https://github.com/updown2/OI-Practice/blob/master/BOI%20(Baltic)/2005%20Bus%20Trip.cpp
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 270
//#define mp make_pair
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
#define gc getchar_unlocked
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
int n , m , goal , Mx ;
struct xxx {
	int from , to , lst , rst , len , ren ;
} a [100009] ;
bool cmp ( xxx a , xxx b ) {
	return a .ren < b .ren ;
}
vpi dps [100009] ;
int main () {
	cin >> n >> m >> goal >> Mx ;
	goal -- ;
	for ( int i = 0 ; i < m ; i ++ ) {
		scanf("%d%d%d%d%d%d",&a [i].from,&a [i].to,&a [i].lst,&a [i].rst,&a [i].len,&a [i].ren ) ;
		a [i].from -- , a [i].to -- ;
	}
	sort ( a , a + m , cmp ) ;
	dps [0] .pb ( { 0 , 0 } ) ;
	for ( int i = 0 ; i < m ; i ++ ) {
		int from = a[i] .from , to = a[i].to ;
		if ( !dps [from] .size() || dps [from][0].se > a [i].lst || a [i].ren > Mx ) C ;
		int l = 0 , r = dps [from].size() ;
		while ( r - l > 1 ) {
			if ( dps [from][mid] .se <= a [i].lst ) l = mid ;
			else r = mid ;
		}
		int val = dps [from][l] .fi + a [i] .rst - a [i] .len ;
		if ( !dps [to].size() || dps [to].back().fi > val ) dps [to] .pb ( { val , a [i].ren } ) ;
	}
	if ( ! dps [goal] .size() ) cout << -1 << endl ; 
	else cout << Mx + dps [goal].back().fi << endl ;  
}
