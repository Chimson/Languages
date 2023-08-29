namespace Lib.Chapter1;

public class BinarySearch {
  
  public static int Rank(int key, int[] a) {
    // assumes array is sorted
    // iterates by replacing either the hi or lo index, by an index near mid
    // returns the index of the found key or -1

    int lo = 0;
    int hi = a.Length - 1;   // largest index
    while (lo <= hi) {
      int mid = lo + (hi - lo)/2;
      if (key < a[mid]) {   // when the key is in the lower half of indixes
        hi = mid - 1;
      }  
      else if (key > a[mid]) {  // when its in the upper half
        lo = mid + 1;
      }
      else {
        return mid;
      }
    }
    return -1;
  } 
}