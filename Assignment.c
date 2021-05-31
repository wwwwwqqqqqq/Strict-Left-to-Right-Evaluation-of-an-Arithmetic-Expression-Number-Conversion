//
//  main.c
//  Assignment
//
//  Created by Weiwei Qin on 2019/3/20.
//  Copyright © 2019 Qin Weiwei. All rights reserved.
//  CSI333 Spring2019 Project1

    
#include <stdio.h>

/*
This function aims to calulate each expression.
It will run when meet every three parts.
*/
int cal(int x,char y,int z)
{
    switch (y) {
        case '+' : return (x + z); break;
        case '-' : return (x - z); break;
        case '*' : return (x * z); break;
        case '/' : return (x / z); break;
    }
    return 0;
}
/*

void morethan10(int *p){
    int n = *p;
    printf("hex: 0x");
    while(n > 0)
    {
        switch(*(p + n)){
            case 10:printf("A");break;
            case 11:printf("B");break;
            case 12:printf("C");break;
            case 13:printf("D");break;
            case 14:printf("E");break;
            case 15:printf("F");break;
            default: printf("%d",*(p+n));break;
        }
        n --;
    }
    printf("\n");
}
*/

/*
This function aims to change the digitals into letters.
If the radix is more than 10,it will appear letters.
A = 10,B = 11,C = 12,D = 13,E = 14,F = 15
Get the pointer points to the array,store the value in the array list.
*/
void morethan10(char *a, int m, int n)
{
    int r;
    while (m > 0)
    {
        r = m % n;
        if (r < 10)
        {
            *a = r + 48;
        }
        else
        {
            *a = r + 55;
        }
        m = m / n;
        a ++;
    }
}

/*
This function aims to get the complement.
*/
void complement(int value,int list[10]){
    int i = 0;
    while(value)
    {
        list[i ++] = value & 1;
        value >>= 1;
    }
    for(int j = i - 1; j >= 0; j--)
        printf("%d ",list[j]);
}

int main()
{
    int num[20];
    int value = 0;
    char ch = '+';
    int i = 0;
    
    printf("Enter an expression:");fflush(stdout);
    
    while (ch != '\n') {
        if (i == 0)
            scanf("%d",&num[i]);
        else
        {
            scanf("%c",&ch);
            if(ch == '\n')
                break;
            scanf("%d",&num[i]);
        }
        value = cal(value,ch,num[i]);
        i ++;
    }
    
    printf("The value of expression is : %d \n",value);fflush(stdout);
    
    int r,sign;
    int x,list[10];
    
    char *n,array[10];
    n = array;
    printf("please input radix:");fflush(stdout);
    
    //When the input radix is less than 2,enter the radix again.
    do{
        printf("please input radix:");fflush(stdout);
        scanf("%d",&r);
    }while ((r < 2));
    
    //If the value is bigger than 0,it is a positive number.
    if(value > 0)
        sign = 1;
    //If the value is less than 0,it is a negative number.
    else if (value < 0){
        sign = -1;
    }
    else
        sign = 0;
    
    for(x = 0;x < 10;x ++)
    {
        //Get the remainder,if it is less than 10,it means that radix is less than 10,we do not need to change the digitals into letters.
        if (value % r < 10)
            list[x] = value % r;
        else{
            //it means that radix is bigger than 10,we need to change the digitals into letters.
            morethan10(n,value,r);
        }
        value = value / r;
        if(value == 0)
            break;
    }
    
    printf("The radix in %d",r);fflush(stdout);
    printf(" is : ");fflush(stdout);
    //If the value is a negative number,it have to get the complement.
    if (sign == -1){
        //printf("-");fflush(stdout);
        complement(value,list);
    }
    
    //If the radix is bigger than 10,we need to get the value from a char array list.
    if(r > 10){
        do {
            printf("%c",array[x]);fflush(stdout);
            x --;
        }
        while (x >= 0);
    }
    
    //If the radix is less or equal to 10,we need to get the value from a int array list.
    else{
        do {
            printf("%d",list[x]);fflush(stdout);
            x --;
        }
        while (x >= 0);
    }
    
    printf("\n");fflush(stdout);
    
    //Get the system suspended.
    system("pause");
    
    //Return a value of 0.
    return 0;
}
