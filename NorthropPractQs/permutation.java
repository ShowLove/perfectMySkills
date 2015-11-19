package interview;

import javax.swing.JOptionPane;

public class permutation {

	public static void main(String args[] )
	{
		String str1 = JOptionPane.showInputDialog(null, "Enter teh string2 you wish to check");
		String str2 = JOptionPane.showInputDialog(null, "Enter teh string2 you wish to check");
		System.out.println("hello world");
		System.out.println( str1+" and "+str2+ " isPermutation? -->"+ isPermutation(str1, str2) );

	}
	
	public static boolean isPermutation(String str1, String str2 )
	{
		int[] cMem = new int[256];

		if( str1.length() != str2.length() )
			return false;

		
		for(int i = 0; i < str1.length(); i++)
		{
				cMem[ str1.charAt(i) ]++;
		}
		for(int i = 0; i < str1.length(); i++)
		{
				cMem[ str2.charAt(i) ]--;
				if( cMem[ str2.charAt(i) ] < 0 )
				{
					return false;
				}
		}

		return true;
	}
	
}
