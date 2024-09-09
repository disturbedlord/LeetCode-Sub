class Solution {
public:

    bool check(vector<int>& arr , int pos , int& n , vector<int>& visited){
        if(pos < 0 or pos >= n or visited[pos]) return false;
        //cout<<pos<<" ";
        if(arr[pos] == 0) return true;
        visited[pos] = 1;
        //FORWARD || BACKWARD
        return check(arr , pos + arr[pos] , n , visited) || check(arr , pos - arr[pos] , n , visited);
        
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> visited = vector<int>(n , 0);
        bool isReachable = false;
        isReachable = check(arr , start , n , visited);

        return isReachable;
    }
};