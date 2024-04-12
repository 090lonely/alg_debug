#include<bits/stdc++.h>
using namespace std;
vector<int> Split(int x,int k){
  vector<int> ret;
  if(x==0){
    ret.push_back(0);
    return ret;
  }
while(x>0){
    ret.push_back(x%k);
    x/=k;
}
reverse(ret.begin(),ret.end());
return ret;

}
int main(){
     int x=15;
     int k=2;
     vector<int> back=Split(x,k);
     for(auto it=back.begin();it!=back.end();it++){
        cout<<*it;
     }
     cout<<endl;
          vector<int> back1=Split(0,k);
     for(auto it=back1.begin();it!=back1.end();it++){
        cout<<*it;
     }
     cout<<endl;

    return 0;
}