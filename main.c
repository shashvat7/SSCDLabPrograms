#include <stdio.h>
#include <stdlib.h>


//global variables for universal usage
int totalwt,totaltat;


//a structure that will hold data of each process
struct fcfs
{
    int pid;
    int bt;
    int at;
    int wt,tat;
};

int main()
{
    int i,j,k,n;
    printf("\n Enter no. of processes: ");
    scanf("%d",&n);

    struct fcfs ar[n];

    //input details for each process
    for(i=0;i<n;i++)
    {
        ar[i].pid=i+1;
        printf("\n Enter arrival time and burst time for process %d : ",ar[i].pid);
        scanf("%d %d",&ar[i].at,&ar[i].bt);
    }



    //bubble sorting processes on the basis of arrival time
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(ar[j].at > ar[j+1].at)
            {
                struct fcfs temp;
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }



//calculating wait and turnaround time for each process
for(i=0;i<n;i++)
{
    if(i==0)
    {
        ar[i].wt=0;
    }

    else{
    ar[i].wt = totalwt-ar[i].at;
    }

    totalwt+=ar[i].bt;
    ar[i].tat=ar[i].wt + ar[i].bt;
    totaltat+=ar[i].tat;
}

//display individual details
for(i=0;i<n;i++)
{
    printf("\n For process %d : \n Waiting time = %d \t\t TurnAround time = %d\n",ar[i].pid,ar[i].wt,ar[i].tat);
}


//average turnaround and wait time
int turn=0,waitt=0;
float avgturn,avgwait;
for(i=0;i<n;i++)
{
    turn+=ar[i].tat;
    waitt+=ar[i].wt;
}

avgturn = (float)turn/n;
avgwait = (float)waitt/n;

printf("\n Average wait time = %f \n Average TurnAround time = %f",avgwait,avgturn);


return 0;

}
