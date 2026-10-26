
#include <stdio.h>

int main()
{
    int seats[5][6]={0};
    int row,col,booked=0,empty,maxRow=0;
    int count[5]={0};
    
    while(1)
    {
        scanf("%d",&row);
        
        if(row==-1)
            break;
        
        scanf("%d",&col);
        
        if(row<1 || row>5 || col<1 || col>6)
        {
            printf("Error: Invalid row or column!\n");
            continue;
        }
        
        if(seats[row-1][col-1]==1)
            printf("Error: Seat already booked!\n");
        else
        {
            seats[row-1][col-1]=1;
            count[row-1]++;
            printf("Seat booked successfully.\n");
        }
    }
    
    printf("Seating Chart:\n");
    printf("   123456\n");
    
    for(int i=0;i<5;i++)
    {
        printf("Row %d ",i+1);
        
        for(int j=0;j<6;j++)
        {
            if(seats[i][j]==1)
                printf("X ");
            else
                printf("O ");
        }
        
        printf("\n");
    }
    
    for(int i=0;i<5;i++)
    {
        booked+=count[i];
        
        if(count[i]>count[maxRow])
            maxRow=i;
    }
    
    empty=30-booked;
    
    printf("Total booked seats: %d\n",booked);
    printf("Total empty seats: %d\n",empty);
    printf("Row with most bookings: Row %d\n",maxRow+1);
    
    return 0;
}

