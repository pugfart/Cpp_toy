#include <iostream>
#include <time.h> 
#include <conio.h> 
#include <windows.h>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <string> 

#define file "record.txt"

using namespace std;

void gotoxy(int,int);
int plane(char,int,int);
void setblock(int i,int x,int block[]);
void block(int block[]);
void record(int k);

int times=0,life=5,kill=0;
int block0[5],block1[5],block2[5],block3[5],block4[5],block5[5],block6[5],block7[5],block8[5],block9[5],block10[5];

int main()
{
	bool start=false,doing;
	char planemove='5',a;
	int x=10,y=20,t,i,j,s,exlife=5;
	
start:	
	cout<<"====�a�V�g���p�C��====\n\n";
	cout<<"��V�䥪�k���������\n";
	cout<<"�ť���o�g\n";
	cout<<"������F�A����m�֤@�R\n";
	cout<<"�@5���R�k�s����\n\n"; 
	system("pause");                                              //�����N��}�l 
	s=clock();
	system("cls");
	gotoxy(0,0);                                                  //�~���쥻���r�����ɶ� 
	cout<<"time                            ";                  
	plane(planemove,x,y);                                         //������l��l 
	
	srand( (unsigned)time(NULL) );
	setblock(0,0,block0);//�U�C��l 
	setblock(0,1,block1);
	setblock(0,2,block2);
	setblock(0,3,block3);
	setblock(0,4,block4);
	setblock(0,5,block5);
	
	setblock(0,6,block6);
	setblock(0,7,block7);
	setblock(0,8,block8);
	setblock(0,9,block9);
	setblock(0,10,block10);
		
	gotoxy(10,0);
	cout<<"life:";
	for(i=0;i<life;i++)
	{
		cout<<char(3);
	}
	while(1)
	{
		doing=false;               //����J�~��getch 
		doing=kbhit();
		if(doing)
		{
			planemove=getch();
			x=plane(planemove,x,y);
		}
		
		if(!((clock()-s)%1000))                                       //�ɶ� 
		{
			t=(clock()-s)/1000;                                           
			gotoxy(6,0);
			cout<<t;
			gotoxy(x,y);
		}
		
		if(life!=exlife)
		{
			gotoxy(15+life,0);
			cout<<" ";
			exlife=life;
		} 
		
		if(times%block0[3]==0)block(block0);
		if(times%block1[3]==0)block(block1);
		if(times%block2[3]==0)block(block2);
		if(times%block3[3]==0)block(block3);
		if(times%block4[3]==0)block(block4);
		if(times%block5[3]==0)block(block5);
		
		if(times%block6[3]==0)block(block6);
		if(times%block7[3]==0)block(block7);
		if(times%block8[3]==0)block(block8);
		if(times%block9[3]==0)block(block9);
		if(times%block10[3]==0)block(block10);
		
		if(life<=0) 
		{
			gotoxy(15,0);
			cout<<" ";
			gotoxy(0,22);
			cout<<"destory "<<kill<<endl;
			record(kill);
			cout<<"�A�Ӥ@��?(Y/N)";
			do{
			cin>>a;
			if(a=='y'||a=='Y') 
			{	
				life=5;
				times=0;	
				system("cls");
				goto start;
			}
			else if(a=='n'||a=='N') 
					{
						break;
					}
			cout<<"\n�п�J\"Y\"�A�Ӥ@����\"N\"����";
			}while(1);
			
			return 0 ;
		}
				
		times++;
	
	}
	return 0;
} 

void gotoxy(int x, int y)                                          //�Ѯv�{�� xy�y�� 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int plane(char move,int x,int y)                                   //���� 
{
	int o;
	char thing='^';
	gotoxy(x,y);
	cout<<"  ";
	switch(move)
	{
		case 0x4B: //���� 
			x-=2;
			if(x<0) x=0;
			gotoxy(x,y);
			cout<<"^^"<<"\b";
			break;
		case 0x4D: //�k�� 
			x=x+2;
			if(x>20) x=20;
			gotoxy(x,y);
			cout<<"^^"<<"\b";
			break;
		case ' '://�g�� 
			o=x/2;
			if(o==0){block0[0]=1;block(block0);}
			if(o==1){block1[0]=1;block(block1);}
			if(o==2){block2[0]=1;block(block2);}
			if(o==3){block3[0]=1;block(block3);}
			if(o==4){block4[0]=1;block(block4);}
			if(o==5){block5[0]=1;block(block5);}
			
			if(o==6){block6[0]=1;block(block6);}
			if(o==7){block7[0]=1;block(block7);}
			if(o==8){block8[0]=1;block(block8);}
			if(o==9){block9[0]=1;block(block9);}
			if(o==10){block10[0]=1;block(block10);}
			
		default:
			gotoxy(x,y);
			cout<<"^^"<<"\b";
			break;
	}
	return x;
}

void setblock(int i,int x,int block[])
{
	block[0]=0;
	block[1]=2*x;
	block[2]=3;
	block[3]=20000+rand()%20000;
	block[4]=rand()%5;
	return;
}

void block(int block[])
{	
	int i;	
	if(block[4]>0)
	{
		block[4]--;
		block[0]=0;
		return;
	}
			
	if(times%block[3]==0)
	{
		if(block[0]==1&&block[4]== 0) 
		{
			gotoxy(block[1],block[2]-1);
			cout<<" ";
			block[2]=2;
			block[3]=20000+rand()%20000;
			block[4]=rand()%5;
			block[0]=0;
			kill++;
			return;
		}
		else
		{
			gotoxy(block[1],block[2]-1);
			cout<<" ";		
		}
		
		if(block[2]>=20) 
		{
			gotoxy(block[1],19);
			cout<<" ";
			block[2]=2;
			block[3]=20000+rand()%30000;
			block[4]=rand()%5;
			life--;
			cout<<"\a";
		}
		else
		{
		gotoxy(block[1],block[2]);
		cout<<"��";
		block[2]++;
		}	
	
	}	
		 
	return;
}

void record(int k)
{
	char get[20],name[5][7],newname[7];
	int num[5],i,j,score[5],n;
	ifstream input;
	ofstream output;
	
	input.open(file,ios::in);//Ū��� 
			
	input.getline(get,20);
	for(i=0;i<5;i++)
		input>>num[i]>>name[i]>>score[i];
	
	input.close();
	output.open(file,ios::out);
	
	for(i=0;i<5;i++)//�W�� 
	{
		if(k>score[i])break;
	}
	
	if(i==5)
	{
		cout<<"���W�] �A���A�F";
		return;
	}
	for(j=4;j>=i;j--)//�ƤJ 
	{
		score[j]=score[j-1];
		for(n=0;n<5;n++)
		{
			name[j][n]=name[j-1][n];
		}
	}
	cout<<"��J�W�l(5�Ӧr����):";
	cin>>newname;
	score[i]=k;
	for(n=0;n<5;n++)
		{
			name[i][n]=newname[n];
		}
	
	
	output<<get<<endl;
	for(i=0;i<5;i++)
	{
		output<<i+1<<" "<<name[i]<<"\t"<<score[i]<<endl;
	}
	
	
	output.close();
	cout<<"��������\n";
	return;
}
