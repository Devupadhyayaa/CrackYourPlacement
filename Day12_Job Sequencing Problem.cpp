//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
vector<int> JobScheduling(Job arr[], int n) 
    { 
        int maxDead=0;
        if(n==1) return {1,arr[0].profit};
        sort(arr,arr+n,[&](Job a,Job b){
            maxDead=max({maxDead,a.dead,b.dead});
            return a.profit>b.profit;
        });
        vector<int> jobs(maxDead+1,-1);
        int maxProfit=0;
        int numOfjobs=0;
        for(int i=0;i<n;i++){
            if(jobs[arr[i].dead]==-1){
                numOfjobs++;
                maxProfit+=arr[i].profit;
                jobs[arr[i].dead]=arr[i].dead-1;
            }
            else{
                int j=jobs[arr[i].dead];
                while(j>0 && jobs[j]!=-1){
                    j=jobs[j];
                }
                if(j){
                numOfjobs++;
                maxProfit+=arr[i].profit;
                jobs[j]=j-1;;
                jobs[arr[i].dead]=j-1;
                }
            }
        }
        return {numOfjobs,maxProfit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
