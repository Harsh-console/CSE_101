#include<bits/stdc++.h>
using namespace std;

//constant window
int largestSumInConstantWindow(int a[], int n, int k){
    assert(k <= n);
    int l = 0, r = k;
    int sum = 0;
    for(int i = l; i < r; i++) sum += a[i];
    int max_sum = sum;
    while(r < n){
        sum -= a[l++];
        sum += a[r++];
        max_sum = max(sum, max_sum);
    }
    return max_sum;
}

// find length of longest subarray with sum <= k
//Time Complexity = O(n**2)
// Space Complexity = O(1)
int longestSumArrayWithUpperSumBrute(int a[], int n, int k){
    int maxLength = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        int j = i;
        for(; j < n; j++){
            sum+= a[j];
            if(sum > k) break;
        }
        maxLength = max(maxLength, j - i + 1);
    }
    return maxLength; 
}

// Time Complexity = O(n)
// Space Complexity = O(n)
int longestSumArrayWithUpperSumOptimized(int a[], int n, int k){
    int maxLength = 0;
    int l = 0, r = 0;
    int sum = 0;
    while(r<n){
        sum += a[r];
        while(sum > k)
            sum -= a[l++];
        if(l>r) r=l;
        maxLength = max(maxLength, r - l + 1);
    }
    return maxLength;
}

int longestSumArrayWithUpperSumOptimal(int a[], int n, int k){
    int maxLength = 0;
    int l = 0, r = 0;
    int sum = 0;
    while(r < n){
        sum += a[r];
        if(sum > k) sum -= a[l++];
        if(l > r) r = l;
        maxLength = max(maxLength, r - l + 1);
        r++;
    }
    return maxLength;
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);
    cout<<longestSumArrayWithUpperSumOptimized(a, n, 25)<<endl;
    return 0;
}
