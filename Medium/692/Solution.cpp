class Solution {
public:
	static bool compS(pair<int,string> a, pair<int,string> b)
	{
		if(a.first == b.first)
			return a.second < b.second;
		return a.first > b.first;
	}
	vector<string> topKFrequent(vector<string>& words, int k) {
		map<string,int> mp;
		vector<string>ans;
		vector<pair<int,string>> str;
		for(auto i:words)     mp[i]++;
		for(auto i:mp)  str.push_back({i.second,i.first});
		sort(str.begin(), str.end(), compS);
		for(auto i:str)
		{
			if(!k--)  return ans;
			ans.push_back(i.second);
		}
		return ans;
	}
};
