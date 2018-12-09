int verifier( char nom[], char pwd[]);
void ajouter(char nom[],char prenom[],char adresse[] ,char tel[],char cin[],char rib[],int jour , int mois ,int annee);
void afficher(GtkWidget *pListView);
typedef struct
{	
	int jour;
	int mois;
	int annee;
        char temps[50];
}Datee;
void afficher_horaire(GtkWidget *pListView);
void ajouter_horaire(Datee d);

typedef struct
{	
	int jour1;
	int mois1;
	int annee1;
        char temps1[50];
}Date1;
void ajouter_rdv(char nom1[],char prenom1[],Date1 d1);
void afficher_rdv(GtkWidget *pListView);
typedef struct
{  
char nom[50]; 
char prenom[20];
char tel[50] ; 
char cin[50] ; 
char adresse[50] ; 
char rib[50] ;
}kprofil;



void ajouter2 (char nom[],char prenom[],char tel[],char sexe[],char poids[],char taille[],char maladies[],char conseils[]);
void afficher2(GtkWidget *pListView);
int verifier_rend(Date1 sa);


