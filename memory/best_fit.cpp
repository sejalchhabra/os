#include<bits/stdc++.h>
using namespace std;

	void Best_fit(int block_size[], int total_blocks, int process_size[], int total_process){
	vector<int>allocation(total_process,-1);
	for(int i=0;i<total_process;i++){
		int idx=-1;
	for(int j=0;j<total_blocks;j++){
		if(block_size[j]>=process_size[i]){
		if(idx==-1)
		idx=j;
		else
		if(block_size[idx]>block_size[j])
		idx=j;
			}	
		}
		if(idx!=-1){
		allocation[i]=idx;
		block_size[idx]-=process_size[i];
		}
	    }
		   cout << " Process No.\tProcess Size\tBlock no."<<endl;
   		for (int i = 0; i < total_process; i++) {
      		cout << " " << i+1 << "\t\t\t\t" << process_size[i] << "\t\t\t\t";
      		if (allocation[i] != -1)
         	cout << allocation[i] + 1;
      		else
         	cout << "Not Allocated";
         	cout << endl;
   		}
	}
	

int main(){
	int num;
	cout<<"enter num of blocks"<<endl;
	cin>>num;
	cout<<"enter block sizes"<<endl;
   	int block_size[num];
   	for(int i=0;i<num;i++){
   	cin>>block_size[i];
   	}
   	int num2;
   	cout<<"enter number of processes"<<endl;
   	cin>>num2;
 	cout<<"enter process sizes"<<endl;
   int process_size[num2];
   for(int i=0;i<num2;i++){
   cin>>process_size[i];}
   int total_blocks = num;
   int total_process = num2;

   Best_fit(block_size, total_blocks, process_size, total_process);
   return 0 ;
}
