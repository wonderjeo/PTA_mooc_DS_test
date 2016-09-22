#include<stdio.h>
#include<stdlib.h>
typedef struct Node *PtrNode;
struct Node {
	int Address;
	int Data;
	int Next;
	PtrNode Link;
};
PtrNode DeleteNode(int j, PtrNode N);
PtrNode DeleteNode(int j, PtrNode N) {
	PtrNode Rear, tmp;
	Rear = N;
	//找到第j个节点的前一个节点（j一定大于1）
	while (--j)
	{
		Rear = Rear->Link;
	}
	tmp = Rear->Link;
	Rear->Link = tmp->Link;
	free(tmp);
	return N;
}
PtrNode InsertNode(int i, PtrNode N, int a, int d, int n);
PtrNode InsertNode(int i, PtrNode N, int a, int d, int n) {
	PtrNode Rear, tmp;
	Rear = N;
	while (--i)
	{
		Rear = Rear->Link;
	}
	tmp = (PtrNode)malloc(sizeof(struct Node));
	tmp->Address = a;
	tmp->Data = d;
	tmp->Next = n;
	if (!Rear->Link) {
		Rear->Link = tmp;
	}
	else {
		tmp->Link = Rear->Link;
		Rear->Link = tmp;
	}
	return N;
}
PtrNode ReadNode(int a, int n);
PtrNode ReadNode(int a, int n) {
	PtrNode N, Rear;
	int address, data, next;
	Rear = (PtrNode)malloc(sizeof(struct Node));
	N = Rear;
	while (n--)
	{
		scanf("%d %d %d", &address, &data, &next);
		PtrNode tmp;
		tmp = (PtrNode)malloc(sizeof(struct Node));
		tmp->Address = address;
		tmp->Data = data;
		tmp->Next = next;
		tmp->Link = NULL;
		if (tmp->Address == a)
		{
			N->Address = tmp->Address;
			N->Data = tmp->Data;
			N->Next = tmp->Next;
		}
		Rear->Link = tmp;
		Rear = Rear->Link;
	}
	return N;
}
PtrNode SortNode(PtrNode N);
PtrNode SortNode(PtrNode N){
	PtrNode Rear;
	int i, j;//i用于记录当前有序的最后一个节点的位置，
			 //j用于记录当前搜索的节点的位置
	Rear = N;
	PtrNode tmp;
	i = 1;
	while (Rear->Next != -1)
	{
		tmp = Rear;
		j = i;
		while (tmp->Address != Rear->Next)
		{
			j++;
			tmp = tmp->Link;
		}
		N = InsertNode(i, N, tmp->Address, tmp->Data, tmp->Next);
		N = DeleteNode(j, N);
		tmp = Rear->Link;
		i++;
		Rear = tmp;
	}
	Rear->Link = NULL;
	return N;
}
void PrintNode(PtrNode N);
void PrintNode(PtrNode N) {
	if (!N) {
		printf("The Node is empty.");
	}
	int flag=1;
	while (N)
	{
		if(flag)
		{
			flag=0;
		}
		else
		{
			printf("\n");		
		}
		if(N->Next>=0)
		printf("%05d %d %05d", N->Address, N->Data, N->Next);
		else
		printf("%05d %d %d", N->Address, N->Data, N->Next);		
		N = N->Link;
	}
	return;
}
PtrNode ReverseK(PtrNode N, int k);
PtrNode ReverseK(PtrNode N, int k) {
	PtrNode Head, Rear, Start;
	Start = (PtrNode)malloc(sizeof(struct Node));
	Start->Link = N;
	if(k==1)
	{
		Start->Address=N->Address;
		Start->Data=N->Data;
		Start->Next=N->Next;
		return Start;
	}
	//若k=1则不翻转
	Head = Start;
	Rear = Start;
	int i = 0;
	while (Rear->Link)
	{
		Rear = Rear->Link;
		if (!((++i) % k)) {
			if (Head == Start) {
				PtrNode tmp;
				tmp = Head->Link;
				int j;
				for (j = 0; j < (k - 1);j++) {
					tmp->Link->Next = tmp->Address;
					tmp = tmp->Link;
				}
				Start->Address = Rear->Address;
				Start->Data = Rear->Data;
				Start->Next = Rear->Next;
				Start->Link->Next = Rear->Link->Address;
				Head = Start->Link;
			}
			else {
				PtrNode tmp;
				tmp = Head;
				int m = k;//Head应在需要处理的节点的k个节点前
				while (m--)
				{
					tmp = tmp->Link;
				}
				tmp->Next = Rear->Next;
				int j;
				for (j = 0; j++; j < (k - 1)) {
					tmp->Link->Next = tmp->Address;
					tmp = tmp->Link;
				}
				Head->Next = Rear->Address;
			}
		}
	}
	return Start;
}
int main()
{
	PtrNode N;
	int a, n, k;
	scanf("%d %d %d", &a, &n, &k);
	N = ReadNode(a, n);//读取n个节点，返回Address为a的节点；
	N = SortNode(N);
	N=ReverseK(N, k);//每k个节点逆序一次
	N = SortNode(N);
	PrintNode(N);//打印N为首节点的链表
	return 0;
}
