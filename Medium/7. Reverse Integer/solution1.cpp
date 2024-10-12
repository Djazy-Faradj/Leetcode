/*
Author: Djazy Faradj
Problem: 7. Reverse Integer
Description: 
 - Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
 - Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Note: Not an optimal solution, this is just a brute force attempt. Solution2 will cover an optimal solution.
Time Complexity: ?
Space Complexity: ?

Relevent Topics: Math
*/

class Solution {
public:
    bool OverIntLimit(string reversedNum)
    {
        string intLimit;
        std::cout << "reversedNum: " << reversedNum << std::endl;
        
        switch (reversedNum[0])
        {
            case '-':
                if (reversedNum.length() < 11) return false;//If int is not in the billions, already return !OverIntLimit
                intLimit = "-2147483648"; // Negative signed int limit
                break;
            default:
                if (reversedNum.length() < 10) return false;//If int is not in the billions, already return !OverIntLimit
                intLimit = "2147483647"; // Positive signed int limit
                          //9646324351 ReversedInt
                break;
        }
        // Long if loop that checks each decimal place of the string int
        for (int i = 0; i < reversedNum.length(); i++)
        {
            if (reversedNum[i] == intLimit[i]) continue;
            if (reversedNum[i] < intLimit[i]) return false;
            if (reversedNum[i] > intLimit[i]) return true;
        }
        return false;
    }    
    int PowerRaise(int decPow)
    {
        int raisedInt = 1;
        for (int i = 0; i < decPow; i++)
        {
            raisedInt*=10;
        }
        return raisedInt;
    }
    int StringToInt(string num)
    {
        int decPow;
        int convertedInt = 0;
        switch(num[0])
        {
            case '-': // Check if negative
                decPow = num.length()-2;
                for (int i = 1; i < num.length(); i++, decPow--)
                {
                    convertedInt += (num[i] - '0')*PowerRaise(decPow);
                }
                return -convertedInt;
            default:
                decPow = num.length()-1;
                for (int i = 0; i < num.length(); i++, decPow--)
                {
                    convertedInt += (num[i] - '0')*PowerRaise(decPow);
                }
                return convertedInt;
        }
    }

    int reverse(int x) {
        string numString = to_string(x);
        string reversedString = "";
        int outputInt;

        switch (numString[0]){
        case '-': // FOR WHEN INTEGER IS NEGATIVE
            for (int i = numString.length()-1; i >= 0; i--) // Loop from end of number to beginning
            {
                reversedString += numString[i];
            }
            // Loop through reversedString, take the substring of the non 0 initial part.
            for (int j = 0; j < reversedString.length(); j++) 
            {
                if (reversedString[j] != '0') 
                {
                    reversedString = reversedString.substr(j, reversedString.length()-j-1);
                    break;
                }
            } 
            reversedString = '-' + reversedString;
            break;
        default: // WHEN INTEGER IS NOT NEGATIVE
            for (int i = numString.length()-1; i >= 0; i--) // Loop from end of number to beginning
            {
                reversedString += numString[i];
            }
            // Loop through reversedString, take the substring of the non 0 initial part.
            for (int j = 0; j < reversedString.length(); j++) 
            {
                if (reversedString[j] != '0') 
                {
                    reversedString = reversedString.substr(j, reversedString.length()-j);
                    break;
                }
            } 
            break;
        }
        OverIntLimit(reversedString) ? outputInt = 0 : outputInt = StringToInt(reversedString);
        return outputInt;
    }
};