class Solution {
public:
    string interpret(string command) 
    {
        int i=0 , n=command.size();
        while(i<n){
            
            if(command[i] == '(' && command[i+1] == ')'){
                command.replace(i,2,"o");
                n-=1;
            }
            else if(command[i+1] == 'a' && command[i+2] == 'l'){
                command.replace(i,4,"al");
                n-=2;
            }
            i++;
        }
        return command;
    }
};
