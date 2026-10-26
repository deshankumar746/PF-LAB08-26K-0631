#include <stdio.h>
int main()
{
    int image[4][4],result[4][4];
    int brightness,threshold;
    
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            scanf("%d",&image[i][j]);
    }
    
    scanf("%d%d",&brightness,&threshold);
    
    printf("Original image:\n");
    
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            printf("%d ",image[i][j]);
        
        printf("\n");
    }
    
    printf("\nBrightness (%+d):\n",brightness);
    
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            int pixel=image[i][j]+brightness;
            
            if(pixel>255)
                pixel=255;
            else if(pixel<0)
                pixel=0;
            
            printf("%d ",pixel);
        }
        
        printf("\n");
    }
    
    printf("\nBlack and white (threshold %d):\n",threshold);
    
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(image[i][j]>=threshold)
                printf("255 ");
            else
                printf("0 ");
        }
        
        printf("\n");
    }
    
    printf("\nFlipped horizontally:\n");
    
    for(int i=0;i<4;i++)
    {
        for(int j=3;j>=0;j--)
            printf("%d ",image[i][j]);
        
        printf("\n");
    }
    
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            result[i][j]=image[i][j];
    }
    
    // A second array prevents updated pixels from affecting later averages.
    for(int i=1;i<3;i++)
    {
        for(int j=1;j<3;j++)
        {
            int sum=0;
            
            for(int r=i-1;r<=i+1;r++)
            {
                for(int c=j-1;c<=j+1;c++)
                    sum+=image[r][c];
            }
            
            result[i][j]=sum/9;
        }
    }
    
    printf("\nSmoothed image:\n");
    
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            printf("%d ",result[i][j]);
        
        printf("\n");
    }
    
    return 0;
}

