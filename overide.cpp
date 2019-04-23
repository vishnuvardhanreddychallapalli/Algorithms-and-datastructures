#include <iostream>
#include <vector>
#include <unordered_set>
#include <iterator>
#include <unordered_map>
#include <utility>
#include <bits/stdc++.h>
using namespace std;
struct vectorHasher
{
std::size_t operator()(const std::vector<int> & vec) const
{
  std::size_t seed = vec.size();
  for(auto& i : vec)
 {
    seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
 }
  return seed;
}
};
struct VectorComparator
{
bool operator()(const vector<int> &vec1,const vector<int> &vec2) const
{
    if(vec1.size()==vec2.size())
    {
        for(unsigned int i=0;i<vec1.size();i++)
        {
            if(vec1.at(i)!=vec2.at(i))
                       return false;
        }
    }
    return true;
}
};

int main() {
    unordered_multimap<int,pair<int,int>> umm;
    vector<int> arr{1,0,-1,0,-2,2};
    int target=0;
    unordered_set<vector<int>,vectorHasher,VectorComparator> us;
    for(int i=0;i<arr.size()-1;i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            pair<int,int> p1;
            p1.first=min(i,j);
            p1.second=max(i,j);
            auto it=umm.find((arr[i]+arr[j]));
            if(it==umm.end())
            {
               umm.emplace(target-(arr.at(p1.first)+arr.at(p1.second)),p1);
            }
            else
            {
                pair<std::unordered_multimap<int,pair<int,int>>::iterator,std::unordered_multimap<int,pair<int,int>>::iterator> r=umm.equal_range((arr.at(p1.first)+arr.at(p1.second)));
                auto it1=r.first;
                while(it1!=r.second)
                {
                    pair<int,int>& p2=it1->second;
                    //make sure you have all unique values..
                    if(i!=p2.first && i!=p2.second && j!=p2.first && j!=p2.second)
                    {
                        vector<int> my_values;
                        my_values.push_back(arr.at(p2.first));
                        my_values.push_back(arr.at(p2.second));
                        my_values.push_back(arr.at(i));
                        my_values.push_back(arr.at(j));
                        sort(my_values.begin(),my_values.end());
                        us.insert(my_values);
                        for(int q=0;q<my_values.size();q++)
                           cout<<my_values.at(q)<<" ";
                        cout<<endl;
                        umm.emplace(target-(arr.at(i)+arr.at(j)),p1);
                    }
                    it1++;
                }
                
            }
            
        }
    }
    //cout<<"****************(((((((((((()))))))))))))))))))))))************"<<endl;
    for(auto it4=us.begin();it4!=us.end();it4++)
    {
        const std::vector<int> &v1=*it4;
       // cout<<"V1 SIZE Is:: "<<v1.size()<<" :";
        for(int i=0;i<v1.size();i++)
        {
            cout<<v1.at(i)<<" ";
        }
        cout<<endl;
    }
   
    
    return 0;
}
