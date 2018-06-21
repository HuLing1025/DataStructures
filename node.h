/*
*�������ߣ����� 
*������ڣ�2018/6/19 
*�����ܣ����ݽṹ(����ջ�����С�����ͼ)������Ͷ���. 
*/ 
#ifndef _NODE_
#define _NODE_
#define MAX_SIZE 100 
#define MAXNUM_VEX 20

typedef char DATA;

//�������������� 
typedef struct LinkNode{
	DATA data;				//��������� 
	struct LinkNode* next;	//ָ����ָ����һ��� 
}LinkNode,*LinkList;

//ջ���Ͷ���
typedef struct Stack{
	DATA Sta[MAX_SIZE];		//�����ʾ��ջ 
	int top;				//ջ��ָ�� 
}Stack; 

//�������Ͷ���
typedef struct Queue{
	DATA Que[MAX_SIZE];		//�����ʾ�Ķ��� 
	int pre;				//��ͷָ�� 
	int aft;				//��βָ�� 
}Queue; 

//��������Ͷ���
typedef struct Tree{
	DATA data;				//������ 
	struct Tree* LChild;	//������ 
	struct Tree* RChild;	//������ 
	int LTag;
	int RTag; 
}Tree;

typedef struct Grap{
	int adj;			//1:�ڽӣ�0:���ڽ� 
	char Info[100];		//������Ϣ 
}Grap;


//�ڽӾ�����ͼ���� 
typedef struct ArcNode{
	int adj;			//1:�ڽӣ�0:���ڽ� 
	char Info[100];		//������Ϣ 
}ArcNode;

typedef struct{
	int vextex[MAXNUM_VEX];		//��������
	ArcNode arcs[MAXNUM_VEX][MAXNUM_VEX];		//�ڽӾ���
	int vexnum,arcnum;					//ͼ�Ķ������ͱ���(����) 
}AdjMatrix; 


/***********�ڽӱ���ͼ����********/
//�߱����������� 
typedef struct Arc{
	DATA arc;					//��(��) 
	struct Arc* nextArc;		//ָ����ָ����һ����(��) 
}Arc;

//��ͷ����������� 
typedef struct Vex{
	DATA vex;					//���� 
	struct Arc* firstArc;		//ָ����ָ���һ����(��) 
}Vex; 
/************ end *****************/ 

#endif
