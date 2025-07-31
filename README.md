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
### Code explanation
Then the for loop:
```cpp
for (int end = 0; end < s.length(); ++end) { }
```
This iterates over the string length. Inside, there are 3 simple operations:
``` cpp
start = std::max(start, lastIndex[s[end]]);
maxLen = std::max(maxLen, end - start + 1);
lastIndex[s[end]] = end + 1;
```
First `start = std::max(start, lastIndex[s[end]]);`,
this code justs assigns the `start` to either the previous `start` value or the stored index in `lastIndex`.
This line is a bit curious for me since `lastIndex[s[end]]` uses a char to find the index where it has been read. This means that instead of using a normal index like `i` or `end` in this case, we are using the numeric value of the `char` type. Basically we are using the ASCII code (ex: 'A' => 65) to look into the lastIndex array, to find out if we have already read the current character, if so, `start` will equal to its index.

Following up, we have `maxLen = std::max(maxLen, end - start + 1);`,
this snippet also compares and gets the max value of the two given parameters. In this case, we are comparing `maxLen` with `end - start + 1` which basically means the offset between start and the current character thats being read. Lets say we are reading the second character in the `abca` string, `end` therefore equals 1 and `start` equals 0 since we haven't found yet an already read character in `lastIndex`, that leads us to 1 - 0 + 1, which tells us the current length of the string we are reading from `a` to `b` which is 2. And that will be our `maxLenp`.

The most simple yet not least important line is the following one:
`lastIndex[s[end]] = end + 1;`.
Which just stores the character we just read. The reason why we sum 1 is because the array is initialised with 0's, non read values will remain 0 while read values will store its index. So if we read the first value its index will be 0, but we can't store that, because we won't be able to dintinguish if the first value was ever read or it wasn't initialised.

### Workflow
Understanding the previous section we can simplify the code workflow as following:
- Store ASCII code of read characters in array
- Look for the ASCII code in the array, if its found, we'll read all characters after the found one to the current character we are reading.
- Compare currently stored maxLength with the string we read in the current iteration.
