
#include <stdio.h>

int main()
{
    int marks[4][3],total[4]={0};
    int highest[3],lowest[3];
    float avg[4],subjectAvg[3];
    char grade[4];
    char subjects[3][15]={"Programming","Calculus","Physics"};
    
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&marks[i][j]);
            
            while(marks[i][j]<0 || marks[i][j]>100)
            {
                printf("Invalid mark! Enter a value between 0 and 100.\n");
                scanf("%d",&marks[i][j]);
            }
            
            total[i]+=marks[i][j];
        }
        
        avg[i]=total[i]/3.0;
        
        if(avg[i]>=80)
            grade[i]='A';
        else if(avg[i]>=65)
            grade[i]='B';
        else if(avg[i]>=50)
            grade[i]='C';
        else
            grade[i]='F';
    }
    
    printf("%-12s %-5s %-5s %-5s %-7s %-9s %s\n",
           "Student","Prog","Calc","Phys","Total","Average","Grade");
    
    int top=0;
    
    for(int i=0;i<4;i++)
    {
        printf("Student %-3d %-5d %-5d %-5d %-7d %-9.2f %c\n",
               i+1,marks[i][0],marks[i][1],marks[i][2],
               total[i],avg[i],grade[i]);
        
        if(avg[i]>avg[top])
            top=i;
    }
    
    int worst=0;
    
    printf("\nSubject statistics:\n");
    printf("%-15s %-8s %-8s %s\n","Subject","Highest","Lowest","Average");
    
    for(int j=0;j<3;j++)
    {
        highest[j]=marks[0][j];
        lowest[j]=marks[0][j];
        int sum=0;
        
        for(int i=0;i<4;i++)
        {
            sum+=marks[i][j];
            
            if(marks[i][j]>highest[j])
                highest[j]=marks[i][j];
            
            if(marks[i][j]<lowest[j])
                lowest[j]=marks[i][j];
        }
        
        subjectAvg[j]=sum/4.0;
        
        printf("%-15s %-8d %-8d %.2f\n",
               subjects[j],highest[j],lowest[j],subjectAvg[j]);
        
        if(j>0 && subjectAvg[j]<subjectAvg[worst])
            worst=j;
    }
    
    printf("\nTop student: Student %d (Average %.2f)\n",top+1,avg[top]);
    printf("Worst subject: %s (Average %.2f)\n",subjects[worst],subjectAvg[worst]);
    
    return 0;
}

