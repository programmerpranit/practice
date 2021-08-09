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


//Sodoku solver

bool isEmpty(int**arr){
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if(arr[i][j]==0){
                return false;
            }
        }
    }
    return true;
}

bool isValid(int** arr, int x, int y, int num){

    for(int i=0; i<10; i++){ //vertical search
        if (arr[i][y]==num){
            return false;
        }
    }
    for(int i=0; i<10; i++){  //Horizontal Search
        if (arr[x][i]==num){
            return false;
        }
    }
    //square search
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if(arr[i+(x-(x%3))][j+(y-(y%3))]==num){
                return false;
            }
        }
    }

    return true;
}

bool sodokuSolver(int** arr, int x ,int y ){
    if(isEmpty(arr)){
        cout<<"isEmpty true";
        return true;
    }

    for(int row=x; row<9; row++){
        for(int col=y; col<9; col++){
            cout<<row<<col;
        if(arr[row][col]==0){

        

        for (int i=1; i<10; i++){
            if(isValid(arr,row,col,i)){
                arr[row][col]=i;
                if(sodokuSolver(arr, row, col)){
                    return true;
                }
                arr[row][col]=0;
                return false;
            }
        }
        }

        }
    }
    
    return false;
}


//Merge Sort

void mergearr(int arr[], int l, int mid, int r){

    int n1 = mid-l+1;
    int n2 = r-mid;

    int a[n1];
    int b[n2];

    for (int i=0; i<n1; i++){
        a[i]= arr[l+i];
    }
    for (int i=0; i<n2; i++){
        b[i]= arr[mid+i+1];
    }

    int i=0;
    int j=0;
    int k=l;
    while (i<n1 && j<n2){
        if(a[i]<b[i]){
            arr[k]=a[i];
            i++;
        }
        else{
            arr[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=a[i];
        k++; i++;
    }
    while(j<n2){
        arr[k]=b[j];
        k++; j++;
    }


}

void mergeSort(int arr[], int s, int e){
    
    if(s<e){
        int mid=(s+e)/2;
        
        mergeSort(arr, s, mid);
        mergeSort(arr, mid+1, e);

        mergearr(arr, s, mid, e);
    }


}


int main(){

    int arr[] ={5,6,8,2,4,1};
    mergeSort(arr, 0, 5);
    for (int i=0; i<6; i++){
        cout<<arr[i]<<" ";
    }
    // cout<<friendsPairing(5);
    // cout<<tilingWays(4);
    // cout<<possiblePath(5,5);
    // cout<<countpath(0,3);
    // permutations("ABC","");
    return 0;
}