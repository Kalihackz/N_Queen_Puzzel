#include <stdio.h>
int main()//the program starts from here
{
    int matrix[20][20],j,size,value;
    printf("**************************WELCOME TO 'N-Queen Game'**************************\n");
    printf("ENTER THE SIZE : ");
    scanf("%d",&size);
    assign(matrix,size);
    value=solve(matrix,size,0,0);
   // printf("%d",value);
    if(value==0)
    {
        printf("THE GAME HAVE NO SOLUTION\n\n");
        return 0;
    }
        printf("THE GAME HAVE SOLUTION AND IS AS FOLLOWS\n\n  ");
        for(j=0;j<size;j++)//loop for designing
        {
        printf("----");
        }
        printf("\n");//newline feed
        display(matrix,size);//displays the current generation matrix
    return 0;//program terminates successfully
}
void assign(int matrix[][20],int size)//fills the generation matrix with random living or dead cells
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            matrix[i][j]=0;//fills the current matrix cell with the random 0 or 1
        }
    }
}
void display(int matrix[][20],int size)//displays the generation matrix
{
    int i,j,x;char c=' ';
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
        x=matrix[i][j];//takes the value of the current cell that is one for alive and zero for dead
        c=x==1?'Q':' ';//if one then changes with 0 symbol and dead then changes with blank
        printf(" | %c",c);//prints the character 0 or blank
        }
        printf(" | \n");
        printf("  ");
        for(j=0;j<size;j++)
        {
        printf("----");
        }
        printf("\n");
    }
}
int isSafe(int matrix[][20],int curRow,int curCol,int size)
{
    int i,j;
    for(i=curRow-1;i>=0;i--)
    {
        if(matrix[i][curCol]==1)
        {
            return 0;
        }
    }
    for(i=curRow-1,j=curCol-1;i>=0&&j>=0;i--,j--)
    {
        if(matrix[i][j]==1)
        {
            return 0;
        }
    }
    for(i=curRow-1,j=curCol+1;i>=0&&j<size;i--,j++)
    {
        if(matrix[i][j]==1)
        {
            return 0;
        }
    }
    return 1;
}
int findSafeCol(int matrix[][20],int r,int c,int size)
{
    int i;
    for(i=c;i<size;i++)
    {
        if(isSafe(matrix,r,i,size))
        {
            return i;
        }
    }
    return -1;
}
int findQueen(int matrix[][20],int r,int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(matrix[r][i])
        {
            break;
        }
    }
    return i;
}
int solve(int matrix[][20],int size,int r,int c)
{
    int x,y;
    if(r==size)
    {
        return 1;
    }
    x=findSafeCol(matrix,r,c,size);
    if(x==-1)
    {
        if(r==0)
        {
            return 0;
        }
        r--;
        y=findQueen(matrix,r,size);
        matrix[r][y]=0;
       return solve(matrix,size,r,y+1);
    }
    else
    {
        matrix[r][x]=1;
        r++;
        return solve(matrix,size,r,0);
    }
}
