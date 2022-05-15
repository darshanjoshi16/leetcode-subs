class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

	int n=grid.size();

	//handling edge cases
	if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
	if(n==1) return 1;

	//queue to perform BFS
	queue<pair<int,int>> q;

	//direction array to check adjacent elements
	int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

	//initialise distance zero
	int dist=0;

	//pushing (0,0) element in queue
	q.push({0,0});

	//mark (0,0) element visited
	grid[0][0]=1;

	while(!q.empty()){

		int size=q.size();

		//adding current element to answer
		dist++;

		while(size--){
			auto front=q.front();
			q.pop();
			for(auto d:dir){
				int adI=front.first+d[0]; //adjacentI 
				int adJ=front.second+d[1]; //adjacentJ

				//check is adI or adJ is out of bound or not
				if(adI<0 || adJ<0 || adI>=n || adJ>=n) continue;

				//check if adjacent element is already visited or not
				if(grid[adI][adJ]==1) continue;

				//mark adjacent element visited
				grid[adI][adJ]=1;

				//if adjacent element is last/destination element then return (dist+1). Add '+1' because to include last element in answer
				if(adI==n-1 && adJ==n-1) return dist+1;                   
				q.push({adI,adJ});

			}
		}
	}
	//if we have not reach the last/destination element , return -1
	return -1;
}
};
