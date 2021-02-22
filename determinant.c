#include <stdio.h>
#include <stdlib.h>

int determinant(int* matrix,short length);
int det2x2(int* matrix);
int det3x3(int* matrix);

int main()
{
    short length;
    int result;
    title();
    printf("\n\n  Enter the square matrix's length=>");
    scanf("%d",&length);
    int matrix[length][length];
    get_matrix(matrix,length);
    print_matrix(matrix,length);
    result = determinant(matrix,length);
    printf("\n\
-----------------------------------------------------------------------------------------------------------------------\n\
            \n  The matrix's determinant is %d\n\n\n",result);
}

void title()
{
    printf("\n\
-----------------------------------------------------------------------------------------------------------------------\n\
########   #####  ##########  #####   #####   ###            ###  ##  ###      ##     ####      ###      ##  ##########\n\
###    ##  #####  ##########  #####  ##   ##  ####          ####      ####     ##    ##  ##     ####     ##  ##########\n\
###    ##  ##         ##      ##     ##    #  ## ##        ## ##  ##  ## ##    ##   ##    ##    ## ##    ##      ##    \n\
###    ##  #####      ##      #####  ######   ##  ##      ##  ##  ##  ##  ##   ##  ##      ##   ##  ##   ##      ##    \n\
###    ##  #####      ##      #####  ####     ##   ##    ##   ##  ##  ##   ##  ##  ##########   ##   ##  ##      ##    \n\
###    ##  ##         ##      ##     ## ##    ##    ##  ##    ##  ##  ##    ## ##  ##      ##   ##    ## ##      ##    \n\
###    ##  #####      ##      #####  ##  ##   ##     ####     ##  ##  ##     ####  ##      ##   ##     ####      ##    \n\
########   #####      ##      #####  ##   ##  ##      ##      ##  ##  ##      ###  ##      ##   ##      ###      ##    \n\
-----------------------------------------------------------------------------------------------------------------------\n");
}



void print_matrix(int* matrix,short length){
    printf("\n");
    for(int i=0;i<length;++i){
        printf("|");
        for(int j=0;j<length;++j){
            printf("%4d",*(matrix+i*length+j));
        }
        printf("  |\n");
    }
}

void get_matrix(int* matrix,short length){
    printf("\n");
    for(int i=0;i<length;++i){
        for(int j=0;j<length;++j){
            printf("[%d,%d]=> ",i+1,j+1);
            scanf("%d",matrix+i*length+j);
        }
    }
}

int det3x3(int* matrix){
    int matrix1[4]={*(matrix+4),*(matrix+5),*(matrix+7),*(matrix+8)};
    int matrix2[4]={*(matrix+3),*(matrix+5),*(matrix+6),*(matrix+8)};
    int matrix3[4]={*(matrix+3),*(matrix+4),*(matrix+6),*(matrix+7)};
    int result=0;
    result= + *(matrix+0) * det2x2(matrix1)
            - *(matrix+1) * det2x2(matrix2)
            + *(matrix+2) * det2x2(matrix3);
    return result;
}

int det2x2(int* matrix){
    int result;
    result=*(matrix+0) * *(matrix+3)-*(matrix+1) * *(matrix+2);
    return result;
}

int determinant(int* matrix,short length){
    if(length==2)
        return det2x2(matrix);
    else if(length==3)
        return det3x3(matrix);

    int result = 0;
    int minor[length-1][length-1];
    for(int count=0;count<length;++count){

        short n=0;short m=0;
        for(int i=1;i<length;++i){
                n=0;
            for(int j=0;j<length;++j){
                    if(j==count) continue;
                    minor[m][n]= *(matrix+i*length+j);
                ++n;
            }
            ++m;
        }

        if((length-1)==3)
            result += *(matrix+count) * pow(-1,(count)) * det3x3(minor);
        else
            return determinant(minor,length-1);
    }
    return result;
}
