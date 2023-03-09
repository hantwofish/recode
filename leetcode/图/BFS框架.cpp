
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>

using namespace std;

// 计算从起点 start 到终点 target 的最近距离
int BFS(Node start, Node target) 
{
    queue<Node> q; //队列
    Set<Node>visited; // 记录位置是否被访问过
	int step ; // 记录步数
	
	q.push(start);
	visited.add(start);
	
	while(!q.empty())
	{
		int qu_size = q.size();
		for(int i = 0 ; i< qu_size ; i++)
		{
			Node cur = q.top(); // 取出队列首元素
			q.pop();  // 删除队列首元素
			
			// 判断当前元素是否到达终点
			if(cur is target)
				return step;
			/* 将当前结点相邻结点加入队列    */
			for( Node x : cur.adj() )
			{
				if( x not is visited)
				{
					q.push(x);
					visited.add(x);
				}
					
			}
		
		}
		
		/* 更新步数在这里   */
		step++;
	}
}