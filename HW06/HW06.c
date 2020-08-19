# include <string.h>


struct record
{
    char                       name[25];
    char                       address[80];
    int                        yearofbirth;
    chadfdfgsdfg s g                       telno[15];
    struct record              *next;
};


    //pointer to record called start - initialized to the start of the list (or NULL)
    struct record * start;
    
    //array uname –contains the user entered name
    char uname[25];

    //array uaddr –contains the user entered address
    char uaddr[80];
    
    //int uyob – contains the user entered year of birth
    int  uyob;
    
    //array utelno – contains the user entered telephone number  
    char utelno[15];
    
    
    
int addRecord (struct record *start,char uname[],char uaddr[],int uyob, char utelno[]) {
  
  struct record *current;
  current = start;
  int i;
  
  if (current != NULL) 
  {
  
    while (current->next != NULL)
    {
      current = current->next;
    }
  
  current->next = (struct record *)malloc(sizeof(struct record));
  current = current->next;

    
  }
  else
  {
   
    start = (struct record *)malloc(sizeof(struct record));
    current = start;
    
  }
  
current->next = NULL;

for (i=0; i<25; i++)  current->name[i] = uname[i];

for (i=0; i<80; i++)  current->address[i] = uaddr[i];

current->yearofbirth = uyob;
  
for (i=0; i<15; i++)  current->telno[i] = utelno[i];
  
  
}





int deleteRecord(struct record *start,char uname[]) {
  
  struct record *current;
  struct record *temp;
  current = start;
  int i;
  
  while(current != NULL) {
    
    if (strcmp(current->name,uname) == 0) 
    {
      
      if (current = start)
      {
	start = current-> next;
	free(current);
	current = start;
      }
      else
      {

	temp->next = current->next;
	free(current);
	current = temp->next;

      }
      
    }
    else
    {
      temp = current;
      current = current->next;
    }
    
  }
  
}



