#include<bits/stdc++.h>
using namespace std;
int lru(int pages[],int n,int capacity){
	unordered_set<int>s;
	unordered_map<int,int>mp;
	vector<int>v;
	int pagefault=0;
	for(int i=0;i<n;i++){
		if(s.size()<capacity){
			if(s.find(pages[i])==s.end()){
			
			s.insert(pages[i]);
			
			pagefault++;
			v.push_back(pages[i]);
			}mp[pages[i]]=i;
		}else{
			if(s.find(pages[i])==s.end()){
				int val,lru=INT_MAX;
				for(auto it=s.begin();it!=s.end();it++){
					if(mp[*it]<lru){
						lru=mp[*it];
						val=*it;
					}
				}
				for(int k=0;k<v.size();k++){
					if(v[k]==val)
					v[k]=pages[i];
				}
				
				s.erase(val);
				s.insert(pages[i]);
				mp[pages[i]]=i;
				pagefault++;
			}
			
		}
		
		for(int j=0;j<v.size();j++){
			cout<<v[j] <<" ";
		}
		cout<<endl;
		
	}
		
	return pagefault;
}
int main(){
	int pages[]={1,2,3,4,1,2,3,1,0,1};
	int n=sizeof(pages)/sizeof(pages[0]);
	int capacity=3;
	cout<<lru(pages,n,capacity);
	return 0;
}