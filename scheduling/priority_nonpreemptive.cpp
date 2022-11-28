
// ---------------- 	Non-Preemptive PRIORITY -------------------------- //

#include<iostream>
using namespace std;

struct Process{
	int pid;
	int art;
	int bt;
	int pri;
};

void find_WaitingTime(Process p[],int n,int wt[],int rt[],int ct[]){
	int rem_bt[n];
	for(int i=0;i<n;i++)
		rem_bt[i]=p[i].bt;
	
	int complete=0,t=0,priority=0,j=0;
	bool check=false;
	int finish_time;
	
	
	cout<<"\n================================Gantt Chart====================================\n";
	
	while(complete!=n){
		for(int i=0;i<n;i++){
			if((p[i].art<=t) && (rem_bt[i]>0) && (p[i].pri>=priority)){
				priority=p[i].pri;
				j=i;
				check=true;
			}
		}
		if(check==false){
			t++;
			continue;
		}
		rem_bt[j]=0;
		if(rem_bt[j]==0){
			complete++;
			priority=0;
			check=false;
			finish_time=t+1;
			ct[j]=finish_time;
			wt[j]=finish_time-p[j].bt-p[j].art;
			rt[j]=wt[j]-p[j].art;
			if(wt[j]<0){
				wt[j]=0;
			}	
			if(rt[j]<0){
				rt[j]=0;
			}
		}
		t+=rem_bt[j];
		cout<<"|| P"<<p[j].pid<<" ";
	}
	cout<<endl;
}

void find_turnAroundTime(Process p[],int n,int wt[],int tat[]){
	for(int i=0;i<n;i++){
		tat[i]=p[i].bt+wt[i];
	}
}

void printingTable(Process p[],int n){
	int wt[n],rt[n],tat[n],ct[n];
	
	find_WaitingTime(p,n,wt,rt,ct);
	find_turnAroundTime(p,n,wt,tat);
	int t_wt=0,t_tat=0,t_rt=0,t_ct=0;
	
	cout<<"\n================================Table====================================\n";
	cout<<"ProcessNo\tArrivalTime\tBurstTime\tPriority\tWaitingTime\tTurnAroundTime\tResponseTime\tCompletionTime\n";
	for(int i=0;i<n;i++){
		cout<<p[i].pid<<"\t\t"<<p[i].art<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].pri<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\t\t"<<rt[i]<<"\t\t"<<ct[i]<<endl;
		t_wt+=wt[i];
		t_tat+=tat[i];
		t_rt+=rt[i];
		t_ct+=ct[i];
	}
	cout<<"\n================================Averages====================================\n";
	cout<<"Average Waiting time :"<<(float)t_wt/(float)n<<endl;
	cout<<"Average Turn Around time :"<<(float)t_tat/(float)n<<endl;
	cout<<"Average Response time :"<<(float)t_rt/(float)n<<endl;
	cout<<"Average Completion time :"<<(float)t_ct/(float)n<<endl;	
		
	
}



int main(){
	
	int n;
	cout<<"Enter the number of process : ";
	cin>>n;
	Process p[n];
	
	for(int i=0;i<n;i++){
		int a,b,pr;
		p[i].pid=i+1;
		cout<<"Enter Arrival Time, Burst Time, priority of process "<<p[i].pid<<":";
		cin>>a>>b>>pr;
		p[i].art=a;
		p[i].bt=b;
		p[i].pri=pr;
	}
	
	printingTable(p,n);
	
	return 0;
}
