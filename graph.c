#include<stdio.h>
#include<stdlib.h>
struct node ;
struct adj
{
	int data;
	struct adj *next;
	struct node *vertex;
};
struct node 
{
	int data;
	int color;
	int d;
	int pi;
	struct adj *list;
};
void CreateList(struct node *List,int data)
{
	struct adj *temp=malloc(sizeof(struct adj)),*r;
	temp->data=data;
	temp->next=NULL;
	if(!List->list)
		List->list=temp;
	else
	{
		r=List->list;
		while(r->next)
			r=r->next;
		r->next=temp;
	}
}
int main()
{
	int num,i,j,data;
	int n;
	scanf("%d",&n);
	struct node VList[n];
	for(i=0;i<n;i++)
	{	scanf("%d",&VList[i].data);
		VList[i].list=NULL;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		for(j=0;j<num;j++)
		{	
			scanf("%d",&data);
			CreateList(&VList[i],data);
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d\t",VList[i].data);
		struct adj *temp=VList[i].list;
		while(temp)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
		
	}
	return 0;
}
