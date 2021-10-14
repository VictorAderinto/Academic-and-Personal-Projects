/**
 * A class that will generate magic squares of
 * odd order using de la Loubere's algorithm.
 */
public class MagicSquare {
  
  //An array to hold the magic square
  //***YOUR CODE HERE***
  private int[][] magicSquareArray;
  
  public MagicSquare(int n) { 
    /* Cnnstruct a magic square of order n
     * (n rows and columns containing numbers
     * from 1 to n*n).
     */
    //***YOUR CODE HERE***
    //int count = 1;
    magicSquareArray = new int[n][n];
    int i = n-1;
    int j = n/2;
    for (int count = 1; count < (n*n + 1); count++){
      magicSquareArray[i][j] = count;
      if (count % n == 0)
      {
        if (i == 0){
          i = n-1;
        }
        else
          i = i -1;
      }
      else {
          j = (j+1) % n;
          i = (i+1) % n; 
      }  
    }
    
  }//constructor
  
  public String toString(){
    /* Return a String allowing the square to be
     * printed. Rows are separated by \n and columns
     * are separated by \t characters.
     */
    String array = "";
    //***YOUR CODE HERE***
    for (int r =0; r < magicSquareArray.length; r++){
      for (int s =0; s < magicSquareArray.length; s++){
        array += magicSquareArray[r][s] + "\t";
      }
      array+= "\n";
    }
    return array; //DUMMY - REMOVE
  }//toString
  
}//MagicSquare class
