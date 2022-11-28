#include<bits/stdc++.h>
using namespace std;

void worstFit(int blockSize[], int m, int processSize[],int n)
{
 vector<int>allocation(n,-1);
	for (int i=0; i<n; i++){
		int wstIdx = -1;
		for (int j=0; j<m; j++){
			if (blockSize[j] >= processSize[i])
			{
				if (wstIdx == -1)
					wstIdx = j;
				else if (blockSize[wstIdx] < blockSize[j])
					wstIdx = j;
			}
			}
		if (wstIdx != -1){
			allocation[i] = wstIdx;
			blockSize[wstIdx] -= processSize[i];
		}
	}

	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++)	{
		cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
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

   worstFit(block_size, total_blocks, process_size, total_process);
   return 0 ;
}


