#include<bits/stdc++.h>
using namespace std;
void First_Fit(int block_size[], int total_blocks, int process_size[], int total_process) {
   vector<int> allocation(total_process,-1);
   
   for (int i = 0; i < total_process; i++) {
      for (int j = 0; j < total_blocks; j++) {
         if (block_size[j] >= process_size[i]) {
            allocation[i] = j;
            block_size[j] -= process_size[i];
            break;
         }
      }
   }
   cout << "Process No.\tProcess Size\tBlock no."<<endl;
   for (int i = 0; i < total_process; i++) {
      cout << " " << i+1 << "\t\t" << process_size[i] << "\t\t";
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

   First_Fit(block_size, total_blocks, process_size, total_process);
   return 0 ;
}
