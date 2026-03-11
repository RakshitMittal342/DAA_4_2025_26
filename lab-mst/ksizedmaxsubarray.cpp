class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> maxm(arr.size()-k+1);
        int m=0;
        int maxi=-1;;
        int i;
        int g=0;
        int b=0;
        for(int j=0;j<arr.size()-k+1;j++){
              if(maxi>=j && m>arr[j+k-1]){}
              else{
               m=0;
            for(i=j;i<j+k;i++){
                 if(arr[i]>m){ 
                    m=arr[i];
                    maxi=i;
                 }
                 
        }
              }
            maxm[g]=m;
            g++;

            
        }
     
        return maxm;
        
        
        
    }
};
