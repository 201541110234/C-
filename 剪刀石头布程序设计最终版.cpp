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
       printf("���ļ�����\n");
	   exit(0);
	}
	printf("        ||<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>||\n");
    printf("        ||                    ��ӭ��������ʯͷ����Ϸ                      ||\n");
    printf("        ||                    ׼������ô����ʼ�ɣ�����                    ||\n");
    printf("        ||________________________________________________________________||\n");
	printf("\n");
	printf("        ***************************************************************\n");
	printf("        *                   ������ѡ����Ϸģʽ����                    *\n");
	printf("        *                        1---��ϰģʽ                         *\n");
	printf("        *                        2---�˻���սģʽ                     *\n");
	printf("        *                        3---����ģʽ                         *\n");
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
		printf("��ӭ�����˻���սģʽ\n");
		printf("��Ϸ���������ʤ��\n");
		printf("������֮���޷��ֳ�ʤ�������ͻȻ����ģʽ\n");
		n=1;i=0;
		input_player(p,m,n,i);
		if(pr[i].sum<5&&pr[i].win<3&&pr[i].sum<5&&pr[i].lose<3&&pr[i].draw!=3){
			printf("���û�������Ϸ\n");
            output_player(p,m,n);
		}
		else if(pr[i].win==3||pr[i].lose==3){
		fwrite(&pr,sizeof(pr),1,fp);
			output_player(p,m,n);}
		else {
			printf("\n");
			printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
			printf("<                ����ͻȻ����ģʽ��ף����ˣ���                <\n");
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
				printf("         <          ��Ӯ��        >\n");
				printf("         <><><><><><><><><><><><><>\n");
			}
			else{
               printf("\n");
               printf("         <><><><><><><><><><><><><>\n");
               printf("         <          ������        >\n");
			   printf("         <><><><><><><><><><><><><>\n");
			}

		}
		break;
	case 3:	
		printf("��ӭ��������ģʽ\n");
		printf("��Ϸ����\n");
		printf("1��Ӯһ�̻�3��,ƽ�ֻ�1�֣���һ�̻�0��\n");
		printf("2������ʮ����Ϸ��û�������Ϸ����Ϊ��\n");
	    printf("3����Ϸ����������ߵ�����\n");
		printf("�������������\n");
		scanf("%d",&n);

	
		for(i=0;i<n;i++)
		{
		printf("�������%d������ǳ�\n",i+1);
		scanf("%s",pr[i].name);
		printf("�����%s��ʼ��Ϸ\n",pr[i].name);
        input_player(p,m,n,i);
		fwrite(&pr,sizeof(pr),1,fp);
		}
        output_player(p,m,n);
		break;
}
	int q;
	printf("�Ƿ������������ģʽ���ǡ�����������1���񡪡���������2\n");
    scanf("%d",&q);
	if(q==1){
	printf("����1��������ϰģʽ   ����2�������˻�ģʽ    ����3����������ģʽ   ����4���˳���Ϸ\n");
	i=0;
	}
	else 
		break;
	if(fclose(fp)){
		printf("�ر��ļ�����\n");
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
printf("����1��ʼ��Ϸ������2�˳���Ϸ\n");
while(1)
{
	srand((unsigned)time(NULL));
    n=rand()%(2-0+1)+1;
scanf("%d",&k);
if(k==2)break;

printf("������1,2,3��           1����ʯͷ��2���������3����   \n");
scanf("%d",&sel);
switch(sel)
{
		
case 1:

	if(n<=1) {
		printf("���ʯͷ�����Գ�ʯͷ��ƽ��\n");

	draw=draw+1;	break;}
	else if(n>1&&n<=2) {
		printf("���ʯͷ�����Գ���������Ӯ\n");
		win++;
	win=win;	break;}
	else {
		printf("���ʯͷ�����Գ���������\n");
	lose=lose+1;	break;}
case 2:

	if(n<=1){
       printf("������������Գ�ʯͷ������\n");
	  lose=lose+1;break;}
	else if(n>1&&n<=2){
		printf("������������Գ�������ƽ��\n");
	draw=draw+1;break;}

	else{
		printf("������������Գ�������Ӯ\n");

	win=win+1;break;}
case 3:

	if(n<=1){
		printf("����������Գ�ʯͷ����Ӯ\n");
		win++;
    	win=win+1;break;}
	else if(n>1&&n<=2){
		printf("����������Գ�����������\n");
	lose=lose+1;break;}
	else{
		printf("����������Գ�����ƽ��\n");

		draw=draw+1;break;}
default:
	printf("�������\n");break;

}
printf("����1������Ϸ������2�˳���Ϸ\n");

}
p[i].win=win;
p[i].lose=lose;
p[i].draw=draw;
p[i].sum=win+lose+draw;
break;
case 2:
int k1,sel1;
printf("����1��ʼ��Ϸ������2�˳���Ϸ\n");
while(1)
{
	srand((unsigned)time(NULL));
    n=rand()%(2-0+1)+1;
scanf("%d",&k1);
if(k1==2)break;

printf("������1,2,3��           1����ʯͷ��2���������3����   \n");
scanf("%d",&sel1);
switch(sel1)
{
		
case 1:

	if(n<=1) {
		printf("���ʯͷ�����Գ�ʯͷ��ƽ��\n");

	draw=draw+1;	break;}
	else if(n>1&&n<=2) {
		printf("���ʯͷ�����Գ���������Ӯ\n");
		win++;
	win=win;	break;}
	else {
		printf("���ʯͷ�����Գ���������\n");
	lose=lose+1;	break;}
case 2:

	if(n<=1){
       printf("������������Գ�ʯͷ������\n");
	  lose=lose+1;break;}
	else if(n>1&&n<=2){
		printf("������������Գ�������ƽ��\n");
	draw=draw+1;break;}

	else{
		printf("������������Գ�������Ӯ\n");

	win=win+1;break;}
case 3:

	if(n<=1){
		printf("����������Գ�ʯͷ����Ӯ\n");
		win++;
    	win=win+1;break;}
	else if(n>1&&n<=2){
		printf("����������Գ�����������\n");
	lose=lose+1;break;}
	else{
		printf("����������Գ�����ƽ��\n");

		draw=draw+1;break;}
default:
	printf("�������\n");break;

}
if(win+lose+draw==5||win==3||lose==3||draw==3) break;
else
printf("����1������Ϸ������2�˳���Ϸ\n");
}
p[i].win=win;
p[i].lose=lose;
p[i].draw=draw;
p[i].sum=win+lose+draw;
break;
case 3:
int k2,sel2,r=9;
printf("����1��ʼ��Ϸ������2�˳���Ϸ\n");
while(1)
{
	srand((unsigned)time(NULL));
    n=rand()%(2-0+1)+1;
scanf("%d",&k2);
if(k2==2)break;

printf("������1,2,3��           1����ʯͷ��2���������3����   \n");
scanf("%d",&sel2);
switch(sel2)
{
		
case 1:

	if(n<=1) {
		printf("���ʯͷ�����Գ�ʯͷ��ƽ��\n");

	draw=draw+1;	break;}
	else if(n>1&&n<=2) {
		printf("���ʯͷ�����Գ���������Ӯ\n");
		win++;
	win=win;	break;}
	else {
		printf("���ʯͷ�����Գ���������\n");
	lose=lose+1;	break;}
case 2:

	if(n<=1){
       printf("������������Գ�ʯͷ������\n");
	  lose=lose+1;break;}
	else if(n>1&&n<=2){
		printf("������������Գ�������ƽ��\n");
	draw=draw+1;break;}

	else{
		printf("������������Գ�������Ӯ\n");

	win=win+1;break;}
case 3:

	if(n<=1){
		printf("����������Գ�ʯͷ����Ӯ\n");
		win++;
    	win=win+1;break;}
	else if(n>1&&n<=2){
		printf("����������Գ�����������\n");
	lose=lose+1;break;}
	else{
		printf("����������Գ�����ƽ��\n");

		draw=draw+1;break;}
default:
	printf("�������\n");break;

}
printf("��ʣ��%d����Ϸ\n",r);
r--;
printf("����1������Ϸ������2�˳���Ϸ\n");
if(win+lose+draw==10) break;
}
if(win+lose+draw<10){
	printf("û�������Ϸ������Ϊ��\n");
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
printf("                            ����������������������������\n");
printf("                            ��        ��Ϸ���        ��\n");
printf("                            ����������������������������\n");
printf("                            +++++++++++++++++++++++\n");
printf("                            +  win=%d              +\n",p[i].win);
printf("                            +  lose=%d             +\n",p[i].lose);
printf("                            +  draw=%d             +\n",p[i].draw);
printf("                            +  ������%d��          +\n",p[i].sum);
printf("                            +++++++++++++++++++++++\n");
break;
	case 2:
		i=0;
p[i].sum=p[i].win+p[i].lose+p[i].draw;
printf("\n");
printf("                            ����������������������������\n");
printf("                            ��        ��Ϸ���        ��\n");
printf("                            ����������������������������\n");
printf("                            +++++++++++++++++++++++\n");
printf("                            +  win=%d              +\n",p[i].win);
printf("                            +  lose=%d             +\n",p[i].lose);
printf("                            +  draw=%d             +\n",p[i].draw);
printf("                            +  ������%d��          +\n",p[i].sum);
printf("                            +++++++++++++++++++++++\n");
if(p[i].win==3){
printf("\n");
printf("         <><><><><><><><><><><><><>\n");
printf("         <        ��Ӯ��          >\n");
printf("         <><><><><><><><><><><><><>\n");
}
else{ 
printf("\n");
printf("         <><><><><><><><><><><><><>\n");
printf("         <        ������          >\n");
printf("         <><><><><><><><><><><><><>\n");
}
break;
	case 3:	
		int i;
         sort_player(p,m,n);
		 printf("��������\n");
	printf("�ǳ�      Ӯ�ľ���        ��ľ���        ƽ�ֵľ���     �÷�\n");
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
printf("����1��ʼ��Ϸ������2�˳���Ϸ\n");
while(1)
{
	srand((unsigned)time(NULL));
    n=rand()%(2-0+1)+1;
scanf("%d",&k3);
if(k3==2)break;

printf("������1,2,3��           1����ʯͷ��2���������3����   \n");
scanf("%d",&sel3);
switch(sel3)
{
		
case 1:

	if(n<=1) {
		printf("���ʯͷ�����Գ�ʯͷ��ƽ��\n");

	draw=draw+1;	break;}
	else if(n>1&&n<=2) {
		printf("���ʯͷ�����Գ���������Ӯ\n");
		win++;
	win=win;	break;}
	else {
		printf("���ʯͷ�����Գ���������\n");
	lose=lose+1;	break;}
case 2:

	if(n<=1){
       printf("������������Գ�ʯͷ������\n");
	  lose=lose+1;break;}
	else if(n>1&&n<=2){
		printf("������������Գ�������ƽ��\n");
	draw=draw+1;break;}

	else{
		printf("������������Գ�������Ӯ\n");

	win=win+1;break;}
case 3:

	if(n<=1){
		printf("����������Գ�ʯͷ����Ӯ\n");
		win++;
    	win=win+1;break;}
	else if(n>1&&n<=2){
		printf("����������Գ�����������\n");
	lose=lose+1;break;}
	else{
		printf("����������Գ�����ƽ��\n");

		draw=draw+1;break;}
default:
	printf("�������\n");break;

}
if(win>0||lose>0) break;
printf("����1������Ϸ������2�˳���Ϸ\n");
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
printf("                            ����������������������������\n");
printf("                            ��        ��Ϸ���        ��\n");
printf("                            ����������������������������\n");
printf("                            +++++++++++++++++++++++\n");
printf("                            +  win=%d              +\n",pr[i].win);
printf("                            +  lose=%d             +\n",pr[i].lose);
printf("                            +  draw=%d             +\n",pr[i].draw);
printf("                            +  ������%d��          +\n",pr[i].sum);
printf("                            +++++++++++++++++++++++\n");
}