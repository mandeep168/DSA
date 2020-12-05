#include<bits/stdc++.h>
using namespace std;
int main(){
	int n = 10;
	int arr[n] = {4,-100, 67,-124,4,67,2342,67,123,-567};
	int best = 0,sum = 0;
	for(int i=0;i<n;i++){
		sum = max(sum,sum+arr[i]);
		best = max(best, sum);
	}
	cout<<best;
}