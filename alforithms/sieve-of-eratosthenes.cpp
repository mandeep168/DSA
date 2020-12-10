#include<bits/stdc++.h>
using namespace std;
//bool arr[1000001] = {1};
void sieveOfEratosthenes(){
  bool arr[1000001];
  memset(arr, true, sizeof(arr));
  arr[0] = 0;
  arr[1] = 0;
  for(int i = 2;i*i<=1000000;i++){
    if(arr[i]){
      for(int p = i*i;p<=1000000;p+=i){
        arr[p]=0;
      }
    }
  }
  for(int i=0;i<=30;i++){
    if(arr[i]) cout<<i<<" ";
  }
}

int main(){
  // bool arr[1000001];
  // for(int i=0;i<1000001;i++) arr[i] = 1;
  sieveOfEratosthenes();

}
