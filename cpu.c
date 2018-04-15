#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct process
{
    int burst_time,wait_time,turn_time,process_id;
}pro[5];
void write()
{
    FILE *f;
    int v;
    printf("enter 5 cpu bursts");
    f=fopen("CPUBURST.txt","w");
    for(int i=0;i<5;i++)
    {
    scanf("%d",&v);
    putw(v,f);
    }
    fclose(f);
}
void waiting_time()
{
        pro[0].wait_time=0;
        for(int j=1;j<5;j++){
        pro[j].wait_time = pro[j-1].burst_time + pro[j-1].wait_time;
        }
}
void turnaround_time()
{
    for(int j=0;j<5;j++){
        pro[j].turn_time = pro[j].burst_time + pro[j].wait_time;
        }

}
void print()
{
    printf("process no\tburst time\twait time\tturn around time\n");
for(int i=0;i<5;i++)
{
    printf("p%d\t\t%d\t\t%d\t\t%d\n",pro[i].process_id,pro[i].burst_time,pro[i].wait_time,pro[i].turn_time);
}
}
void read()
{
int i=0;
FILE *fp;
fp=fopen("CPUBURST.txt","r");
if(fp==NULL)
{
    printf("file does not exist");
    exit(1);
}
for(i=0;i<5;i++)
{
    if(getc(fp)>=0)
    {
    pro[i].burst_time=getw(fp);
    pro[i].process_id=i+1;
    }
    else
    {
        printf("this file contains negative numbers ");
        exit(1);
    }
}
fclose(fp);
}
int main()
{
    int choice;
    struct process exp;
    printf("1 for reading the existing cpu Burst\n2 for writing new cpu Bursts\nenter your choice : ");
    scanf("%d",&choice);
        switch(choice)
        {
      case 1:
        read();
        for(int i=0;i<4;i++)
        {for(int j=i+1;j<5;j++){
        if(pro[i].burst_time>pro[j].burst_time)
        {
            exp=pro[i];
            pro[i]=pro[j];
            pro[j]=exp;
        }
        }}
        waiting_time();
        turnaround_time();
        print();
        break;
      case 2:
        write();
        printf("if you want to display SHORTEST JOB FIRST press 1:");
        scanf("%d",&choice);
        break;
      default:
          printf("wrong input");
        exit(1);
        }
    
}
