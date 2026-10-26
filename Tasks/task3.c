
#include <stdio.h>

int main()
{
    int stock[3][4];
    int total[3]={0};
    int empty=0,grandTotal=0;
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            scanf("%d",&stock[i][j]);
            total[i]+=stock[i][j];
        }
    }
    
    printf("Original stock:\n");
    
    for(int i=0;i<3;i++)
    {
        printf("Aisle %d: ",i+1);
        
        for(int j=0;j<4;j++)
            printf("%d ",stock[i][j]);
        
        printf("\n");
    }
    
    int maxAisle=0;
    
    for(int i=1;i<3;i++)
    {
        if(total[i]>total[maxAisle])
            maxAisle=i;
    }
    
    printf("\nAisle with most stock: Aisle %d (%d units)\n",
           maxAisle+1,total[maxAisle]);
    
    printf("\nLow stock alerts:\n");
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(stock[i][j]<5)
            {
                printf("Aisle %d, Position %d -> %d units\n",
                       i+1,j+1,stock[i][j]);
                
                if(stock[i][j]==0)
                    empty++;
                
                stock[i][j]+=10;
            }
        }
    }
    
    printf("\nEmpty shelves: %d\n",empty);
    printf("\nStock after restocking:\n");
    
    for(int i=0;i<3;i++)
    {
        printf("Aisle %d: ",i+1);
        
        for(int j=0;j<4;j++)
        {
            printf("%d ",stock[i][j]);
            grandTotal+=stock[i][j];
        }
        
        printf("\n");
    }
    
    printf("\nNew grand total: %d units\n",grandTotal);
    
    return 0;
}

