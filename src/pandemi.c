#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

enum Dimension{
    LINES = 20,COLUMN = 40
};

void initialisateMap();//char jeu[LINES][COLUMN]);
void printMap();
void evolutionOfVirus();
void emptyCell(char copie[LINES][COLUMN],int i,int j);
void populatedCell(char copie[LINES][COLUMN],int i,int j);
char jeu[LINES][COLUMN];//The representation of the game

int main(int argc, char * argv[]){
    int a;//Counter for the loop if argc == 2
    int argm;//The number of days the user entered
    if(argc > 2){
        printf("Erreur: Attendu un seul argument: le nombre de jours à simuler.");
    }else if(argc == 1){
        initialisateMap();
        printf("Jour 0\n");
        printMap();
    }else if(argc == 2){
        int argm = atoi(argv[1]);
        if(argm < 0 && argm > 100){
            printf("Erreur: Le nombre de jours à simuler doit être entre 0 et 100.\n");
        } 
        initialisateMap();
        for(a = 0;a <= argm;a++){
            //evolutionOfVirus();
            printf("Jour %d \n",a);
            printMap();
            if(a!=argm)
                evolutionOfVirus();   
        }
    }
    return 0;
}

/*
*This method iniatialisate the matrix that represents the map
*
*/
void initialisateMap(){
    int i =0;
    int j =0;
    char c;
    for (i = 0; i < LINES;i++){
        for(j = 0;j<COLUMN;j++){
            c = getchar();
            if(c == '\n')
                c = getchar();
            while (c != '.'&& c != 'H' && c != 'X'){
                if(c != '\n')
                    printf("Erreur: Caractère '%c' inattendu, attendu '.', 'H' ou 'X'.\n",c);
            }
            jeu[i][j] = c;
        }
    }
    //printf("\n");
}


void printMap(){
    int i;
    int j;
    for(i = 0;i<LINES;i++){
        for(j=0;j<COLUMN;j++){
                printf("%c",jeu[i][j]);
        }
        printf("\n");
    } 
}

void evolutionOfVirus(){
    int i;
    int j;
    int nbCellArounds;
    char copie[LINES][COLUMN];
    for(i = 0; i < LINES;i++){
        for(j =0; j < COLUMN;j++){
            copie[i][j] = jeu[i][j];
        }
    }
    for (i = 0; i < LINES;i++){
        for(j=0;j<COLUMN;j++){
            if(jeu[i][j] == '.'){        
                emptyCell(copie,i,j);
            }else if(jeu[i][j] == 'H' || jeu[i][j] == 'X'){
                populatedCell(copie,i,j);
            }
        }
    }   
}

void emptyCell(char copie[LINES][COLUMN],int i,int j){
    int a;
    int infected = 0;
    int healthy= 0;
    int clean = 0;    
    int checkI = i-1;
    int checkJ = j-1;
    for(a=0;a<8;a++){
        if(a==0){
            checkI = i-1;
            checkJ = j-1;   
        }else if(a==1){
            checkI = i-1;
            checkJ = j;
        }else if(a==2){
            checkI =i-1;
            checkJ = j+1;
        }else if(a==3){
            checkI=i;
            checkJ=j-1;
        }else if(a==4){
            checkI=i;
            checkJ=j+1;
        }else if(a==5){
            checkI=i+1;
            checkJ=j-1;
        }else if(a==6){
            checkI=i+1;
            checkJ=j;
        }else if(a==7){
            checkI=i+1;
            checkJ=j+1;
        }
        if(checkI >=0 && checkI < LINES && checkJ>=0 && checkJ < COLUMN){
            if(copie[checkI][checkJ] == '.'){
                clean++;
            }else if(copie[checkI][checkJ] == 'H'){
                healthy++;
            }else if (copie[checkI][checkJ] == 'X'){
                infected++;
            }
            if((healthy+infected) == 3 || healthy == 3 || infected == 3){
                if(healthy == 2 || healthy == 3){
                    jeu[i][j]= 'H';               
                }else if (infected == 2 || infected == 3){
                    jeu[i][j] = 'X';     
                }
                break;
            }
        }
    
    }
       
}

void populatedCell(char copie[LINES][COLUMN],int i,int j){
    int a;
    int neighboor = 0;
    int infected = 0;
    int healthy= 0;
    int clean = 0;
    int checkI = i-1;
    int checkJ = j-1;
    for(a=0;a<8;a++){
        if(a==0){
            checkI = i-1;
            checkJ = j-1;
        }else if(a==1){
            checkI = i-1;
            checkJ = j;
        }else if(a==2){
            checkI =i-1;
            checkJ = j+1;
        }else if(a==3){
            checkI=i;
            checkJ=j-1;
        }else if(a==4){
            checkI=i;
            checkJ=j+1; 
        }else if(a==5){
            checkI=i+1;
            checkJ=j-1;
        }else if(a==6){
            checkI=i+1;
            checkJ=j;
        }else if(a==7){
            checkI=i+1;
            checkJ=j+1;   
        }
        if(checkI >=0 && checkI < LINES && checkJ>=0 && checkJ < COLUMN){
            neighboor++;
            if(copie[checkI][checkJ] == '.'){
                clean++;
            }else if(copie[checkI][checkJ] == 'H'){
                healthy++;
            }else if (copie[checkI][checkJ] == 'X'){
                infected++;
            }
            /*
            if((infected+healthy) == 2 || (infected + healthy) == 3){
                if(copie[i][j] == 'H'){
                    if(infected > healthy)
                        jeu[i][j] = 'X';                       
                }
                break;
            }else if (a == 7 && ((infected+healthy)< 2 || (infected+healthy) > 3)){
                jeu[i][j] = '.';
            }*/

       }
    }
    if((infected+healthy) == 2 || (infected + healthy) == 3){
        if(copie[i][j] == 'H'){
            if(infected > healthy)
            jeu[i][j] = 'X';
        }
    }else if (((infected+healthy)< 2) ||((infected+healthy) > 3)){
        jeu[i][j] = '.';
    }

}
