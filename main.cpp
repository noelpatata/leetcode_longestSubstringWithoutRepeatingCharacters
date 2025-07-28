#include <iostream>
bool contains(const char arr[], int size, char target){
    for(int i = 0; i<size; i++){
        if(arr[i] == target){
           return true; 
        }
    }
    return false;
}
int lengthOfLongestSubstring(std::string s) {
    if(s.length() > 5000 || s.length() < 1 ) { return 0;};

    int maxLength = 0;
    int currMaxLength = 0;
    int stringLength = s.length();
    int maxValues[stringLength];
    char values [stringLength];
    int maxValuesArrayIndex = 0;
     
    for(int i = 0; i<stringLength; i++){
        if(s[i] == s[i+1] ||
            contains(values, stringLength, s[i]) ||
            i == s.length() - 1){

            if(maxLength < currMaxLength){
                maxLength = currMaxLength;
            }

            maxValues[maxValuesArrayIndex] = currMaxLength;
            
            currMaxLength = 0;
            maxValuesArrayIndex++;
            continue;
        }

        values[i] = s[i];
        currMaxLength++;
        
    }

    return maxLength == 0 ? 1 : maxLength;
}


int main() {
    std::string arr [4] = {"au", "abcabcbb", "bbbbb", "pwwkew"};
    for(int i = 0; i < size(arr); i++){
        std::string input = arr[i];
        int result = lengthOfLongestSubstring(input);
        std::cout << "Length of input: " << input.length() << std::endl;
        std::cout << "Length of the longest substring without repeating characters: " << result << std::endl;
    }
    
    return 0;
}