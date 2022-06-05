/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

static int k = 1;

typedef struct noeud
{
  int num;
  struct noeud *filsD, *filsG;
} noeud;

void
creer (noeud * racine, int k)
{
  noeud *nouv;
  nouv=(noeud*)malloc(sizeof(noeud));
  nouv->num = k;
  k++;

  nouv->filsG = NULL;
  nouv->filsD = NULL;
  
 
  

  int choix;
  printf ("0 ou 1 droite ou gauche : ");
  fflush(stdout);
  scanf ("%d", &choix);
  if (choix == 0)
    {
      racine->filsG = nouv;
      racine->filsD = NULL;
    }
  if(choix==1)
    {
      
      racine->filsG = NULL;
      racine->filsD = nouv;
    }
    
    

}

void
prefixe (noeud * racine)
{
  if (&(racine->num) != NULL)
    {
        prefixe(racine->filsG);
        printf(" %d ", racine->num);
        prefixe(racine->filsD);
        

    }
}


int
main ()
{
  printf ("Hello World\n");
  noeud pere;
  pere.num = 0;
  pere.filsD = NULL;
  pere.filsG = NULL;

  creer(&pere, k);

  prefixe (&pere);



  return 0;
}
