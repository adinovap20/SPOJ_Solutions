// Problem : https://www.spoj.com/problems/VECTAR8/
// Author : adinovap20
#include <bits/stdc++.h>

typedef long long ll;
#define forl(i,a1,a2) for(i=a1;i<a2;i++)
#define forle(i,a1,a2) for(i=a1;i<=a2;i++)
#define nl "\n"
#define sp " "
#define deb(x); cout << #x << " = " << x << endl;
#define all(v) v.begin(),v.end()
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll,ll>>
#define F first
#define S second

const unsigned int M = 1000000007;
using namespace std;

#ifndef ONLINE_JUDGE
    #include "headers/debug.h"
#endif

struct ch {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<typename T>
istream &operator>>(istream &input,vector<T> &v){ 
    for(auto &i: v) cin >> i;
    return input;            
}

vector<bool> prime(1E6+5, true);
vll tmp;

void solve(){
    ll n,i; cin >> n;
    cout << upper_bound(all(tmp),n) - tmp.begin() << nl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t = 1; ll n = 1E6;
    prime[0] = false; prime[1] = false;
    for(ll i=2; i*i<=n; i++){
        if(prime[i]==false) continue;
        for(ll j=i*i; j<=n; j+=i){
            prime[j] = false;
        }
    }
    for(ll i=2; i<=n; i++){
        if(!prime[i]) continue;
        string tr = to_string(i);
        bool flag = true;
        for(auto x : tr){
            if(x=='0'){
                flag = false; break;
            }
        }
        if(flag==false) continue;
        while(tr.size()!=1){
            reverse(all(tr));
            tr.pop_back();
            reverse(all(tr));
            ll a = stoll(tr);
            if(!prime[a]){
                flag = false; break;
            }
        }
        if(flag==true){
            tmp.push_back(i);
        }
    }
    // cout << tmp;
    cin >> t;
    ll __t = t;
    while(t--){
        solve();
    }
    return 0;
}
