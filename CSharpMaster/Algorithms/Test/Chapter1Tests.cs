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
    Results.Print($"GCD(1,0) == {expected}");
  }

  [Test]
  public void GCDTest1() {
    int actual = MathFunctions.GCD(24, 18);
    int expected = 6;
    Assert.True(expected == actual, $"{expected} != {actual}");
    Results.Print($"GCD(24,18) == {expected}");
  }

  [Test]
  public void GCDTest2() {
    int actual = MathFunctions.GCD(2310, 1001);
    int expected = 77;
    Assert.True(expected == actual, $"{expected} != {actual}");
    Results.Print($"GCD(2310,1001) == {expected}");
  }

  [Test]
  public void RankTest1() {
    int[] arr = {2, 4, 7, 9, 10, 15};
    int key = 7;
    int expected = 2;
    int actual = BinarySearch.Rank(key, arr);
    Assert.AreEqual(expected, actual);
    Results.Print($"rank({key}, [2,4,7,9,10,15]) == {expected}");
  }

  [Test]
  public void RankTest2() {
    int[] arr = {2, 4, 7, 9, 10, 15};
    int key = 6;
    int expected = -1;
    int actual = BinarySearch.Rank(key, arr);
    Assert.AreEqual(expected, actual);
    Results.Print($"rank({key}, [2,4,7,9,10,15]) == {expected}");
  }

  // ADD MORE rank() TESTS

}