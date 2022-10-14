

#include<stdio.h>
#include<time.h>
void sort(int s[], int f[], int act_no[], int n) 
{  
    int temp;
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-1-i; j++)
        {
            if (f[j] > f[j+1])
            {
                temp=f[j];
                f[j]=f[j+1];
                f[j+1]=temp;

                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
                
                temp=act_no[j];
                act_no[j]=act_no[j+1];
                act_no[j+1]=temp;            
            }
        }        
    }
}

void printMaxActivities(int s[], int f[], int act_no[], int n)
{
    int i, j;
 
    printf ("Following activities are selected \n");
    int k=0;
    i = 0;
    printf("%d ",act_no[i]);
    
    for (j = 1; j < n; j++)
    {
      
      if (s[j] >= f[i])
      {
          printf("%d ", act_no[j]);
          i = j;
      }
    }

    printf("\n");
}

int main()
{
    clock_t begin,end;
    int n;
    printf(" Enter no. of activities: ");
    scanf("%d",&n);
    int s[n];
    int f[n]; 
    int ac_no[n];
    for(int i=0; i<n; i++)
    {
        ac_no[i]=i+1;
    }
    printf("ENTER THE START TIME OF \n");
    for(int i=0;i<n;i++)
    {  
        printf("%d. Activity %d: ", i+1, i+1);
        scanf("%d", &s[i]); 
    }
    printf("ENTER THE FINISH TIME OF \n");
    for(int i=0;i<n;i++)
    {  
        printf("%d. Activity %d: ", i+1, i+1);
        scanf("%d", &f[i]);
    }
    for(int i=0; i<n; i++)
    {
        printf("%d ", ac_no[i]); 
    }
    printf("\n");
    begin = clock();
    sort(s,f,ac_no,n);
    end = clock();
    printMaxActivities(s, f,ac_no, n);
    float TT = (float)(end-begin)/CLOCKS_PER_SEC;
    printf("Time taken: %.15f s",TT);
    return 0;
}
