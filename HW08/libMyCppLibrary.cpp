 #include "HW08.h"
 
/*****************************************************************
//
//  Function name:		RoundNumber   
//
//  DESCRIPTION:		rounding up the input number to the next 
// 				multiple of 5 number
//
//  Parameters:			number (int): an integer number which is to be rounded up 
//
//  Return values:		(int): the rounded numbr
//
//****************************************************************/

JNIEXPORT jint JNICALL Java_HW08_RoundNumber(JNIEnv *env, jclass thisclass, jint number)
{
	// Rounding up the input number to the next multiple of 5

	number -= 1;
	return number + (5 - number % 5);
}


/*****************************************************************
//
//  Function name:		convertftoC   
//
//  DESCRIPTION:		A function to conver the temperature from Fahrenheit to Celsius
//
//  Parameters:			(int Fahrenheit): the temperature in Fahrenheit 
// 				
//
//  Return values:		float: the converted temperature in Celsius
//
//****************************************************************/

JNIEXPORT jfloat JNICALL Java_HW08_convertftoC(JNIEnv *env, jclass thisclass, jint Fahrenheit)
{
	return (Fahrenheit - 32.) * 5. / 9.;
}

