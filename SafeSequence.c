#include<stdio.h>
#include<string.h>
int main()
{
    printf("===================================================================================================================================================================================================================\n");
    printf("==================================================SOLUTION TO FIND WHETHER THE GIVEN SYSTEM IS IN A SAFE STATE OR NOT.=============================================================================================\n");
    
    int enteredByUser[4];
    int Process[5];
    char available[4]={'A','B','C','D'};
   
   
    int AllocationA[5]={0,1,1,0,0};
    int AllocationB[5]={0,0,3,6,0};
    int AllocationC[5]={1,0,5,3,1};
    int AllocationD[5]={2,0,4,2,4};
    int sumA=0,sumB=0,sumC=0,sumD=0;
    int MaxA[5]={0,1,2,0,0};
    int MaxB[5]={0,7,3,6,6};
    int MaxC[5]={1,5,5,5,5};
    int MaxD[5]={2,0,6,2,6};
    int AvailableA[6],AvailableB[6],AvailableC[6],AvailableD[6];
    memset(AvailableA,0,6*sizeof(AvailableA[0]));
    memset(AvailableB,0,6*sizeof(AvailableB[0]));
    memset(AvailableC,0,6*sizeof(AvailableC[0]));
    memset(AvailableD,0,6*sizeof(AvailableD[0]));
    AvailableA[0]=1;
    AvailableB[0]=5;
    AvailableC[0]=2;
    AvailableD[0]=0;
    if(AvailableA[0]>=0 && AvailableB[0]>=0 && AvailableC[0]>=0 && AvailableD[0]>=0){
    printf("Given:\n\n");
    printf("===========================================================================\n");
    printf("||Process  |      Allocation   ||      Maximum      ||      Available    ||\n");
    printf("---------------------------------------------------------------------------\n");
    printf("||  P      | A  | B  | C  | D  || A  | B  | C  | D  || A  | B  | C  | D  ||\n");
    printf("---------------------------------------------------------------------------\n");
    
    for(int i=0;i<5;i++){
    printf("||  P%d     | %d  | %d  | %d  | %d  || %d  | %d  | %d  | %d  || %d  | %d  | %d  | %d  ||\n",i,AllocationA[i],AllocationB[i],AllocationC[i],AllocationD[i],MaxA[i],MaxB[i],MaxC[i],MaxD[i],AvailableA[i],AvailableB[i],AvailableC[i],AvailableD[i]);
    sumA=sumA+AllocationA[i];
    sumB=sumB+AllocationB[i];
    sumC=sumC+AllocationC[i];
    sumD=sumD+AllocationD[i];
    }
    printf("===========================================================================\n");
    printf("\n===================================================================================================================================================================================================================\n");
    printf("\nWILL APPLY THE BANKERS ALGORITHM TO FIND OUT THE SOLUTION.\n");
    printf("\n===================================================================================================================================================================================================================\n");
    printf("\nSTEP 1:\n");
    printf("ALREADY ALLOCATED RESOURCES OF A,B,C,D.\n\n");
    printf("===========================================================================\n");
    printf("||Process  |      Allocation   ||      Maximum      ||      Available    ||\n");
    printf("---------------------------------------------------------------------------\n");
    printf("||  P      | A  | B  | C  | D  || A  | B  | C  | D  || A  | B  | C  | D  ||\n");
    printf("---------------------------------------------------------------------------\n");
    for(int i=0;i<5;i++){
    printf("||  P%d     | %d  | %d  | %d  | %d  || %d  | %d  | %d  | %d  || %d  | %d  | %d  | %d  ||\n",i,AllocationA[i],AllocationB[i],AllocationC[i],AllocationD[i],MaxA[i],MaxB[i],MaxC[i],MaxD[i],AvailableA[i],AvailableB[i],AvailableC[i],AvailableD[i]);
    }
    printf("---------------------------------------------------------------------------\n");
    printf("           | %d  | %d  | %d | %d ||\n",sumA,sumB,sumC,sumD);
    printf("------------------------------------------------------\n");

    enteredByUser[0]=AvailableA[0]+sumA;
    enteredByUser[1]=AvailableB[0]+sumB;
    enteredByUser[2]=AvailableC[0]+sumC;
    enteredByUser[3]=AvailableD[0]+sumD;
    printf("\n\nALLOCATED RESOURCES ARE:\n");
    printf("=============================\n");
    printf("||  A |  B   |  C   |  D   ||\n");
    printf("-----------------------------\n");
    printf("|| %d  |  %d  |  %d  |  %d  ||\n",enteredByUser[0],enteredByUser[1],enteredByUser[2],enteredByUser[3]);
    printf("=============================\n");
    printf("\n===================================================================================================================================================================================================================\n");
    printf("\nSTEP 2:\n");
    printf("CALCULATE THE REMAINING NEED\n\n");
    int RemNeedA[5];
    int RemNeedB[5];
    int RemNeedC[5];
    int RemNeedD[5];
    for(int i=0;i<5;i++)
    {
        RemNeedA[i]=MaxA[i]-AllocationA[i];
        RemNeedB[i]=MaxB[i]-AllocationB[i];
        RemNeedC[i]=MaxC[i]-AllocationC[i];
        RemNeedD[i]=MaxD[i]-AllocationD[i];
    }
    printf("================================================================================================\n");
    printf("||Process  |      Allocation   ||      Maximum      ||      Available    ||    RemainingNeed  ||\n");
    printf("------------------------------------------------------------------------------------------------\n");
    printf("||  P      | A  | B  | C  | D  || A  | B  | C  | D  || A  | B  | C  | D  || A  | B  | C  | D  ||\n");
    printf("------------------------------------------------------------------------------------------------\n");
    for(int i=0;i<5;i++){
    printf("||  P%d     | %d  | %d  | %d  | %d  || %d  | %d  | %d  | %d  || %d  | %d  | %d  | %d  || %d  | %d  | %d  | %d  ||\n",i,AllocationA[i],AllocationB[i],AllocationC[i],AllocationD[i],MaxA[i],MaxB[i],MaxC[i],MaxD[i],AvailableA[i],AvailableB[i],AvailableC[i],AvailableD[i],RemNeedA[i],RemNeedB[i],RemNeedC[i],RemNeedD[i]);
    }
    printf("------------------------------------------------------------------------------------------------\n");
    printf("           | %d  | %d  | %d | %d ||\n",sumA,sumB,sumC,sumD);
    printf("------------------------------------------------------\n");
    printf("\n===================================================================================================================================================================================================================\n");
    printf("\nSTEP3:\n");
    printf("CALCULATE ALL PROCESS AVAILABLE RESOURCES SO THAT WE CAN IDENTIFY THE SAFE SEQUENCE.\n\n");
    
    int x=1,j=0,l=0,m=0,r=0,k,u=0;
    int SafeSequence[5];
    int count[5];
    memset(count,0,5*sizeof(count[0]));
    while(x){
        if((j<5 && m<5 && u<5)&& AvailableA[j]>=RemNeedA[m] && AvailableB[j]>=RemNeedB[m] && AvailableC[j]>=RemNeedC[m] && AvailableD[j]>=RemNeedD[m] && (count[m]!=1))
        {
            AvailableA[j+1]=AllocationA[m]+AvailableA[j];
            AvailableB[j+1]=AllocationB[m]+AvailableB[j];
            AvailableC[j+1]=AllocationC[m]+AvailableC[j];
            AvailableD[j+1]=AllocationD[m]+AvailableD[j];
            RemNeedA[m]=0;
            RemNeedB[m]=0;
            RemNeedC[m]=0;
            RemNeedD[m]=0;
            SafeSequence[u]=m;
            count[m]=1;
            u++;
            m++;
            j++;
            
        }
       
        else{
            if(m==5 && r!=1){
            m=0;
            r=1;
        
            }
           
            else{
                m++;
            }
        }
        for(k=0;k<5;k++)
        {
            if(count[k]!=1){
                break;
            }
        }

        if(k==5)
        break;
    }
    
    printf("================================================================================================\n");
    printf("||Process  |      Allocation   ||      Maximum      ||      Available    ||    RemainingNeed  ||\n");
    printf("------------------------------------------------------------------------------------------------\n");
    printf("||  P      | A  | B  | C  | D  || A  | B  | C  | D  || A  | B  | C  | D  || A  | B  | C  | D  ||\n");
    printf("------------------------------------------------------------------------------------------------\n");
    char result1[2],result2[2],result3[2],result4[2];
    int w,v,y,z;
    for(int i=0;i<5;i++){
    sprintf(result1,"%d",AvailableA[i]);    
    sprintf(result2,"%d",AvailableB[i]);    
    sprintf(result3,"%d",AvailableC[i]);    
    sprintf(result4,"%d",AvailableD[i]);
    w=strlen(result1);
    v=strlen(result2);
    y=strlen(result3);
    z=strlen(result4);
    printf("||  P%d     | %d  | %d  | %d  | %d  || %d  | %d  | %d  | %d  ||",i,AllocationA[i],AllocationB[i],AllocationC[i],AllocationD[i],MaxA[i],MaxB[i],MaxC[i],MaxD[i]);

    if(w==1)
    {
        printf(" %d  |",AvailableA[i]);

    }
    else{
        printf(" %d |",AvailableA[i]);

    }
    if(v==1)
    {
        printf(" %d  |",AvailableB[i]);

    }
    else{
        printf(" %d |",AvailableB[i]);

    }

    if(y==1)
    {
    printf(" %d  |",AvailableC[i]);

    }
    else{
    printf(" %d |",AvailableC[i]);
    }
    if(z==1)
    {
    printf(" %d  ",AvailableD[i]);
    }
    else{
    printf(" %d ",AvailableC[i]);
    }

    printf("|| %d  | %d  | %d  | %d  ||\n",RemNeedA[i],RemNeedB[i],RemNeedC[i],RemNeedD[i]);
    }
    printf("------------------------------------------------------------------------------------------------\n");

    printf("           | %d  | %d  | %d | %d ||                   ",sumA,sumB,sumC,sumD);
    sprintf(result1,"%d",AvailableA[5]);
    sprintf(result2,"%d",AvailableB[5]);
    sprintf(result3,"%d",AvailableC[5]);
    sprintf(result4,"%d",AvailableC[5]);
    
    int a=strlen(result1);
    int b=strlen(result2);
    int c=strlen(result3);
    int d=strlen(result4);
     if(a==1)
    {
        printf("|| %d  |",AvailableA[5]);

    }
    else{
        printf("|| %d |",AvailableA[5]);

    }
    if(b==1)
    {
        printf(" %d  |",AvailableB[5]);

    }
    else{
        printf(" %d |",AvailableB[5]);

    }

    if(c==1)
    {
    printf(" %d  |",AvailableC[5]);

    }
    else{
    printf(" %d |",AvailableC[5]);
    }
    if(d==1)
    {
    printf(" %d  ||\n",AvailableD[5]);
    }
    else{
    printf(" %d ||\n",AvailableC[5]);
    }
    printf("------------------------------------------------------------------------------------------------\n");


    if(AvailableA[5]==enteredByUser[0] && AvailableB[5]==enteredByUser[1] && AvailableC[5]==enteredByUser[2] && AvailableD[5]==enteredByUser[3])
    {
        printf("\n===================================================================================================================================================================================================================\n");

        printf("\nYES SYSTEM IS IN A SAFE STATE\n");
        printf("\nRESPECTED SAFE SEQUENCE IS:\n");
        for(int i=0;i<5;i++){
            if(i==4)
            {
              printf("P%d \n",SafeSequence[i]);  
              break;
            }
            printf(" P%d ->\t",SafeSequence[i]);
        }
    }

    else{
        printf("\n===================================================================================================================================================================================================================\n");

        printf("\n GIVEN SYSTEM WITH ALLOCATED RESOURCE IS NOT IN A SAFE SEQUENCE.\n");
    }
    printf("\n===================================================================================================================================================================================================================\n");
    }

    else{
            printf("AVAILABLE RESOURCES ARE LESS THAN ZERO\n");
            printf("\n===================================================================================================================================================================================================================\n");

    }
}