#include<stdio.h>
#include"proto_qu.h"

void main()
{
    int arr[2];
    fr1=(node*)malloc(sizeof(node));
    fr2=(node*)malloc(sizeof(node));
    re1=fr1;
    re2=fr2;
    assign(arr);
    average(arr);
    return;
}

