class Solution {
public:
    bool isValid(string s) {
        
            //creating the stack of characters using STL
            stack<char> stack;
      //this loop will run till stack's capacity of size and it will push the opening paranthesis into the stack untill it encounters the closing paranthesis
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                stack.push(s[i]);
                continue;
            }
            
          //whenever the stack is not empty and stack's top is not opening paranthesis matching with the closing paranthesis , it will return the false value otherwise it will pop the top element
            if(!stack.empty())
            {
                if(s[i]==')') 
                    if(stack.top()!='(')
                    return false;
                    else
                        stack.pop();
                
                 if(s[i]=='}') 
                    if(stack.top()!='{')
                    return false;
                    else
                        stack.pop();
                
                 if(s[i]==']') 
                    if(stack.top()!='[')
                    return false;
                    else
                        stack.pop();
            }
          //it will check that if stack is empty and the character in the stack is closing paranthesis then it will return the false
            else if(stack.empty() && (s[i]==')' || s[i]=='}' || s[i]==']'))
                return false;
        }
      
      //after completion of our requisite, it will check the emptyness of stack
        if(stack.empty())
        return true;
        else
            return false;
    }
};
