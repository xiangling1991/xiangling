/**********************************************
	并查集算法，简称Union-Find
************************************************/

int pre[1000 ];  		//前导点集

int find(int x)                                                                                                         

{ 

    int r=x;											//查找根节点

    while ( pre[r ] != r )                             //返回根节点 r
          r=pre[r ];
    int i=x , j ;

    while( i != r )                                    //路径压缩

    {
         j = pre[ i ]; // 在改变上级之前用临时变量  j  记录下他的值 

         pre[ i ]= r ; //把上级改为根节点

         i=j;

    }

    return r ;

}

 

 

void join(int x,int y)   
//判断x y是否连通，
{

    int fx=find(x),fy=find(y);

    if(fx!=fy)					//如果已经连通，就不用管了 

        pre[fx]=fy;				//如果不连通，就把它们所在的连通分支合并起

}
