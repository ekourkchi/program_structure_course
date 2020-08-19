/*****************************************************************
//
//  NAME:		Ehsan Kourkchi
//
//  HOMEWORK:		Project 1
//
//  CLASS:		ICS 212
//
//  INSTRUCTOR:		Ravi Narayan
//
//  DATE:		December 1, 2013           
//
//  FILE:		hw09.c        
//
//  DESCRIPTION:	This file contains the tcp header handling
//			functions, required for HW09
//
//****************************************************************/
// To compile the program:
// $ make all
// $ ./tcp_hw09  test.bin
//****************************************************************/


# include <stdio.h>
# include <string.h>
# include  <stdlib.h>



// functions prototype
int printheader();
int readfile(char []);
int writefile(char []);
int response();



// a Global tcp structure 
struct tcp {
   
   int validity;
   unsigned char source[2];
   unsigned char destination[2];
   unsigned char sequence[4];
   unsigned char acknowledge[4];
   unsigned char offset;
   unsigned char reserved[2]; 
   unsigned char flags;  
   unsigned char window[2];
   unsigned char checksum[2];
   unsigned char urgent[2];
  
}    header;




/*****************************************************************
//
//  Function name:		Main  
//
//  DESCRIPTION:		a function that provide a user interface that asks 
//				the user interactively to add data to the data base 
//				It provides some user friendly menu facilities 
//
//  Parameters:			Needs one argument, which is the name of input binary file
//				which contains the TCP header
//
//  Return values:		int: != 0 exit with error
//				     = 0 complete the program without error
//****************************************************************/


int main(int argc, char *argv[])
{
  
  char outfile[20];
  strcpy(outfile, "output.");
  
  header.validity = 0; // it is set to 1 when a tcp header file is imported
  
  // check for the number of input arguments
  if(argc != 2)
  {
    printf("\n   Please just enter the input file name as the in-line argument. \n\n");
    return 1;
  }
  
  //reading in the input binary file
  if(readfile(argv[1]))
  {
    printf("\n   Invalide file name: \"%s\" \n\n", argv[1]);
    return 2;
  }
  
  printf("\n ********************************");
  printf("\n TCP request header [%s]", argv[1]);
  printheader();
  
  // Prepare the response header based on the stored input header
  response();
  
  // making the name the output file to store the response
  strcat(outfile, argv[1]);
  
  
  // writing the output file
  if(writefile(outfile))
  {
    printf("\n   File \"%s\" cannot be created. \n\n", outfile);
    return 3;
  }
  
  
  // Reading in the output again 
  if(readfile(outfile))
  {  
    printf("\n   The output file \"%s\" is not available. \n\n", outfile);
    return 4;    
    
  } 
  printf("\n ********************************");
  printf("\n TCP response header [%s]", outfile);
  
  // Printing out the output file
  printheader();
  
  

  return 0;
  
} /** The end of main program */

/*****************************************************************/
/*****************************************************************/
/*****************************************************************/

/*****************************************************************
//
//  Function name:		readfile  
//
//  DESCRIPTION:		a function that read in a binary file which
//				contains the header of a TCP message
//
//  Parameters:			char [] filename: the name of binary input file
//
//  Return values:		int: = 1 not able to open the file, exit
//				     = 0 read in the file, and exit with success
//****************************************************************/

int readfile(char filename[]) 
{
  
  FILE *file;
  int i;
  unsigned char input[20];
  
  file = fopen(filename, "rb");
  if (file == NULL) return 1;

  
  fread(input, sizeof(input), 1, file);
    
   header.source[0] = input[0];
   header.source[1] = input[1];
   
   header.destination[0] = input[2];
   header.destination[1] = input[3];
   
   for(i=0; i<4; i++)
     header.sequence[i] = input[4+i];
   
   for(i=0; i<4; i++)
     header.acknowledge[i] = input[8+i];
   
   header.offset = input[12] & 0xf0;      // & 1111 0000
   header.reserved[0] = input[12] & 0x0f;   // & 0000 1111
   header.reserved[1] = input[13] & 0xc0;   // & 1100 0000 
   
   header.flags = input[13] & 0x3f;      // & 0011 1111
   
   header.window[0] = input[14];
   header.window[1] = input[15];
   
   header.checksum[0] = input[16];
   header.checksum[1] = input[17];
   
   header.urgent[0] = input[18];
   header.urgent[1] = input[19];
   
  header.validity = 1;
  
  fclose(file);
  return 0;
}

/*****************************************************************/
/*****************************************************************/
/*****************************************************************/

/*****************************************************************
//
//  Function name:		printheader  
//
//  DESCRIPTION:		a function that prints the inported tcp header
//
//  Parameters:			no input ... It uses the global variable (struct tcp)
//
//  Return values:		int: = 1 exit withour printing (no valid tcp header imported)
//				     = 0 printing the header with success
//****************************************************************/

int printheader()
{
  unsigned long number;
  
  if (header.validity == 0) 
    return 1;
  
  printf("\n  ***************************\n");
  
  number = header.source[0]*256 + header.source[1];
  printf("  Source Port: %d\n", number);
  
  number = header.destination[0]*256 + header.destination[1];
  printf("  Destination Port: %d\n", number);
  
  number = header.sequence[0]*256*256*256 + header.sequence[1]*256*256 + header.sequence[2]*256 + header.sequence[3];
  printf("  Sequence Number: %u\n", number);
  
  number = header.acknowledge[0]*256*256*256 + header.acknowledge[1]*256*256 + header.acknowledge[2]*256 + header.acknowledge[3];
  printf("  Acknowledge Number: %u\n", number);
  
  
  number = header.offset / 16;
  printf("  Data Offset: %d\n", number);
  
  number = header.reserved[0] / 16 + header.reserved[1] / 64;
  printf("  Reserved: %d\n", number);
  
  printf("  Flags: "); 
  if (header.flags & 0x20) printf("URG ");
  if (header.flags & 0x10) printf("ACK ");
  if (header.flags & 0x08) printf("PSH ");
  if (header.flags & 0x04) printf("RST ");
  if (header.flags & 0x02) printf("SYN ");
  if (header.flags & 0x01) printf("FIN ");
  printf("\n");
  
  number = header.window[0]*256 + header.window[1];
  printf("  Window: %ld\n", number);
  
  printf("  Checksum: %x\n", header.checksum[0]*256 + header.checksum[0]);
  
  number = header.urgent[0]*256 + header.urgent[1];
  printf("  Urgent Pointer: %ld\n", number);
  printf("  ***************************\n\n");
  
 return 0;
  
}

/*****************************************************************/
/*****************************************************************/
/*****************************************************************/

/*****************************************************************
//
//  Function name:		writefile  
//
//  DESCRIPTION:		a function that writes the header of a TCP message
//				in a file
//
//  Parameters:			char [] filename: the name of binary output file
//
//  Return values:		int: = 1 not able to create the file for writing, exit
//				     = 0 writing out the file, and exit with success
//****************************************************************/

int writefile(char filename[])
{
  
  FILE *file;
  int i;
  unsigned char output[20];
  
  
  if (header.validity == 0) 
    return 1;   // no valid header is available
  
  file = fopen(filename, "wb");
  
  if (file == NULL) 
     return 1;   // unable to open the file for writing
  
  output[0] = header.source[0];
  output[1] = header.source[1];
  
  output[2] = header.destination[0];
  output[3] = header.destination[1];
  
  for(i=0; i<4; i++)
     output[4+i] = header.sequence[i];
  
  for(i=0; i<4; i++)
     output[8+i] = header.acknowledge[i];
  
   output[12] = header.offset | header.reserved[0];
   output[13] = header.flags | header.reserved[1];
  
   output[14] = header.window[0];
   output[15] = header.window[1];
   
   output[16] = header.checksum[0];
   output[17] = header.checksum[1];
   
   output[18] = header.urgent[0];
   output[19] = header.urgent[1];
   
   fwrite(output, sizeof(output), 1, file);
   
   
  fclose(file);
  return 0;
}

/*****************************************************************/
/*****************************************************************/
/*****************************************************************/

/*****************************************************************
//
//  Function name:		response  
//
//  DESCRIPTION:		a function that creates the response based on the stored request
//				+ The response file will switch the source and destination ports
//				+ The sequence number must be incremented by 1 for the response
//				+ The acknowledgment number of the response must be sequence number of the request
//				+ If the SYN flag is set in the request, both the SYN and ACK flags must be set in the response
//
//  Parameters:			no input parameter
//
//  Return values:		int: = 1 exit withour printing (no valid tcp header imported)
//				     = 0 printing the header with success
//****************************************************************/

int response()
{
  
  
  if (header.validity == 0) 
    return 1;   // no valid header is available
    
    
  int i;
  unsigned char tmp;
  
  for(i=0; i<2; i++) 
  {
    tmp = header.source[i];
    header.source[i] = header.destination[i];
    header.destination[i] = tmp;
  } 
    
  
  for(i=0; i<4; i++) 
      header.acknowledge[i] = header.sequence[i];
  

  
  header.sequence[3]++;
  if(header.sequence[3] == 0) {header.sequence[2]++;
  if(header.sequence[2] == 0) {header.sequence[1]++;
  if(header.sequence[1] == 0) header.sequence[0]++;}}
  
  if(header.flags & 0x02)  header.flags = header.flags | 0x12;
  
  return 0;
}
  
/*****************************************************************/
/*****************************************************************/
/*****************************************************************/