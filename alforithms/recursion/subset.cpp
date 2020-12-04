#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

#define PB push_back;
//means pb will be replaced by push_back on compilation

vi subset;
void search(int k,int n){
	if(k == n+1) {
		if(subset.size()==0) cout<<"phi";
		else {for(int x:subset) cout<<x<<" ";}
			cout<<"\n";
			return ;
	}
	//incude k;
	subset.push_back(k);
	search(k+1,n);
	subset.pop_back();
	search(k+1,n);
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

   //finding subset by recursion 
	search(1,3);
}
