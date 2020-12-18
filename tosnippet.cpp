#include<bits/stdc++.h>
using namespace std;
int main(){
  string s,ou;
  int i;bool ok;
  while(getline(cin,s)){
    ou = "\"";ok = true;
    for(i=0;i<s.size();i++){
      if(s[i] == ' ' && ok){
        ou += '\\';ou += 't';i++;continue;
      }
      ok = false;
      if(s[i] == '"' || s[i] == '\\') ou += '\\';
      ou += s[i];
    }
    ou += "\",";
    cout << ou << "\n";
  }
}
