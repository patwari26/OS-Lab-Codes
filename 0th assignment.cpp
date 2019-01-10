//You are the SEMICOLON to My STATEMENTS;
//author:Patwari26
#include<bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define    endl        '\n'
#define mii         map<ll int,ll int>
#define msi         map<string,ll int>
#define mis         map<ll int, string>
#define mpi         map<pair<ll int,ll int>,ll int>
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define INF         (1ll<<60)
#define rep(i,a,b)  for(i=a;i<=b;i++)
#define rrep(i,a,b)  for(i=a;i>=b;i--)
#define what_is(x)  cerr << #x << " is " << x << endl;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define N 100005
using namespace std;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
int main()
{
    ios
    int TESTS=1;
//    cin>>TESTS;
    while(TESTS--){
        ll prof_n,stud_n,i,pref1,pref2,pref3,j;
        double cpi_val;
        cout<<"ENTER TOTAL NUMBER OF PROF AND STUDENTS"<<endl;
        cin>>prof_n>>stud_n;
        vector <pair<double,ll>> cpi;
        vi pref[stud_n+1];
        vi prof[prof_n+1];
        vi remaining_stud;
        rep(i,0,stud_n-1) {

            cin>>cpi_val>>pref1>>pref2>>pref3;
            cpi.pb(mp(cpi_val,i)); 
            pref[i].pb(pref1);pref[i].pb(pref2);pref[i].pb(pref3);
        }
        sort(all(cpi));
        ll min_each_prof=stud_n/prof_n;
        rep(i,0,stud_n-1){
            ll stud_index=cpi[i].S;
            ll c=0;
            rep(j,0,pref[stud_index].size()-1){
                if(prof[pref[stud_index][j]].size()<min_each_prof){
                    prof[pref[stud_index][j]].pb(stud_index);
                    c=1;
                    break;
                } 
            }
            if(c==0) remaining_stud.pb(stud_index);
        }
        j=remaining_stud.size()-1;
        rep(i,0,prof_n-1){
            while(prof[i].size()<min_each_prof){
                prof[i].pb(remaining_stud[j]);
                j--;
                if(j==-1) break;
            }
        }
        rep(i,0,prof_n-1){
            if(j==-1) break;
            ll kk=rand() % prof_n;
                prof[kk].pb(remaining_stud[j]);
                j--;
            }
        rep(i,0,prof_n-1){
            cout<<i<<": ";
            rep(j,0,prof[i].size()-1) cout<<prof[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}

