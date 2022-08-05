#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>

char prod[10][20],start[2];
char nonterm[10],term[10];
char input[10],stack[50];
int table[10][10];
int te,nte;
int n;

void main()
{
	clrscr();
	init();
	parse();
	getch();
}

init()
{
  	int i,j;
  	printf("\nNOTE:\n");
  	printf("The terminals should be entered in single lower case letters,special symbol and\n");
  	printf("non-terminals should be entered in single upper case letters.\n");
  	printf("extends to symbol is '->' and epsilon symbol is '@' \n");
  	printf("\nEnter the no. of terminals:");
  	scanf("%d",&te);
  	for(i=0;i<te;i++)
  	{
  		fflush(stdin);
  		printf("Enter the terminal %d:",i+1);
  		scanf("%c",&term[i]);
  	}
 	term[i]='$';
 	printf("\nEnter the no. of non terminals:");
  	scanf("%d",&nte);
  	for(i=0;i<nte;i++)
  	{	
  		fflush(stdin);
  		printf("Enter the non-terminal %d:",i+1);
  		scanf("%c",&nonterm[i]);
  	}
  	printf("\nEnter the no. of productions:");
  	scanf("%d",&n);
  	for(i=0;i<n;i++)
  	{
  		printf("Enter the production %d:",i+1);
  		scanf("%s",prod[i]);
  	}
  	fflush(stdin);
  	printf("\nEnter the start symbol:");
  	scanf("%c",&start[0]);
  	printf("\nEnter the input string:");
  	scanf("%s",input);
  	input[strlen(input)]='$';
  	printf("\n\nThe productions are:");
  	printf("\nProductionNo.	Production");
  	for(i=0;i<n;i++)
  		printf("\n %d		%s",i+1,prod[i]);
  	printf("\n\nEnter the parsing table:");
  	printf("\n Enter the production number in the required entry as mentioned above.");
  	printf("\n Enter the undefined entry or error of table as '0'\n\n");
  	for(i=0;i<nte;i++)
  	{
  		for(j=0;j<=te;j++)
  		{
  			fflush(stdin);
  			printf("Entry of table[%c,%c]:",nonterm[i],term[j]);
  			scanf("%d",&table[i][j]);
  		}
  	}
  }

parse()
{
  	int i,j,prodno;
  	int top=-1,current=0;
  	stack[++top]='$';
  	stack[++top]=start[0];
  	do
 	{
 		if((stack[top]==input[current])&&(input[current]=='$'))
 		{
 			printf("\nThe given input string is parsed");
 			getch();
 			exit(0);
 		}
 		else if(stack[top]==input[current])
 		{
 			top--;
 			current++;
 		}
 		else if(stack[top]>='A'&&stack[top]<='Z')
 		{
 			for(i=0;i<nte;i++)
 				if(nonterm[i]==stack[top]) break;
 			for(j=0;j<=te;j++)
 				if(term[j]==input[current]) break;
 			prodno=table[i][j];
 			if(prodno==0)
 			{
 				printf("\nThe given input string is not parsed");
 				getch();
 				exit(0);
 			}
 			else
 			{
 				for(i=strlen(prod[prodno-1])-1;i>=3;i--)
 				{
 					if(prod[prodno-1][i]!='@')
 					stack[top++]=prod[prodno-1][i];
 				}
 				top--;
 			}
 		}
 		else
 		{
 			printf("\nThe given input string is not parsed");
 			getch();
 			exit(0);
 		}
 	}while(1);
}