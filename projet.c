#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct passager{
    char nom[25],prenom[25],adresse[30],tel[12];
    int age,id;
    struct passager *next,*before;
}passager,*pass;

typedef struct avion {
    char code[25];
    char modeleAv[25];
    char pilote[25];
    int capacite,jrF,mnthF,anF,nbrVA;
    struct avion *next , *before;
}avion,*av;

typedef struct vol{
    struct avion avVol;
    struct passager listePass;
    int jDep,mDep,aDep,jArv,mArv,aArv;
    struct vol *next,*before;
}vol,*vo;

vo initialise(vo v){
    return NULL;
}

vo ajout (vo v , char code[],char pilote[],char modele[] ,int capacite,int jrF,int mnthF,int anF,int nbrVA , char nom[], char prenom[],char adresse[],char tel[], int age,int id,int jDep,int mDep,int aDep,int jArv,int mArv,int aArv){
    vo v1;
    v1 = malloc(sizeof(vo));
    strcpy(v1->avVol.code,code);
    strcpy(v1->avVol.pilote,pilote);
    strcpy(v1->avVol.modeleAv,modele);
    v1->avVol.capacite = capacite;
    v1->avVol.jrF = jrF;
    v1->avVol.mnthF = mnthF;
    v1->avVol.anF = anF;
    v1->avVol.nbrVA = nbrVA;
    v1->listePass.age = age;
    v1->listePass.id = id;
    strcpy(v1->listePass.nom,nom);
    strcpy(v1->listePass.prenom,prenom);
    strcpy(v1->listePass.adresse,adresse);
    strcpy(v1->listePass.tel,tel);
    v1->jDep = jDep;v1->mDep = mDep;v1->aDep = aDep;
    v1->jArv = jArv;v1->mArv = mArv;v1->aArv = aArv;
    
    if(v == NULL){
        v1->next = NULL;
        v1->before = NULL;
        return v1;
    }
    else{
        v1->next = v;
        v1->before = NULL;
        v->before = v1;
        return v1;
    }


}



void affich(vo v){
    int i = 1;
    if(v == NULL)
        printf("liste des vols est vide !\n");
    while(v!=NULL){
        printf("Vol %d : %s\n",i,v->avVol.pilote);
        v = v->next;
        i++;
    }
}
int main (){
char code[25] = "1010", pilote[25]="morad";char modele[25] = "55" ;
int capacite=1515, jrF=18, mnthF=8, anF=2012, nbrVA=15454 ; 
char nom[25] ="hamada",  prenom[25] = "smoo", adresse[30] = "ddeaz232", tel[12] = "151515";  
int age = 21, id = 121, jDep = 28, mDep = 4, aDep = 2021, jArv = 29, mArv = 4, aArv = 2021;
    vo vol1,vol2;
    vol1 = NULL;
    vol2 = initialise(vol2);
    vol1 = ajout(vol1, code, pilote , modele , capacite, jrF,mnthF, anF, nbrVA ,  nom,prenom, adresse,tel,  age, id,jDep,mDep,aDep,jArv,mArv,aArv);
    affich(vol1);
    /*vol2 = ajout(vol1, code,pilote, modele , capacite, jrF,mnthF, anF, nbrVA ,  nom,prenom, adresse,tel,  age, id,jDep,mDep,aDep,jArv,mArv,aArv);
    //affich(vol2);
    vol1 = ajout(vol1, code,pilote, modele , capacite, jrF,mnthF, anF, nbrVA ,  nom,prenom, adresse,tel,  age, id,jDep,mDep,aDep,jArv,mArv,aArv);
    affich(vol1);
    vol2 = ajout(vol1, code,pilote, modele , capacite, jrF,mnthF, anF, nbrVA ,  nom,prenom, adresse,tel,  age, id,jDep,mDep,aDep,jArv,mArv,aArv);
*/
    //affich(vol2);
}