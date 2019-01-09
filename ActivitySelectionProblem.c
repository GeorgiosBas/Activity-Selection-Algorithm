#include <stdio.h>
#include <stdlib.h>

void findMaxActivities(int n,int arr1[n],int depr[n]);

int main(){
    printf("Give number of activities: ");
    int n;
    scanf("%d",&n);
    int arrl[n],depr[n];
    for(int i = 0; i<n; i++){
        printf("%d activity\n",i+1);
        printf("Start time of %d activity: ",i+1);
        scanf("%d",&arrl[i]);
        printf("Finish time of %d activity: ",i+1);
        scanf("%d",&depr[i]);
    }
    findMaxActivities(n,arrl,depr);
    return 0;
}

int compareIntegers(void *x1,void *x2){
    return *(int *) x1 - *(int *) x2;
}

void findMaxActivities(int n,int arrl[n],int depr[n]){
    qsort((void *) arrl, n, sizeof(int), compareIntegers); //sort the tables
    qsort((void *) depr, n, sizeof(int), compareIntegers);
    int depr_time[n];
    int activitiesIn = 1,maxActivities = 1;
    depr_time[0] = depr[0];
    int i = 1, j = 0,k = 0;

    while (i < n && j < n){
        if (arrl[i] < depr[j]){
            activitiesIn++;
            if (activitiesIn >= maxActivities){
                if(activitiesIn == maxActivities)k++;   //k is to keep the number of the same activities in 2 or more time periods
                else k = 0;
                maxActivities = activitiesIn;
                depr_time[k] = depr[j];           //departure time of max activity
            }
            i++;
        }
        else{
            activitiesIn--;
            j++;
        }
    }
    for(i=0; i<=k; i++){
        printf("Maximum Number of Activities : %d at time period %d-%d\n",maxActivities,depr_time[i]-1,depr_time[i]);
    }
}
