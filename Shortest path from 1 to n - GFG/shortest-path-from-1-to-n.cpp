//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minimumStep(int n){
        int count = 0;
        while(n!= 0){
            if(n%3){
                n-=1;
            }
            else{
                n /= 3;
            }
            count++;
        }
        return count-1;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 


// } Driver Code Ends