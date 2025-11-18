#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 5;
const int MOD = 998244353, G = 3;

ll power(ll x, ll y)
{
    ll res = 1;
    for( ; y>0; y>>=1, x=x*x%MOD) if(y&1) res = res*x%MOD;
    return res;
}
ll inv(ll x)
{
    return power(x, MOD-2);
}

class NTT
{
private:
    static void ntt(vector<int> &a, bool invert)
    {
        int len = a.size();
        for(int now = 0, i = 1; i<len-1; i++)
        {
            int hbit = len/2;
            while( (now & hbit) )
            {
                now ^= hbit;
                hbit>>=1;
            }
            now^=hbit;
            if(now > i) swap(a[now], a[i]);
        }
        for(int l = 2; l<=len; l<<=1)
        {
            int wl = power(G, (MOD-1)/l);
            if(invert) wl = power(wl, MOD-2);
            for(int i=0; i<len; i+=l)
            {
                for(int k=0, now = 1; k<l/2; k++, now = 1ll*now*wl%MOD)
                {
                    int u = a[i+k], v = 1ll*a[i+k+l/2]*now%MOD;
                    a[i+k] = (u+v)%MOD;
                    a[i+k+l/2] = (u-v+MOD)%MOD;
                }
            }
        }

        if(invert)
        {
            int ivn = power(len, MOD-2);
            for(int i=0; i<len; i++) a[i] = 1ll*ivn*a[i]%MOD;
        }

        return;
    }

public:
    static vector<int> multiply(vector<int> vec1, vector<int> vec2)
    {
        vector<int> res;
        int len = 1;
        while(len < (int)(vec1.size() + vec2.size()-1) ) len<<=1;
        vec1.resize(len, 0);
        vec2.resize(len, 0);
        ntt(vec1, 0);
        ntt(vec2, 0);
        for(int i=0; i<len; i++)
        {
            res.push_back(1ll*vec1[i]*vec2[i]%MOD);
        }
        ntt(res, 1);
        return res;
    }
};

int n;
ll ans = 0;
int w[N];
int p[N];
vector<int> e[N];
bool vis[N];
int sz[N], mx[N], tot, rt;

void getrt(int u, int fa)
{
    sz[u] = 1;
    mx[u] = 0;
    for(auto v : e[u])
    {
        if(v == fa || vis[v]) continue;
        getrt(v, u);
        sz[u] += sz[v];
        mx[u] = max(mx[u], sz[v]);
    }
    mx[u] = max(mx[u], tot - sz[u]);
    if(mx[u] < mx[rt]) rt = u;
}

void dfs_collect(int u, int fa, int len, vector<int> &poly)
{
    if((int)poly.size() <= len) poly.resize(len+1, 0);
    poly[len] = (poly[len] + p[u]) % MOD;
    for(auto v : e[u])
    {
        if(v == fa || vis[v]) continue;
        dfs_collect(v, u, len+1, poly);
    }
}


vector<int> merge_all(vector<vector<int>> polys, int l, int r)
{
    priority_queue<pair<int, int> > id;
	
	for(int i=l; i<=r; i++)
	{
		id.push({-(int)polys[i].size(), i});
	}
	
	while(id.size() >= 2)
	{
		int tmp = id.top().second;
		auto& left = polys[id.top().second]; id.pop();
	    auto& right = polys[id.top().second]; id.pop();
	    
	    auto cross = NTT::multiply(left, right);
	    for(int i=0; i<(int)cross.size() && i<n; i++)
	    {
	        ans = (ans + 2LL * cross[i] * w[i]) % MOD;
	    }
	    if((int)left.size() < (int)right.size()) left.resize(right.size());
	    for(int i=0; i<(int)right.size(); i++)
	    {
	        left[i] = (left[i] + right[i]) % MOD;
	    }
		id.push({-(int)polys[tmp].size(), tmp});
	}
	return polys[id.top().second];
}

void solve(int u)
{
    vis[u] = 1;
    vector<vector<int> > polys;
    polys.push_back({p[u]});
    for(auto v : e[u])
    {
        if(vis[v]) continue;
        vector<int> poly;
        dfs_collect(v, u, 1, poly);
        polys.push_back(poly);
    }
    if(polys.size() > 1) {
        auto merged = merge_all(polys, 0, polys.size()-1);
    }
    for(auto v : e[u])
    {
        if(vis[v]) continue;
        mx[rt=0] = tot = sz[v];
        getrt(v, u);
        solve(rt);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ll sum = 0;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    ll inv_sum = inv(sum);
    for(int i=1; i<=n; i++) p[i] = (1ll * a[i] * inv_sum) % MOD;

    for(int i=0; i<n; i++) cin >> w[i];

    for(int i=1; i<n; i++)
    {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    tot = mx[rt] = n;
    getrt(1, 0);
    solve(rt);

	ll sumprob = 0;
    for(int i=1; i<=n; i++)
    {
        sumprob = (sumprob + 1ll * p[i] * p[i]) % MOD;
    }
    ans = (ans + sumprob * w[0]) % MOD;

    cout << ans << "\n";
    return 0;
}
