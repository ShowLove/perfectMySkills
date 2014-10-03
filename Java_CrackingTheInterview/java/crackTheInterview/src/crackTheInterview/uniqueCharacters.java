package crackTheInterview;

public class uniqueCharacters {
	
	/*Implement an algorithm to determin if a string has all unique characers.
	 * What if you cannot use additional data structures*/

	/***********************************************************************************
	    The time complexity for this code is 0(n), where n is the length of the string. The space
		complexity is 0(1).
	 * **********************************************************************************/
	public boolean charsInStringUnique(String str)
	{
		boolean[] char_set = new boolean[256]; //number of values in ascii
		for(int i = 0; i < str.length(); i++)
		{
			//Getting the int value of the char and
			//setting a flag at that ascii spot
			int val = str.charAt(i);
			if(char_set[val])
				return false;
			char_set[val] = true;
		}
		return true;		
	}

	/////////////////////////////////HELPER_FUNCTIONS//////////////////////////////////////
	
	public void printResult(boolean isUnique)
	{
		if(isUnique)
		{
			System.out.println("Your string had all unique chars");
		}
		else
		{
			System.out.println("Your string had duplicate chars");
		}
	}
	
	/*************************************************************************
	 *	//In Main  use the following
	 * 		boolean isUnique;
		//Create an object of the main class to use its methods
		cti_main myMethods = new cti_main();
		uniqueCharacters uChar = new uniqueCharacters();
		String myString = myMethods.promptForAndRetunString();
	 * ***********************************************************************/
}
