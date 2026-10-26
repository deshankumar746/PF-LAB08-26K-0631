#include <stdio.h>

int main()
{
    int beds[2][3][2]={0};
    int choice;
    
    do
    {
        printf("1. Admit\n");
        printf("2. Discharge\n");
        printf("3. Report\n");
        printf("4. Exit\n");
        scanf("%d",&choice);
        
        if(choice==1)
        {
            int floor,id,found=0;
            scanf("%d%d",&floor,&id);
            
            if(floor<1 || floor>2)
            {
                printf("Invalid floor.\n");
                continue;
            }
            
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<2;j++)
                {
                    if(beds[floor-1][i][j]==0 && found==0)
                    {
                        beds[floor-1][i][j]=id;
                        printf("Patient %d admitted: Floor %d, Ward %d, Bed %d.\n",
                               id,floor,i+1,j+1);
                        found=1;
                    }
                }
            }
            
            if(found==0)
                printf("Floor %d is full.\n",floor);
        }
        else if(choice==2)
        {
            int id,found=0;
            scanf("%d",&id);
            
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<3;j++)
                {
                    for(int k=0;k<2;k++)
                    {
                        if(beds[i][j][k]==id && found==0)
                        {
                            beds[i][j][k]=0;
                            printf("Patient %d discharged from Floor %d, Ward %d, Bed %d.\n",
                                   id,i+1,j+1,k+1);
                            found=1;
                        }
                    }
                }
            }
            
            if(found==0)
                printf("Patient ID %d not found.\n",id);
        }
        else if(choice==3)
        {
            int wardCount[2][3]={0};
            int floorCount[2]={0};
            int maxFloor=0,maxWard=0;
            
            printf("--- Occupancy Report ---\n");
            
            for(int i=0;i<2;i++)
            {
                printf("Floor %d\n",i+1);
                
                for(int j=0;j<3;j++)
                {
                    int vacant=0;
                    
                    for(int k=0;k<2;k++)
                    {
                        if(beds[i][j][k]!=0)
                            wardCount[i][j]++;
                        else
                            vacant++;
                    }
                    
                    floorCount[i]+=wardCount[i][j];
                    
                    printf("  Ward %d: Occupied %d, Vacant %d\n",
                           j+1,wardCount[i][j],vacant);
                    
                    if(wardCount[i][j]>wardCount[maxFloor][maxWard])
                    {
                        maxFloor=i;
                        maxWard=j;
                    }
                }
                
                float percentage=floorCount[i]/6.0*100;
                printf("  Floor occupancy: %.1f%%\n",percentage);
                
                if(percentage>80)
                    printf("WARNING: Floor %d is more than 80%% full.\n",i+1);
            }
            
            printf("Highest occupancy: Floor %d, Ward %d (%d occupied)\n",
                   maxFloor+1,maxWard+1,wardCount[maxFloor][maxWard]);
        }
        
    }while(choice!=4);
    
    return 0;
}

