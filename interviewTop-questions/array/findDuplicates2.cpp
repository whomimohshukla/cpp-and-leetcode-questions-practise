#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
  
int findDuplicateMethod2(vector<int>&arr){

    while(arr[0]!=arr[arr[0]]){
        swap(arr[0],arr[arr[0]]);
        
    }
    return arr[0];
}
int main()
{
    vector<int> arr{1, 3, 4, 2, 2};

    int ans=findDuplicateMethod2(arr);

    cout<<"duplicate number is :"<<ans<<endl;



    return 0;
}
