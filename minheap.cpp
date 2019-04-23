///genearlly stl heap have max heap behaviour we need to convert the behavoiur to min heap by the following code...
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct mapper
{
    bool operator()(const int &a,const int &b)
    {
        if(a<b)
              return false;
        return true;
    }
};
int main() {
    priority_queue<int,vector<int>,mapper> p;
    p.push(10);
    p.push(12);
    p.push(-5);
    cout<<"The topper is :"<<p.top()<<endl;
    cout<<endl;
}
