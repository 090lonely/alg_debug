// #include<iostream>
// #include<algorithm>
// #include<bits/stdc++.h>
// #include <numeric>
// using namespace std;
// int main(){
//     int x=12;int y=16;
//     int res=gcd(x,y);
//     cout<<res<<endl;
//     return 0;
// }
#include <iostream>
//#include <numeric> // 包含numeric头文件
using namespace std;
//没办法了，这里实现一个gcd
int gcd_my(int a,int b){
  while(a!=b){
    if(a>b)a-=b;
    else b-=a;

    //更相减损术
  }
return a;

}
int main() {
    int a = 12;
    int b = 18;
   int result = gcd_my(a, b); 
   cout<<result<<endl;
   // int result = std::gcd(a, b); // 使用std::gcd函数计算最大公约数
  //  std::cout << "GCD of " << a << " and " << b << " is " << result << std::endl;
    return 0;
}
