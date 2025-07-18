// User function template for C++

class Solution {
  public:
    void multiply(vector<int>& nums, int &size, int &multiplier) {
        int carry = 0;
    
        for(int i = 0; i<size; i++) {
            int result = (multiplier*nums[i])+carry;
    
            nums[i]   = result%10;
    
            carry     = result/10;
        }
    
        while(carry) {
            nums[size] = carry%10;
            size++;
            carry /= 10;
        }
    }
    vector<int> factorial(int n) {
        vector<int> nums(10000, 0);
        nums[0] = 1;
        int size = 1;
        int fact = n;
    
    
        for(int multiplier = 2; multiplier<=fact; multiplier++)
            multiply(nums, size, multiplier);
        
        vector<int> result;
        for(int i = size-1; i>=0 ; i--)
        result.push_back(nums[i]);
        return result;
        
    }
};