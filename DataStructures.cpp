/*
*�������ߣ����� 
*������ڣ�2018/6/19--2018/6/21
*�����ܣ����ݽṹ(����ջ�����С�����ͼ) ��ز���. 
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"node.h"
#define Error 0
#define OK 1

Tree *pre=NULL;
int visited[MAXNUM_VEX]; 

//***********����*************// 

//������������ 
void createLinkList(LinkList *H)	//ʹ�ö���ָ�����ͷָ�� 
{	
	LinkNode *p,*s;
	DATA ch;
	(*H)=(LinkList)malloc(sizeof(LinkNode));
	(*H)->next=NULL;
	p=*H;
	printf("�������������ݣ�\n");
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

//�����������
void showData(LinkList H)
{
	LinkNode* p;
	p=H->next;
	printf("�������������:\n");
	while(p)
	{
		printf("%c ",p->data);
		p=p->next;
	 } 
	printf("\n");
	getchar();
}
//��������˵� 
void menu_1()
{
	printf("1.����������.\n");
	printf("2.ɾ������.\n");
	printf("3.��������.\n");
	printf("4.�޸�����.\n");
	printf("5.��������.\n");
	printf("6.�����������.\n");
	printf("0.�˳��������.\n");
}

// ����������
void addNewData(LinkList H)
{
	LinkNode *p,*s;
	p=H;
	while(p->next!=NULL) p=p->next;
	s=(LinkNode*)malloc(sizeof(LinkNode));
	printf("����Ҫ��ӵ�������:\n");
	scanf("%c",&s->data);
	getchar();
	p->next=s;
	s->next=NULL;
	system("cls");
	printf("��ӳɹ���\n");
	getchar();
}

//ɾ������
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
		printf("����Ҫɾ����λ��:\n");
		scanf("%d",&address);
		getchar();
		if(address>0&&address<=num) break;
		else	printf("----------������������������---------\n"); 
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
	printf("ɾ���ɹ���\n");
 } 

//��������
int serchData(LinkList H)
{
	LinkNode* p=H;
	char chooce;
	DATA key;
	int i,address;
	while(1)
	{
		printf("���ҷ�ʽ��\n");
		printf("1.λ�ò���.\n");
		printf("2.���ݲ���.\n");
		printf("0.�˳�����.\n");
		scanf("%c",&chooce);
		getchar();
		switch(chooce)
		{
			case '1':{
				printf("����Ҫ���ҵ�λ�ã�\n");
				scanf("%d",&address);
				getchar();
				for(i=1;i<=address,p!=NULL;i++)
					p=p->next;
				if(p==NULL)	printf("λ�÷Ƿ���\n");
				else printf("������ϣ�\n������Ϊ:%c\n",p->data);
				getchar(); 
				break;
			}
			case '2':{
				printf("����Ҫ���ҵ����ݣ�\n");
				scanf("%c",&key);
				getchar();
				for(i=1;p;i++)
				{
					p=p->next;
					if(p->data==key)	break;
				}
				if(p==NULL)	printf("δ�ҵ������ݣ�\n");
				else		printf("���ҳɹ���\n�����ݵĵ�ַΪ��%d\n",i);
				getchar();
				break;
			}
			case '0':
				return 0;				
		}
		system("cls");
	}
}

//�޸�����
int changeData(LinkList H)
{
	LinkNode* p=H;
	int i,address;
	DATA input;
	showData(H);
	printf("����Ҫ�޸����ݵĵ�ַ:\n");
	scanf("%d",&address);
	getchar();
	for(i=1;i<=address&&p!=NULL;i++)
	{
		p=p->next;
		printf("p->data:%c\n",p->data);
	}
	if(p==NULL) 	printf("λ�÷Ƿ���\n");
	else{
		printf("�������޸ĺ�����ݣ�\n");
		scanf("%c",&input);
		getchar();
		p->data=input;
		printf("�޸ĳɹ���\n");
	}
	getchar();
	system("cls");
 } 

//��������(ð������)[Ч�ʿ�����Щ����]
void dataSort(LinkList H)
{
	char chooce;
	DATA temp;
	LinkNode *p1,*p2;
	printf("1.����.\n");
	printf("2.����.\n");
	do{
		scanf("%c",&chooce);
		getchar();
	}while(chooce!='1'&&chooce!='2');
	switch(chooce)
	{
		case '1':{	//���� 
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
		case '2':{	//���� 
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
	printf("������ɣ�\n");
	getchar();
 } 

//������ز��������� 
int operationLinkList()
{
	LinkList H;
	char chooce;
	createLinkList(&H);			//������������ 
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

//**************ջ*************// 

//��ջ 
int Push(Stack *S)
{
	DATA input;
	if(S->top==MAX_SIZE)
	{
		printf("��������ջ����������ջ����������");
		getchar();
		return (-1);
	}
	printf("������ջ���ݣ�\n");
	scanf("%c",&input);
	getchar();
	S->top++;
	S->Sta[S->top]=input;
	printf("��ջ�ɹ���\n");
	getchar();
	system("cls");
}

//��ջ
int Pop(Stack *S)
{
	if(S->top==-1)
	{
		printf("��������ջ�գ����ܳ�ջ����������");
		getchar();
		return (-1);
	}
	printf("��ջ����Ϊ:\n%c\n",S->Sta[S->top]);
	S->top--;
	printf("��ջ�ɹ���\n");
	getchar();
	system("cls");
 } 

//��ȡջ������ 
int GetTop(Stack S)
{
	if(S.top==-1)
	{
		printf("ջ�գ�\n");
		getchar();
		return (-1);
	}
	printf("ջ������Ϊ��\n%c\n",S.Sta[S.top]);
	getchar();
	system("cls");
}

//ջ�����˵� 
void menu_2()
{
	printf("1.��ջ.\n");
	printf("2.��ջ.\n");
	printf("3.��ȡջ������.\n");
	printf("0.�˳�.\n"); 
}

//ջ��ز��������� 
int operationStack()
{
	char chooce;
	Stack S;
	S.top=-1;		//��ʼ��ջ
	while(1)
	{
		menu_2();		//��ʾ�˵� 
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

//************����************// 

//�����
int EnterQueue(Queue *Q)
{
	DATA input;
	if(Q->aft==MAX_SIZE-1)
	{
		printf("����������������������ӡ�������\n");
		getchar();
		return (-1);
	}
	printf("����Ҫ������ݣ�\n");
	scanf("%c",&input);
	getchar();
	Q->aft++;
	Q->Que[Q->aft]=input;
	printf("��ӳɹ���\n");
	getchar();
	system("cls");
 } 

//������
int DeleteQueue(Queue *Q)
{
	if(Q->pre==Q->aft)
	{
		printf("���������ն��У����ܳ����С�������\n");
		getchar();
		system("cls");
		return (-1);
	}
	Q->pre++;
	printf("Ҫ�������ݣ�\n%c\n",Q->Que[Q->pre]);
	printf("���ӳɹ���\n");
	getchar();
	system("cls");
 } 

//��ȡ��ͷ����
int GetHead(Queue Q)
{
	if(Q.aft==Q.pre)
	{
		printf("�����������������ݡ�������\n");
		getchar();
		system("cls");
	}
	Q.pre++;
	printf("��ͷ������Ϊ��\n%c\n",Q.Que[Q.pre]);
	getchar();
	system("cls");
 } 

//���в����˵� 
void menu_3()
{
	printf("1.�����.\n");
	printf("2.������.\n");
	printf("3.��ȡ��ͷ����.\n");
	printf("0.�˳�.\n");
}

//������ز��������� 
int operationQueue()
{
	Queue Q;
	char chooce;
	//���������ǳ�ʼ������ 
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










//���� 
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

//�������
void PreOrder(Tree *root)
{
	if(root!=NULL)
	{
		printf("%c ",root->data);
		PreOrder(root->LChild);
		PreOrder(root->RChild);
	}
 } 


//�������
void InOrder(Tree *root)
{
	if(root!=NULL)
	{
		PreOrder(root->LChild);
		printf("%c ",root->data);
		PreOrder(root->RChild);
	}
}

//�������
void PostOrder(Tree *root)
{
	if(root!=NULL)
	{
		PreOrder(root->LChild);
		PreOrder(root->RChild);
		printf("%c ",root->data);
	}
}
 
//��������������
void InThread(Tree *root)
{
	if(root)
	{
		InThread(root->LChild);		//������������ 
		if(!root->LChild)
		{
			root->LTag=1;
			root->LChild=pre;
		}
		if(pre!=NULL&&pre->RChild==NULL)	//ע���·���� 
		{
			pre->RChild=root;
			pre->RTag=1;
		}
		pre=root;
		InThread(root->RChild);	//������������ 
	}
} 

//���������ҽ����
Tree *InNext(Tree *p) 
{
	Tree *Next,*q;
	if(p->RTag==1)	Next=p->RChild;		//ʹ������ 
	else
	{
		for(q=p->RChild;q->LTag!=1;q=q->LChild);	//�����
		Next=q; 
		
	}
	return(Next);
}

//���������ҵ�һ�����
Tree *InFirst(Tree *T)
{
	Tree *p=T;
	if(!p)	return (NULL);
	while(p->LTag!=1)		p=p->LChild;
	return p;
} 

//�������������� 
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
	printf("1.�������.\n");
	printf("2.�������.\n");
	printf("3.�������.\n");
	printf("4.������������.\n");
	printf("5.��������������.\n");
	printf("0.�˳�.\n");
}

//��������ز��������� 
int operationTree()
{
	char chooce;
	Tree *T;
	printf("����������������������ݣ�(�����Һ���ʹ��'.'����)\n");
	createBiTree(&T); 		//���� 
	printf("������ɣ�\n");
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
				printf("����������Ϊ:\n");
				PreOrder(T);
				getchar();
				break;
			}
			case '2':{
				printf("����������Ϊ:\n");
				InOrder(T);
				getchar();
				break;
			}
			case '3':{
				printf("����������Ϊ:\n");
				PostOrder(T);
				getchar();
				break;
			}
			case '4':{
				InThread(T);
				pre->RTag=1;
				printf("�������ɹ���\n");
				getchar();
				break;
			}
			case '5':{
				printf("����������������:\n");
				TInOrder(T); 
				getchar();
				break;
			}
			case '0':return 0;	
		}
		system("cls");
	}
	
}

//****************ͼ��ز���***************//
 
//�󶥵�λ�ú��� 
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

//����һ��������
int createGraph_1(AdjMatrix* G)
{
	int i,j,k,weight;
	int v1,v2; 
	printf("�������(��)��:\n");
	scanf("%d",&(G->arcnum));
	getchar();
	printf("�����붥����:\n");
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

//�����ڽӱ�
void createGraph_2(Vex G_2[])
{
	Arc *ptr;
	int arcnum,vexnum,k,v1,v2;
	printf("�����붥�����ͱ���(�����ʽΪ��������,����(Ӣ�Ķ���))��\n");
	scanf("%d,%d",&vexnum,&arcnum);		//����ͼ�Ķ������ͱ���(����) 
	getchar();
	for(k=1;k<=vexnum;k++)
		G_2[k].firstArc=0;			//Ϊ�ڽ������G_2�����Ԫ�ص����򸳳�ֵ
	for(k=0;k<arcnum;k++)				//ΪG_2����ĸ�Ԫ�طֱ������Ե����� 
	{
		printf("v1,v2=");
		scanf("%d,%d",&v1,&v2);
		getchar();
		ptr=(Arc*)malloc(sizeof(Arc));//���ڵ�v1�����ڽڵ�v2�����ڴ�ռ� 
		ptr->arc=v2;						   //������v2���뵽�����У�ʹ�ýڵ�����������Ȼ���� 
		ptr->nextArc=G_2[v1].firstArc;
		G_2[v1].firstArc=ptr;			   //���ڽӵ�v2�����ͷ�ڵ�v1��
		/*��������ͼ�����������������Ҫɾ��*/
		ptr=(Arc*)malloc(sizeof(Arc));
		ptr->arc=v1;
		ptr->nextArc=G_2[v2].firstArc;
		G_2[v2].firstArc=ptr; 
	 }	 
	printf("������ɣ�\n");	
 } 

//�ڽӱ�������ȱ���__apart2 
void DepthFirstSerch(AdjMatrix G,int v0)
{
	int vj;
	printf("%d ",v0);
	visited[v0]=1;
	for(vj=0;vj<G.vexnum;vj++)
		if(!visited[vj]&&G.arcs[v0][vj].adj==1)
			DepthFirstSerch(G,vj);
}
 
//����____part1 
void DFS_1(AdjMatrix* G)
{
	int vi;
	for(vi=1;vi<=G->vexnum;vi++)	visited[vi]=0;
	for(vi=1;vi<=G->vexnum;vi++)
		if(!visited[vi])	DepthFirstSerch(*G,vi);
}


//�ڽӱ�������ȱ��� 
void DFS_2(Vex G[],int v)
{
	int w;
	Arc *p;
	p=G[v].firstArc;
	printf("%d ",v);				//������ʶ���
	G[v].vex=1;						//�����־����1�������Ѿ����ʹ�
	while(p)
	{
		w=p->arc;					//ȡ������v��ĳ�ڽӵ�����
		if(G[w].vex==0)
			DFS_2(G,w);				//����ö���δ���ʹ���ݹ���ã��ӸĶ���������������ĸ��ڽӵ���������
		p=p->nextArc; 
	 } 
}
 

//ͼ��ز����˵� 
void menu_5()
{
	printf("���������ڽӾ��󡪡�����\n");
	printf("1.ʹ���ڽӾ����ʾͼ.\n");
	printf("2.������ȱ���ͼ(DFS).\n");
	printf("���������ڽӱ���������\n");
	printf("3.ʹ���ڽӱ��ʾͼ.\n");
	printf("4.��ȶ����ȱ���ͼ(DFS).\n\n");
	printf("0.�˳�.\n\n");	
}


//ͼ��ز��������� 
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
				printf("������ȱ����Ľ��Ϊ:\n");
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
				printf("�����������������ʼ����v:\n");
				scanf("%d",&v);
				printf("ͼ�����������������DFS��\n");
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

//�������˵� 
void menu()
{
	printf("1.��������в���.\n");
	printf("2.��ջ���в���.\n");
	printf("3.�Զ��н��в���.\n");	
	printf("4.�Զ��������в���.\n");
	printf("5.��ͼ���в���.\n");
	printf("0.�˳�����.\n");
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
				operationLinkList();break;		//�������� 
			case '2':
				operationStack();break;			//����ջ
			case '3':
				operationQueue();break;			//��������
			case '4':
				operationTree();break;			//������
			case '5':
				operationGraph();break;			//����ͼ
			case '0':
				exit(0);
		}
		system("cls");
	}
	return 0;
}
