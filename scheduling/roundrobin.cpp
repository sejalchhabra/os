#include<bits/stdc++.h>
using namespace std;
class roundRobin{
public:
vector<int>art;
vector<int>bt;
int n;
int q;
roundRobin(int m, vector<int>arrival_time,vector<int>burst_time,int quantum){
	 n=m;
	 art=arrival_time;
	 bt=burst_time;
	 q=quantum;
}
	vector<int>wt{n,0};
	vector<int>tat{n,0};
	vector<int>ct{n,0};
void findWaitingTime()
{
    int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] = bt[i];
 
    int t = 0;
    while (1)
    {
        bool done = true;

        for (int i = 0 ; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = false; 
 
                if (rem_bt[i] > q)
                {
                    t += q;
                    rem_bt[i] -= q;
                }
                else
                {
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
 
                    rem_bt[i] = 0;
                }
            }
        }
 
        if (done == true)
        break;
    }
}
void findTurnAroundTime()
{
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
void findavgTime()
{
   int total_wt = 0, total_tat = 0;
 
    findWaitingTime();
 
    findTurnAroundTime();
 
    cout << "AT\t "<< " \tBT "
        << "  WT " << " \tTAT\n";
 
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << art[i] << "\t\t" << bt[i] <<"\t "
            << wt[i] <<"\t\t " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "
        << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
        << (float)total_tat / (float)n;
}
};
int main(){
vector<int>arrival={0,1,2};
  vector<int>burst={10,5,8};
  int n=arrival.size();
  int q=2;
roundRobin process(n,arrival,burst,q);
process.findavgTime();
}
