class Solution {
public:
	string decodeString(string s) {
		stack<string> st;
		int n = s.size(), curr=0;
		string temp="";
		for(int i=0;i<n;i++)
		{
			if(s[i]>='0' && s[i]<='9')
			{    
				while(i<n && s[i]>='0' && s[i]<='9')    
					curr = curr*10 + (s[i++]-'0'); 
				i--;
			}
			else if(s[i] == '[')
			{
				st.push(temp);
				temp = "";
				st.push(to_string(curr));
				curr = 0;
			}
			else if(s[i] == ']')
			{
				int num = stoi(st.top());
				st.pop();
				string u,str = st.top();
				st.pop();
				while(num--)    u += temp;
				temp = str + u;
			}
			else    temp += s[i];
		}
		return temp;
	}
};
