#include <iostream>

int contains(const std::string arr, char target){
    for(int i = 0; i<arr.length(); i++){
        if(arr[i] == target){
           return i; 
        }
    }
    return -1;
}
std::string substring(const std::string arr, int j){
    std::string subString = "";
    for(int i = 0; i<arr.length(); i++){
        if(i >= j) {
            subString += arr[i];
        }
    }
    return subString;
}

int lengthOfLongestSubstring(const std::string& s) {
    int lastIndex[128] = {0};
    int maxLen = 0;
    int start = 0;

    for (int end = 0; end < s.length(); ++end) {
        std::cout << "s[end]: ";
        std::cout << s[end];
        std::cout << "\n";
        std::cout << "LastIndex: ";
        std::cout << lastIndex[s[end]];
        std::cout << "\n";

        start = std::max(start, lastIndex[s[end]]);
        maxLen = std::max(maxLen, end - start + 1);
        lastIndex[s[end]] = end + 1;
    }

    return maxLen;
}


int main() {
    std::string arr [4] = {"au", "abcabcbb"};
    for(int i = 0; i < 4; i++){
        std::string input = arr[i];
        if(input.length() <= 0){ continue; }

        int result = lengthOfLongestSubstring(input);
        std::cout << "Length of input: " << input.length() << std::endl;
        std::cout << "Length of the longest substring without repeating characters: " << result << std::endl;
    }

    
    return 0;
}