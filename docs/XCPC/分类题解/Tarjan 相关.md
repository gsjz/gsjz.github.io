

Tarjan 的关键
构建一个无向连通图的dfs树是一个竭泽而渔的过程。
一个结点他们直接儿子对应的子树之间，有天然的不连通性。子树内部则有天然的连通性，问题是怎么跑到子树外面。
如果连到一个没见过的点，实际上由于dfs的性质，就被子树吸收了，成为了子树的一部分；如果连到一个见过的点，那它的信息大概率被处理过了，即子树内部的点或者祖先。
总的来说思路就是根据上述性质把边分成：一个自己指定的 dfs 搜索树上的搜索边，以及返祖边。


[Problem - F - Codeforces](https://codeforces.com/gym/105657/problem/F)

tarjan 求 scc。