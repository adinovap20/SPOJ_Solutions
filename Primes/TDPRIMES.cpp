// Problem : https://www.spoj.com/problems/TDPRIMES/
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

vector<bool> is_prime(1E8+1, true);

void solve(){
    ll i,j,n;
    n = 1E8;
    vector<ll> primes;
    for(i=2; i*i<=n; i++){
        if(is_prime[i]==false) continue;
        for(j=i*i; j<=n; j+=i){
            is_prime[j] = false;
        }
    }
    ll ptr = 0;
    for(i=2; i<=n; i++){
        if(is_prime[i] && ptr%100 == 0){
            cout << i << nl; ptr++; continue;
        }
        if(is_prime[i]) ptr++;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    ll __t = t;
    while(t--){
        solve();
    }
    return 0;
}
