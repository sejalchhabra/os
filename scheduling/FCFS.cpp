#include<bits/stdc++.h>
using namespace std;
class fcfs{
public:
vector<int>art;
vector<int>bt;
vector<int>tat;
vector<int>wt;
vector<int>ct;
int n;
fcfs(int m,vector<int>a,vector<int>b){
		n=m;
		art=a;
		bt=b;
	}
void findcompletiontime(){

        ct.push_back(bt[0]);
	for(int i=1;i<n;i++){
	int temp=0;
	if(bt[i-1]>art[i])
	   temp= bt[i]+ct[i-1];
	   else
	    temp=art[i]+bt[i];
	   ct.push_back(temp);
	 }
   }
  void findTurnaroundtime()
{
    for (int  i = 0; i < n ; i++){
       int temp = ct[i]-art[i];
        tat.push_back(temp);}
}
void findwaitingtime()
{    wt.push_back(0);
    for (int  i = 1; i < n ; i++ ){
        int temp =  ct[i-1]-art[i] ;
        if(temp<0)
        temp=0;
	wt.push_back(temp);}
}


void findavgTime()
{ int totalwt = 0, totaltat = 0;
    findcompletiontime();
    findTurnaroundtime();
    findwaitingtime();
 	
    cout << "Processes  "<<"arrival time"<< " Burst time  "
         << " Waiting time  " <<"completion time"<< " Turn around time\n";
 
    for (int  i=0; i<n; i++)
    {
        totalwt = totalwt + wt[i];
        totaltat = totaltat + tat[i];
        cout << "   " << i+1 << "\t\t"<<art[i]<<"\t\t" << bt[i] <<"\t    "
            << wt[i] <<"\t\t  " <<ct[i]<<"\t\t"<< tat[i] <<endl;
    }
 
    cout << "Average waiting time = "
         << (float)totalwt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)totaltat / (float)n;
}
};
int main(){
  vector<int>arrival={0,1,2};
  vector<int>burst={10,5,8};
  int n=arrival.size();
 
 fcfs process(n,arrival,burst);
 process.findavgTime();
}
