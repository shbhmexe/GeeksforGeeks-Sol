class Solution {
public:
    // Function to find the median of two sorted arrays
    double medianOf2(vector<int>& a, vector<int>& b) {
        // Ensure 'a' is the smaller array for efficient binary search
        if (a.size() > b.size())
            return medianOf2(b, a);

        int m = a.size();
        int n = b.size();
        int low = 0, high = m;

        // Binary search on the smaller array
        while (low <= high) {
            int Px = (low + high) / 2;                  // Partition index for array 'a'
            int Py = (m + n + 1) / 2 - Px;              // Corresponding partition in array 'b'

            // Edge values at the partition
            int x1 = (Px == 0) ? INT_MIN : a[Px - 1];   // Left max of 'a'
            int x3 = (Px == m) ? INT_MAX : a[Px];       // Right min of 'a'

            int x2 = (Py == 0) ? INT_MIN : b[Py - 1];   // Left max of 'b'
            int x4 = (Py == n) ? INT_MAX : b[Py];       // Right min of 'b'

            // Check if we have a valid partition
            if (x1 <= x4 && x2 <= x3) {
                if ((m + n) % 2 == 0) {
                    // If total length is even, return average of two middle values
                    return (max(x1, x2) + min(x3, x4)) / 2.0;
                } else {
                    // If total length is odd, return max of left elements
                    return max(x1, x2);
                }
            } else if (x1 > x4) {
                // Too many elements from 'a' on the left, move partition left
                high = Px - 1;
            } else {
                // Too few elements from 'a' on the left, move partition right
                low = Px + 1;
            }
        }

        // Should not reach here for valid input
        return -1.0;
    }
};




// //Approach-1 - Brute Force
// //T.C : O(m+n)
// //S.C : O(m+n)
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size();
//         int n = nums2.size();
        
//         vector<int> temp(m+n);
//         int i = 0, j = 0, k = 0;
        
//         while(i < m && j < n) {
//             if(nums1[i] < nums2[j])
//                 temp[k++] = nums1[i++];
//             else
//                 temp[k++] = nums2[j++];
//         }
        
//         while(i < m) temp[k++] = nums1[i++];
//         while(j < n) temp[k++] = nums2[j++];
        
//         int size = m+n;
        
//         if(size%2 != 0)
//             return temp[size/2];
        
//         return (temp[size/2]+temp[(size/2)-1])/2.0;
        
//     }
// };


// //Approach-2 - Optimising Space from Approach-1
// //T.C : O(m+n)
// //S.C : O(1)
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size();
//         int n = nums2.size();
//         int size = m+n;
        
//         int idx1 = (size/2)-1;
//         int element1 = -1;
//         int idx2 = size/2;
//         int element2 = -1;
        
//         int i = 0, j = 0, k = 0;
        
//         while(i < m && j < n) {
//             if(nums1[i] < nums2[j]) {
//                 if(k == idx1) {
//                     element1 = nums1[i];
//                 }
//                 if(k == idx2) {
//                     element2 = nums1[i];
//                 }
//                 i++;
//             } else {
//                 if(k == idx1) {
//                     element1 = nums2[j];
//                 }
//                 if(k == idx2) {
//                     element2 = nums2[j];
//                 }
//                 j++;
//             }
//             k++;
//         }
        
//         while(i < m) {
//             if(k == idx1) {
//                 element1 = nums1[i];
//             }
//             if(k == idx2) {
//                 element2 = nums1[i];
//             }
//             i++;
//             k++;
//         }
        
//         while(j < n) {
//             if(k == idx1) {
//                 element1 = nums2[j];
//             }
//             if(k == idx2) {
//                 element2 = nums2[j];
//             }
//             j++;
//             k++;
//         }

//         if(size%2 == 1)
//             return element2;
        
//         return (element1 + element2)/2.0;
        
//     }
// };



public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int m = nums1.size();
        int n = nums2.size();
        
        int low = 0, high = m;
        while(low <= high) {
            
            int Px = low + (high-low)/2;
            int Py = (m+n+1)/2 - Px;
            
            int x1  = (Px == 0) ? INT_MIN : nums1[Px-1];
            int x3 = (Px == m) ? INT_MAX : nums1[Px];
            
            int x2  = (Py == 0) ? INT_MIN : nums2[Py-1];
            int x4 = (Py == n) ? INT_MAX : nums2[Py];
            
            if(x1 <= x4 && x2 <= x3) {
                if((m+n)%2 == 0)
                    return (max(x1, x2) + min(x3, x4))/2.0;
                
                return max(x1, x2);
            } else if(x1 > x4) {
                high = Px-1;
            } else {
                low = Px+1;
            }
        }
        
        return -1;
    }
};