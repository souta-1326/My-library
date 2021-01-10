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
