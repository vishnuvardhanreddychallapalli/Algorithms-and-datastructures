#include <iostream>
#include <utility>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;
int main() {
    unordered_map<int,list<pair<int,int>>> um1,um2;
    vector<vector<int>> arr1{{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> arr2{{1,2,3},{4,5,6},{7,8,9}};
    if(arr1[0].size()!=arr2.size())
    {
        cout<<"Multiplication not possible:"<<endl;
    }
    else
    {
       cout<<"reading matrix1..... ";
      for(int i=0;i<arr1.size();i++)
      {
        list<pair<int,int>> fl;
        for(int j=0;j<arr1[i].size();j++)
        {
              if(arr1[i][j]!=0)
              {
                 pair<int,int> p;
                 p.first= j;
                 p.second= arr1.at(i).at(j);
                 fl.push_back(p);
              }
        }
        um1.emplace(i,fl);
      }
      cout<<"done..."<<endl;
      cout<<"check the matrix1:  "<<endl;
      for(int i=0;i<arr1.size();i++)
      {
          list<pair<int,int>> &l=um1.at(i);
          for(list<pair<int,int>>::iterator pt=l.begin();pt!=l.end();pt++)
          {
              cout<<"("<<pt->first<<","<<pt->second<<")";
          }
          cout<<endl;
      }
      cout<<"reading matrix2..... ";
      for(int i=0;i<arr2.size();i++)
      {
        list<pair<int,int>> fl;
        for(int j=0;j<arr2[i].size();j++)
        {
              if(arr2[j][i]!=0)
              {
                 pair<int,int> p;
                 p.first= j;
                 p.second= arr2.at(j).at(i);
                 fl.push_back(p);
              }
        }
        um2.emplace(i,fl);
      }
      cout<<"done..."<<endl;
      cout<<"check the matrix2:  "<<endl;
      for(int i=0;i<arr2.size();i++)
      {
          list<pair<int,int>> &l=um2.at(i);
          for(list<pair<int,int>>::iterator pt=l.begin();pt!=l.end();pt++)
          {
              cout<<"("<<pt->first<<","<<pt->second<<")";
          }
          cout<<endl;
      }
      cout<<"Starting the sparse-multiplication....."<<endl;
      int final_rows=arr1.size(),final_cols=arr2[0].size();
      vector<vector<int>> final_ans(final_rows);
      cout<<"Processing begin...."<<endl;
      for(int i=0;i<final_rows;i++)
      {
          for(int j=0;j<final_cols;j++)
          {
             list<pair<int,int>> &mat1_row=um1.at(i);
             list<pair<int,int>> &mat2_row=um2.at(j);
             list<pair<int,int>>::iterator iter1=mat1_row.begin();
             list<pair<int,int>>::iterator iter2=mat2_row.begin();
              int my_ans=0;
              while(iter1!=mat1_row.end() && iter2!=mat2_row.end())
              {
                 if(iter1->first<iter2->first)
                 {
                     iter1++;
                 }
                 else if(iter1->first>iter2->second)
                 {
                     iter2++;
                 }
                 else
                 {
                    my_ans=my_ans+(iter1->second*iter2->second);
                    ++iter1;
                    ++iter2;
                 }
             }
             final_ans.at(i).push_back(my_ans); 
           }
        }
        
        for(int i=0;i<final_ans.size();i++)
        {
            for(int j=0;j<final_ans[i].size();j++)
            {
                cout<<final_ans[i][j]<<" ";
            }
            cout<<endl;
        }

    }
     
    
    return 0;
}
