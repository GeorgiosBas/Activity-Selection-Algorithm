#include <stdio.h>

void findMaxBands(int n,int arr1[n],int depr[n]);
void quickSort(int a[],int l,int h);
int partition(int a[],int l,int h);

int main(){
    printf("Doste arithmo pareuriskomenon mpanton: ");
    int n;
    scanf("%d",&n);
    int arrl[n],depr[n];
    for(int i = 0; i<n; i++){
        printf("%d mpanta\n",i+1);
        printf("Doste ora afixis %d mpantas: ",i+1);
        scanf("%d",&arrl[i]);
        printf("Doste ora anaxorisis %d mpantas: ",i+1);
        scanf("%d",&depr[i]);
    }
    findMaxBands(n,arrl,depr);
    return 0;
}

void findMaxBands(int n,int arrl[n],int depr[n]){
    quickSort(arrl,0,n-1);                          //taksinomo tous pinakes asxetos ama xalao tis periodous me grigori methodo
    quickSort(depr,0,n-1);
    int depr_time[n];
    int bandsIn = 1,maxBands = 1;
    depr_time[0] = depr[0];
    int i = 1, j = 0,k = 0;

    while (i < n && j < n){                         //elengxo mexri na teleiosoun oi pinakes
        if (arrl[i] < depr[j]){
            bandsIn++;                              //auksano tis mpantes stin idia periodo
            if (bandsIn >= maxBands){
                if(bandsIn == maxBands)k++;        //to k einai gia na kratiso tis perissoteres fores poy emfanizete idios arithmos mpantwn
                else k = 0;
                maxBands = bandsIn;
                depr_time[k] = depr[j];           //kratao tin anaxorisi tis megistis mpantas
            }
            i++;
        }
        else{
            bandsIn--;                        //bgazo tin teleutea mpanta afou to arrl den ginete na einai megalitero apo to depr se mia periodo
            j++;                              //auksanontas to j oste to depr na ginei megalitero apo to arrl kai na metraei mpantes apo ekei pou emeine kai oxi apo to 0
        }
    }
    for(i=0; i<=k; i++){
        printf("Maximum Number of Bands : %d at time %d-%d\n",maxBands,depr_time[i]-1,depr_time[i]);
    }
}

void quickSort(int a[],int l,int h){
    int j;
    if(l<h){
        j=partition(a,l,h);
        quickSort(a,l,j-1);
        quickSort(a,j+1,h);
    }
}

int partition(int a[],int l,int h){
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=h+1;

    do{
        do{
            i++;
        }while(a[i]<v&&i<=h);
        do{
            j--;
        }while(v<a[j]);
        if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    a[l]=a[j];
    a[j]=v;
    return j;
}
