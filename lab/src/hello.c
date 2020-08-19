# include <stdlib.h>
# include <stdio.h>


int main(int argc, char *argv [] )
{

int index = 0;
double sum = 0;

printf("\nNumber of arguments: %d\n\n", argc);

for (index =1; index <= argc-1; index++ )
{

if (atof(argv[index]) != 0)

{

printf("Num[%d] = %s\n", index, argv[index]);

sum += atof(argv[index]);

}}

printf("\nAverage: %f\n", sum/(argc-1));




return 0;
}
