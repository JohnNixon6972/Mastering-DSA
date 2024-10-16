class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> res;

        string result = "";
        int idx = 0;

        while(idx < s.length()){
            if(isdigit(s[idx])){
                int count = 0;

                while(isdigit(s[idx])){
                    count = count * 10 + (s[idx] - '0'); 
                    idx++;
                }

                countStack.push(count);
            }
            else if (s[idx] == '['){
                res.push(result);
                result = "";
                idx++;
            }else if (s[idx] == ']'){
                string temp = res.top();
                res.pop();

                int repeat = countStack.top();
                countStack.pop();

                while(repeat--){
                    temp += result;
                }
                result = temp;
                idx++;
            }else{
                result += s[idx];
                idx++;
            }
        }
        return result;
    }

};