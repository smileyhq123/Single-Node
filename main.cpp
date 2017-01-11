#include<iostream>

using namespace std;

struct List{
	int item;
	List *next;
};

List *sort(List *head)//选择排序法
{
	List *p0, *p1,*small;
	int temp1;

	for (p0 = head; p0->next != NULL; p0 = p0->next)
	{
		small = p0;
		for (p1 = p0->next; p1; p1 = p1->next)
		{
			if (p1->item < small->item)
				small = p1;
		}
		if (small != p0)
		{
			temp1 = small->item;
			small->item = p0->item;
			p0->item = temp1;
		}
	}
	return head;
}

List*creat()//创建链表，以输入0结束
{
	List *head, *p, *s;
	int x, cycle = 1;
	head = (List*)malloc(sizeof(List));
	p = head;
	while (cycle)
	{
		cout << "Please input a data:";
		cin >> x;
		if (x != 0)
		{
			//s = (List*)malloc(sizeof(List));
			s = new List;
			s->item = x;
			p->next = s;
			p = s;
		}
		else
			cycle = 0;
	}
	head = head->next;
	p->next = NULL;

	return (head);
}
bool delist(List *L, int num)//删除值为num的节点
{
	List *p,*s;
	p = L;
	s = L->next;

	if (L->item == num)
	{
		L = L->next;
		//free(p);
		delete p;
		p = NULL;
		return true;
	}
	while (s&&s->item != num)
	{
		s = s->next;
		p = p->next;
	}
	if (s)
	{
		p->next = s->next;
		//free(s);
		delete s;
		s = NULL;
		return true;
	}
	else
		return false;
}
//参数
//L 单链表
//int i 插入节点的序号
//int data 插入节点的值
void insert(List *L, int i, int data)
{
	List *s, *p;
	p = L;
	s = (List*)malloc(sizeof(List));
	int j = 0;
	while (p&&j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p)
		return;
	else
	{
		s->item = data;
		s->next = p->next;
		p->next = s;
	}
}

int lenlist(List *L)//链表的长度
{
	int k = 0;
	List *p;
	p = L;
	while (p)
	{
		p = p->next;
		k++;
	}
	return k;
}

void display(List *head)//显示链表
{
	List *p;
	p = head;
	while (p != NULL)
	{
		cout << p->item << "  ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	List *node,*node_sort;
	node = creat();
	display(node);
	int k = lenlist(node);


	int t = 3;
	int data = 5;
	insert(node, t, data);
	display(node);
	int n = lenlist(node);

	bool flag = delist(node, data);
	display(node);

	node_sort = sort(node);
	display(node_sort);
	return 0;
}