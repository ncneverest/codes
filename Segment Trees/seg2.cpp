#include <bits/stdc++.h>

//to update a range with given value...

using namespace std;


int construct_util(int arr[],int *st, int ss, int se, int idx){

	if(ss == se){
		st[idx] = arr[ss];
		return arr[ss];
	}

	int mid = ss + (se - ss)/2;

	st[idx] = construct_util(arr,st,ss,mid,2*idx+1)+construct_util(arr,st,mid+1,se,2*idx+2);

	return st[idx];
				
}

int* construct(int arr[],int size){

	int h = ceil(log2(size));
	int max = 2*pow(2,h) - 1;
	int *st = new int[max];
	construct_util(arr,st,0,size-1,0);
	return st;
}

int get_sum(int *st, int ss, int se, int qs, int qe,int idx){
	
	if(se < qs || qe < ss){
		return 0;
	}

	if(ss >= qs && se <= qe){
		return st[idx];
	}

	int mid = ss + (se - ss)/2;
	return get_sum(st,ss,mid,qs,qe,2*idx+1) + get_sum(st,mid+1,se,qs,qe,2*idx+2);
}

void update(int *st,int l , int r, int ss,int se, int idx,int nv){

	if(ss > r || se < l){
		return;
	}

	if(ss == se){	
		st[idx] = nv;		
		return;
	}

	int mid = ss + (se - ss)/2;
	update(st,l,r,ss,mid,2*idx+1,nv);
	update(st,l,r,mid+1,se,2*idx+2,nv);
	
	st[idx] = st[idx*2 + 1] + st[idx * 2 + 2];

}

int main() {
	
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int size  = sizeof(arr)/sizeof(arr[0]);

	int	*st = construct(arr,size);

	cout << get_sum(st,0,size-1,3,4,0) << endl;

	//update index 2-4 to 10...
	for(int i = 2; i <= 4; i++) arr[i] = 10;

	update(st,2,4,0,size-1,0,10);

	for(int i = 0; i < size; i++) cout << arr[i] << " ";
	cout << endl;

	cout << get_sum(st,0,size-1,3,4,0) << endl;

	return 0;
}
