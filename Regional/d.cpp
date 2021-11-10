#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector <int> vi;
typedef vector <ll> vll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

typedef vector < pii > vpii;
typedef vector < pll > vpll;

typedef vector <string> vs;
typedef vector < vi > vvi;
typedef vector < vll > vvll;

#define fl(i, a, b)	for (int i(a); i < (b); i ++)

#define all(v) 	(v).begin(), (v).end()
#define srt(v)	sort (all (v))

#define pb push_back
#define mp make_pair

#define dig(i)	(s[i] - '0')
#define slen(s)	s.length()

#define fr first
#define sc second

#define len(x) ((int) (x).size())
#define fill (x, y)	memset(x, y, sizeof(x))
#define clr(a)	fill(a, 0)
#define endl '\n'

#define PI 3.14159265358979323

#define trace1(x1)					cerr << #x1 << ": " << x1 << endl;
#define trace2(x1, x2)				cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << endl;
#define trace3(x1, x2, x3)			cerr << #x1 << ": " << x1 << " | " << #x2 << ": " << x2 << " | " << #x3 << ": " << x3 << endl;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T power(T x, T y, ll m = MOD) { T ans = 1; x %= m; while (y > 0) { if (y & 1ll) ans = (ans * x) % m; y >>= 1ll; x = (x * x)%m; } return ans%m;}

vector<vector<int>> tab(5000, vector<int>(5000, -1));

int subsetSum(vi a, int n, int sum)
{
     
    if (sum == 0)
        return 1;
         
    if (n <= 0)
        return 0;

    if (tab[n - 1][sum] != -1)
        return tab[n - 1][sum];

    if (a[n - 1] > sum)
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum);
    else{
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum) ||
                       subsetSum(a, n - 1, sum - a[n - 1]);
    }
}

int main() {
    int n, aux1, total, potencia, x;
    bool flag;
    
    vi a;

    while (cin >> n ){
        flag = false;
        total = 0;
        for (int i = 0; i < n; i++){
            cin >> aux1;
            
            a.push_back(pow(2, aux1));
            total += pow(2, aux1);

        }
        
        potencia = 0;
        while( pow(2, potencia) <= total){

            // trace1(pow(2, potencia));
            // cout << subsetSum(a, len(a), pow(2, potencia)) << endl;

            x = total - pow(2, potencia);
            if(  (x != 0) && ((x & (x - 1)) == 0) ){
                if ( subsetSum(a, len(a), pow(2, potencia)) ){
                    flag = true;
                    break;
                }
            }
            potencia++;
        }

        if( flag ) cout << "Y" << endl;
        else cout << "N" << endl;
        

    }

	return 0;
}