#include<iostream>
#include<vector>
#include<queue>
using namespace std;
   
vector<int>h(10010,-1);
vector<int>e(20020);
vector<int>en(20020);
vector<bool>d(10010,false);
int idx=0;
int n;
    void add(int a,int b){
        e[idx]=b;en[idx]=h[a];h[a]=idx++;
    }
    bool bfs(int u){
        queue<int>q;
        q.push(u);
        d[u]=true;
        int sum=1;
        //memset(d,false,sizeof(d));
        while(!q.empty()){
            auto j=q.front();
            q.pop();
            for(int i=h[j];i!=-1;i=en[i]){
                int t=e[i];
                if(d[t]==false){
                    sum++;
                    d[t]=true;
                    q.push(t);
                }
            }
        }
        if(sum==n)return true;
        return false;

    }
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        int nums=edges.size();
        //memset(h,-1,sizeof(h));
        if(nums!=n-1)return false;
        for(auto i:edges){
            add(i[0],i[1]);
            add(i[1],i[0]);
            
        }
        return bfs(0);
       

    }
    int main()
    {
        cin>>n;
        vector<vector<int>>edges={{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
        cout<<validTree(n,edges)<<endl;
    }
