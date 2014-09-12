package crackTheInterview;
import java.io.*;

public class cti_main {
	
	/***********************************************************************************
	  
	 * **********************************************************************************/
	/////////////////////////////////HELPER_FUNCTIONS//////////////////////////////////////
	
	public static void main(String[] args)
	{
		boolean isPermutation;
		//Create an object of the main class to use its methods
		cti_main myMethods = new cti_main();
		isStringPermutation isPerm = new isStringPermutation();
		
		String myString1 = myMethods.promptForAndRetunString();
		String myString2 = myMethods.promptForAndRetunString();
		
		isPermutation = isPerm.permutation(myString1, myString2);
		isPerm.printResult(isPermutation);	
	}
	
	/*******************************************************************************
	 *  This function returns a string. Function prompts user to provide the string.
	 ***************************************************************************** */
	public String promptForAndRetunString()
	{
		System.out.println("Input string: ");
		String string = "";
		InputStreamReader input = new InputStreamReader(System.in);
		BufferedReader reader = new BufferedReader(input);
		
		try
		{
			string = reader.readLine();
		}
		catch(Exception e)
		{
			;
		}
		
		return string;
	}
	
	/***********************************************************************************
	  TODO: !main
	 * **********************************************************************************/
}
