#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* constant definitions */
#define NAME_LENGTH 20
#define BUF_SIZE 80

void replace(FILE *infile, FILE *outfile, char *full, char *first, char *last, char *street, char *state){
    char inbuff[BUF_SIZE];
    char *cp;//char pointer
    char outbuff[BUF_SIZE*2];

    rewind(infile); //start file at the beginning
    
    while (fgets (inbuff, BUF_SIZE, infile) != NULL){
        cp = outbuff;
	int i;
        for ( i=0; i < strlen(inbuff); i++) {

            if (strncmp(&inbuff[i], "#N#", 3) == 0) {
                strcpy(cp, full);
                i += 2;
                cp += strlen(full); //moves pointer past full
            } else if (strncmp(&inbuff[i], "#F#", 3) == 0) {
                strcpy(cp, first);
                i += 2;
                cp += strlen(first);
            } else if (strncmp(&inbuff[i], "#L#", 3) == 0) {
                strcpy(cp, last);
                i += 2;
                cp += strlen(last);
            } else if (strncmp(&inbuff[i], "#A#", 3) == 0) {
                strcpy(cp, street);
                cp += strlen(street);
                *cp++ = '\n';
                strcpy(cp, state);
                i += 2;
                cp += strlen(state);
            } else{
                *cp = inbuff[i];
                cp++;

            }
                
        }
        *cp = '\0'; // have to null terminate prior to printing
        fprintf(outfile, "%s", outbuff);
    }
    fprintf (outfile, "\n"); // new line for new info
}




int main(int argc, char *argv[]){
    
    FILE *infile, *outfile, *info;
    char fullbuff[BUF_SIZE], firstbuff[BUF_SIZE], lastbuff[BUF_SIZE], streetbuff[BUF_SIZE], statebuff[BUF_SIZE];
    char blank[BUF_SIZE];
    char outbuff[BUF_SIZE*2];

    

    
    if (argc != 4){
        printf ("Enter three file names (input, info, output): \n");
        printf ("ERROR: must have three files\n");
        exit (1);
    }
    
    if (( infile = fopen (argv[1], "r")) == NULL){
        printf ("Cannot open input file.\n");
        exit (1);
    }
     
     if (( info = fopen (argv[2], "r")) == NULL){
        printf ("Cannot open info file.\n");
        exit (1);
    }

    if (( outfile = fopen (argv[3], "w")) == NULL){
        printf ("Cannot open output file.\n");
        exit (1);
    }
   
    
    
    while (!feof (info)){
        
        if (fgets (fullbuff, BUF_SIZE, info) == NULL) {
		printf("Fullname not found\n");
		break;
	}
        if (fgets (firstbuff, BUF_SIZE, info) == NULL) {
		printf("First name not found\n");
		break;
	}
	if (fgets (lastbuff, BUF_SIZE, info) == NULL) {
		printf("Last name not found\n");
		break;
	}
        if (fgets (streetbuff, BUF_SIZE, info) == NULL) {
		printf("Street address not found\n");
		break;
	}
        if (fgets (statebuff, BUF_SIZE, info) == NULL) {
		printf("City/State not found\n");
		break;
	}
	fgets(blank, BUF_SIZE, info);	// toss blank line

        fullbuff[strlen(fullbuff) -1] = '\0'; //strips new lines off buffer
        firstbuff[strlen(firstbuff) -1] = '\0';
        lastbuff[strlen(lastbuff) -1] = '\0';
        streetbuff[strlen(streetbuff) -1] = '\0';
        statebuff[strlen(statebuff) -1] = '\0';
        

        /*printf ("%s\n%s\n%s\n%s\n%s\n", fullbuff, firstbuff, lastbuff, streetbuff, statebuff);
        */
        replace(infile, outfile, fullbuff, firstbuff, lastbuff, streetbuff, statebuff); // replace infile with outfile with correct info
    }
    fclose (infile); //closing files
    fclose(info);
    fclose (outfile);
    
return (0);
}
