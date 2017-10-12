/*
* Here is the main class of the project. That programs is 
* in charge of all the input and the output messages(including
* errors messages). It will initialisate the map that the user have 
* entered in stdin and show the evolution of the virus.  
*
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//The dimensions of the matrix 
enum Dimension{
    LINES = 20,COLUMN = 40
};

bool initialisateMap();//char jeu[LINES][COLUMN]);
void printMap();
void evolutionOfVirus();
void emptyCell(char copie[LINES][COLUMN],int i,int j);
void populatedCell(char copie[LINES][COLUMN],int i,int j);
char jeu[LINES][COLUMN];//The representation of the game

/*
 * The main methods with two arguments
 * @params argc the number of arguments that the user entered
 * @params argv the array of strings that contains each arguments
 *
 */
int main(int argc, char * argv[]){
    int a;//Counter for the loop if argc == 2
    bool haveNoErr = true;//variable that will check if there are errors in the map
    int argm;//The number of days the user entered
    if(argc > 2){
        fprintf(stdout,"Erreur: Attendu un seul argument: le nombre de jours à simuler.");
    }else if(argc ==1){
        haveNoErr = initialisateMap();
        if(haveNoErr){    
            fprintf(stdout,"Jour 0\n");
            printMap();
        }
    }else if(argc == 2){
        int argm = atoi(argv[1]);
        if(argm < 0 || argm > 100){
            fprintf(stdout,"Erreur: Le nombre de jours à simuler doit être entre 0 et 100.\n");
        }else{ 
            haveNoErr=initialisateMap();//checking if there are errors or no
            if(haveNoErr){
                for(a = 0;a <= argm;a++){
                    fprintf(stdout,"Jour %d\n",a);
                    printMap();
                    if(a!=argm)
                        evolutionOfVirus();   
                }
            }
        }    
    }
    return 0;
}

/*
 * This method iniatialisate the matrix that represents the map. 
 * The inialisation is based on the input that the user entered.
 * It will show error messages depending on the cases(map too short,
 * unexpected character entered)
 * @return a boolean that specifie if there were an error or not 
 */
bool initialisateMap(){
    int i =0;
    int j =0;
    char c;
    for (i = 0; i < LINES;i++){
        for(j = 0;j<COLUMN;j++){
            c = getchar();
            if(c == '\n' && j != 0){
                fprintf(stdout,"Erreur: Caractère `EOF` inattendu, attendu `H`, `X` ou `.`.\n");
                return false;
            }
            if(c == '\n')
                c=getchar();
            if(c!='.' && c != 'H' && c!='X' && c != ' '){
                fprintf(stdout,"Erreur: Caractère `%c` inattendu, attendu `H`, `X` ou `.`.\n",c);
                return false;
            }
            while(c == ' ' && c != '\n'){
                c = getchar();
            }
            jeu[i][j] = c;
             
        }
    }
    return true;
    
}


/*
 * This method will print the map on stdout
 */
void printMap(){
    int i;
    int j;
    for(i = 0;i<LINES;i++){
        for(j=0;j<COLUMN;j++){
            fprintf(stdout,"%c",jeu[i][j]);
        }
        printf("\n");
    } 
}


/*
 * This method is the one that will changes the map
 * day after day. 
 */
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


/*
 * This method is called by the method evolutionOfVirus() if the cell
 * that is being checked is a non-populated one.
 * It will check the neighboor of the cell and modifie or not depending 
 * on the conditions.
 * @params copie it is a copie of the current map
 * @params i,j the coordonates of the cell   
 */
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
        }
        
    }
    if((healthy+infected) == 3 || healthy == 3 || infected == 3){
        if(healthy == 2 || healthy == 3){
            jeu[i][j]= 'H';
        }else if (infected == 2 || infected == 3){
            jeu[i][j] = 'X';
        }
   }

       
}


/*
 * This method is called by the method evolutionOfVirus() if the cell
 * that is being checked is a non-populated one.
 * It will check the neighboor of the cell and modifie or not depending 
 * on the conditions.
 * @params copie it is a copie of the current map
 * @params i,j the coordonates of the cell   
 */
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
