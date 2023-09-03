namespace Lib.Chapter1;

public class BinarySearch {
  
  public static int Rank(in int key, in int[] a) {
    // assumes array is sorted increasing (not decreasing)
    // iterates by replacing either the hi or lo index, by an index near mid on next step
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

  public static int RecRank(in int key, in int[] a) {
    return RecRank(key, a, 0, a.Length - 1);
  }

  public static int RecRank(in int key, in int[] a, in int lo, in int hi) {
    /*
      a needs to be sorted increasing
      change the interval, dependent on which current half the key could live in
      R(3, [2,3,4,7,9,10], 0, 5) = 1 
        mid = 2
        return R(3, a, 0, 1) = 1
          mid = 0
          return R(3, a, 1, 1) = 1 
            mid = 1
            return 1
    */
    if (lo > hi) {return -1;}
    int mid = lo + (hi - lo)/2;
    if (key < a[mid]) {
      return RecRank(key, a, lo, mid - 1);
    }
    else if (key > a[mid]) {
      return RecRank(key, a, mid + 1, hi);
    }
    else {
      return mid;
    }
  }
}