#include <bits/stdc++.h>
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    int min,i,j,temp=0 ;
    for(i=0;i<n-1;i++){
        temp=i;
        min = arr[i];
        for( j=i;j<n;j++){
            if(arr[j]<min){
                min= arr[j];
                temp =j;
            }

        }
        swap(arr[i], arr[temp]);
        
    }
}
    

