#include <bits/stdc++.h>
using namespace std;

void reverseAString(string a){
    if(a.length()==0){
        return;
    }
    string b = a.substr(1);
    reverseAString(b);
    cout<<a[0];
    
}

void permutations(string s, string ans){

    if(s.length()==0){
        cout<<ans<<endl;
    }
    for (int i=0;i<s.length();i++){
    char ch = s[i];
    string ros= s.substr(0,i)+s.substr(i+1);
    permutations(ros,ans+ch);
    }
}

int countpath(int s, int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count = 0;
    for (int i=1; i<=6; i++){
        count+=countpath(s+i,e);
    }
    return count;
}

int possiblePath(int a, int b){
    if(a==1 || b==1){
        return 1;
    }
    int ans = possiblePath(a,b-1) + possiblePath(a-1,b);
    return ans;
}

int tilingWays(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    return tilingWays(n-1)+tilingWays(n-2);
}

int friendsPairing(int n){
    if(n==0 || n==2 ||n==1){
        return n;
    }
    return friendsPairing(n-1)+friendsPairing(n-2)*(n-1);
}

// Backtracking

bool isSafe(int** arr, int x, int y, int n){
    if(x<n && y<n && arr[x][y]==1){
        return true;
    }
    return false;
}

bool ratInMaze(int** arr, int x, int y, int n, int** solutionArr){

    if(x==n-1 && y==n-1){
        solutionArr[x][y]=1;
        return true;
    }

    if(isSafe(arr, x, y, n)){
        solutionArr[x][y]=1;
        if(ratInMaze(arr, x+1, y, n, solutionArr)){ //right shift
            return true;
        }
        if(ratInMaze(arr, x, y+1, n, solutionArr)){ //bottom shift
            return true;
        }
        solutionArr[x][y]=0;  //Backtrack
        return false;
    }

    return false;
}


bool isSafe2(int** arr, int x, int y, int n){

    if(x>=n || y>=n){
        return false;
    }

    if(arr[x][y]==1){
        return false;
    }

    for (int row = 0; row<x; row++){
        if(arr[row][y]==1){
            return false;
        }
    }

    for(int col=y-1; col>0; col--){
        if(arr[x][col]==1){
            return false;
        }
    }

    int row = x;
    int col = y;
    while(row>=0 && col>=0){
        if (arr[row][col]==1){
            return false;
        }
        row--;
        col--;
    }

    row = x;
    col = y;
    while(row>=0 && col<n){
        if (arr[row][col]==1){
            return false;
        }
        row--;
        col++;
    }


    return true;
}


bool nQueen(int** arr, int x, int n){
    
    if(x>=n){
        return true;
    }

    for (int col=0; col<n; col++){
        if(isSafe2(arr, x, col, n)){
            arr[x][col]=1;
            if(nQueen(arr,x+1,n)){
                return true;
            }
            arr[x][col]=0;
        }
    }

    return false;
}


int main(){

    int n;
    cin>>n;

    int** arr = new int*[n];
    for (int i=0; i<n;i++){
        arr[i]=new int [n];
        for(int j=0; j<n; j++){
            arr[i][j]=0;
        }
    }

    if (nQueen(arr, 0, n)){
        for (int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    // for(int i=0; i<n; i++){
    //     for (int j=0; j<n; j++){
    //         cin>>arr[i][j];
    //     }
    // }

    // int** solutionArr = new int*[n];
    // for (int i=0; i<n;i++){
    //     solutionArr[i]=new int [n];
    //     for(int j=0; j<n; j++){
    //         solutionArr[i][j]=0;
    //     }
    // }

    // if (ratInMaze(arr,0,0,n,solutionArr)){
    //     for(int i=0; i<n; i++){
    //         for (int j=0; j<n; j++){
    //             cout<<solutionArr[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    // }
   
    // cout<<friendsPairing(5);
    // cout<<tilingWays(4);
    // cout<<possiblePath(5,5);
    // cout<<countpath(0,3);
    // permutations("ABC","");
    return 0;
}