#include<iostream>
#include<stdbool.h>
#include<windows.h>
using namespace std;


int  check(int a[])
{

	if(((a[0]==1 && a[1]==1 && a[2]==1))||((a[3]==1 && a[4]==1 && a[5]==1))||((a[6]==1 && a[7]==1 && a[8]==1)))
		return 1;
	else
		if(((a[0]==1 && a[3]==1 && a[6]==1))||((a[1]==1 && a[4]==1 && a[7]==1))||((a[2]==1 && a[5]==1 && a[8]==1)))
			return 1;
		else
			if(((a[0]==1 && a[4]==1 && a[8]==1))||((a[2]==1 && a[4]==1 && a[6]==1)))
				return 1;
				
	if(((a[0]==2 && a[1]==2 && a[2]==2))||((a[3]==2 && a[4]==2 && a[5]==2))||((a[6]==2 && a[7]==2 && a[8]==2)))
		return 2;
	else
		if(((a[0]==2 && a[3]==2 && a[6]==2))||((a[1]==2 && a[4]==2 && a[7]==2))||((a[2]==2 && a[5]==2 && a[8]==2)))
			return 2;
		else
			if(((a[0]==2 && a[4]==2 && a[8]==2))||((a[2]==2 && a[4]==2 && a[6]==2)))
				return 2;
				
	return -1;			

}
void display(int a[])
{
	for(int i=0;i<9;i++)
	{
		if(a[i]==2)
			cout<<"x ";
		else
			cout<<a[i]<<" ";
		if(i==2||i==5||i==8)
			cout<<"\n";
	}
}
int main()
{
	again:
	system("cls");
	cout<<"Enter the matrix entries by there INDEX position. INITIAL MATRIX\n";
	cout<<"\t0 1 2 \t_ _ x  Enter: 2			0 0 0 \n\t3 4 5 \t_ 0 _  Enter: 4			0 0 0\n\t6 7 8 \t_ _ x  Enter: 8			0 0 0\n";
	
	int win=-1;
	int x,count=0;
	int a[9]={0};
	bool con=true;
	int p1=0,p2=0;
	while(con)
	{
		cout<<"Enter player 1:";cin>>x;a[x]=1;
		++count;
		display(a);	
		if(count>4)
		{
			win=check(a);
			if(win==1)
				break;
		}
		if(count==9)
		{
			con=false;
			break;
		}

		cout<<"Enter player 2:";cin>>x;a[x]=2;
		++count;
		display(a);
		if(count>4)
		{
			win=check(a);
			if(win==2)
				break;
		}
	}

	if(win==-1)
		cout<<"No One is Winner\n";	
	else
		cout<<"Player "<<win<<" Won\n";
	cout<<"\nWant to play again(y/n)";
	char ch;cin>>ch;
	if(ch=='y')
		goto again; 	
return 0;	
}
