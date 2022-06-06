#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*int Saisir(){
    int entier;
    printf("saisir entier : ");

    scanf("%d",&entier);
    return entier;

}

typedef struct produit{
    int ref;
    char *nom;
}produit;

void Saisir2(produit *prod){
    printf("Entrez la ref produit : ");
    scanf("%d", &(prod->ref));
    printf("Entrez le nom du produit: ");
    char buffer[30];
    scanf("%s", buffer);

    prod->nom = (char*) malloc((strlen(buffer)+1)*sizeof(char));

    strcpy(prod->nom, buffer);

}

void affiche (produit prod){
    printf("\n la reference est de %d", prod.ref);
    printf("\n le nom du produit est %s", prod.nom);
}
*/




typedef struct noeud
{
  int num;
  struct noeud *filsD, *filsG;
} noeud;

void
creer (noeud * racine){
  static int k = 1;
  noeud *nouv;
  nouv=(noeud*)malloc(sizeof(noeud));
  nouv->num = k;
  k++;

  nouv->filsG = NULL;
  nouv->filsD = NULL;

  int choix;
  printf ("1 ou 0 - droite ou gauche : ");
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

  creer(&pere);
  printf("creation du fils \n");
  creer(pere.filsG);


  prefixe (&pere);



  return 0;
}
