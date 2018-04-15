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
    printf("enter 5 cpu bursts(no negative inputs) : ");
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
printf("execution order : ");
    for(int i=0;i<5;i++)
    {
        printf("P%d\t",pro[i].process_id);
    }
    printf("\n");
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

    pro[i].burst_time=getw(fp);
    pro[i].process_id=i+1;

}
for(i=0;i<5;i++)
    {
        if(pro[i].burst_time<0)
        {
            printf("file contains negative numbers please write positive numbers on file ");
            exit(1);
        }
    }
fclose(fp);
}
int main()
{
    int choice;
    char q='a';
    struct process exp;
    while(q!='q')
    {
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
        printf("to exit press q to continue press any key : ");
        fflush(stdin);
        scanf("%c",&q);
        break;
      case 2:
        write();
        printf("to exit press q to continue press any key : ");
        fflush(stdin);
        scanf("%c",&q);
        break;
      default:
          printf("wrong input\n");
          printf("to exit press q to continue press any key : ");
          fflush(stdin);
          scanf("%c",&q);
        }
    }
}
