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
