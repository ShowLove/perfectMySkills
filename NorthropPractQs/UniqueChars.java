import javax.swing.JOptionPane;


public class UniqueChars {

	/*
	Implement an algorithm to determine if a string has all unique characters. What if
	you cannot use additional data structures
	*/

	public static void main( String args[] )
	{
		String str = JOptionPane.showInputDialog(null, "Enter teh string you wish to check");
		System.out.println( "Unique chars? "+ onlyUniqueChars(str) );
	}

	public static boolean onlyUniqueChars( String str )
	{
		boolean[] newChars = new boolean[256];

		for( int i = 0; i < str.length(); i++)
		{
			if( newChars[str.charAt(i)] == false )
			{
				newChars[str.charAt(i)] = true; //We haven't seen this char yet
			}
			else if( newChars[str.charAt(i)] == true )
			{
				return false; 					//not all unique characters
			}
				
		}
		return true;
	}

}