import javax.swing.JOptionPane;


public class reverseString {
	
	public static void main( String args[] )
	{
		String str = JOptionPane.showInputDialog(null, "Enter teh string you wish to check");
		System.out.println("OringStr-"+str+",revStr-"+ revString(str) );
	}

	public static StringBuffer revString(String str)
	{
		StringBuffer myStr = new StringBuffer();
		
		if( str == null || str.isEmpty() )
			return myStr;
		
		for(int i = str.length() - 1; i >= 0; i--)
		{
			myStr.append(str.charAt(i));
		}
		
		return myStr;
	}
}