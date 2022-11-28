#include<bits/stdc++.h>
#define disksize 200;
using namespace std;

void cscan(int arr[],int head){
	int seek_count,distance=0,curr_head;
	vector<int>left, right,sequence;
	for(int i=0;i<8;i++){
		if(arr[i]<head)
		left.push_back(arr[i]);
		else right.push_back(arr[i]);
	}
	sort(left.begin(),left.end());
	sort(right.begin(),right.end());
	
	for(int i=0;i<right.size();i++){
		int curr_head=right[i];
		sequence.push_back(right[i]);
		distance=(curr_head-head);
		seek_count+=distance;
		head=curr_head;
	}
	head=0;
	seek_count+=disksize-1;
	for(int i=0;i<left.size();i++){
		curr_head=left[i];
		sequence.push_back(left[i]);
		distance=(curr_head-head);
		seek_count+=distance;
		head=curr_head;
	}
	cout<<seek_count<<endl;
	for(int i=0;i<sequence.size();i++){
		cout<<sequence[i]<<" ";
	}
}
int main(){
	int pages[]={100, 57, 34, 20,70,140,199,10};
	int n=sizeof(pages)/sizeof(pages[0]);
	int head=50;
	cscan(pages,head);
}