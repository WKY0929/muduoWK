#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>res;
void initNum(vector<int>&nums,int n){
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
    }

class Solution{
public:
    void dfs(vector<int>&nums,int begin,int end,int L,int R,int S){
        if(begin==end){
            int sum=0;
            for(int i=L;i<=R;i++){
                sum+=nums[i];
            }
            if(sum==S){
                res.push_back(nums);
                return;
            }else{
                return;
            }
        }
        for(int i=begin;i<=end;i++){
            swap(nums[i],nums[begin]);
            dfs(nums,begin+1,end,L,R,S);
            swap(nums[i],nums[begin]);
        }
    }
};
int main(){
    vector<int> nums;
    int i;
    cout<<"input N"<<endl;
    cin>>i;
    initNum(nums,i);
    Solution s;
    int L,R,S;
    cout<<"input L S R"<<endl;
    cin>>L;
    cin>>S;
    cin>>R;
    s.dfs(nums,0,nums.size()-1,L-1,R-1,S);
    if(res.empty())cout<<"-1"<<endl;
    else{
        vector<int>temp=res[0];
         for(auto num:temp){
                cout<<num<<" ";
        }
    }
    return 0;

}