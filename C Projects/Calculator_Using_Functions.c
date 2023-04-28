#include <stdio.h>

float add(float num , float num1)
{
    printf("Answer Equals %.2f + %.2f = %.2f" , num , num1 , num + num1);
}

float sub(float num , float num1)
{
    printf("Answer Equals %.2f - %.2f = %.2f" , num , num1 , num - num1);
}

float multi(float num , float num1)
{
    printf("Answer Equals %.2f * %.2f = %.2f" , num , num1 , num * num1);
}

float div(float num , float num1)
{
    printf("Answer Equals %.2f / %.2f = %.2f" , num , num1 , num / num1);
}

void main()
{
    float num , num1;
    char op , retry;    
    
    do
    {
        printf("Enter The First Number: ");
        scanf("%f" , &num);
        fflush(stdin);

        printf("Enter The Second Number: ");
        scanf("%f" , &num1);
        fflush(stdin);  

        printf("Enter The Operation (+ / - / * / '/'): ");
        scanf("%c" , &op);
        fflush(stdin);

        if (op == '+')
        {
            add(num , num1);
        }

        else if (op == '-')
        {
            sub(num , num1);
        }    

        else if (op == '*')
        {
            multi(num , num1);
        }

        else if (op == '/')
        {
            div(num , num1);
        }

        else
        {
            printf("Error!!\n");
            
        }       
        printf("\nDo You Want To Try Again (y/n): ");
        scanf("%c" , &retry);
        fflush(stdin);

        if (retry == 'n')
        {
            printf("Quiting!!");
        }

    } while (retry == 'y');
    

}
