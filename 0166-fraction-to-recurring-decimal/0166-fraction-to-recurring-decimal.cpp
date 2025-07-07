class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        string res;
        long divisor = abs(1L*numerator);
        long divident = abs(1L*denominator);
        long quotient;

        if((numerator < 0)^(denominator < 0)) res += "-";
        
        if(divisor >= divident) {
          quotient = divisor/divident;
          divisor %= divident;
          res += to_string(quotient);
        } else {
          res += "0";
        }

        if(divisor == 0) return res;

        res += ".";

        unordered_map<int,int> mp;
        while(divisor != 0) {
          if(mp.count(divisor)) {
            res.insert(mp[divisor],"(");
            res += ")";
            break;
          }
          mp[divisor] = res.size();
          
          divisor *= 10;
          quotient = divisor/divident;
          divisor %= divident;
          res += to_string(quotient);
        }

        return res;
    }
};


/*
interger part




fractional part
for repeated part
we can store the remain 
if the same remain occour
then it repeat

corner case

denominator = 0
denominator <0 or numerator <0
denominator num * 10 overflow condition



*/