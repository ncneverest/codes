#include <bits/stdc++.h>

/*
 * segmentation tree, used to find the sum of given segment in an array
 * time complexity : O(log2(n)) for searching and updating both...
 */

#define ULL unsigned long long int
#define LL long long int
#define endl '\n'
#define allons_y ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

int getsumUtil(int *st,int start,int end,int qs,int qe,int idx){
	if(qs <= start && qe >= end){
		return st[idx];
	}
	if(end < qs || start > qe){
		return 0;
	}
	int mid = start + (end - start)/2;
	return getsumUtil(st,start,mid,qs,qe,2*idx+1)+
		   getsumUtil(st,mid+1,end,qs,qe,2*idx+2);
}

int getsum(int *st,int n,int qs,int qe){
	if(qs < 0 || qe >= n || qs > qe){
		cout << "invalid input" << endl;
		return 0;
	}
	return getsumUtil(st,0,n-1,qs,qe,0);
}

int constructUtil(int arr[],int *st,int start, int end,int current){
	if(start == end){
		st[current] = arr[start];
		return arr[start];
	}
	int mid = start + (end - start)/2;
	st[current] = constructUtil(arr,st,start,mid,current*2+1) + constructUtil(arr,st,mid+1,end,current*2+2);
	return st[current];
}

int* construct_st(int arr[],int size){
	int height = (int) ceil(log2(size));

	int max_size = 2*pow(2,height) - 1;

	int *st = new int[max_size];

	constructUtil(arr,st,0,size-1,0);
	
	return st;
}

void update(int* st,int ss,int se,int i_t_u, int diff, int idx){
	if(i_t_u < ss || i_t_u > se){
		return;
	}

	st[idx] = st[idx] + diff;
	if(se != ss){
		int mid = ss + (se - ss)/2;
		update(st,ss,mid,i_t_u,diff,2*idx+1);
		update(st,mid+1,se,i_t_u,diff,2*idx+2);
	}
}

int main() {
	allons_y;
		
	int arr[] = {1,2,3,4,5,6};
	int size = sizeof(arr)/sizeof(arr[0]);

	int* st = construct_st(arr,size);
	cout << getsum(st,size,0,3) << endl;	

	//to update the value in array and also in our seg tree.

	int idx_to_update = 2,					
	    new_value = 8,                     			//old  value = 4
	    diff = new_value - arr[idx_to_update];     

	arr[idx_to_update] = new_value; 				//we update the arr

	update(st,0,size-1,idx_to_update,diff,0);  		//to update the data in seg tree

	//st,ss,se,idx_to_update,diff,current_idx

	cout << getsum(st,size,0,3) << endl;

	return 0;
}
