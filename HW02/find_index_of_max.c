/*****************************************************************
//
//  Function name:		find_index_of_max   
//
//  DESCRIPTION:		This funstion finds the index of maximum value of an array
//
//  Parameters:			float array[]: a float array
//				int size : the size of the array
//
//  Return values:		int: the integer value of the index of the maximum value
//
//****************************************************************/


int find_index_of_max(float array[ ], int size)
{
  
  int index = 0, max_index = 0;
  float max = array[0];

  for (index=0; index < size; index++)
  {
     if (array[index] > max) 
     {
     max = array[index];
     max_index = index;  
     }
  }
  
  return max_index;
}
