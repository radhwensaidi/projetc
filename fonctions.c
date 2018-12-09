#include<gtk/gtk.h>
#include<string.h>
#include"fonctions.h"

int verifier( char nom[], char pwd[])
{ 
int a;
FILE* f;
char ch[30],ch1[30];
f=fopen("/home/radhwen/Bureau/projectmed/projectmed1/src/users","r");
if(f!=NULL)
{
while((fscanf(f,"%s %s %d", ch, ch1,&a)!=EOF))
{
if((strcmp(nom,ch)==0)&&(strcmp(pwd,ch1)==0)){
return(a);}}
fclose(f);}
else{
return(0); 
}}




void ajouter(char nom[],char prenom[],char adresse[] ,char tel[],char cin[],char rib[],int jour , int mois , int annee)
{FILE*f;

f=fopen("/home/radhwen/Bureau/projectmed/projectmed1/src/myspace.txt","w");

fprintf(f,"%s %s %s %s %s %s %d %d %d",nom,prenom,adresse,tel,cin,rib,jour,mois,annee);
fclose(f);
}






void afficher(GtkWidget *pListView)
{
enum {
NOM,

PRENOM,
ADRESSE,
TEL,
CIN,
DATE,
TOGGLE_COLUMN,
N_COLUMN
};


GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore =gtk_list_store_new(N_COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_BOOLEAN	);

FILE *f;char var[50],var1[50],var2[50],var3[50],var4[50],var5[50]; 
f=fopen("/home/radhwen/Bureau/projectmed/projectmed1/src/myspace.txt","r");
while(fscanf(f,"%s %s %s %s %s %s",var,var1,var2,var3,var4,var5)!=EOF)
	{
GtkTreeIter pIter;
gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,
NOM,var,
PRENOM,var1,
ADRESSE,var2,
TEL,var3,
CIN,var4,
DATE,var5,

TOGGLE_COLUMN,TRUE,
-1);
	}


void toggled_func(GtkCellRendererToggle *cell_renderer, gchar *path, gpointer user_data)
{
 
    GtkTreeIter iter;
    GtkTreePath *ppath;
    gboolean boolean;
 
 
// convertir la chaine path en GtkTreePath 
 
     ppath = gtk_tree_path_new_from_string (path);
 
// convertir la valeure recuperée en GtkTreeIter  
     gtk_tree_model_get_iter (GTK_TREE_MODEL (user_data),
                           &iter,
                           ppath);
//  utiliser la variable GtkTreeIter pour acceder la valeure booleaine                           
     gtk_tree_model_get (GTK_TREE_MODEL (user_data),
                           &iter,
                           TOGGLE_COLUMN,&boolean,
                           -1);
// changer cette valeure booleaine (! boolean )                          
     gtk_list_store_set (user_data, &iter,
                      TOGGLE_COLUMN, !boolean,
                      -1);
 
 
}


pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("nom",
pCellRenderer,
"text", NOM,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("prenom",
pCellRenderer,
"text", PRENOM,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("adresse",
pCellRenderer,
"text", ADRESSE,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("tel",
pCellRenderer,
"text", TEL,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("cin",
pCellRenderer,
"text", CIN,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("date",
pCellRenderer,
"text", DATE,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);




pCellRenderer = gtk_cell_renderer_toggle_new();
pColumn=gtk_tree_view_column_new_with_attributes("select",pCellRenderer,"active", TOGGLE_COLUMN,
NULL);

g_signal_connect(G_OBJECT(pCellRenderer), "toggled", (GCallback)toggled_func, pListStore);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);	

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 


fclose(f);
	
}




void ajouter_horaire(Datee d)
{	FILE* f;
	f=fopen("/home/radhwen/Bureau/projectmed/projectmed1/src/horaire.txt","a+");
  	if(f!=NULL) 
 		{  fprintf(f," %d %d %d %s \n", d.jour ,d.mois, d.annee, d.temps);  	
	fclose(f);  } 	


} 



void afficher_horaire(GtkWidget *pListView)
{
enum {
JOUR,

MOIS,
ANNEE,
TEMPS,
TOGGLE_COLUMN,
N_COLUMN
};


GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore =gtk_list_store_new(N_COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_BOOLEAN	);

FILE *f;char var[50],var1[50],var2[50],var3[50];
f=fopen("/home/radhwen/Bureau/projectmed/projectmed1/src/horaire.txt","r");
while(fscanf(f,"%s %s %s %s ",var,var1,var2,var3)!=EOF)
	{
GtkTreeIter pIter;
gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,
JOUR,var,
MOIS,var1,
ANNEE,var2,
TEMPS,var3,

TOGGLE_COLUMN,TRUE,
-1);
	}


void toggled_func(GtkCellRendererToggle *cell_renderer, gchar *path, gpointer user_data)
{
 
    GtkTreeIter iter;
    GtkTreePath *ppath;
    gboolean boolean;
 
 
// convertir la chaine path en GtkTreePath 
 
     ppath = gtk_tree_path_new_from_string (path);
 
// convertir la valeure recuperée en GtkTreeIter  
     gtk_tree_model_get_iter (GTK_TREE_MODEL (user_data),
                           &iter,
                           ppath);
//  utiliser la variable GtkTreeIter pour acceder la valeure booleaine                           
     gtk_tree_model_get (GTK_TREE_MODEL (user_data),
                           &iter,
                           TOGGLE_COLUMN,&boolean,
                           -1);
// changer cette valeure booleaine (! boolean )                          
     gtk_list_store_set (user_data, &iter,
                      TOGGLE_COLUMN, !boolean,
                      -1);
 
 
}
pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("jour",
pCellRenderer,
"text", JOUR,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("mois",
pCellRenderer,
"text", MOIS,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("annee",
pCellRenderer,
"text", ANNEE,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("temps",
pCellRenderer,
"text", TEMPS,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_toggle_new();
pColumn=gtk_tree_view_column_new_with_attributes("select",pCellRenderer,"active", TOGGLE_COLUMN,
NULL);

g_signal_connect(G_OBJECT(pCellRenderer), "toggled", (GCallback)toggled_func, pListStore);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);	

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 


fclose(f);
	
}


void ajouter_rdv(char nom1[],char prenom1[],Date1 d1)
{	FILE* f;
	f=fopen("/home/radhwen/Bureau/projectmed/projectmed1/src/RDV_MED.txt","a+");
  	if(f!=NULL) 
 		{  fprintf(f," %s %s %d %d %d %s \n",nom1,prenom1, d1.jour1 ,d1.mois1, d1.annee1, d1.temps1);  	
	fclose(f);  } 	


}
int verifier_rend(Date1 sa)
{
Date1 s;
int v=0; // salle non reserve
FILE *f5;
char ch1[50] ; char ch2[50];
f5=fopen("/home/radhwen/Bureau/projectmed/projectmed1/src/RDV_MED.txt","r");
if(f5!=NULL)
{
while(fscanf(f5,"%s %s %d %d %d %s ",ch1,ch2,&s.jour1,&s.mois1,&s.annee1,s.temps1)!=EOF)
{if (s.jour1==sa.jour1) {
if (s.mois1==sa.mois1) {
if (s.annee1==sa.annee1) {
if (strcmp(s.temps1,sa.temps1)==0)


{v=1;}
}
}
}
}
fclose(f5);
}
return v;
}

void afficher_rdv(GtkWidget *pListView)
{
enum {
NOM1,

PRENOM1,
JOUR1,
MOIS1,
ANNEE1,
TEMPS1,
TOGGLE_COLUMN,
N_COLUMN
};


GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore =gtk_list_store_new(N_COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_BOOLEAN	);

FILE *f;char var10[50],var11[50],var12[50],var13[50],var14[50],var15[50];
f=fopen("/home/radhwen/Bureau/projectmed/projectmed1/src/RDV_MED.txt","r");
while(fscanf(f,"%s %s %s %s %s %s ",var10,var11,var12,var13,var14,var15)!=EOF)
	{
GtkTreeIter pIter;
gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,
NOM1,var10,
PRENOM1,var11,
JOUR1,var12,
MOIS1,var13,
ANNEE1,var14,
TEMPS1,var15,

TOGGLE_COLUMN,TRUE,
-1);
	}

void toggled_func(GtkCellRendererToggle *cell_renderer, gchar *path, gpointer user_data)
{
 
    GtkTreeIter iter;
    GtkTreePath *ppath;
    gboolean boolean;
 
 
// convertir la chaine path en GtkTreePath 
 
     ppath = gtk_tree_path_new_from_string (path);
 
// convertir la valeure recuperée en GtkTreeIter  
     gtk_tree_model_get_iter (GTK_TREE_MODEL (user_data),
                           &iter,
                           ppath);
//  utiliser la variable GtkTreeIter pour acceder la valeure booleaine                           
     gtk_tree_model_get (GTK_TREE_MODEL (user_data),
                           &iter,
                           TOGGLE_COLUMN,&boolean,
                           -1);
// changer cette valeure booleaine (! boolean )                          
     gtk_list_store_set (user_data, &iter,
                      TOGGLE_COLUMN, !boolean,
                      -1);
 
 
}




pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("nom1",
pCellRenderer,
"text", NOM1,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);


pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("prenom1",
pCellRenderer,
"text", PRENOM1,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);


pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("jour1",
pCellRenderer,
"text", JOUR1,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("mois1",
pCellRenderer,
"text", MOIS1,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("annee1",
pCellRenderer,
"text", ANNEE1,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("temps1",
pCellRenderer,
"text", TEMPS1,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);


pCellRenderer = gtk_cell_renderer_toggle_new();
pColumn=gtk_tree_view_column_new_with_attributes("select",pCellRenderer,"active", TOGGLE_COLUMN,
NULL);

g_signal_connect(G_OBJECT(pCellRenderer), "toggled", (GCallback)toggled_func, pListStore);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);	

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 


fclose(f);
}

void ajouter2 (char nom[],char prenom[],char tel[],char sexe[],char poids[],char taille[],char maladies[],char conseils[])
{FILE*f;

f=fopen("/home/radhwen/Bureau/projectmed/projectmed1/src/myfiche.txt","a+");

fprintf(f,"%s %s %s %s %s %s %s %s \n",nom,prenom,tel,sexe,poids,taille,maladies,conseils);
fclose(f);
}

void afficher2(GtkWidget *pListView)
{
enum {
NOM,

PRENOM,
TEL,
SEXE,
POIDS,
TAILLE,


MALADIES,
CONSEILS,


TOGGLE_COLUMN,
N_COLUMN
};


GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
pListStore = gtk_list_store_new(N_COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_BOOLEAN	);

FILE *f;char var[50],var1[50],var2[50],var4[50],var5[50],var6[50],var7[50],var8[50];
f=fopen("/home/radhwen/Bureau/projectmed/projectmed1/src/myfiche.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %s",var,var1,var2,var6,var7,var8,var4,var5)!=EOF)
	{ 
GtkTreeIter pIter;
gtk_list_store_append(pListStore, &pIter);
gtk_list_store_set(pListStore, &pIter,
NOM,var,
PRENOM,var1,
TEL,var2,
SEXE,var6,
POIDS,var7,
TAILLE,var8,

MALADIES,var4,

CONSEILS,var5,



TOGGLE_COLUMN,TRUE,
-1);
	}


void toggled_func(GtkCellRendererToggle *cell_renderer, gchar *path, gpointer user_data)
{
 
    GtkTreeIter iter;
    GtkTreePath *ppath;
    gboolean boolean;
 
 
// convertir la chaine path en GtkTreePath 
 
     ppath = gtk_tree_path_new_from_string (path);
 
// convertir la valeure recuperée en GtkTreeIter  
     gtk_tree_model_get_iter (GTK_TREE_MODEL (user_data),
                           &iter,
                           ppath);
//  utiliser la variable GtkTreeIter pour acceder la valeure booleaine                           
     gtk_tree_model_get (GTK_TREE_MODEL (user_data),
                           &iter,
                           TOGGLE_COLUMN,&boolean,
                           -1);
// changer cette valeure booleaine (! boolean )                          
     gtk_list_store_set (user_data, &iter,
                      TOGGLE_COLUMN, !boolean,
                      -1);
 
 
}




pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("nom",
pCellRenderer,
"text", NOM,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("prenom",
pCellRenderer,
"text", PRENOM,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("tel",
pCellRenderer,
"text", TEL,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("maladies",
pCellRenderer,
"text", MALADIES,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);

pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("conseils",
pCellRenderer,
"text", CONSEILS,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);


pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("poids",
pCellRenderer,
"text", POIDS,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);


pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("taille",
pCellRenderer,
"text", TAILLE,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);


pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("sexe",
pCellRenderer,
"text", SEXE,
NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);





pCellRenderer = gtk_cell_renderer_toggle_new();
pColumn=gtk_tree_view_column_new_with_attributes("select",pCellRenderer,"active", TOGGLE_COLUMN,
NULL);

g_signal_connect(G_OBJECT(pCellRenderer), "toggled", (GCallback)toggled_func, pListStore);
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);	

gtk_tree_view_set_model(GTK_TREE_VIEW(pListView),GTK_TREE_MODEL(pListStore)); 


fclose(f);
}




