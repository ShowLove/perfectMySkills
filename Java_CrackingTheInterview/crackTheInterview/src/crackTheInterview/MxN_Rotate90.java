package crackTheInterview;

public class MxN_Rotate90 {

	/*	OUTPUT
	 * 
	Before array:
			0  1  2  3  
			1  2  3  4  
			2  3  4  5  
			3  4  5  6  
	After array:
			3  2  1  0  
			4  3  2  1  
			5  4  3  2  
			6  5  4  3  
	 *
	 */
	
/*
 * 
 * 	1 for i = 0 to n
 	temp = top[i]j
 	top[i] = leftfi]
 	leftfi] = bottom[i]
	bottom[i] = right[i]
 	right[i] = temp
 * 
 */
	
/*		PROBLEM
 * Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
 */
	
	public void rotate(int[][] matrix, int n) {
		
		for (int layer = 0; layer < n / 2; ++layer) {
			
			int first = layer;
			int last = n - 1 - layer;
			
			for(int i = first; i < last; ++i) {
				
				int offset = i - first;
				// save top
				int top = matrix[first][i];
				
				 // left -> top
				matrix[first][i] = matrix[last-offset][first];
				
				// bottom -> left
				matrix[last-offset][first] = matrix[last][last - offset];
				
				// right -> bottom
				matrix[last][last - offset] = matrix[i][last];
				
				// top -> right
				matrix[i][last] = top;
			}
		}
	}
	

	

}
