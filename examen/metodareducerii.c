#include<stdio.h>


int maxim(int x[],int n){
    int max;
    if(n==0)
        max=x[0];
    else{
        max=maxim(x,n-1);
        if(x[n]>max)
            max=x[n];
    }
    return max;
}

int maximv2(int x[],int ls, int ld){
    int max;
    if(ls==ld)
        max=x[ls];
    else{
        int max1=maximv2(x,ls,(ls+ld)/2);
        int max2=maximv2(x,(ls+ld)/2+1,ld);
        if (max1 > max2) {
            max = max1;
        } else {
            max = max2;
        }
    }
    return max;
}

void main(){
    int a[]={3,7,986,234,12,654};
    printf("maxim e %d",maximv2(a,0,6));
}