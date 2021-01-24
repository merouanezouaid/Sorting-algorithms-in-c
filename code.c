
#include <stdio.h>
#include <stdlib.h>

void tri_fusion(int *tab, int d, int f);
void fusion(int *tab, int d, int q ,int f);
void insertion_tri(int *t,int nbr);
void selection_tri(int *t, int nbr);
void tri_rapide(int *tab, int d, int f);
int partition(int *tab, int d, int f);
void echanger(int *a, int *b) ;
int *tribulle2(int *T, int nbr);

int main(){
  int *a, n, i, mode;

 printf("Entrer la taille du tableau:");
 scanf("%d", &n);

  if(n > 0) {
   a = malloc(n * sizeof(int));

   if(a == NULL){
       exit(22);
   }
   
  printf("Entrer %d entiers\n", n);
 
  for (i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  printf("Choisir le mode de tri\n");
  printf("1.Tri de fusion\n");
  printf("2.Tri de selection\n");
  printf("3.Tri d'insertion\n");
  printf("4.Tri de bulle\n");
  printf("5.Tri rapide\n");
  scanf("%d",&mode);
    switch(mode){
      case 1:
      tri_fusion(a, 0 , n-1);
      break;
      case 2:
      selection_tri(a, n);
      break;
      case 3:
      insertion_tri(a, n);
      break;
      case 4:
      tribulle2(a, n);
      break;
      case 5:
      tri_rapide(a, 0 , n-1);
      break;
    }
    
    printf("\nLe tableau triee:\n");

  for (i = 0; i < n; i++){
     printf("%d\t", a[i]);
  }
 free(a);
 }
 
  return 0;
}



void tri_fusion(int *tab, int d, int f){
   if (d<f){
       int q = (d+f)/2;
       tri_fusion(tab, d, q);
       tri_fusion(tab, q+1, f);
       fusion(tab, d, q, f);
   }
}

void fusion(int *tab, int d, int q ,int f){
    int t[f-d+1];
    int m = f;          //indice de fin de t2
    int x=d, y=q+1, k=0;   //x indice de debut de t1 , y indice de debut de t2
    while(x<=q && y<=m){
        if(tab[x]<tab[y]){
            t[k]=tab[x];
            x=x+1;
        }
        else{
            t[k]=tab[y];
            y=y+1;
        }
      k++;
    }

    while(x<=q){
        t[k]=tab[x];
        k++;
        x++;
    }
    while(y<=m){
        t[k]=tab[y];
        k++;
        y++;
    }
   for(x = d; x <= f; x++) {
		tab[x] = t[x - d];
	}
}


void insertion_tri(int *t,int nbr){
int i,j,x;
    for(i=1;i<nbr;i++)
  {
      x=t[i];
      j=i;
      while((j>0) &&(t[j-1]>x))
      {
        t[j]=t[j-1];
        j--;
      }
      t[j]=x;
      printf("%d:%d :\t", i, j-1);
       for(int k=0; k<nbr; k++){
            printf("|%d|  ",t[k]);
      }
      printf("\n");
      j++;
  }
}



void selection_tri(int *t, int nbr){
        int i, min, k , tmp;
        for(i=0; i < nbr-1; i++){
                min = i;
                for(k = i+1; k < nbr ; k++)
                    if(t[k] < t[min])
                        min = k;
                if(min != i){
                        tmp = t[i];
                        t[i] = t[min];
                        t[min] = tmp;
                }
      printf("\n%d :\t", i+1);
       for(int x=0; x<nbr; x++){
            printf("|%d|  ",t[x]);
      }
       printf("\n");
      }
}




void tri_rapide(int *tab, int d, int f){
   if (d<f){
       int q = partition(tab, d, f);
       tri_rapide(tab, d, q-1);
       tri_rapide(tab, q+1, f);
   }
}

int partition(int *tab, int d, int f){
    int pivot = tab[f];
    int i = d-1;
    for(int j = d; j<=f-1; j++){
        if(tab[j]<=pivot){
         i++;
         echanger(&tab[i], &tab[j]);    
        }
    }
 echanger(&tab[i+1], &tab[f]);
 return i+1;
}


void echanger(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 


int *tribulle2(int *T, int nbr){
   int i=0,j,etat,tmp;
   do{ 
     i++;
     etat=0;
     for(j=0; j<nbr-i; j++){
         if(T[j]>T[j+1]){
             tmp=T[j];
             T[j]=T[j+1];
             T[j+1]=tmp;
             etat=1;
              printf("%d:%d :\t", i, j+1);
            for(int k=0; k<nbr; k++){
                printf("|%d|\t",T[k]);
            }
            printf("\n");
         } 
     }
   } while(etat);
  return T;
}



