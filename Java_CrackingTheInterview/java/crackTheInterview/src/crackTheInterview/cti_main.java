package crackTheInterview;
import java.io.*;

public class cti_main {
	
	/***********************************************************************************
	  
	 * **********************************************************************************/
	/////////////////////////////////HELPER_FUNCTIONS//////////////////////////////////////
	
	public static void main(String[] args)
	{	
		
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
	
	/*************************************************************************
	 *  This function prints a double array need array and length of cols n
	 * ***********************************************************************
	 * @param array
	 * @param n
	 */
	public void printDoubleArray( int array[][], int n)
	{
		for(int i = 0; i < n; i++)
		{
			System.out.printf("\t\t");
			for(int j = 0; j < n; j++)
			{
				System.out.printf("%d  ", array[i][j]);	
			}
			System.out.println();
		}
	}
	
	/***********************************************************************************
	  TODO: !main
	 * **********************************************************************************/
}
