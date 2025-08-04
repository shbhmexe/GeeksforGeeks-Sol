//Question 326
/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void SortedStack ::sort() 
{
    vector<int>arr;
while(!s.empty()){
    arr.push_back(s.top());
    s.pop();
}
std::sort(arr.begin(),arr.end(),greater<int>());

for(int i=arr.size()-1;i>=0;i--){
    s.push(arr[i]);
}
    
}