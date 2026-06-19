//Question 44 june26
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int largest = -1;
        int secondlargest = -1;
        
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] > largest){
                secondlargest = largest;
                largest = arr[i];
            }
            
            if(arr[i] < largest && arr[i] > secondlargest){
                secondlargest = arr[i];
            }
        }
        return secondlargest;
    }
};