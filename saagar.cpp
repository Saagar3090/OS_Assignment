#include<stdio.h>
 
int main()
{
    int at[20],bt[20],xt[20],yt[20],ct[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp,count=0;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
    
    printf("\nEnter Arrival Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&at[i]);
        p[i]=i+1;           //contains process number
    }
 
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;           //contains process number
    }
    for(i=0;i<n;i++)
    {
    	xt[i]=bt[i];
	}
 
    //sorting arrival time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(at[j]<at[pos])
                pos=j;
        }
 
        temp=at[i];
        at[i]=at[pos];
        at[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
for(i=0;i<n;i++){
	ct[i]=0;
	xt[i]=0;
	yt[i]=0;
}    

    for(i=0;i<n;i++)
    {
    	if(bt[i]>3)
    	{
    		xt[i]=bt[i]-3;
    		count=count+3;
		}
		else{
			ct[i]=bt[i]+count;
			count=count+bt[i];
		}
	}
for(i=0;i<n;i++)
    {
    	if(ct[i]==0){
    		if(xt[i]>6)
    		{
    			yt[i]=xt[i]-6;
    			count=count+6;
			}
			else{
				ct[i]=xt[i]+count;
				count=count+xt[i];
			}
			}
}
for(i=0;i<=n;i++)
	{
		if(ct[i]==0)
		{
			ct[i]=count+yt[i];
			count=ct[i];
								
		}
}

for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];     //calculate turnaround time
        total+=tat[i];
    }
    avg_tat=(float)total/n;     //average turnaround time
    total=0;
 
 
    //calculate waiting time
    for(i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      //average waiting time
 
    printf("\nProcess\t     Arrival Time	Burst Time	  Completition Time    \tTurnaround Time  Waiting Time");
    for(i=0;i<n;i++)
    {
        printf("\np%d\t\t  %d\t\t  %d\t\t	%d\t\t    %d\t\t\t%d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
 
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}
