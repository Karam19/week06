#include<stdio.h>

int main()
{
    int processes[1000], bt[1000],at[1000],ct[1000],tat[1000],wt[1000];
    int n;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    printf("Enter the brust time for each proceses\n");
    for(int i=0;i<n;i++)
        scanf("%d",&bt[i]);
    printf("Enter the Arrival time for each proceses\n");
    for(int i=0;i<n;i++)
        scanf("%d",&at[i]);
    for(int i=1;i<=n;i++)
        processes[i]=i;

    int sum=0,total_tat=0,total_wt=0;
    //calculate completion time of processes
    for(int j=0;j<n;j++)
    {
        sum+=bt[j];
        ct[j]+=sum;
    }

    //calculate turnaround time and waiting times
    for(int k=0;k<n;k++)
    {
        tat[k]=ct[k]-at[k];
        total_tat+=tat[k];
    }
	//calculate waiting time
    for(int k=0;k<n;k++)
    {
        wt[k]=tat[k]-bt[k];
        total_wt+=wt[k];
    }

    printf("Processes   completion time   Waiting time   Turn around time\n");

    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("         %d ",(i+1));
        printf("             %d ", ct[i] );
        printf("            %d",wt[i] );
        printf("            %d\n",tat[i] );
    }
    int s=(float)total_wt / (float)n;
    int t=(float)total_tat / (float)n;
    printf("Average waiting time = %d",s);
    printf("\n");
    printf("Average turn around time = %d ",t);
    return 0;
}