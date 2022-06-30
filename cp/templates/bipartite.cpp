// is it possible to convert graph into 2 sets such that there is no edge between nodes in a given set

void dfs(int i, int color, vector<vector<int>> & graph, vector<int> & colors, int & res)
{
        colors[i] = color;
        for(auto & val:graph[i]){
                if(colors[val] == -1){
                        dfs(val,not color,graph,colors,res);
                }else{
                        res = res and (color == not colors[val]);
                }
        }
}

