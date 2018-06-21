/*
*程序作者：胡令 
*完成日期：2018/6/19 
*程序功能：数据结构(链表、栈、队列、树、图)结点类型定义. 
*/ 
#ifndef _NODE_
#define _NODE_
#define MAX_SIZE 100 
#define MAXNUM_VEX 20

typedef char DATA;

//链表结点类型声明 
typedef struct LinkNode{
	DATA data;				//结点数据域 
	struct LinkNode* next;	//指针域，指向下一结点 
}LinkNode,*LinkList;

//栈类型定义
typedef struct Stack{
	DATA Sta[MAX_SIZE];		//数组表示的栈 
	int top;				//栈顶指针 
}Stack; 

//队列类型定义
typedef struct Queue{
	DATA Que[MAX_SIZE];		//数组表示的队列 
	int pre;				//队头指针 
	int aft;				//队尾指针 
}Queue; 

//树结点类型定义
typedef struct Tree{
	DATA data;				//数据域 
	struct Tree* LChild;	//左子树 
	struct Tree* RChild;	//右子树 
	int LTag;
	int RTag; 
}Tree;

typedef struct Grap{
	int adj;			//1:邻接，0:不邻接 
	char Info[100];		//其他信息 
}Grap;


//邻接矩阵定义图类型 
typedef struct ArcNode{
	int adj;			//1:邻接，0:不邻接 
	char Info[100];		//其他信息 
}ArcNode;

typedef struct{
	int vextex[MAXNUM_VEX];		//顶点向量
	ArcNode arcs[MAXNUM_VEX][MAXNUM_VEX];		//邻接矩阵
	int vexnum,arcnum;					//图的顶点数和边数(弧数) 
}AdjMatrix; 


/***********邻接表定义图类型********/
//边表结点类型声明 
typedef struct Arc{
	DATA arc;					//边(弧) 
	struct Arc* nextArc;		//指针域，指向下一条边(弧) 
}Arc;

//表头结点类型声明 
typedef struct Vex{
	DATA vex;					//顶点 
	struct Arc* firstArc;		//指针域，指向第一条边(弧) 
}Vex; 
/************ end *****************/ 

#endif
