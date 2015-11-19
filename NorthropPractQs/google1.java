import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

public class main {

    public static void main(String[] args) {
        // Prints "Hello, World" to the terminal window.
        System.out.println("Hello, World");
                
        int[] numbers =  createIntArray(10);
        
        System.out.println("   Array"+Arrays.toString(numbers));
        
        printLink(numbers, 10);
        
        System.out.println( answer(numbers) );
        
    }
    
    public static void printLink(int[] numbers, int size)
    {
    	int number = 0;
    	
    	
    	//print placeholder

		number = 0;
    	//print links
    	System.out.format("   Links[");
    	for(int i = 0; i < size; i++)
    	{
    		number = numbers[number];
    		System.out.format("%d, ", number);
    	}
    	System.out.format("]\n");
    }



	public static int[] createIntArray(int size)
	{
		Random rand = new Random();
		int number = 0;
		
		int[] myIntArray = new int[size];
		
		
		for(int i = 0; i < size; i++){
			number = Math.abs( rand.nextInt()%size );
		
			while ( number == i ){
				number = Math.abs( rand.nextInt()%size );
			}
			myIntArray[i] = number;
		}
		
		return myIntArray;
	}
	
	public static boolean containsInt(int[] array, int size, int value)
	{
		for(int i = 0; i < size; i++)
		{
			if( array[i] == value )
				return true;
		}
		return false;
	}

	
	
    public static int answer(int[] numbers) {
    	
    	//Find meeting point variables
    	int redirect = numbers[0];					int slow = redirect;
    	int fast = numbers[ numbers[slow]  ];		int size = numbers.length;	
		//Get link array variables
		int number = 0;		int[] linkArray = new int[size*4];
		//find size of repeat sequence variables
		int i2 = 0;			int trueCounter = 0;	int checkLimit = 0;
		int listSize = 0;	int num1 = 0, num2 = 0;
		//get a list of links variables
		List<Integer> list = new ArrayList<Integer>();
		
		//get linkArray
    	for(int i = 0; i < size*4; i++)
    	{
    		number = numbers[number%size];
    		linkArray[i] = number;
    	}

		// Find meeting point. 
		while( slow != fast )
		{
			slow = numbers[slow];
			fast = numbers[ numbers[fast]  ];
		}
		
		//get a list of the links
		for(int i = 0; i < size*2; i++)
		{
			if (linkArray[i] == fast )
			{
				for(int j = i; j < size*3 - i; j++)
				{
					list.add(linkArray[j]);
				}
				break;
			}
		}
		
		//find size of repeat sequence	
		for( int i = 0; i < list.size(); i++)
		{	
			i2 = i+1;
			checkLimit = i*2+1;
			if( checkLimit < list.size() )
			{
				trueCounter = 0;

				for(int j = 0; j < i2; j++)
				{
					num1 = list.get(j);
					num2 = list.get(i2+j);
					if( num1 == num2 )
					{
						trueCounter++;
					}	
				}
				
				if( trueCounter == (i+1) )
				{
					listSize = trueCounter;
					return listSize;
				}
			}
						
		} 

		return listSize;
    } //answer function
	
}
	