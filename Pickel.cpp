#include <bits/stdc++.h>
#include <climits>

using namespace std;

void uppercase(string str){
    for (int i = 0; i < str.size(); i++){
        if (str[i]>='a' && str[i]<='z'){
            str[i] -=32; //+=for lower case
                
        }
        cout << str[i];
    }
}

int getBit(int n, int pos){
    return (n & (1<<pos))!=0;
}

int setBit(int n, int pos){
    return (n|(1<<pos));
}

int clearBit(int n, int pos){
    return (n & (~(1<<pos)));
}

int toogleBit(int n, int pos){
    return (n ^ (1<<pos));
}

int updateBit(int n, int pos, int value){
    int mask = ~(1<<pos);
    n = n & mask;
    return (n | (value<<pos));
}

int numberofones(int n){
    int count = 0;
    while (n){
        n = n & (n-1);
        count++;
    }
    return count;
}

bool ispowerof2(int n){
    return (n & (n-1))==0;     
}

void subsets(int arr[], int n){
    for (int i=0; i<(1<<n); i++){
        cout<<"{";
        for (int j=0; j<n; j++){
            if (i & (1<<j)){
                cout<<arr[j];
            }
        }cout<<"}"<<endl;
    }
}

int uniquenoarr(int arr[], int n){
    int uniq=0;
    for (int i=0; i<n; i++){
        uniq ^= arr[i];
    }
    return uniq;
}

void doubleNumber(int arr[], int n){
    int twoxor=0;
    for (int i=0; i<n; i++){
        twoxor ^=arr[i];
    }
    int xor2 = twoxor;
    int pos=0;
    int p = 0;
    while (p==0){
        p = getBit(xor2, pos);
        pos++;
    }
    int oneno=0;
    for (int i=0; i<n; i++){
        if(getBit(arr[i], (pos-1))==1){
            oneno ^= arr[i];
        }
    }
    cout<<oneno<<endl;
    int twono;
    twono = oneno ^ twoxor;
    cout<<twono;

}

int thrice(int arr[], int n){
    int ar64[64];
    int result = 0;
    for (int i=0; i<64; i++){
        int count=0;
        for (int j=0; j<n; j++){
            if (getBit(arr[j], i)){
                count++;
                
            }
        }
        if((count%3) != 0){
            result=setBit(result, i);
        }
    }
    int bit;
    for (int i=0; i<64; i++){
        
    }
    return result;
}

void primeSOE(int n){
    int soe[100] = {0};
    for (int i=2; i<n; i++){
        if(soe[i]==0){
            for (int j=i*i; j<n; j+=i){
                soe[j]=1;
            }
        }
    }

    for (int i=2; i<n; i++){
        if (soe[i]==0){
            cout<<i<<" ";
        }
    }
}

void spf(int n){
    int seive[100]={1};
    for(int i=2; i<=n; i++){
        seive[i]=i;
    }
    for (int i=2; i<=n; i++){
        if(seive[i]==i){
            for (int j=i*i; j<=n; j+=i){
                if(seive[j]==j){
                    seive[j]=i;
                }
            }
        }
    } 
    while(n!=1){
        cout<<seive[n]<<" ";
        n=n/seive[n];
    }
    
}

// Find the number of numbers in the interval [1,n] which are divisible by a or b.
int ine(int n, int a, int b){
    int c1 = n/a;
    int c2 = n/b;
    int c3 = n/(a*b);

    return (c1+c2-c3);
}

int gcd(int a, int b){

    while (b!=0){
        int rem = a%b;
        a=b;
        b=rem;
    }
    return a;
}


bool prime(int n){
    for (int i=2;i<n;i++){
        if(n%i==0){
            return false;
            break;
        }
    }
    return true;
}

void fibonaci(int n){
    int t1=0;
    int t2=1;
    int t3;
    for (int i=1;i<=n;i++){
        cout<<t1<<"\n";
        t3=t1+t2;
        t1=t2;
        t2=t3;
    }
    return;
}

int factorial(int n){
    int i;
    int j=1;
    for (i=1;i<=n;i++){
       j=j*i;
    }
    return j;
}

int bicoe(int i , int j){
    int k;
    k=factorial(i)/(factorial(j)*factorial(i-j));
    return k;
}

int sumn(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    return sum;
}

void triplet(int i, int j, int k){
    int a=max(i,max(j,k));
    int b,c;
    if(a==i){
        b=j;
        c=k;
    }
    else if(a==j){
        b=i;
        c=k;
    }
    else{
        b=i;
        c=j;
    }

    if(a*a==(b*b)+(c*c)){
        cout<<"Pythagoras triplet";
    }
    else{
        cout<<"Not Pythagoras triplet";
    }
    return;
}

int reverseno(int n){
    
    int ans=0;
    
    while (n>0){

        int i= n%10;
        ans = (ans*10)+i;
        n/=10;
    
    }
    return ans;
}

int binarytodecimal(int n){
    int i,j,k;
    j=1;
    k=0;
    while(n>0){
        i=n%10;
        k+=j*i;
        j=(j*2);
        n=n/10;

    }
    return k;
}

int octaltodecimal(int n){
    int i,j,k;
    j=1;
    k=0;
    while(n>0){
        i=n%10;
        k+=j*i;
        j=(j*8);
        n=n/10;

    }
    return k;
}

int hexadecimaltodecimal(string n){
    int ans=0;
    int x=1;
    int s=n.size();
    for (int i=s-1;i>=0;i--){
        if(n[i]>='0' && n[i]<='9'){
            ans+=x*(n[i]-'0');
        
        }
        else if(n[i]>='A' && n[i]<='F'){
            ans+=x*(n[i]-'A'+10);
        }
        x*=16;
    }
    return ans;
}



int decimaltobinary(int n){
    int i,j,k;
    int ans=0;
    i=1;
    while(n>0){
        
        ans+=(n%2)*i;
        n/=2;
        i*=10;
    }
    
    return ans;
}



int decimaltooctal(int n){
   int i,j,k;
    int ans=0;
    i=1;
    while(n>0){
        
        ans+=(n%8)*i;
        n/=8;
        i*=10;
    }
    
    return ans;
}

string decimaltohexadecimal(int n){
    int x,j,k;
    string ans="";
    x=1;
    while (x<=n){
        x*=16;
    }
    x/=16;

    while (n>0){
        int lastdigit=n/x;
        n-=lastdigit*x;
        x/=16;
        if(lastdigit<=9){
            ans=ans+to_string(lastdigit);
        }
        else{
            char c='A'+ lastdigit-10;
            ans.push_back(c);
        }
    }
    
    
    return ans;
}

// int addbinary(int i, int j){
//     int ans=0;
//     int ten=1;
//     int carry=0;
//     int a,b;
//     while (i>0 && j>0){
        
//         if(i>0){
//             a=i%10;
//         }
//         if(j>0){
//             b=j%10;
//         }
//         // a=i%10;
//         // b=j%10;

//         if (a+b+carry==1){
//             ans=ans+(1*ten);
//             carry=0;
//         }
//         else if (a+b+carry==2){
//             ans=ans+(0*ten);
//             carry=1;
//         }
//         else if (a+b+carry==3){
//             ans=ans+(1*ten);
//             carry=1;
//         }
//         else if (a+b+carry==0){
//             ans=ans+(0*ten);
//             carry=0;
//         }
//         if(a==0 && b==0 && carry==1){
//         ans=ans+(1*ten);
//         carry=0;
//         }
        
//         i=i/10;
//         j=j/10;
//         ten*=10;
//     }
    
//     return ans;
// }

int addbinary(int a , int b){
    int carry=0;
    int ans=0;
    int i=1;
    while(a>0 && b>0){
        if (a%10==0 && b%10==0){
            if(carry==1){
                ans=ans+1*i;
                carry=0;
            }
            else{
                ans=ans;
                carry=0;
            }
        }
        else if ((a%10==1 && b%10==0) || (a%10==0 && b%10==1)){
            if(carry==1){
                ans=ans;
                carry=1;
            }
            else{
                ans=ans+1*i;
                carry=0;
            }
        }
        else if (a%10==1 && b%10==1){
            if(carry==1){
                ans=ans+1*i;
                carry=1;
            }
            else{
                ans=ans;
                carry=1;
            }
        }
        a/=10;
        b/=10;
        i*=10;
    }
    while(a>0){
        if(a%10==0){
            if(carry==1){
                ans=ans+i*1;
                carry=0;
            }
            else{
                ans=ans;
                carry=0;
            }
        }
        else if(a%10==1){
            if(carry==1){
                ans=ans;
                carry=1;
            }
            else{
                ans=ans+i;
                carry=0;
            }
        }
        a/=10;
        i*=10;
    }
    while(b>0){
        if(b%10==0){
            if(carry==1){
                ans=ans+i;
                carry=0;
            }
            else{
                ans=ans;
                carry=0;
            }
        }
        else if(b%10==1){
            if(carry==1){
                ans=ans;
                carry=1;
            }
            else{
                ans=ans+i;
                carry=0;
            }
        }
        b/=10;
        i*=10;
    }

    if (carry==1){
        ans=ans+i;
        carry=0;
    }


    //reverseno(ans);
    return ans;
}

int searcharray(int array[], int n, int key){
    for (int i=0;i<n;i++){
        if(array[i]==key){
            return i;
        }
    }
    return -1;
}

int binarysearch(int array[], int n, int key){
    int s=0;
    int e=n;
    while (s<=e){
        int mid=(s+e)/2;
        if (array[mid]==key){
            return mid;
        }
        else if (array[mid]<key){
            s=mid+1;
        }
        else if (array[mid]>key){
            e=mid-1;
        }
    }
    return -1;
}

void selectionsort(int arr[], int n){
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if(arr[j]<arr[i]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void bubblesort(int arr[], int n){
    for (int j=0; j<n-1; j++){
        for (int i=0; i<n; i++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i];
    }
}

void insertionsort(int array[], int n){
    for (int i=1; i<n; i++){
        int current=array[i];
        int j=i-1;
        while (array[j]>current && j>=0){
            array[j+1]=array[j];
            
            j--;
        }
        array[j+1]=current;
    }
    for (int i=0; i<n; i++){
        cout<<array[i];
    }
}

void maxtilln(int arr[], int n){
    int mx=-99999;
    for(int i=0; i<n; i++){
        mx = max(arr[i],mx);
        cout<<mx<<endl;
    }    
}

void sumofsubarrays(int arr[],int n){
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum=sum+arr[j];
            cout<<sum<<endl;
        }
    }
}

int longestarisubarr(int arr[],int n){
    int cd = arr[1]-arr[0];
    int len;
    int mx=-99999;
    for(int i=2; i<n; i++){
        len=2;
        while(i<n){
            if(arr[i]-arr[i-1]==cd){
                len++;
                mx=max(mx,len);
                i++;
            }
            else{
                break;
            }
        }       
        cd = arr[i]-arr[i-1];   
    }
    return mx;
}

void recordbreaker(int arr[],int n){
    int mx=arr[0];
    if (n==1){
        cout<<1;
    }
    for(int i=0; i<n; i++){
        
        if (arr[i]>mx){
            cout<<i+1<<endl;
        }
        mx = max(arr[i],mx);
        
    }
}

void smallmissingno(int arr[], int n){
    int N=10e6+2;
    bool check[N];
    for(int i=0; i<N; i++){
        check[i]=0;
    }

    for(int i=0; i<n; i++){
        if (arr[i]>0){
            int a=arr[i];
            check[a]=1;
        }
    }
    int ans=-1;
    int j;
    for(j=1; j<N; j++){
        if(check[j]==0){
            ans=j;
            break;
        }
    }
    cout<<ans+1;
}

void repeatedno(int arr[], int n){
    

    const int p=100;
    int a[n];
    for (int i=0; i<p; i++){
        a[i]=-1;
    }
    int ans=p;
    for(int i=0; i<n; i++){
        if(a[arr[i]] != -1){
            a[arr[i]]=i;
        }
        else{
            ans=min(ans,a[arr[i]]);
            
        }
        
    }

    if(ans==1000){
        cout<<"-1";
    }
    else{
        cout<<ans<<endl;
    }
}

void sumofarrsearch(int arr[], int n){
    int st=0, en=0;
    int sum;
    cin>>sum;
    int currsum=0;

    while(en<n){
        if(currsum<sum){
            en++;
            currsum=currsum+arr[en];
            
        }
        else if(currsum>sum){
            st++;
            currsum=currsum-arr[st];
            
        }
        else if(currsum==sum){
            cout<<st+1<<" "<<en;
            break;
        }
    }
    if(en=n){
        cout<<"-1";
    }
}

int kedanalgo(int arr[], int n){
    int maximumsum = INT_MIN;
    int sum=0;
    for (int i = 0 ; i < n ; i++){
        sum += arr[i];
        
        if(sum < 0){
            sum = 0;
        }
        maximumsum = max(maximumsum, sum);
    }
    return maximumsum;
}

void circlearray(int arr[], int n){
    int nonwraped=kedanalgo(arr,n);
    int a[n];
    int totalsum=0;
    for (int i=0;i<n;i++){
        totalsum+=arr[i];
        a[i]=-arr[i];
    }
    
    int wraped = totalsum + kedanalgo(a,n);

    cout<<max(wraped , nonwraped);

}

void sumpair(int arr; int n; int sum){
    
    int st=0;
    int en=n-1;

    while(st<n){
        if (arr[st]+arr[en] < sum){
            st++;
        }
        else if (arr[st]+arr[en] > sum){
            en--;
        }
        else if (arr[st]+arr[en] == sum){
            cout<<st<<" "<<en;
            break;
        }
    }
}

int main(){
    
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    
    cout<<"hii";

    

    




















    /*int sum;
    cin>>sum;
    sumpair(arr,n,sum);/*
    // circlearray(arr, n);
    // cout<<kedanalgo(arr, n);
    // sumofarrsearch(arr[],n);
    // maxtilln(arr,n);
    // sumofsubarrays(arr,n);
    // cout<<longestarisubarr(arr,n);
    // recordbreaker(arr,n);
    // smallmissingno(arr,n);





      // matrix addition
    // int n1,n2,n3;
    // cin>>n1>>n2>>n3;
    // int m1[n1][n2];
    // int m2[n2][n3];
    // int ans[n1][n3];

    // for (int i=0; i<n1; i++){
    //     for (int j=0; j<n2; j++){
    //         cin>>m1[i][j];
    //     }
    // }
    // for (int i=0; i<n2; i++){
    //     for (int j=0; j<n3; j++){
    //         cin>>m2[i][j];
    //     }
    // }
    // for (int i=0; i<n1; i++){
    //     for (int j=0; j<n3; j++){
    //         ans[i][j]=0;
    //     }
    // }
    
    // for(int i=0; i<n1; i++){
    //     for(int j=0; j<n3; j++){
    //         for(int k=0; k<n2; k++){
    //             ans[i][j] += m1[i][k] * m2[k][j];
    //         }
    //     }
    // }
    
    // for (int i=0; i<n3; i++){
    //     for (int j=0; j<n3; j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}