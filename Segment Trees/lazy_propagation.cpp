/*  
	In this program of segment tree , we update the old nodes in the range [l,r] to a new value
	we may also increment the value with certain diff. value instead of updating with a new value.
*/

#include <bits/stdc++.h>
#define endl '\n'

int *lazy;

using namespace std;

int construct_util(int *st, int arr[],int ss, int se, int idx){
	if(ss == se){
		st[idx] = arr[ss];
		return arr[ss];
	}
	int mid = ss + (se - ss)/2;
	st[idx] = construct_util(st,arr,ss,mid,2*idx+1) + construct_util(st,arr,mid+1,se,2*idx+2);
	return st[idx];
}

int *construct(int arr[], int size){
	int h = ceil( log2(size));
	int m = 2*pow(2,h) - 1;
	int *st = new int[m];
	lazy = new int[m];
	construct_util(st,arr,0,size-1,0);
	return st;
}

int get_sum(int *st,int ss, int se, int qs, int qe,int idx){
	
	if(lazy[idx] != 0){
		st[idx] = (se - ss + 1)*lazy[idx];   	//use += if updating with only diff
		if(ss != se){
			lazy[2*idx+1] = lazy[idx];          //here too and some other places...
			lazy[2*idx+2] = lazy[idx];
		}
		lazy[idx] = 0;
	}

	if(qs > se || qe < ss) return 0;

	if(qs <= ss && qe >= se){
		return st[idx];
	}
	int mid = ss + (se - ss)/2;

	return get_sum(st,ss,mid,qs,qe,2*idx+1)    +
		   get_sum(st,mid+1,se,qs,qe,2*idx+2);
}

void update(int *st, int ss,int se, int qs,int qe,int idx ,int nv){
	
	if(lazy[idx] != 0){
		st[idx] = (se - ss + 1) * lazy[idx];
		if(ss != se){
			lazy[2*idx+1] = lazy[idx];
			lazy[2*idx+2] = lazy[idx];			
		}
		lazy[idx] = 0;
	}

	if(qe < ss || qs > se) return ;

	if(qs <= ss && qe >= se){	
		st[idx] = (se - ss + 1) * nv;

		if(ss != se){
			lazy[2*idx+1] =  nv;
			lazy[2*idx+2] =  nv;
		}
		return ;
	}

	int mid = ss + (se - ss)/2;
	update(st,ss,mid,qs,qe,2*idx+1,nv);
	update(st,mid+1,se,qs,qe,2*idx+2,nv);

	st[idx] = st[2*idx+1] + st[2*idx+2];

}

int main() {

	int arr[] = {1,2,3,4,5,6,7,8};
	int size = sizeof(arr)/sizeof(arr[0]);
    
	for(int i = 0; i < size; i++) cout << arr[i] << " ";
	cout << endl;

	int *st = construct(arr,size);
	cout << get_sum(st,0,size-1,3,7,0) << endl;

	update(st,0,size-1,3,5,0,8);   				//ss,se,qs,qe,idx,nv

	for(int i = 3; i <= 5; i++) arr[i] = 8;	
	
	for(int i = 0; i < size; i++) cout << arr[i] << " ";
	cout << endl;

	cout << get_sum(st,0,size-1,3,7,0) << endl;
		
	return 0;
}

