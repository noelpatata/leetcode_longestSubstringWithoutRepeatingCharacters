# Longest Substring Without Repeating Characters
This is a challenge from [LeetCode](https://leetode.com).
In this challenged i faced the following problem:
Develop a function for extracting the longest substring without repeating characters given an input string.
## Explanation
First I need to initialise an empty array (filled with 0's) with a size of 128 elements.
### Why a 128 sized array
Short answer: C++ uses ASCII to encode characters.
I know it is not that simple (I guess, I just learned this today).
The thing is that this is the best way to store the characters since the problem's description states that the string only includes english characters. This way I'll never read more than 128 different characters, therefore the array that stores the different characters can't be bigger than 128.
Then 
