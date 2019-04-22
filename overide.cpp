#include <iostream>
#include <vector>
#include <unordered_set>
#include <iterator>

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
    vector<int> v1{1,2,3};
    vector<int> v2{2,1,3};
    vector<int> v3{3,2,1};
    vector<int> v4{7,8,9};
    unordered_set<std::vector<int>,vectorHasher,VectorComparator> us;
    us.insert(v1);
    us.insert(v2);
    us.insert(v3);
    us.insert(v4);
    auto it=us.begin();
    for(;it!=us.end();it++)
    {
        vector<int> v1=*it;
        for(int i=0;i<v1.size();i++)
        {
            cout<<v1.at(i)<<" ";
        }
        cout<<endl;
    }

    return 0;
}
