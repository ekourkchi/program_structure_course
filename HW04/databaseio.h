int readfile(struct account accarray[ ], int * numcust, char filename[ ]);
int writefile(struct account accarray[ ], int numcust, char filename[ ]); 
int readfield2string(FILE *inputfile, char readstring1[], char readstring2[], int max_length2);
void strappend(char string1[ ], char string2[ ]);
char *stringlower(char *string);
