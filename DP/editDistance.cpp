#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solveUsingRecursion(string a,string b,int i,int j){
    if(i==a.length()){
        return b.length()-j;
    }
    if(j==b.length()){
        return a.length()-i;
    }

    int ans=0;

    if(a[i]==b[j]){
        ans=0+solveUsingRecursion(a,b,i+1,j+1);
    }
    else{
        int replace=1+solveUsingRecursion(a,b,i+1,j+1);
        int insert=solveUsingRecursion(a,b,i,j+1);
        int remove=solveUsingRecursion(a,b,i+1,j);
        ans=min(insert,min(remove,replace));
    }

    return ans;


}

int minDistance(string word1,string word2){
    int i=0;
    int j=0;

    int ans=solveUsingRecursion(word1,word2,i,j);

    return ans;
}
int main()
{

    string word1="horse";
    string word2="rorse";

    int ans=minDistance(word1,word2);

    cout<<"the minium number of opertaions:"<<ans<<endl;
 return 0;
}