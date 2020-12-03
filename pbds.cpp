#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> //for pbds advanced stl container
using namespace std;
using namespace __gnu_pbds;


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


int main(){
       
       //initialized policy based data structure
	pbds arr;
	for(int i=0;i<=10;i++){
		arr.insert(i);
	}

	cout<<*arr.find_by_order(2);  //gives kth largest number 2 here starting from 0th largest element which is minimum that is 0 in our case.
	cout<<"\n";
	cout<<arr.order_of_key(6);  //give count of element stricly lesser than the key passes that is 6 here
	// both operations work in log(n) time.
	//inversion cout (problem)
}





