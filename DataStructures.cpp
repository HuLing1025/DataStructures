/*
*程序作者：胡令 
*完成日期：2018/6/19--2018/6/21
*程序功能：数据结构(链表、栈、队列、树、图) 相关操作. 
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"node.h"
#define Error 0
#define OK 1

Tree *pre=NULL;
int visited[MAXNUM_VEX]; 

//***********链表*************// 

//建立链表数据 
void createLinkList(LinkList *H)	//使用二级指针接收头指针 
{	
	LinkNode *p,*s;
	DATA ch;
	(*H)=(LinkList)malloc(sizeof(LinkNode));
	(*H)->next=NULL;
	p=*H;
	printf("请输入链表数据：\n");
	ch=getchar();
	while(ch!='.')
	{
		s=(LinkNode*)malloc(sizeof(LinkNode));
		s->data=ch;
		s->next=p->next;
		p->next=s;
		p=p->next;
		ch=getchar();
	}
	getchar();
}

//输出链表数据
void showData(LinkList H)
{
	LinkNode* p;
	p=H->next;
	printf("链表的数据如下:\n");
	while(p)
	{
		printf("%c ",p->data);
		p=p->next;
	 } 
	printf("\n");
	getchar();
}
//链表操作菜单 
void menu_1()
{
	printf("1.加入新数据.\n");
	printf("2.删除数据.\n");
	printf("3.查找数据.\n");
	printf("4.修改数据.\n");
	printf("5.数据排序.\n");
	printf("6.输出链表数据.\n");
	printf("0.退出链表操作.\n");
}

// 加入新数据
void addNewData(LinkList H)
{
	LinkNode *p,*s;
	p=H;
	while(p->next!=NULL) p=p->next;
	s=(LinkNode*)malloc(sizeof(LinkNode));
	printf("输入要添加的新数据:\n");
	scanf("%c",&s->data);
	getchar();
	p->next=s;
	s->next=NULL;
	system("cls");
	printf("添加成功！\n");
	getchar();
}

//删除数据
void deleData(LinkList H)
{
	LinkNode *p=H,*s=H;
	int i=0,num=0,address;
	while(s)
	{
		s=s->next;
		num++;
	 }
	num--;
	showData(H);
	while(1)
	{	
		printf("输入要删除的位置:\n");
		scanf("%d",&address);
		getchar();
		if(address>0&&address<=num) break;
		else	printf("----------输入有误！请重新输入---------\n"); 
	}
	while(address!=1&&address<=num)		
	{
		p=p->next;
		i++;
		if(i==address-1) break;
	}
	s=p->next;
	p->next=p->next->next;
	free(s);
	printf("删除成功！\n");
 } 

//查找数据
int serchData(LinkList H)
{
	LinkNode* p=H;
	char chooce;
	DATA key;
	int i,address;
	while(1)
	{
		printf("查找方式：\n");
		printf("1.位置查找.\n");
		printf("2.数据查找.\n");
		printf("0.退出查找.\n");
		scanf("%c",&chooce);
		getchar();
		switch(chooce)
		{
			case '1':{
				printf("输入要查找的位置：\n");
				scanf("%d",&address);
				getchar();
				for(i=1;i<=address,p!=NULL;i++)
					p=p->next;
				if(p==NULL)	printf("位置非法！\n");
				else printf("查找完毕！\n该数据为:%c\n",p->data);
				getchar(); 
				break;
			}
			case '2':{
				printf("输入要查找的数据：\n");
				scanf("%c",&key);
				getchar();
				for(i=1;p;i++)
				{
					p=p->next;
					if(p->data==key)	break;
				}
				if(p==NULL)	printf("未找到该数据！\n");
				else		printf("查找成功！\n该数据的地址为：%d\n",i);
				getchar();
				break;
			}
			case '0':
				return 0;				
		}
		system("cls");
	}
}

//修改数据
int changeData(LinkList H)
{
	LinkNode* p=H;
	int i,address;
	DATA input;
	showData(H);
	printf("输入要修改数据的地址:\n");
	scanf("%d",&address);
	getchar();
	for(i=1;i<=address&&p!=NULL;i++)
	{
		p=p->next;
		printf("p->data:%c\n",p->data);
	}
	if(p==NULL) 	printf("位置非法！\n");
	else{
		printf("请输入修改后的数据：\n");
		scanf("%c",&input);
		getchar();
		p->data=input;
		printf("修改成功！\n");
	}
	getchar();
	system("cls");
 } 

//数据排序(冒泡排序)[效率可能有些低下]
void dataSort(LinkList H)
{
	char chooce;
	DATA temp;
	LinkNode *p1,*p2;
	printf("1.升序.\n");
	printf("2.降序.\n");
	do{
		scanf("%c",&chooce);
		getchar();
	}while(chooce!='1'&&chooce!='2');
	switch(chooce)
	{
		case '1':{	//升序 
			for(p1=H->next;p1!=NULL;p1=p1->next)
				for(p2=p1->next;p2!=NULL;p2=p2->next)
				{
					if(p1->data>p2->data)
					{
						temp=p1->data;
						p1->data=p2->data;
						p2->data=temp;
					}
				}
			break;
		}
		case '2':{	//降序 
			for(p1=H->next;p1!=NULL;p1=p1->next)
				for(p2=p1->next;p2!=NULL;p2=p2->next)
				{
					if(p1->data<p2->data)
					{
						temp=p1->data;
						p1->data=p2->data;
						p2->data=temp;
					}
				}
			break;
		}
	}
	printf("排序完成！\n");
	getchar();
 } 

//链表相关操作主函数 
int operationLinkList()
{
	LinkList H;
	char chooce;
	createLinkList(&H);			//建立链表数据 
	system("cls");
	while(1)
	{
		menu_1();
		scanf("%c",&chooce);
		getchar();
		switch(chooce)
		{
			case '1':
				addNewData(H);break;
			case '2':
				deleData(H);break;
			case '3':
				serchData(H);break;
			case '4':
				changeData(H);break;
			case '5':
				dataSort(H);break;
			case '6':
				showData(H);break;
			case '0':
				return 0;	 
		}
		system("cls");
	}	
}

//**************栈*************// 

//入栈 
int Push(Stack *S)
{
	DATA input;
	if(S->top==MAX_SIZE)
	{
		printf("————栈满，不能入栈！————");
		getchar();
		return (-1);
	}
	printf("输入入栈数据：\n");
	scanf("%c",&input);
	getchar();
	S->top++;
	S->Sta[S->top]=input;
	printf("入栈成功！\n");
	getchar();
	system("cls");
}

//出栈
int Pop(Stack *S)
{
	if(S->top==-1)
	{
		printf("————栈空，不能出栈！————");
		getchar();
		return (-1);
	}
	printf("出栈数据为:\n%c\n",S->Sta[S->top]);
	S->top--;
	printf("出栈成功！\n");
	getchar();
	system("cls");
 } 

//获取栈顶数据 
int GetTop(Stack S)
{
	if(S.top==-1)
	{
		printf("栈空！\n");
		getchar();
		return (-1);
	}
	printf("栈顶数据为：\n%c\n",S.Sta[S.top]);
	getchar();
	system("cls");
}

//栈操作菜单 
void menu_2()
{
	printf("1.进栈.\n");
	printf("2.出栈.\n");
	printf("3.获取栈顶数据.\n");
	printf("0.退出.\n"); 
}

//栈相关操作主函数 
int operationStack()
{
	char chooce;
	Stack S;
	S.top=-1;		//初始化栈
	while(1)
	{
		menu_2();		//显示菜单 
		scanf("%c",&chooce);
		getchar();
		switch(chooce)
		{
			case '1':{
				Push(&S);
				break;
			}
			case '2':{
				Pop(&S);
				break;
			}
			case '3':{
				GetTop(S);
				break;
			}
			case '0':return 0;
		}
	}
	system("cls"); 
}

//************队列************// 

//入队列
int EnterQueue(Queue *Q)
{
	DATA input;
	if(Q->aft==MAX_SIZE-1)
	{
		printf("————队已满，不能入队————\n");
		getchar();
		return (-1);
	}
	printf("输入要入队数据：\n");
	scanf("%c",&input);
	getchar();
	Q->aft++;
	Q->Que[Q->aft]=input;
	printf("入队成功！\n");
	getchar();
	system("cls");
 } 

//出队列
int DeleteQueue(Queue *Q)
{
	if(Q->pre==Q->aft)
	{
		printf("————空队列，不能出队列————\n");
		getchar();
		system("cls");
		return (-1);
	}
	Q->pre++;
	printf("要出队数据：\n%c\n",Q->Que[Q->pre]);
	printf("出队成功！\n");
	getchar();
	system("cls");
 } 

//获取队头数据
int GetHead(Queue Q)
{
	if(Q.aft==Q.pre)
	{
		printf("————队列无数据————\n");
		getchar();
		system("cls");
	}
	Q.pre++;
	printf("队头的数据为：\n%c\n",Q.Que[Q.pre]);
	getchar();
	system("cls");
 } 

//队列操作菜单 
void menu_3()
{
	printf("1.入队列.\n");
	printf("2.出队列.\n");
	printf("3.获取队头数据.\n");
	printf("0.退出.\n");
}

//队列相关操作主函数 
int operationQueue()
{
	Queue Q;
	char chooce;
	//以下两步是初始化队列 
	Q.pre=-1;
	Q.aft=-1; 
	while(1)
	{
		menu_3();
		scanf("%c",&chooce);
		getchar();
		switch(chooce)
		{
			case '1':{
				EnterQueue(&Q);
				break;
			}
			case '2':{
				DeleteQueue(&Q);
				break;
			}
			case '3':{
				GetHead(Q);
				break;
			}
			case '0': return 0;
		}
		system("cls");
	 } 
}










//建树 
void createBiTree(Tree **root)
{
	DATA input;
	input=getchar();
	if(input=='.')	*root=NULL;
	else
	{
		*root=(Tree*)malloc(sizeof(Tree));
		(*root)->data=input;
		createBiTree(&(*root)->LChild);
		createBiTree(&(*root)->RChild);
	 }
}

//先序遍历
void PreOrder(Tree *root)
{
	if(root!=NULL)
	{
		printf("%c ",root->data);
		PreOrder(root->LChild);
		PreOrder(root->RChild);
	}
 } 


//中序遍历
void InOrder(Tree *root)
{
	if(root!=NULL)
	{
		PreOrder(root->LChild);
		printf("%c ",root->data);
		PreOrder(root->RChild);
	}
}

//后序遍历
void PostOrder(Tree *root)
{
	if(root!=NULL)
	{
		PreOrder(root->LChild);
		PreOrder(root->RChild);
		printf("%c ",root->data);
	}
}
 
//建立二叉线索树
void InThread(Tree *root)
{
	if(root)
	{
		InThread(root->LChild);		//线索化左子树 
		if(!root->LChild)
		{
			root->LTag=1;
			root->LChild=pre;
		}
		if(pre!=NULL&&pre->RChild==NULL)	//注意短路特性 
		{
			pre->RChild=root;
			pre->RTag=1;
		}
		pre=root;
		InThread(root->RChild);	//线索化右子树 
	}
} 

//线索树中找结点后继
Tree *InNext(Tree *p) 
{
	Tree *Next,*q;
	if(p->RTag==1)	Next=p->RChild;		//使用线索 
	else
	{
		for(q=p->RChild;q->LTag!=1;q=q->LChild);	//空语句
		Next=q; 
		
	}
	return(Next);
}

//线索树中找第一个结点
Tree *InFirst(Tree *T)
{
	Tree *p=T;
	if(!p)	return (NULL);
	while(p->LTag!=1)		p=p->LChild;
	return p;
} 

//遍历线索二叉树 
void TInOrder(Tree *root)
{
	Tree *p;
	p=InFirst(root);
	while(p)
	{
		printf("%c ",p->data);
		p=InNext(p);
	}
}

void menu_4()
{
	printf("1.先序遍历.\n");
	printf("2.中序遍历.\n");
	printf("3.后序遍历.\n");
	printf("4.线索化二叉树.\n");
	printf("5.遍历线索二叉树.\n");
	printf("0.退出.\n");
}

//二叉树相关操作主函数 
int operationTree()
{
	char chooce;
	Tree *T;
	printf("按先序序列输入二叉树数据：(无左右孩子使用'.'代替)\n");
	createBiTree(&T); 		//建树 
	printf("构建完成！\n");
	getchar();
	getchar();
	system("cls");
	while(1)
	{
		menu_4();
		scanf("%c",&chooce);
		getchar();
		switch(chooce)
		{
			case '1':{
				printf("先序遍历结果为:\n");
				PreOrder(T);
				getchar();
				break;
			}
			case '2':{
				printf("中序遍历结果为:\n");
				InOrder(T);
				getchar();
				break;
			}
			case '3':{
				printf("后序遍历结果为:\n");
				PostOrder(T);
				getchar();
				break;
			}
			case '4':{
				InThread(T);
				pre->RTag=1;
				printf("线索化成功！\n");
				getchar();
				break;
			}
			case '5':{
				printf("线索化中序遍历结果:\n");
				TInOrder(T); 
				getchar();
				break;
			}
			case '0':return 0;	
		}
		system("cls");
	}
	
}

//****************图相关操作***************//
 
//求顶点位置函数 
int LocateVertex(AdjMatrix* G,int v)
{
	int j=Error,k; 
	for(k=1;k<=G->vexnum;k++)
	{
		if(G->vextex[k]==v)
		{
			j=k;
			break;
		}
	}
	return(j);
}

//创建一个有向网
int createGraph_1(AdjMatrix* G)
{
	int i,j,k,weight;
	int v1,v2; 
	printf("请输入边(弧)数:\n");
	scanf("%d",&(G->arcnum));
	getchar();
	printf("请输入顶点数:\n");
	scanf("%d",&(G->vexnum));
	getchar();
	for(i=1;i<=G->vexnum;i++)
		for(j=1;j<=G->vexnum;j++)
			G->arcs[i][j].adj=0;
	for(i=1;i<=G->vexnum;i++)
	{ 
		printf("Input the %d point:\n",i);
		scanf("%d",&G->vextex[i]);
		getchar();
	}
		
	for(k=1;k<=G->arcnum;k++)
	{
		printf("Input the v1,v2,weight:\n");
		scanf("%d,%d,%d",&v1,&v2,&weight);
		getchar();
		i=LocateVertex(G,v1);
		j=LocateVertex(G,v2);
		G->arcs[i][j].adj=weight;
	}
} 

//建立邻接表
void createGraph_2(Vex G_2[])
{
	Arc *ptr;
	int arcnum,vexnum,k,v1,v2;
	printf("请输入顶点数和边数(输入格式为：顶点数,边数(英文逗号))：\n");
	scanf("%d,%d",&vexnum,&arcnum);		//输入图的顶点数和边数(弧数) 
	getchar();
	for(k=1;k<=vexnum;k++)
		G_2[k].firstArc=0;			//为邻接链表的G_2数组各元素的链域赋初值
	for(k=0;k<arcnum;k++)				//为G_2数组的各元素分别建立各自的链表 
	{
		printf("v1,v2=");
		scanf("%d,%d",&v1,&v2);
		getchar();
		ptr=(Arc*)malloc(sizeof(Arc));//给节点v1的相邻节点v2分配内存空间 
		ptr->arc=v2;						   //将顶点v2插入到链表中，使得节点插入后单链表仍然有序 
		ptr->nextArc=G_2[v1].firstArc;
		G_2[v1].firstArc=ptr;			   //将邻接点v2插入表头节点v1后
		/*对于有向图，接下来的四行语句要删除*/
		ptr=(Arc*)malloc(sizeof(Arc));
		ptr->arc=v1;
		ptr->nextArc=G_2[v2].firstArc;
		G_2[v2].firstArc=ptr; 
	 }	 
	printf("构建完成！\n");	
 } 

//邻接表深度优先遍历__apart2 
void DepthFirstSerch(AdjMatrix G,int v0)
{
	int vj;
	printf("%d ",v0);
	visited[v0]=1;
	for(vj=0;vj<G.vexnum;vj++)
		if(!visited[vj]&&G.arcs[v0][vj].adj==1)
			DepthFirstSerch(G,vj);
}
 
//遍历____part1 
void DFS_1(AdjMatrix* G)
{
	int vi;
	for(vi=1;vi<=G->vexnum;vi++)	visited[vi]=0;
	for(vi=1;vi<=G->vexnum;vi++)
		if(!visited[vi])	DepthFirstSerch(*G,vi);
}


//邻接表深度优先遍历 
void DFS_2(Vex G[],int v)
{
	int w;
	Arc *p;
	p=G[v].firstArc;
	printf("%d ",v);				//输出访问顶点
	G[v].vex=1;						//顶点标志域置1，表明已经访问过
	while(p)
	{
		w=p->arc;					//取出顶点v的某邻接点的序号
		if(G[w].vex==0)
			DFS_2(G,w);				//如果该顶点未访问过则递归调用，从改顶点出发，沿着它的各邻接点向下搜索
		p=p->nextArc; 
	 } 
}
 

//图相关操作菜单 
void menu_5()
{
	printf("————邻接矩阵————\n");
	printf("1.使用邻接矩阵表示图.\n");
	printf("2.深度优先遍历图(DFS).\n");
	printf("————邻接表—————\n");
	printf("3.使用邻接表表示图.\n");
	printf("4.深度度优先遍历图(DFS).\n\n");
	printf("0.退出.\n\n");	
}


//图相关操作主函数 
int operationGraph()
{
	AdjMatrix G_1;
	Vex G_2[MAXNUM_VEX]; 
	int v;
	char chooce;
	while(1)
	{
		menu_5();
		scanf("%c",&chooce);
		getchar();
		system("cls");
		switch(chooce)
		{
			case '1':{
				createGraph_1(&G_1);
				getchar();
				break;
			}
			case '2':{
				printf("深度优先遍历的结果为:\n");
				DFS_1(&G_1);
				getchar();
				break;
			}
			case '3':{
				createGraph_2(G_2);
				getchar();
				break;
			}
			case '4':{
				printf("输入深度优先搜索起始顶点v:\n");
				scanf("%d",&v);
				printf("图的深度优先搜索序列DFS：\n");
				DFS_2(G_2,v);
				getchar(); 
				getchar(); 
				break;
			}
			case '0':return 0; 
		}
		system("cls");
	}	
}

//主函数菜单 
void menu()
{
	printf("1.对链表进行操作.\n");
	printf("2.对栈进行操作.\n");
	printf("3.对队列进行操作.\n");	
	printf("4.对二叉树进行操作.\n");
	printf("5.对图进行操作.\n");
	printf("0.退出程序.\n");
}

int main()
{
	char chooce;
	while(1)
	{
		menu();
		scanf("%c",&chooce);
		getchar();
		system("cls");
		switch(chooce)
		{
			case '1':
				operationLinkList();break;		//操作链表 
			case '2':
				operationStack();break;			//操作栈
			case '3':
				operationQueue();break;			//操作队列
			case '4':
				operationTree();break;			//操作树
			case '5':
				operationGraph();break;			//操作图
			case '0':
				exit(0);
		}
		system("cls");
	}
	return 0;
}
