#include<bits/stdc++.h>
using namespace std;
int main(){
    int i, j, k, hitCount = 0;
    int frames;
    cout<<"enter the num of frames"<<endl;
    cin>>frames;
    
    int p_count;
    cout<<"enter the num of pages"<<endl;
    cin>>p_count;
	
    cout<<"enter the values"<<endl;
    vector <int> processes(p_count);
    for(int i=0;i<p_count;i++){
    	cin>>processes[i];
	}
    vector <int> hit(p_count);
    
    vector<vector<int>> a(frames);
    for(i = 0; i < frames; i++){
        a[i] = vector <int>(p_count,-1);
    }
    
    map <int, int> mp;    
    
    for(i = 0; i < p_count ; i++){
        vector<pair<int,int>> c;
        
        for(auto x: mp)
        {
            c.push_back({x.second, x.first});
        }
        
        sort(c.begin(),c.end());
        
        bool hasCompleted = false;
        
        for(j = 0;j < frames; j++){
            if(a[j][i] == processes[i])
            {
                hitCount++;
                hit[i] = true;
                
                mp[processes[i]]++;
                hasCompleted = true;
                break;
            }
            if(a[j][i] == -1)
            {
                for(k = i ; k < p_count; k++)
                    a[j][k] = processes[i];
                    
                mp[processes[i]]++;
                hasCompleted = true;
                break;
            }
        }
        if(j == frames || hasCompleted == false){
            for(j = 0;j < frames; j++){
                if(a[j][i] == c[c.size() - 1].second){
                    mp.erase(a[j][i]);
                    
                    for(k = i; k < p_count ; k++)
                        a[j][k]= processes[i];
                        
                    mp[processes[i]]++;
                    break;
                }
            }
        }
        for(auto x:mp){
            if(x.first != processes[i]){
                mp[x.first]++;
            }
        }
    }
    cout << "Process    ";
    for(i = 0 ; i < p_count; i++){
        cout << processes[i] << "  ";
    }
    cout << endl;
    
    for(i = 0; i < frames; i++){
        cout << "Frame" << i << "     ";
        for(j = 0; j < p_count; j++){
            if(a[i][j] == -1)
                cout << "-  ";
                else 
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
    
    cout << "Page Fault ";
    for(i = 0; i < p_count; i++){
        
        if(hit[i])
            cout << "N  ";
        else
            cout << "Y  ";
    }
    cout << "\n\n";
    
    cout << "Page Fault " << p_count - hitCount << endl;
    cout << "Hit " << hitCount << endl;
    
    return 0;
}