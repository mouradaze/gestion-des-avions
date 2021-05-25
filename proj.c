#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
typedef struct{
	int j;
	int m;
	int a;
}date;
typedef struct{
	char code[20],pilote[30],modele[15];
	int capacite,nb_Vols;
	date date_fabrication;
}avion;
typedef struct passager{
	int iD,age,telephone;
	char nom[40],prenom[40],adresse[50];
}passager;
struct celluleP{
	passager PA;
	struct celluleP *nxt,*prev; 
};
typedef struct celluleP celluleP , *llistP;
typedef struct{
	llistP pasg;
	avion Avion;
	date date_depart;
	date date_arrivee;
	int numVol;
}vol;
struct celluleV{
	vol v; 
	struct celluleV *next,*previous;
};
typedef struct celluleV celluleV , *llistV;

/***************************************************************************************************************************************************************************/

llistV InitialVol(llistV LISTE){
	return NULL;
}

llistP InitialPassager(llistP liste){
	return NULL;
}

llistV Ajout_Vol(llistV LISTE,vol V,avion Av){
	int i;
		llistV l1;
		l1 = (celluleV *)malloc(sizeof(celluleV));
		if(l1 == NULL)
			exit(1);
		else{
		l1->v.pasg = NULL;
		l1->v.numVol = V.numVol;
		l1->v.date_depart.j = V.date_depart.j;
		l1->v.date_depart.m = V.date_depart.m;
		l1->v.date_depart.a = V.date_depart.a;
		l1->v.date_arrivee.j = V.date_arrivee.j;
		l1->v.date_arrivee.m = V.date_arrivee.m;
		l1->v.date_arrivee.a = V.date_arrivee.a;		
		strcpy(l1->v.Avion.code,Av.code);
		fflush(stdin);
		strcpy(l1->v.Avion.pilote,Av.pilote);
		fflush(stdin);
		strcpy(l1->v.Avion.modele,Av.modele);
		fflush(stdin);
		l1->v.Avion.capacite = Av.capacite;
		l1->v.Avion.nb_Vols = Av.nb_Vols;
		l1->v.Avion.date_fabrication.j = Av.date_fabrication.j;
		l1->v.Avion.date_fabrication.m = Av.date_fabrication.m;
		l1->v.Avion.date_fabrication.a = Av.date_fabrication.a;
		l1->next = NULL;
		if(LISTE == NULL){
			l1->previous = NULL;
			printf("\nVOL AJOUTE AVEC SUCCES !! \n");
			return l1;
		}
		else{
			llistV l2 = LISTE;
			while(l2->next != NULL)
				l2 = l2->next;
			l2->next = l1;
			l1->previous = l2;
			printf("\nVOL AJOUTE AVEC SUCCES !! \n");
			return LISTE;
		}
		}
}

llistP Ajout_Passager(llistP liste,passager Pa){
		llistP l1 = (celluleP *)malloc(sizeof(celluleP));
		if(l1 == NULL)
			exit(1);
		else{
		l1->PA.iD = Pa.iD;
		strcpy(l1->PA.nom,Pa.nom);
		strcpy(l1->PA.prenom,Pa.prenom);
		l1->PA.age = Pa.age;
		l1->PA.telephone = Pa.telephone;
		strcpy(l1->PA.adresse,Pa.adresse);
		l1->nxt = NULL;
		if(liste == NULL){
			l1->prev = NULL;
			return l1;
		}
		else{
			llistP l2 = liste;
			while(l2->nxt != NULL)
				l2 = l2->nxt;
				l2->nxt = l1;
				l1->prev = l2;
			return liste;
		}
}
}



int Ajout_Passager_Vol(llistV LISTE,int NUM_VOL,passager Pa){
	llistV l1 = LISTE;
	while(l1 != NULL){
		if(NUM_VOL == l1->v.numVol){
			l1->v.pasg = Ajout_Passager(l1->v.pasg,Pa);
		}
		l1 = l1->next;
	}
	printf("\nPASSAGER AJOUTE AVEC SUCCES !! \n");
}

bool Modifier_Date(llistV LISTE,date dateDEPART,date dateARRIVEE,int NUM_VOL){
	llistV l1 = LISTE;
	while(l1 != NULL){
		if(NUM_VOL == l1->v.numVol){
			if((l1->v.date_depart.j < dateDEPART.j && l1->v.date_depart.m < dateDEPART.m && l1->v.date_depart.a < dateDEPART.a) 
			&& (l1->v.date_arrivee.j < dateARRIVEE.j && l1->v.date_arrivee.m < dateARRIVEE.m && l1->v.date_arrivee.a < dateARRIVEE.a)){
				l1->v.date_depart.j = dateDEPART.j;
				l1->v.date_depart.m = dateDEPART.m;
				l1->v.date_depart.a = dateDEPART.a;
				return true;
			}
		}
		l1 = l1->next;
	}
	return false;
}

bool Trouve_Passager(llistP liste,int ID){
	llistP l1 = liste;
	while(l1!=NULL){
		if(ID == l1->PA.iD)
			return true;
		l1 = l1->nxt;
	}
	return false;
}

bool Trouve_Passager_Vol(llistV LISTE,int ID,int NUM_VOL){
	llistV l1 = LISTE;
	llistP l2;
	while(l1 != NULL){
		if(NUM_VOL == l1->v.numVol){
			l2 = l1->v.pasg;
			while(l2 != NULL){
				if(l2->PA.iD == ID)
					return true;
				l2 = l2->nxt;
			}
		}
		l1 = l1->next;
	}
	return false;
}

bool Trouve_Vol(llistV LISTE,int NUM_VOL){
	llistV l1 = LISTE;
	while(l1 != NULL){
		if(NUM_VOL == l1->v.numVol)
			return true;
		l1 = l1->next;
	}
	return false;
}

void Afficher_Vol(llistV LISTE){
	llistV l1 = LISTE;
	while(l1 != NULL){
		printf("\n********** Vol **********\n");
		printf("Numero de vol : %d",l1->v.numVol);
		printf("\nDate de depart : %d/%d/%d",l1->v.date_depart.j,l1->v.date_depart.m,l1->v.date_depart.a);
		printf("\nDate d'arrivee : %d/%d/%d",l1->v.date_arrivee.j,l1->v.date_arrivee.m,l1->v.date_arrivee.a);
		printf("\nCode de l'avion : %s",l1->v.Avion.code);
		printf("\nNom du pilote : %s",l1->v.Avion.pilote);
		printf("\nModele de l'avion : %s",l1->v.Avion.modele);
		printf("\nCapacite de l'avion : %d",l1->v.Avion.capacite);
		printf("\nNombre de vols de l'avion : %d",l1->v.Avion.nb_Vols);
		printf("\nDate de fabrication de l'avion : %d/%d/%d",l1->v.Avion.date_fabrication.j,l1->v.Avion.date_fabrication.m,l1->v.Avion.date_fabrication.a);
		llistP l2 = l1->v.pasg;
		if(l2 == NULL)
			printf("\n Il n'existe aucun passager dans ce vol !! \n");
		else{
			printf("\n\n********** Passagers du vol **********\n");
			while(l2 != NULL){
				printf("ID du passager : %d",l2->PA.iD);
				printf("\nNom du passager : %s",l2->PA.nom);
				printf("\nPrenom du passager : %s",l2->PA.prenom);
				printf("\nAge du passager : %d",l2->PA.age);
				printf("\nTelephone du passager : 0%d",l2->PA.telephone);
				printf("\nAdresse du passager : %s",l2->PA.adresse);
				printf("\n\n");
				l2 = l2->nxt;
			}
		}
		l1 = l1->next;
		printf("\n\n");
	}
}

void Afficher_Passager(llistV LISTE,int NUM_VOL){
	llistV l1 = LISTE;
	int trouve = 0;
	while(l1 != NULL){
		if(NUM_VOL == l1->v.numVol){
			llistP l2 = l1->v.pasg;
			while(l2 != NULL){
				if(l2->PA.age < 10){
					trouve = 1;
					printf("ID du passager : %d",l2->PA.iD);
					printf("\nNom du passager : %s",l2->PA.nom);
					printf("\nPrenom du passager : %s",l2->PA.prenom);
					printf("\nAge du passager : %d",l2->PA.age);
					printf("\nTelephone du passager : 0%d",l2->PA.telephone);
					printf("\nAdresse du passager : %s",l2->PA.adresse);
					printf("\n\n");
				}
				l2 = l2->nxt;
			}
		}
		l1 = l1->next;
	}
	if(trouve == 0)
		printf("\nIL N'EXISTE AUCUN PASSAGER AYANT MOINS DE 10 ANS DANS CE VOL !! \n\n");
}

void Afficher_Vol_Suivant(llistV LISTE){
	time_t timestamp = time( NULL );
    struct tm * timeInfos = localtime(&timestamp);
    int nextDay = timeInfos->tm_mday+1;
    llistV l1 = LISTE;
    int trouve = 0;
    while(l1!=NULL){
    	if(nextDay == l1->v.date_depart.j){
    		trouve = 1;
			printf("\n********** Vol **********\n");
			printf("Numero de vol : %d",l1->v.numVol);
			printf("\nDate de depart : %d/%d/%d",l1->v.date_depart.j,l1->v.date_depart.m,l1->v.date_depart.a);
			printf("\nDate d'arrivee : %d/%d/%d",l1->v.date_arrivee.j,l1->v.date_arrivee.m,l1->v.date_arrivee.a);
			printf("\nCode de l'avion : %s",l1->v.Avion.code);
			printf("\nNom du pilote : %s",l1->v.Avion.pilote);
			printf("\nModele de l'avion : %s",l1->v.Avion.modele);
			printf("\nCapacite de l'avion : %d",l1->v.Avion.capacite);
			printf("\nNombre de vols de l'avion : %d",l1->v.Avion.nb_Vols);
			printf("\nDate de fabrication de l'avion : %d/%d/%d",l1->v.Avion.date_fabrication.j,l1->v.Avion.date_fabrication.m,l1->v.Avion.date_fabrication.a);
			llistP l2 = l1->v.pasg;
			if(l2 == NULL)
				printf("\n Il n'existe aucun passager dans ce vol !! \n");
			else{
				printf("\n\n********** Passagers du vol **********\n");
				while(l2 != NULL){
					printf("ID du passager : %d",l2->PA.iD);
					printf("\nNom du passager : %s",l2->PA.nom);
					printf("\nPrenom du passager : %s",l2->PA.prenom);
					printf("\nAge du passager : %d",l2->PA.age);
					printf("\nTelephone du passager : 0%d",l2->PA.telephone);
					printf("\nAdresse du passager : %s",l2->PA.adresse);
					printf("\n\n");
					l2 = l2->nxt;
				}
			}

		}
    	l1 = l1->next;
	}
	if(trouve == 0)
		printf("\nIl n'existe aucune vol le %d/%d/%d !!\n",timeInfos->tm_mday+1,timeInfos->tm_mon+1,timeInfos->tm_year+1900);
}

llistP SuppDebut(llistP liste)
{
    llistP l1;
    if(liste == NULL)
    	return NULL;
    if(liste->nxt == NULL){
        free(liste);
        return NULL;
    }
    l1 = liste;
	liste = liste->nxt;
    free(l1);
    liste->prev = NULL;
    return liste;
    
}
llistP SuppFin(llistP liste)
{
    llistP l1 = liste;
 	if(liste == NULL)
    	return NULL;
    if(liste->nxt == NULL){
        free(liste);
        return NULL;
    }
    while(l1->nxt != NULL)
        l1 = l1->nxt;
	l1->prev->nxt = NULL;
    free(l1);
    return liste;  
}

llistV Supp_Dernier_Vol(llistV LISTE){
	llistV l1 = LISTE;
	if(l1 == NULL){
		printf("\nERREUR DE SUPPRESSION : la liste des vols est vide !! \n");
		return NULL;
	}
	if(l1->next == NULL){
		free(l1);
		return NULL;
	}
	while(l1->next != NULL)
		l1 = l1->next;
	l1->previous->next = NULL;
	free(l1);
	printf("\nSUPPRESSION DU DERNIER VOL EFFECTUEE AVEC SUCCES !! \n");
	return LISTE;
}

llistP Supp_Passager(llistP liste,int ID){
	llistP l1 = liste;
	while(l1 != NULL){
		if(l1->PA.iD == ID){
			if(l1->prev == NULL)
				l1 = SuppDebut(l1);
			else if(l1->nxt == NULL)
				l1 = SuppFin(l1);
			else{
				l1->prev->nxt = l1->nxt;
				l1->nxt->prev = l1->prev;
				return liste;
			}
		}
		else
			l1 = l1->nxt;
	}
}

llistV Supp_Passager_Vol(llistV LISTE,int ID,int NUM_VOL){
	llistV l1 = LISTE;
	while(l1 != NULL){
		if(NUM_VOL == l1->v.numVol){
			llistP l2 = l1->v.pasg;
			if(l2->prev == NULL){
				if(l2->PA.iD == ID){
					free(l2);
					l1->v.pasg = NULL;
					printf("\nSUPPRESSION DU PASSAGER EFFECTUEE AVEC SUCCES !! \n");
					return l1;
				}
			}
			else if(l2->nxt == NULL){
				if(l2->PA.iD == ID){
					free(l2);
					printf("\nSUPPRESSION DU PASSAGER EFFECTUEE AVEC SUCCES !! \n");
					l1->v.pasg = NULL;
					return l1;
				}
			}
			else{
				while(l2 != NULL){
					if(l2->PA.iD == ID){
						
						l2->prev->nxt = l2->nxt;
						l2->nxt->prev = l2->prev;
						free(l2);
						printf("\nSUPPRESSION DU PASSAGER EFFECTUEE AVEC SUCCES !! \n");
						return l1;
					}
					l2 = l2->nxt;
				}
			}
		}
		else
			l1 = l1->next;
	}
	return LISTE;
}

void menuPrincipal(){
    printf("************ Menu Principal **************\n");
    printf("1- Ajouter un vol\n");
    printf("2- Ajouter Un Passager A Un Vol\n");
    printf("3- Recherche D'un Passager\n");
    printf("4- Appartenance D'un Vol\n");
    printf("5- Modifier La Date D'un Vol\n");
    printf("6- Afficher Tous Les Vols\n");
    printf("7- Afficher Les Passager De Moins De 10 Ans\n");
    printf("8- Afficher Les Vols De Demain\n");
    printf("9- Supprimer Le Dernier Vol\n");
    printf("10- Supprimer Un Passager\n");
    printf("11- Fermer Le Programme\n");
	printf("Votre Choix : ");
}
/***************************************************************************************************************************************************************************/

int main(){
	llistV LISTE = NULL;
	llistP liste = NULL;
	date dateDEPART,dateARRIVEE;
	avion Av;
	passager Pa;
	vol V;
	int choix,ID,NUM_VOL;
	do{
		menuPrincipal();
		scanf("%d",&choix);
		switch(choix){
			case 1 : 
				printf("Donner le numero du vol : ");
				scanf("%d",&V.numVol);
				NUM_VOL = V.numVol;
				if(!Trouve_Vol(LISTE,NUM_VOL)){
					printf("la date de depart du vol  \n");
					printf("Le Jour : ");scanf("%d",&V.date_depart.j);
					printf("Le Mois : ");scanf("%d",&V.date_depart.m);
					printf("L'annee : ");scanf("%d",&V.date_depart.a);
					printf("la date d'arrivee du vol  \n");
					printf("Le Jour : ");scanf("%d",&V.date_arrivee.j);
					printf("Le Mois : ");scanf("%d",&V.date_arrivee.m);
					printf("L'annee' : ");scanf("%d",&V.date_arrivee.a);
					fflush(stdin);
					printf("Donner le code de l'avion : ");
					scanf("%s",Av.code);
					fflush(stdin);
					printf("Donner le nom du pilote : ");
					scanf("%s",Av.pilote);
					fflush(stdin);
					printf("Donner le modele de l'avion : ");
					scanf("%s",Av.modele);
					fflush(stdin);
					printf("Donner la capacite de l'avion : ");
					scanf("%d",&Av.capacite);
					printf("Donner le nombre de vols de l'avion : ");
					scanf("%d",&Av.nb_Vols);
					printf("le jour de fabrication de l'avion \n");
					printf("Le Jour : ");scanf("%d",&Av.date_fabrication.j);
					printf("Le Mois : ");scanf("%d",&Av.date_fabrication.m);
					printf("L'annee' : ");scanf("%d",&Av.date_fabrication.a);
					LISTE = Ajout_Vol(LISTE,V,Av);
				}
				else
					printf("\nce vol existe deja . Reessayez !!\n\n");
			break;
			
			case 2 :
				if(LISTE == NULL)
					printf("\nvous devez ajouter au moins un vol !!\n\n");
				else{
					printf("Donner l'iD du passager : ");
					scanf("%d",&Pa.iD);
					ID = Pa.iD;
					if(!Trouve_Passager(liste,ID)){
						printf("Donner le nom du passager : ");
						scanf("%s",&Pa.nom);
						fflush(stdin);
						printf("Donner le prenom du passager : ");
						scanf("%s",&Pa.prenom);
						fflush(stdin);
						printf("Donner l'age du passager : ");
						scanf("%d",&Pa.age);
						printf("Donner le numero de telephone du passager : ");
						scanf("%d",&Pa.telephone);
						printf("Donner l'adresse du passager : ");
						scanf("%s",&Pa.adresse);	
						printf("Donner le numero de vol dont vous voulez ajouter ce passager : ");
						scanf("%d",&NUM_VOL);
						if(Trouve_Vol(LISTE,NUM_VOL)){
							liste = Ajout_Passager(liste,Pa);
							Ajout_Passager_Vol(LISTE,NUM_VOL,Pa);
						}
						else if(!Trouve_Vol(LISTE,NUM_VOL))
							printf("\nle numero saisi ne correspond a aucun vol dans la liste !!\n\n");
					}
					else
						printf("\nce passager existe deja . Reessayez !!\n\n");
				}
			break;
			
			case 3 :
				if(LISTE == NULL && liste == NULL)
					printf("\nvous devez ajouter au moins un vol et un passager !!\n\n");
				else if(LISTE == NULL)
					printf("\nvous devez ajouter au moins un vol !!\n\n");
				else if(liste == NULL)
					printf("\nvous devez ajouter au moins un passager !!\n\n");
				else{
					printf("Donner l'iD du passager recherche : ");
					scanf("%d",&ID);
					printf("Donner le numero de vol : ");
					scanf("%d",&NUM_VOL);
					if(Trouve_Passager_Vol(LISTE,ID,NUM_VOL))
						printf("\nLe passager d'identifiant %d existe dans la liste des vols !!\n\n",ID);
					else
						printf("\nle passager recherche n'existe pas dans la liste des vols !!\n\n");
				}
			break;
			
			case 4 :
				if(LISTE == NULL)
					printf("\nvous devez ajouter au moins un vol !!\n\n");
				else{
					printf("Donner le numero de vol recherche : ");
					scanf("%d",&NUM_VOL);
					if(Trouve_Vol(LISTE,NUM_VOL))
						printf("\nLe vol dont le numero est %d existe dans la liste !!\n\n",NUM_VOL);
					else
						printf("\nle vol recherche n'existe pas dans la liste !!\n\n");	
				}
			break;
			
			case 5 :
				if(LISTE == NULL)
					printf("\nvous devez ajouter au moins un vol !!\n\n");
				else{
					printf("Donner le numero de vol pour modifier sa date : ");
					scanf("%d",&NUM_VOL);
					printf("Donner la nouvelle date de depart du vol ");
					printf("Le Jour : ");scanf("%d",&dateDEPART.j);
					printf("Le Jour : ");scanf("%d",&dateDEPART.m);
					printf("Le Jour : ");scanf("%d",&dateDEPART.a);
					//scanf("%d/%d/%d",&dateDEPART.j,&dateDEPART.m,&dateDEPART.a);
					printf("Donner la nouvelle date d'arrivee du vol ");
					printf("Le Jour : ");scanf("%d",&dateARRIVEE.j);
					printf("Le Jour : ");scanf("%d",&dateARRIVEE.m);
					printf("Le Jour : ");scanf("%d",&dateARRIVEE.a);
					//scanf("%d/%d/%d",&dateARRIVEE.j,&dateARRIVEE.m,&dateARRIVEE.a);
					if(Modifier_Date(LISTE,dateDEPART,dateARRIVEE,NUM_VOL))
						printf("\nMODIFICATION EFFECTUEE AVEC SUCCES !!\n\n");
					else
						printf("\nla nouvelle date du vol n'est pas superieure a l'ancienne date !! \n\n");
				}
			break;

			case 6 :
				if(LISTE == NULL)
					printf("\nvous devez ajouter au moins un vol !!\n\n");
				else
					Afficher_Vol(LISTE);
			break;
			
			case 7 :
				if(LISTE == NULL && liste == NULL)
					printf("\nvous devez ajouter au moins un vol et un passager !!\n\n");
				else if(LISTE == NULL)
					printf("\nvous devez ajouter au moins un vol !!\n\n");
				else if(liste == NULL)
					printf("\nvous devez ajouter au moins un passager !!\n\n");
				else{
					printf("Donner le numero de vol dans lequel vous herchez un passager ayant moins de 10 ans : ");
					scanf("%d",&NUM_VOL);
					Afficher_Passager(LISTE,NUM_VOL);
				}
					
			break;
			
			case 8 :
				if(LISTE == NULL)
					printf("\nvous devez ajouter au moins un vol !!\n\n");
				else
					Afficher_Vol_Suivant(LISTE);			
			break;
			
			case 9 :
				if(LISTE == NULL)
					printf("\nvous devez ajouter au moins un vol !!\n\n");
				else{
					LISTE = Supp_Dernier_Vol(LISTE);
					printf("\n");
				}
			break;
			
			case 10 :
				if(LISTE == NULL && liste == NULL)
					printf("\nvous devez ajouter au moins un vol et un passager !!\n\n");
				else if(LISTE == NULL)
					printf("\nvous devez ajouter au moins un vol !!\n\n");
				else if(liste == NULL)
					printf("\nvous devez ajouter au moins un passager !!\n\n");
				else{
					printf("Donner l'iD du passager a supprimer : ");
					scanf("%d",&ID);
					printf("Donner le numero de vol  : ");
					scanf("%d",&NUM_VOL);
					LISTE = Supp_Passager_Vol(LISTE,ID,NUM_VOL);	
				}
			break;
			
			case 11 :
				printf("\n\t\t\t        FIN DU PROGRAMME"); 
			break;
			default : printf("\nVotre choix doit etre compris entre 1 et 11 !! \n\n");break;
		}
	}while(choix!=11);
}