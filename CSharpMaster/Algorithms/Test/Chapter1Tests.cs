namespace Test;

using Lib.Chapter1;
using NUnit.Framework;

[TestFixture]
public class Chapter1Tests {


  [OneTimeSetUp]
  public static void Init() {
    // error stream prints immediately
    Console.Error.WriteLine(Results.Title("Chapter 1 Tests"));
  }

  [Test]
  public void GCDTest0() {
    int actual = MathFunctions.GCD(1,0);
    int expected = 1;
    Assert.True(expected == actual, $"{expected} != {actual}");
    Results.Print($"GCD(1,0) == {actual}");
  }

  [Test]
  public void GCDTest1() {
    int actual = MathFunctions.GCD(24, 18);
    int expected = 6;
    Assert.True(expected == actual, $"{expected} != {actual}");
    Results.Print($"GCD(24,18) == {actual}");
  }

  [Test]
  public void GCDTest2() {
    int actual = MathFunctions.GCD(2310, 1001);
    int expected = 77;
    Assert.True(expected == actual, $"{expected} != {actual}");
    Results.Print($"GCD(2310,1001) == {actual}");
  }

  [Test]
  public void RankTest1() {
    int[] arr = {2, 4, 7, 9, 10, 15};
    int key = 7;
    int expected = 2;
    int actual = BinarySearch.Rank(key, arr);
    Assert.AreEqual(expected, actual);
    Results.Print($"rank({key}, {Results.ArrStr<int>(arr)}) == {actual}");
  }

  [Test]
  public void RankTest2() {
    int[] arr = {2, 4, 7, 9, 10, 15};
    int key = 6;
    int expected = -1;
    int actual = BinarySearch.Rank(key, arr);
    Assert.AreEqual(expected, actual);
    Results.Print($"rank({key}, {Results.ArrStr<int>(arr)}) == {actual}");
  }

  [Test]
  public void RankTest3() {
    int[] arr = {15, 10, 9, 7, 4, 2};
    int key = 4;
    int expected = -1;
    int actual = BinarySearch.Rank(key, arr);
    Assert.AreEqual(expected, actual);
    Results.Print($"rank({key}, {Results.ArrStr<int>(arr)}) == {actual}");
  }

  [Test]
  public void RankTest4() {
    int[] arr = {2, 5, 6, 8, 9, 10};
    int key = 9;
    int expected = 4;
    int actual = BinarySearch.Rank(key, arr);
    Assert.AreEqual(expected, actual);
    Results.Print($"rank({key}, {Results.ArrStr<int>(arr)}) == {actual}");
  }

  [Test]
  public void MaxTest1() {
    double[] arr = {9.0, 4.0, 3.0, -2.0, 10.0, 7.0};
    double expected = 10;
    double actual = ArrayProcess.Max(arr);
    Assert.AreEqual(expected, actual);
    Results.Print($"Max({Results.ArrStr<double>(arr)} == {actual})");
  }

  [Test]
  public void AverageTest1() {
    double[] arr = {9.0, 4.0, 3.0, -2.0, 10.0, 7.0};
    double expected = 31.0 / 6.0;
    double actual = ArrayProcess.Average(arr);
    Assert.AreEqual(expected, actual);
    Results.Print($"Average({Results.ArrStr<double>(arr)}) == {actual}");
  }

  [Test]
  public void CopyTest1() {
    double[] arr = {9.0, 4.0, 3.0, -2.0, 10.0, 7.0};
    double[] copy = ArrayProcess.Copy(arr);
    Assert.AreEqual(arr, copy);
    Assert.AreNotSame(arr, copy);
    Results.Print($"Copy(array) passes");
  } 

  [Test]
  public void ReverseTestEven() {
    double[] arr = {9.0, 4.0, 3.0, -2.0, 10.0, 7.0};
    double[] expected = {7.0, 10.0, -2.0, 3.0, 4.0, 9.0};
    ArrayProcess.Reverse(arr);
    Assert.AreEqual(expected, arr);
    Results.Print($"Reverse(9,4,3,-2,10,7) == {Results.ArrStr<double>(arr)}");
  }

  [Test]
  public void ReverseTestOdd() {
    double[] arr = {9.0, 4.0, 3.0, -2.0, 10.0};
    double[] expected = {10.0, -2.0, 3.0, 4.0, 9.0};
    ArrayProcess.Reverse(arr);
    Assert.AreEqual(expected, arr);
    Results.Print($"Reverse(9,4,3,-2,10) == {Results.ArrStr<double>(arr)}");
  }

  [Test]
  public void TwoDPrintTest() {
    /*
    1 0 2   1 2 0   3 2 4
    0 2 1 * 0 2 1 = 1 4 4
    1 2 0   1 0 2   1 6 2
    */
    double[,] a = {{1, 0, 2}, {0, 2, 1}, {1, 2, 0}};
    double[,] b = {{1, 2, 0}, {0, 2, 1}, {1, 0, 2}};
    double[,] expected = {{3, 2, 4}, {1, 4, 4}, {1, 6, 2}};
    double[,] actual = MathFunctions.MatrixMult(a, b);
    Results.Print($"a:\n{Results.TwoDArrStr<double>(a)}");
    Results.Print($"b:\n{Results.TwoDArrStr<double>(b)}");
    Results.Print($"a x b = c\nc:\n{Results.TwoDArrStr<double>(actual)}");
    Assert.AreEqual(expected, actual);
  }

  [Test]
  public void AbsTest1() {
    int x = -1;
    int actual = (int) MathFunctions.Abs(x);
    int expected = 1;
    Assert.AreEqual(expected, actual);
    Results.Print($"abs(-1) == {actual}");
  }

  [Test]
  public void AbsTest2() {
    int x = 1;
    int actual = (int) MathFunctions.Abs(x);
    int expected = 1;
    Assert.AreEqual(expected, actual);
    Results.Print($"abs(1) == {actual}");
  }

  [Test] 
  public void IsPrimeTest1() {
    int x = 25;
    bool actual = MathFunctions.IsPrime(x);
    bool expected = false;
    Assert.AreEqual(expected, actual);
    Results.Print($"isPrime(25) == false");
  }

  [Test] 
  public void IsPrimeTest2() {
    int x = 19;
    bool actual = MathFunctions.IsPrime(x);
    bool expected = true;
    Assert.AreEqual(expected, actual);
    Results.Print($"isPrime(19) == true");
  }

  [Test]
  public void SqrtTest() {
    double x = 4.0;
    double actual = MathFunctions.Sqrt(x);
    double expected = 2.0;
    Assert.AreEqual(expected, actual);
    Results.Print($"Sqrt(4.0) == {actual}");
  }

  [Test]
  public void HTest() {
    int N = 2;
    double actual = MathFunctions.H(N); 
    double expected = 1.5;
    Assert.AreEqual(expected, actual);
    Results.Print($"H(2) = {actual}");
  }

  [Test]
  public void HypTest() {
    double a = 3.0;
    double b = 4.0;
    double actual = MathFunctions.Hypotenuse(a, b);
    double expected = 5.0;
    Assert.AreEqual(expected, actual);
    Results.Print($"Hypotenus(3, 4) == {actual}"); 
  }

  [Test]
  public void RecRankTest1() {
    int[] arr = {2, 4, 7, 9, 10, 15};
    int key = 7;
    int expected = 2;
    int actual = BinarySearch.Rank(key, arr);
    Assert.AreEqual(expected, actual);
    Results.Print($"RecRank({key}, {Results.ArrStr<int>(arr)}) == {actual}");
  }

  [Test]
  public void RecRankTest2() {
    int[] arr = {2, 4, 7, 9, 10, 15};
    int key = 6;
    int expected = -1;
    int actual = BinarySearch.Rank(key, arr);
    Assert.AreEqual(expected, actual);
    Results.Print($"RecRank({key}, {Results.ArrStr<int>(arr)}) == {actual}");
  }

  [Test]
  public void RecRankTest3() {
    int[] arr = {15, 10, 9, 7, 4, 2};
    int key = 4;
    int expected = -1;
    int actual = BinarySearch.Rank(key, arr);
    Assert.AreEqual(expected, actual);
    Results.Print($"RecRank({key}, {Results.ArrStr<int>(arr)}) == {actual}");
  }

  [Test]
  public void RecRankTest4() {
    int[] arr = {2, 5, 6, 8, 9, 10};
    int key = 9;
    int expected = 4;
    int actual = BinarySearch.Rank(key, arr);
    Assert.AreEqual(expected, actual);
    Results.Print($"RecRank({key}, {Results.ArrStr<int>(arr)}) == {actual}");
  }

  [Test]
  public void UniformTest() {
    int N = 10;
    string msg = "random doubles in [0, 10): ";
    for (int i = 0; i < N; ++i) {
      msg += $"{Rand.Uniform(0, 10)} ";
    }
    msg += $"\n";
    Results.Print(msg);
    Assert.Pass();
  }
  [Test]
  public void DiscreteTest() {
    
    // produce an array of 10 doubles that sums to 1
    // (may be a better way, see Shuffle())
    double factor = -1;
    double[] a = new double[10];
    while(factor < 0) {
      factor = 1;
      for (int i = 0; i < 9; ++i) {
        a[i] = Rand.Uniform(0, 1);
        factor -= a[i];
      }
      a[9] = factor;
    }
   
    Results.Print($"random ints from discrete dist: " + 
      $"{Rand.Discrete(a)} from {Results.ArrStr<double>(a)}");
    Assert.Pass();
  }

  [Test]
  public void ShuffleTest() {
    double[] a = {2, 5, 6, 8, 9, 10};  
    double[] actual = new double[6];
    a.CopyTo(actual, 0);
    Rand.Shuffle(actual);
    Results.Print($"{Results.ArrStr<double>(a)} " + 
      $"randomly shuffles to {Results.ArrStr<double>(actual)}");
    Assert.Pass();
  }

  // STOPPED AT PG. 46 (not printed number)
}