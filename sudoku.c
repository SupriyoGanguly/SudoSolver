/*
*A non recursive solution for sudo solver.
* Author: Supriyo Ganguly
*/
#include<stdio.h>
#define char int

void max_arr_ele(int a[],int n,int *k)
{
int x=a[0],i;
for(i=1;i<n;i++)
{
	if(a[i]>x)
	{*k=i; x=a[i];}
}
}

void get_notallowed(char a[][9],int col,int r,char not_allow[],int *j,int p1)
{
	int i,p,q;
	for(i=0;i<col;i++) {
			if(a[r][i]==100) continue;
			not_allow[(*j)++]=a[r][i]; }
	for(i=0;i<9;i++) {
			if(a[i][p1]==100) continue;
			not_allow[(*j)++]=a[i][p1]; }
	if(r>=0 && r<=2)
			{
				if(p1>=0 && p1<=2)
				{
					for(p=0;p<=2;p++)
					for(q=0;q<=2;q++)
					{ if(a[p][q]==100) continue; not_allow[(*j)++]=a[p][q];}
				}
				else if(p1>=3 && p1<=5)
				{
					for(p=0;p<=2;p++)
					for(q=3;q<=5;q++)
					{ if(a[p][q]==100) continue; not_allow[(*j)++]=a[p][q];}
				}
				else
				{
					for(p=0;p<=2;p++)
					for(q=6;q<=8;q++)
					{ if(a[p][q]==100) continue; not_allow[(*j)++]=a[p][q];}
				}
			}
			else if(r>=3 && r<=5)
			{
				if(p1>=0 && p1<=2)
				{
					for(p=3;p<=5;p++)
					for(q=0;q<=2;q++)
					{ if(a[p][q]==100) continue; not_allow[(*j)++]=a[p][q];}
				}
				else if(p1>=3 && p1<=5)
				{
					for(p=3;p<=5;p++)
					for(q=3;q<=5;q++)
					{ if(a[p][q]==100) continue; not_allow[(*j)++]=a[p][q];}
				}
				else
				{
					for(p=3;p<=5;p++)
					for(q=6;q<=8;q++)
					{ if(a[p][q]==100) continue; not_allow[(*j)++]=a[p][q];}
				}
			}
			else
			{
				if(p1>=0 && p1<=2)
				{
					for(p=6;p<=8;p++)
					for(q=0;q<=2;q++)
					{ if(a[p][q]==100) continue; not_allow[(*j)++]=a[p][q];}
				}
				else if(p1>=3 && p1<=5)
				{
					for(p=6;p<=8;p++)
					for(q=3;q<=5;q++)
					{ if(a[p][q]==100) continue; not_allow[(*j)++]=a[p][q];}
				}
				else
				{
					for(p=6;p<=8;p++)
					for(q=6;q<=8;q++)
					{ if(a[p][q]==100) continue; not_allow[(*j)++]=a[p][q];}
				}
			}                                          //check the values not allowed & put them in array
			//*******************
}

int main()
{
	int i,j,r,flag[9][9],p1,p2=0,f,g,m=0;
	char a[9][9],not_allow[30]={0},var,l,t,r1=0;
	printf("\t\tSUDOKU SOLVER\n");
	printf("it's std sudoku from 1 t0 9\nnow enter the matrix"
			"(write 100 for blank spaces)\n");
	for(i=0;i<9;i++) for(j=0;j<9;j++)  scanf("%d",&a[i][j]);
	for(i=0;i<9;i++)
	for(j=0;j<9;j++) flag[i][j]=0;
	r=0;
	while(r!=9)
	{
		for(i=0;i<9;i++)
			{ if(flag[r][i]==-2) continue;
			 if(a[r][i]==100)  flag[r][i]=-1;
			else flag[r][i]=0; }                //set the flag array
		for(i=0;i<9;i++) { if(flag[r][i]==-1) {p1=i; break;} }      //check the first blank & hold the position in p1
		do{
			j=0;
			get_notallowed(a,9,r,not_allow,&j,p1);
			var=1;   g=0;
			while(1)
			{
				for(i=0;i<j;i++)
					{if(not_allow[i]==var) {var++;g=0;break;}
					else {g=1;} }
				if(g==1) break;
			}              //get the allowed value & hold in var
			//*******************
			do{
			m=0;
			for(t=1;t<=9;t++) {if(var==t) {m=1; break;}}
			if(m==0)
			{
				if(g==0) {a[r1][p2]=100;flag[r1][p2]=-1;}
				g=0;
				for(i=0;i<9;i++)
				for(j=0;j<9;j++) {if(flag[i][j]==-2) {r1=i;p2=j;}}  //p2 holds last modified position
				if(a[r1][p2]==9)
				{ a[r1][p2]=100;  flag[r1][p2]=-1; continue;}
				l=a[r1][p2];
				a[r1][p2]=100;  flag[r1][p2]=-1;
				do
				{
					l++;
					j=0;
					get_notallowed(a,9,r1,not_allow,&j,p2);
					for(i=0;i<j;i++)
					{	if(l==not_allow[i]) {f=0;break;}
						else f=1;	}
					if(f==1) break;
				}while(1);
				a[r1][p2]=var=l;   flag[r1][p2]=-2;
			}				//last position is remodified
			if(m==1 && g==0) {r=r1;p1=p2;}
			if(m==1) {g=1; break;}
		} while(1);
		if(g==1) break;
		}while(1);            //for current position
		a[r][p1]=var; flag[r][p1]=-2;
		//******************
			for(i=0;i<9;i++)
		{ if(flag[r][i]!=-1) f=1;
		 else {f=0; break;}   }
		if(f==1)  r++;
		else continue;
	}
	printf("\n");
	for(i=0;i<9;i++)
	{
	for(j=0;j<9;j++) printf("%d ",a[i][j]);
	printf("\n");
	}
	return 0;
}
