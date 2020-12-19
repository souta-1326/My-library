#include<bits/stdc++.h>
#include<atcoder/all>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define PI arccos(-1)
#define fi first
#define se second
#define mpa make_pair
#define emb emplace_back
#define endll "\n"
using namespace std;
using namespace atcoder;
template<class T> inline void input(vector<T> &v){
  for(int i=0;i<v.size();i++) cin >> v[i];
}
template<class T,class S> inline void input(vector<T> &v,vector<S> &u){
  for(int i=0;i<v.size();i++) cin >> v[i] >> u[i];
}
template<class T,class S,class R> inline void input(vector<T> &v,vector<S> &u,vector<R> &t){
  for(int i=0;i<v.size();i++) cin >> v[i] >> u[i] >> t[i];
}
template<class T> inline void input(vector<vector<T>> &v){
  for(int i=0;i<v.size();i++){
    for(int j=0;j<v[0].size();j++) cin >> v[i][j];
  }
}
template<class T> inline void output(vector<T> &v,bool space = true){
  if(space){
    for(int i=0;i<v.size()-1;i++) cout << v[i] << " ";
    cout << v.back() << endll;
  }
  else{
    for(int i=0;i<v.size();i++) cout << v[i] << endll;
  }
}
template<class T,class S> inline void output(vector<T> &v,vector<S> &u){
  for(int i=0;i<v.size();i++) cout << v[i] << " " << u[i] << endll;
}
template<class T,class S,class R> inline void output(vector<T> &v,vector<S> &u,vector<R> &t){
  for(int i=0;i<v.size();i++) cout << v[i] << " " << u[i] << " " << t[i] << endll;
}
template<class T> inline void output(vector<vector<T>> &v){
  for(int i=0;i<v.size();i++){
    for(int j=0;j<v[0].size()-1;j++) cout << v[i][j] << " ";
    cout << v[i].back() << endll;
  }
}
template<class T,class S> T gcd(T x,S y){
  if(x%y==0) return y;
  else return gcd(y,x%y);
}
template<class T,class S> T lcm(T x,S y){
  return x/gcd(x,y)*y;
}
template<class T,class S> T ceil(T x,S y){
  if(x == 0) return 0;
  else return (x-1)/y+1;
}
template<class T> bool isprime(T x){
  for(T i=2;i*i<=x;i++){
    if(x%i == 0) return false; 
  }
  return true;
}
vector<bool> isprime_format(int n){
  vector<bool> P(n+1,1);P[0] = P[1] = 1;
  for(int i=2;i*i<=n;i++){
    if(!P[i]) continue;
    for(int j=i+i;j<=n;j+=i) P[j] = false;
  }
  return P;
}
vector<int> prime_format(int n){
  vector<bool> P = isprime_format(n);
  vector<int> ans;
  for(int i=2;i<=n;i++){
    if(P[i]) ans.emb(i);
  }
  return ans;
}
template<class T> vector<T> topo_sort(T N,vector<vector<T>> G){
  T i,j,f;
  vector<int> cnt(N);
  for(i=0;i<N;i++){
    for(j=0;j<G[i].size();j++) cnt[G[i][j]]++;
  }
  vector<T> q;
  for(i=0;i<N;i++){
    if(cnt[i] == 0) q.emb(i);
  }
  for(f=0;f<N;f++){
    for(i=0;i<G[q[f]].size();i++){
      cnt[G[q[f]][i]]--;
      if(cnt[G[q[f]][i]] == 0){
        q.emb(G[q[f]][i]);
      }
    }
  }
  return q;
}
template<class T> vector<T> dijkstra(T N,vector<T> st,vector<vector<pair<T,T>>> G){
  T fn,fp,i;
  priority_queue<pair<T,T>,vector<pair<T,T>>,greater<>> q;
  vector<T> D(N,-1);
  for(i=0;i<st.size();i++){
    D[st[i]] = 0;
    q.push(mpa(0,st[i]));
  }
  while(!q.empty()){
    fn = q.top().fi;fp = q.top().se;q.pop();
    if(D[fp] < fn) continue;
    for(i=0;i<G[fp].size();i++){
      if(D[G[fp][i].fi] == -1 || D[G[fp][i].fi] > D[fp]+G[fp][i].se){
        D[G[fp][i].fi] = D[fp]+G[fp][i].se;
        q.push(mpa(D[G[fp][i].fi],G[fp][i].fi));
      }
    }
  }
  return D;
}
template<class T> vector<T> dijkstra(T N,T st,vector<vector<pair<T,T>>> G){
  return dijkstra(N,vector<T>({st}),G);
}
template <class T> class WarshallFloyd{
  T N,inf;
  vector<vector<T>> D;
  vector<vector<T>> prev;
  bool isdirect;
  void setting(){
    for(T k=0;k<N;k++){
      for(T i=0;i<N;i++){
        for(T j=0;j<N;j++){
          if(D[i][k] == inf || D[k][j] == inf) continue;
          if(D[i][j] > D[i][k]+D[k][j]){
            D[i][j] > D[i][k]+D[k][j];
            prev[i][j] = prev[k][j];
          } 
        }
      }
    }
  }
public:
  WarshallFloyd(T N,vector<T> &u,vector<T> &v,vector<T> &c,T inf,bool isdirect){
    this->N = N;
    this->inf = inf;
    this->isdirect = isdirect;
    assert(u.size() == v.size());
    vector<vector<T>>(N,vector<T>(N,inf)).swap(D);
    vector<vector<T>>(N,vector<T>(N)).swap(prev);
    for(T i=0;i<N;i++){
      for(T j=0;j<N;j++) prev[i][j] = i;
    }
    for(T i=0;i<N;i++) D[i][i] = 0;
    for(T i=0;i<u.size();i++){
      D[u[i]][v[i]] = min(D[u[i]][v[i]],c[i]);
      if(!isdirect) D[v[i]][u[i]] = min(D[v[i]][u[i]],c[i]);
    }
    setting();
  }
  WarshallFloyd(vector<vector<T>> D,T inf,bool isdirect){
    this->N = D.size();
    this->inf = inf;
    this->D = D;
    this->isdirect = isdirect;
    vector<vector<T>>(N,vector<T>(N)).swap(prev);
    for(T i=0;i<N;i++){
      for(T j=0;j<N;j++) prev[i][j] = i;
    }
    setting();
  }
  void append(T s,T t,T c){
    for(T i=0;i<N;i++){
      for(T j=0;j<N;j++){
        if(D[i][s] != inf && D[t][c] != inf){
          if(D[i][j] > D[i][s]+c+D[t][j]){
            D[i][j] = D[i][s]+c+D[t][j];
            prev[i][j] = prev[t][j];
          }
        }
        if(!isdirect && D[i][t] != inf && D[s][j] != inf){
          if(D[i][j] > D[i][t]+c+D[s][j]){
            D[i][j] = D[i][t]+c+D[s][j];
            prev[i][j] = prev[s][j];
          }
        }
      }
    }
  }
  T at(T i,T j){
    return D[i][j];
  }
  vector<T> Path(T s,T t){
    vector<T> ret;
    ret.emb(t);
    while(t != s) ret.emb(t=prev[s][t]);
    reverse(all(ret));
    return ret;
  }
  bool negative_cycle(){
    for(T i=0;i<N;i++){
      if(D[i][i] < 0) return true;
    }
    return false;
  }
  vector<vector<T>> Graph(){
    return D;
  }
};
int main(){
  cin.tie(0);ios::sync_with_stdio(false);
  //-----------------------------------------------
  
}
