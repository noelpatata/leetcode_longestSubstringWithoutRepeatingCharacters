#include <iostream>

int contains(const std::string arr, int size, char target){
    for(int i = 0; i<size; i++){
        if(arr[i] == target){
           return i; 
        }
    }
    return -1;
}

int lengthOfLongestSubstring(std::string s) {
    if(s.length() > 5000 || s.length() < 1 ) { return 0;};
    
    int stringLength = s.length();
    std::string currString;
    std:: string maxString;

    for(int i = 0; i < stringLength; i++){

        currString += s[i];

        if(contains(currString, stringLength, s[i+1]) >= 0){
            if(currString.length() > maxString.length()){
                maxString = currString;
            }
            
            i = contains(currString, stringLength, s[i+1])+1;
            currString = "";
        }
        

    }

    if(currString.length() > maxString.length()){ maxString = currString; }

    return maxString.length() == 0 ? 1 : maxString.length();
}


int main() {
    std::string arr [4] = {"abcabcbb"};
    for(int i = 0; i < 4; i++){
        std::string input = arr[i];
        if(input.length() <= 0){ continue; }

        int result = lengthOfLongestSubstring(input);
        std::cout << "Length of input: " << input.length() << std::endl;
        std::cout << "Length of the longest substring without repeating characters: " << result << std::endl;
    }
    
    return 0;
}