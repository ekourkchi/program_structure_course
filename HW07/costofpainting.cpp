/*****************************************************************
//
//  Function name:		costofpainting   
//
//  DESCRIPTION:		This function calculates the painint cost using a recursive algorithm
// 				The road stripe painters have formed a union. Each painter will only paint a 
//				section of 2 miles of stripes on the road and charge $200 for the service.  
//				If the road is longer than 2 miles, the painter will divide the road into three equal parts, 
//				and subcontract each of those parts to three other painters, 
//				charging $100 to hire the three painters.  
//				Each of the hired painters will do the same thing as the painter who hired them.  
//				If their section is 2 miles or less, they will paint it and charge $200, 
//				otherwise they will  divide their section into three parts, 
//				charge $100 and hire three more painters, and so on.
//
//  Parameters:			(double length) Road distance in mile
//
//  Return values:		(int) The cost of painting
//
//****************************************************************/


int  costofpainting(double length) 
{
 
 if (length <= 0) return 0;
 if (length <= 2 && length > 0) return 200;
   
 return 3*costofpainting(length/3)+100;
  
}