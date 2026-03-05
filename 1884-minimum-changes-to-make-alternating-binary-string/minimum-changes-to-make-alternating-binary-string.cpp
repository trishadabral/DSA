class Solution {
public:
    int minOperations(string s) {
        int n=s.length(),c=0,f=0;
        //here we will check for both pattern 01 and 10;
        // sol  have 2 possibility str starting with 10 could have min operation or str "01"
        // for 10 at every even index there should be 1;
        // for 01 at every even index there should be 0;
        //c count mismatch for str 10 as soln and f for 01;
        for(int i=0;i<n;i++){
           if(i%2==0){
               if(s[i]=='0')c++;//if  even idx ='0'  has mismatch in for str staring with 10
               else f++;
           }
           else{
             if(s[i]=='1')c++;//if  odd idx ='0'  has mismatch in for str staring with 10
               else f++;
           }
        }
        //return thr min. no. of mismatch
        return min(c,f);
    }
};