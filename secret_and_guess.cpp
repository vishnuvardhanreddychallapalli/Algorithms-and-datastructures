#include <iostream>
#include <unordered_map>
#include <utility>
#include <iterator>
#include <cstring>
using namespace std;
string get_hint(string& secret,string& guess)
{
    unordered_multimap<char,int> um;
    int no_of_correct_matches=0,no_of_placement_mismatches=0;
    for(int i=0;i<secret.size();i++)
    {
        if(secret.at(i)==guess.at(i))
                 no_of_correct_matches++;
        else
            um.emplace(guess.at(i),i);
    }
    cout<<"The no of correct guess: "<<no_of_correct_matches<<endl;

    for(int i=0;i<secret.size();i++)
    {
        if(secret.at(i)==guess.at(i))
                continue;
        else
        {
           
            if(um.find(secret.at(i))==um.end())
            {
               
                continue;
            }
            else
            {
                pair<unordered_multimap<char,int>::iterator,unordered_multimap<char,int>::iterator> r= um.equal_range(secret.at(i));
                unordered_multimap<char,int>::iterator it1=r.first;
                
                while(it1!=r.second)
                {
                    if(it1->first==secret.at(i) && it1->second!=i)
                    {
                        no_of_placement_mismatches++;
                        um.erase(it1);
                        break;
                    }
                    it1++;
                }
            }
        }
    }
  
    string final_hint="";
    if(no_of_correct_matches==0 && no_of_placement_mismatches==0)
         final_hint="";
    else if(no_of_placement_mismatches==0)
          final_hint=std::to_string(no_of_correct_matches)+"A";
    else if(no_of_correct_matches==0)
        final_hint=std::to_string(no_of_placement_mismatches)+"B";
    else
       final_hint=std::to_string(no_of_correct_matches)+"A"+std::to_string(no_of_placement_mismatches)+"B";
    return final_hint;
}
int main() {
  
  string str1,str2;
  cin>>str1>>str2;
  cout<<get_hint(str1,str2)<<endl;
}
