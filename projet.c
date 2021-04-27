#include<stdio.h>
#include<stdio.h>
#include<stdio.h>

typedef struct passager{
    char nom[25],prenom[25],adresse[30],tel[12];
    int age,id;
    struct passager *next,*before
}passager,*pass;

typedef struct avion {
    char code[25],pilote[25];
    int modele,capacite,jrF,mnthF,anF;
    struct avion *next , *before;
}avion,*av;

typedef struct vol{
    struct avion avVol;
    struct passager listePass;
    int hDep,hArv;
    struct vol *next,*before;
}vol,*vo;

vo initialise(vo v){
    return NULL;
}

vo ajout (vo v ){
    vo v1 = v;
    v1 = malloc(sizeof(vo));
}
int main (){

}