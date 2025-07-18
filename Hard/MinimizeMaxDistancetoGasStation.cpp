#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    /**
     * Calculates how many new stations are required to ensure the distance 
     * between any two consecutive stations is at most 'dist'.
     * This version is more robust than the original.
     */
    int numberOfGasStationsRequired(long double dist, std::vector<int>& stations) {
        int cnt = 0;
        for (int i = 1; i < stations.size(); i++) {
            double dist_between = stations[i] - stations[i-1];
            // The number of new stations needed between two existing ones is
            // ceil(distance_between / desired_max_dist) - 1.
            cnt += std::ceil(dist_between / dist) - 1;
        }
        return cnt;
    }

    /**
     * Finds the smallest possible maximum distance between adjacent gas stations
     * after adding 'k' new stations.
     */
    long double findSmallestMaxDist(std::vector<int>& stations, int k) {
        int n = stations.size();
        long double low = 0;
        long double high = 0;

        // The maximum possible answer is the largest gap between existing stations.
        for (int i = 0; i < n - 1; i++) {
            high = std::max(high, (long double)(stations[i+1] - stations[i]));
        }

        // Binary search for the optimal distance.
        long double diff = 1e-7; // A small tolerance for convergence
        while (high - low > diff) {
            long double mid = (low + high) / 2.0;
            int required_stations = numberOfGasStationsRequired(mid, stations);
            
            if (required_stations > k) {
                // If we need more stations than we have, our guessed 'mid' distance is too small.
                // We must allow a larger distance.
                low = mid;
            } else {
                // If we can achieve this 'mid' with 'k' or fewer stations,
                // it's a possible answer. Let's try for an even smaller distance.
                high = mid;
            }
        }
        return high;
    }
};