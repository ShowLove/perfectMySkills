
		//Declare array of booleans initialized to false
		boolean[] char_set = new boolean[256];
		//Find char at index of string
		int val = str.charAt(0);
		char_set[val] = true;

		//String check condition
		if( str == null || str.isEmpty() )
			return 0;
		//Find string length
		int strLength = str.length();
		//Get # digits in a number 100 = 3
		int value = String.valueOf(str).length();
		//like a String, but can be modified. append and insert
		StringBuffer mystr = new StringBuffer();
		mystr.append("c");

		//Convert string to char array
		char[] content = str.toCharArray();
		//Sort a char array
		Arrays.sort( content );
		//creating a new string so you must return it like that
		return new String(content);

		//Turn a string to an array
		char[] chars = word.toCharArray();	

		//Check for anagram
		Arrays.sort(w1);
		Arrays.sort(w2);
		Arrays.equals(charFromWord, charFromAnagram);

		 //Convert string to integer// Float.parseFloat() and Double.parseDouble()
		 int i = Integer.parseInt("123");

		 //Check for duplicates in set
		 //A Set is a Collection that cannot contain duplicate elements.
		 //since Set doesn't contain duplicate, size must be less for an array which contains duplicates
		 List inputList = Arrays.asList(input);
		 Set inputSet = new HashSet(inputList);
		 if(inputSet.size()< inputList.size())
		 	return true;

		 //Option 2//  Set doesn't allow duplicates
		 Set tempSet = new HashSet();
		 for (String str : input) {
		 	if (!tempSet.add(str)) {
		 		return true;