class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		int t = tasks.size();
		vector<int>freq(26,0);
		for(int i=0;i<t;i++)
			freq[tasks[i]-'A']++;
		sort(freq.begin(),freq.end());
		int chunk = freq[25]-1;
		int idle = chunk*n;
		for(int i=24;i>-1;i--)  
			 idle -= min(chunk,freq[i]);
		return idle<0?t:t+idle;
	}
};
