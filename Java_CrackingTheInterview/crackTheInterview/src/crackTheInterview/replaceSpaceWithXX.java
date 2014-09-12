package crackTheInterview;

public class replaceSpaceWithXX {
	
	/***********************************************************************************
	Write a method to replace all spaces in a string with '%20'. You may assume that the
	string has sufficient space at the end of the string to hold the additional characters,
	and that you are given the "true" length of the string. (Note: if implementing in Java,
	please use a character array so that you can perform this operation in place.)	  
	 * **********************************************************************************/
	
	/***********************************************************************************
	//SOLUTION
	starting from the end and work backwards. In the first scan, we count how many spaces there 
	are in the string.In the second pass, which is done in reverse order, we actually edit the string. 
	When we see a space, we copy %20 into the next spots. If there is no space, then we copy the 
	original character.	  
	 * **********************************************************************************/
	public void replaceSpaces(char[] str, int length) 
	{
		int spaceCount = 0, newLength, i;
		for (i = 0; i < length; i++) 
		{
			if (str[i] == ' ') 
			{
				spaceCount++;
			}
		}
		
		newLength = length + spaceCount * 2;
		str[newLength] = '\0';
		for (i = length - 1; i >= 0; i--) 
		{
			if (str[i] == ' ') 
			{
				str[newLength - 1] = '0';
				str[newLength - 2] = '2';
				str[newLength - 3] = '%';
				newLength = newLength - 3;
			} else 
			{
				str[newLength - 1] = str[i];
				newLength = newLength - 1;
			}
		}
	}
	
}
