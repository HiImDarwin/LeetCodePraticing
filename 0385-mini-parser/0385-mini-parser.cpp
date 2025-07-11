/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty()) return NestedInteger();
        if (s[0] != '[') return NestedInteger(stoi(s));

        int index = 1;
        NestedInteger result;
        while(index<s.length()-1) {
            
            if(s[index] == ',') {
                index++;
            } else if(s[index] == '[') {
                int start = index;
                int depth = 0;
                do {
                    if(s[index] == '[') depth++;
                    else if(s[index] == ']') depth--;
                    index++;
                } while(index<s.size() && depth >0);
                result.add(deserialize(s.substr(start, index - start)));
            } else {
                int start =index;
                while(index<s.size() && (isdigit(s[index]) || s[index]=='-')) {
                    index++;
                }
                int num = stoi(s.substr(start, index - start));
                result.add(NestedInteger(num));
            }
        }
        return result;
    }
};

