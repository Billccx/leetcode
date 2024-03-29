class Solution {
    public  boolean validTree(int n, int[][] edges) {
        //数组p用来存储每个节点的祖宗
        int[] p = new int[n];
        //初始化，每个节点的祖宗初始化为它自己
        for(int i =0; i < n; i++){
            p[i] = i;
        }
        //集合的合并操作
        for(int j = 0; j < edges.length;j++){
            //遍历的过程，如果发现有环，则直接退出
            if(find(edges[j][0],p) == find(edges[j][1],p)){
                return false;
            }else{
                //否则合并两个集合
                union(edges[j][0],edges[j][1],p);
            }
        }
        //用来存储连通分量的个数
        int c = 0;
        for(int i = 0; i < n; i++){
            //根节点（连通分量）的个数
            if(p[i] == i){
                c++;
            }
        }
        //判断是否只有一个根节点
        return c == 1;
    }
    //两个集合的合并操作
    void union(int x,int y,int[] p){
        //如果两个节点的祖宗不相等，则将两个集合合并
        int fx = find(x,p), fy = find(y,p);
        if(fx != fy) p[fx] = fy;
    }
    //查找一个节点的祖宗节点
    int find(int x,int[] p){
        //如果当前节点的祖宗为它自己本身，则为根节点，否则继续往上递归
        if(p[x] != x) p[x] = find(p[x],p); 
        return p[x];
    }
}

/*
在执行合并操作时，将更小的树连接到更大的树上，这样的优化方式就称为“按秩合并”
在执行查找的过程中，扁平化树的结构，这样的优化方式称为“路径压缩”
*/
