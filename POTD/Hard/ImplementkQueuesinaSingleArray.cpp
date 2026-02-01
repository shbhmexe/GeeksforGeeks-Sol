
.///Question 717
#include <bits/stdc++.h>
using namespace std;

class kQueues {
    int *exe, *shbhm, *front, *rear;
    int free_spot, n, k;

public:
    kQueues(int n, int k) : n(n), k(k), free_spot(0) {
        exe = new int[n];
        shbhm = new int[n];
        front = new int[k];
        rear = new int[k];
        fill(front, front + k, -1);
        fill(rear, rear + k, -1);
        iota(shbhm, shbhm + n, 1);
        shbhm[n - 1] = -1;
    }

    void enqueue(int x, int i) {
        if (free_spot == -1) return;
        int idx = free_spot;
        free_spot = shbhm[idx];
        if (front[i] == -1) front[i] = idx;
        else shbhm[rear[i]] = idx;
        shbhm[idx] = -1;
        rear[i] = idx;
        exe[idx] = x;
    }

    int dequeue(int i) {
        if (front[i] == -1) return -1;
        int idx = front[i];
        front[i] = shbhm[idx];
        shbhm[idx] = free_spot;
        free_spot = idx;
        return exe[idx];
    }

    bool isEmpty(int i) {
        return front[i] == -1;
    }

    bool isFull() {
        return free_spot == -1;
    }
};