int ceil(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        
        if(arr[mid] == x)
        {
            return arr[mid];
        }
        else if(arr[mid] > x)
        {   
            ans = arr[mid];
            high = mid - 1;
        }
        else 
        {
            low = mid + 1;
        }
    }
    
    return ans;
}
 
