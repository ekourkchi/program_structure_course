
/*****************************************************************
//
//  Function name:		strappend  
//
//  DESCRIPTION:		a function to appends the second string argument 
				to the first string
//
//  Parameters:			char[] string1: The first string that the secound is to be attached to
//				char[] string2: The secound string which is to be attached to the forst one
//
//  Return values:		No output.
//
//****************************************************************/

void strappend(char string1[ ], char string2[ ]) 

{
  int index1 = 0, index2 = 0;
  
  while (string1[index1] != '\0') 
  {
    index1++;
  }

  while (string2[index2] != '\0') 
  {
    string1[index1] = string2[index2];
    index1++;
    index2++;
  }
  
  string1[index1] = '\0';

  
}
