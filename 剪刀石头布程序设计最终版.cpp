#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct player{
	char name[10];
	int win,lose,draw,sum,df;
};
void input_player(struct player *p,int m,int n,int i);
void output_player(struct player pr[],int m,int n);
void sort_player(struct player p[],int m,int n);
void input_player1(struct player *p,int m,int n,int i);
void output_player1(struct player pr[],int m,int n);
void main()
{	
	struct player pr[10],*p=pr;
     FILE * fp;
	int i,m,n;
	if((fp=fopen("jl.txt","w"))==NULL){
       printf("打开文件错误！\n");
	   exit(0);
	}
	printf("        ||<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>||\n");
    printf("        ||                    欢迎来到剪刀石头布游戏                      ||\n");
    printf("        ||                    准备好了么，开始吧！！！                    ||\n");
    printf("        ||________________________________________________________________||\n");
	printf("\n");
	printf("        ***************************************************************\n");
	printf("        *                   《《请选择游戏模式》》                    *\n");
	printf("        *                        1---练习模式                         *\n");
	printf("        *                        2---人机对战模式                     *\n");
	printf("        *                        3---天梯模式                         *\n");
	printf("        ***************************************************************\n");
	while(1){
	scanf("%d",&m);
	if(m==4) break;
	switch(m){
	case 1:
		n=0;i=0;
        input_player(p,m,n,i);
		fwrite(&pr,sizeof(pr),1,fp);
		output_player(p,m,n);
		break;
	case 2:
		int w,l,d;
		printf("欢迎来到人机对战模式\n");
		printf("游戏规则五局三胜。\n");
		printf("如果五局之内无法分出胜负则进入突然死亡模式\n");
		n=1;i=0;
		input_player(p,m,n,i);
		if(pr[i].sum<5&&pr[i].win<3&&pr[i].sum<5&&pr[i].lose<3&&pr[i].draw!=3){
			printf("玩家没有完成游戏\n");
            output_player(p,m,n);
		}
		else if(pr[i].win==3||pr[i].lose==3){
		fwrite(&pr,sizeof(pr),1,fp);
			output_player(p,m,n);}
		else {
			printf("\n");
			printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
			printf("<                进入突然死亡模式；祝你好运！！                <\n");
			printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
			w=pr[i].win;
			l=pr[i].lose;
			d=pr[i].draw;
		    input_player1(p,m,n,i);
			pr[i].draw=pr[i].draw+d;
			pr[i].lose=pr[i].lose+l;
			pr[i].win=pr[i].win+w;
		fwrite(&pr,sizeof(pr),1,fp);
			output_player1(p,m,n);
			if(pr[i].win>w){
                printf("         <><><><><><><><><><><><><>\n");
				printf("         <          你赢了        >\n");
				printf("         <><><><><><><><><><><><><>\n");
			}
			else{
               printf("\n");
               printf("         <><><><><><><><><><><><><>\n");
               printf("         <          你输了        >\n");
			   printf("         <><><><><><><><><><><><><>\n");
			}

		}
		break;
	case 3:	
		printf("欢迎来到天梯模式\n");
		printf("游戏规则\n");
		printf("1、赢一盘积3分,平局积1分，输一盘积0分\n");
		printf("2、进行十盘游戏，没有完成游戏积分为零\n");
	    printf("3、游戏结果按分数高低排列\n");
		printf("请输入玩家人数\n");
		scanf("%d",&n);

	
		for(i=0;i<n;i++)
		{
		printf("请输入第%d个玩家昵称\n",i+1);
		scanf("%s",pr[i].name);
		printf("请玩家%s开始游戏\n",pr[i].name);
        input_player(p,m,n,i);
		fwrite(&pr,sizeof(pr),1,fp);
		}
        output_player(p,m,n);
		break;
}
	int q;
	printf("是否继续进行其他模式：是————输入1；否————输入2\n");
    scanf("%d",&q);
	if(q==1){
	printf("输入1：进行练习模式   输入2：进行人机模式    输入3：进行天梯模式   输入4：退出游戏\n");
	i=0;
	}
	else 
		break;
	if(fclose(fp)){
		printf("关闭文件错误！\n");
		exit(0);
	}
}
}
void input_player(struct player *p,int m,int n,int i)
{
int win=0,lose=0,draw=0;

switch(m){
case 1:
int k,sel;
printf("输入1开始游戏，输入2退出游戏\n");
while(1)
{
	srand((unsigned)time(NULL));
    n=rand()%(2-0+1)+1;
scanf("%d",&k);
if(k==2)break;

printf("请输入1,2,3。           1代表石头，2代表剪刀，3代表布   \n");
scanf("%d",&sel);
switch(sel)
{
		
case 1:

	if(n<=1) {
		printf("你出石头，电脑出石头，平局\n");

	draw=draw+1;	break;}
	else if(n>1&&n<=2) {
		printf("你出石头，电脑出剪刀，你赢\n");
		win++;
	win=win;	break;}
	else {
		printf("你出石头，电脑出布，你输\n");
	lose=lose+1;	break;}
case 2:

	if(n<=1){
       printf("你出剪刀，电脑出石头，你输\n");
	  lose=lose+1;break;}
	else if(n>1&&n<=2){
		printf("你出剪刀，电脑出剪刀，平局\n");
	draw=draw+1;break;}

	else{
		printf("你出剪刀，电脑出布，你赢\n");

	win=win+1;break;}
case 3:

	if(n<=1){
		printf("你出布，电脑出石头，你赢\n");
		win++;
    	win=win+1;break;}
	else if(n>1&&n<=2){
		printf("你出布，电脑出剪刀，你输\n");
	lose=lose+1;break;}
	else{
		printf("你出布，电脑出布，平局\n");

		draw=draw+1;break;}
default:
	printf("输入错误\n");break;

}
printf("输入1继续游戏，输入2退出游戏\n");

}
p[i].win=win;
p[i].lose=lose;
p[i].draw=draw;
p[i].sum=win+lose+draw;
break;
case 2:
int k1,sel1;
printf("输入1开始游戏，输入2退出游戏\n");
while(1)
{
	srand((unsigned)time(NULL));
    n=rand()%(2-0+1)+1;
scanf("%d",&k1);
if(k1==2)break;

printf("请输入1,2,3。           1代表石头，2代表剪刀，3代表布   \n");
scanf("%d",&sel1);
switch(sel1)
{
		
case 1:

	if(n<=1) {
		printf("你出石头，电脑出石头，平局\n");

	draw=draw+1;	break;}
	else if(n>1&&n<=2) {
		printf("你出石头，电脑出剪刀，你赢\n");
		win++;
	win=win;	break;}
	else {
		printf("你出石头，电脑出布，你输\n");
	lose=lose+1;	break;}
case 2:

	if(n<=1){
       printf("你出剪刀，电脑出石头，你输\n");
	  lose=lose+1;break;}
	else if(n>1&&n<=2){
		printf("你出剪刀，电脑出剪刀，平局\n");
	draw=draw+1;break;}

	else{
		printf("你出剪刀，电脑出布，你赢\n");

	win=win+1;break;}
case 3:

	if(n<=1){
		printf("你出布，电脑出石头，你赢\n");
		win++;
    	win=win+1;break;}
	else if(n>1&&n<=2){
		printf("你出布，电脑出剪刀，你输\n");
	lose=lose+1;break;}
	else{
		printf("你出布，电脑出布，平局\n");

		draw=draw+1;break;}
default:
	printf("输入错误\n");break;

}
if(win+lose+draw==5||win==3||lose==3||draw==3) break;
else
printf("输入1继续游戏，输入2退出游戏\n");
}
p[i].win=win;
p[i].lose=lose;
p[i].draw=draw;
p[i].sum=win+lose+draw;
break;
case 3:
int k2,sel2,r=9;
printf("输入1开始游戏，输入2退出游戏\n");
while(1)
{
	srand((unsigned)time(NULL));
    n=rand()%(2-0+1)+1;
scanf("%d",&k2);
if(k2==2)break;

printf("请输入1,2,3。           1代表石头，2代表剪刀，3代表布   \n");
scanf("%d",&sel2);
switch(sel2)
{
		
case 1:

	if(n<=1) {
		printf("你出石头，电脑出石头，平局\n");

	draw=draw+1;	break;}
	else if(n>1&&n<=2) {
		printf("你出石头，电脑出剪刀，你赢\n");
		win++;
	win=win;	break;}
	else {
		printf("你出石头，电脑出布，你输\n");
	lose=lose+1;	break;}
case 2:

	if(n<=1){
       printf("你出剪刀，电脑出石头，你输\n");
	  lose=lose+1;break;}
	else if(n>1&&n<=2){
		printf("你出剪刀，电脑出剪刀，平局\n");
	draw=draw+1;break;}

	else{
		printf("你出剪刀，电脑出布，你赢\n");

	win=win+1;break;}
case 3:

	if(n<=1){
		printf("你出布，电脑出石头，你赢\n");
		win++;
    	win=win+1;break;}
	else if(n>1&&n<=2){
		printf("你出布，电脑出剪刀，你输\n");
	lose=lose+1;break;}
	else{
		printf("你出布，电脑出布，平局\n");

		draw=draw+1;break;}
default:
	printf("输入错误\n");break;

}
printf("还剩余%d盘游戏\n",r);
r--;
printf("输入1继续游戏，输入2退出游戏\n");
if(win+lose+draw==10) break;
}
if(win+lose+draw<10){
	printf("没有完成游戏；积分为零\n");
p[i].win=win;
p[i].lose=lose;
p[i].draw=draw;
p[i].df=0;
break;
}
else{
p[i].win=win;
p[i].lose=lose;
p[i].draw=draw;
p[i].df=p[i].win*3+p[i].draw;
break;
}
}
}

void sort_player(struct player *p,int m,int n)
{
	int i,j,index;
	struct player temp;
	for(i=0;i<n-1;i++){
	index=i;
	for(j=i;j<n;j++) if(p[j].df>p[index].df) index=j;
	temp=p[i];p[i]=p[index];p[index]=temp;
	}
}
void output_player(struct player *p,int m,int n)
{
	int i;
	switch(m){
	case 1:
		i=0;
	p[i].sum=p[i].win+p[i].lose+p[i].draw;
printf("\n");
printf("                            《》《》《》《》《》《》《》\n");
printf("                            《        游戏结果        》\n");
printf("                            《》《》《》《》《》《》《》\n");
printf("                            +++++++++++++++++++++++\n");
printf("                            +  win=%d              +\n",p[i].win);
printf("                            +  lose=%d             +\n",p[i].lose);
printf("                            +  draw=%d             +\n",p[i].draw);
printf("                            +  你玩了%d盘          +\n",p[i].sum);
printf("                            +++++++++++++++++++++++\n");
break;
	case 2:
		i=0;
p[i].sum=p[i].win+p[i].lose+p[i].draw;
printf("\n");
printf("                            《》《》《》《》《》《》《》\n");
printf("                            《        游戏结果        》\n");
printf("                            《》《》《》《》《》《》《》\n");
printf("                            +++++++++++++++++++++++\n");
printf("                            +  win=%d              +\n",p[i].win);
printf("                            +  lose=%d             +\n",p[i].lose);
printf("                            +  draw=%d             +\n",p[i].draw);
printf("                            +  你玩了%d盘          +\n",p[i].sum);
printf("                            +++++++++++++++++++++++\n");
if(p[i].win==3){
printf("\n");
printf("         <><><><><><><><><><><><><>\n");
printf("         <        你赢了          >\n");
printf("         <><><><><><><><><><><><><>\n");
}
else{ 
printf("\n");
printf("         <><><><><><><><><><><><><>\n");
printf("         <        你输了          >\n");
printf("         <><><><><><><><><><><><><>\n");
}
break;
	case 3:	
		int i;
         sort_player(p,m,n);
		 printf("世界排名\n");
	printf("昵称      赢的局数        输的局数        平局的局数     得分\n");
		for(i=0;i<n;i++)
		{
			printf("%s",p[i].name);
            printf("%15d",p[i].win);
            printf("%15d",p[i].lose);
            printf("%15d",p[i].draw);
            printf("%15d",p[i].df);
			printf("\n");
		}
		break;
	}
}
void input_player1(struct player *p,int m,int n,int i)
{
int k3,sel3,win=0,lose=0,draw=0;
printf("输入1开始游戏，输入2退出游戏\n");
while(1)
{
	srand((unsigned)time(NULL));
    n=rand()%(2-0+1)+1;
scanf("%d",&k3);
if(k3==2)break;

printf("请输入1,2,3。           1代表石头，2代表剪刀，3代表布   \n");
scanf("%d",&sel3);
switch(sel3)
{
		
case 1:

	if(n<=1) {
		printf("你出石头，电脑出石头，平局\n");

	draw=draw+1;	break;}
	else if(n>1&&n<=2) {
		printf("你出石头，电脑出剪刀，你赢\n");
		win++;
	win=win;	break;}
	else {
		printf("你出石头，电脑出布，你输\n");
	lose=lose+1;	break;}
case 2:

	if(n<=1){
       printf("你出剪刀，电脑出石头，你输\n");
	  lose=lose+1;break;}
	else if(n>1&&n<=2){
		printf("你出剪刀，电脑出剪刀，平局\n");
	draw=draw+1;break;}

	else{
		printf("你出剪刀，电脑出布，你赢\n");

	win=win+1;break;}
case 3:

	if(n<=1){
		printf("你出布，电脑出石头，你赢\n");
		win++;
    	win=win+1;break;}
	else if(n>1&&n<=2){
		printf("你出布，电脑出剪刀，你输\n");
	lose=lose+1;break;}
	else{
		printf("你出布，电脑出布，平局\n");

		draw=draw+1;break;}
default:
	printf("输入错误\n");break;

}
if(win>0||lose>0) break;
printf("输入1继续游戏，输入2退出游戏\n");
}
p[i].win=win;
p[i].lose=lose;
p[i].draw=draw;
}
void output_player1(struct player pr[],int m,int n)
{
		int i=0;
pr[i].sum=pr[i].win+pr[i].lose+pr[i].draw;
printf("\n");
printf("                            《》《》《》《》《》《》《》\n");
printf("                            《        游戏结果        》\n");
printf("                            《》《》《》《》《》《》《》\n");
printf("                            +++++++++++++++++++++++\n");
printf("                            +  win=%d              +\n",pr[i].win);
printf("                            +  lose=%d             +\n",pr[i].lose);
printf("                            +  draw=%d             +\n",pr[i].draw);
printf("                            +  你玩了%d盘          +\n",pr[i].sum);
printf("                            +++++++++++++++++++++++\n");
}