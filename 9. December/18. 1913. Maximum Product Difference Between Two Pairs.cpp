// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

void print(priority_queue<int, vector<int>, greater<int>> minHeap, priority_queue<int, vector<int>> maxHeap)
{
    while (!maxHeap.empty())
    {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    while (!minHeap.empty())
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
}

int maxProductDifference(vector<int> &nums)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>> maxHeap;

    for (int i : nums)
    {
        maxHeap.push(i);
        minHeap.push(i);

        if (maxHeap.size() > 2)
        {
            maxHeap.pop();
        }
        if (minHeap.size() > 2)
        {
            minHeap.pop();
        }
    }

    // print(minHeap, maxHeap);

    int second_largest = minHeap.top();
    minHeap.pop();
    int largest = minHeap.top();
    minHeap.pop();
    int second_smallest = maxHeap.top();
    maxHeap.pop();
    int smallest = maxHeap.top();
    maxHeap.pop();

    return (largest * second_largest) - (smallest * second_smallest);
}

int main()
{
    int t;
    cin >> t;

    vector<int> nums(t);

    for (int i = 0; i < t; i++)
        cin >> nums[i];

    cout << maxProductDifference(nums) << endl;
}