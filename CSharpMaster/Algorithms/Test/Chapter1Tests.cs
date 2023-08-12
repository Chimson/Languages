namespace Test;

using Lib.Chapter1;


public class Chapter1Tests {
    
  [SetUp]
  public void Setup() {
  }

  // [Test]
  // public void SetupCheck() {
  //   Check.PrintHi();
  //   Assert.Pass();
  // }

  [Test]
  public void GCDTest() {
    int result = MathFunctions.GCD(24, 18);
    Assert.True(result == 6);
  }
}