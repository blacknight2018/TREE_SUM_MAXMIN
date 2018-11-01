#include<stdio.h>

struct Tree
{
	int Data;
	int P;
	int C[100];
	int CN;
};
struct Tree myTree[100] = { 0 };
unsigned int NODENUM = 1;
void dg(int N)
{
	int NUM;
	int VLOP;
	int SNUM = 0;
	int STIN = 0;
	printf("NUM:%d\n", myTree[N].Data);
	scanf("%d", &NUM);
	myTree[N].CN = NUM;
	if (0 == NUM) return;
	STIN = NODENUM;
	for (VLOP=1; VLOP<=NUM; VLOP++)
	{
		scanf("%d", &SNUM);
		myTree[NODENUM].Data = SNUM;
		myTree[NODENUM].P = N;
		myTree[N].C[VLOP-1] = NODENUM;
		NODENUM++;
	}
	for (VLOP = 1; VLOP <= NUM; VLOP++)
	{
			dg(STIN+VLOP-1);
	}
}
int TREE_STEP[8] = { 0 };
void getSum(int SUM, int N,int STEP)
{
	int VLOP = 0;
	int CN = myTree[N].CN;
	if (CN == 0)
	{
		TREE_STEP[STEP] = myTree[N].Data;
		for (unsigned i = 1; i <= STEP+1; i++)
		{
			printf("%d ", TREE_STEP[i - 1]);
		}
		printf(" SUM:%d\n", SUM + myTree[N].Data);
		return;
	}
	TREE_STEP[STEP] = myTree[N].Data;
	for (VLOP = 1; VLOP<=CN; VLOP++)
	{
		getSum(SUM + myTree[N].Data, myTree[N].C[VLOP - 1],STEP+1);
	}
}
int main()
{
	myTree[0].Data = 10;
	myTree[0].P = -1;
	dg(0);
	getSum(0, 0,0);
    return 0;
}
