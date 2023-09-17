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
    Results.Print($"a:\n{Results.TwoDArrStr<double>(a)}\n");
    Results.Print($"b:\n{Results.TwoDArrStr<double>(b)}\n");
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

  [Test]
  public void BagTest1() {
    Bag<int> bag = new Bag<int>(0);
    Results.Print($"BagTest1: {bag.ToString()}");
    Assert.Pass();
  }

  [Test]
  public void BagTest2() {
    Bag<int> bag = new Bag<int>(0);
    bag.Add(1);
    Results.Print($"BagTest2: {bag.ToString()}");
    Assert.Pass();
  }

    public void BagTest3() {
    Bag<int> bag = new Bag<int>(0);
    bag.Add(1);
    bag.Add(2);
    Results.Print($"BagTest3: {bag.ToString()}");
    Assert.Pass();
  }

  [Test]
  public void BagTestNoAdd() {
    Node<int> third = new Node<int>(2, null);
    Node<int> second = new Node<int>(1, third);
    Node<int> first = new Node<int>(0, second);
    Bag<int> bag = new Bag<int>(first);
    Results.Print($"BagTestNoAdd passes");
    Assert.Pass();
  }

  [Test]
  public void BagTest5() {
    Bag<int> bag = new Bag<int>(0);
    bag.Add(1);
    bag.Add(2);
    bag.Add(3);
    bag.Add(4);
    Results.Print($"BagTest5: {bag.ToString()}");
    Assert.Pass();
  }

  [Test]
  public void BagIter1() {
    Bag<int> bag = new Bag<int>(0);
    bag.Add(1);
    bag.Add(2);
    Results.Print($"BagIter1: {bag.ToString()}\n");
    Results.Print($"BagIter1: {bag.ToString()}");
    Assert.Pass();
  }

  [Test]
  public void BagIter2() {
    Bag<int> bag = new Bag<int>(0);
    bag.Add(1);
    bag.Add(2);
    Results.Print($"BagIter2: {bag.ToString()}\n");
    bag.Add(3);
    bag.Add(4);
    Results.Print($"BagIter2: {bag.ToString()}");
    Assert.Pass();
  }

  [Test]
  public void QueueTest1() {
    // add 0
    Queue<int> queue = new Queue<int>(0);
    Assert.AreEqual(queue.First.Item, 0);
    Assert.AreEqual(1, queue.Size);
    int num = 0;
    foreach (Node<int> node in queue) {
      Assert.AreEqual(node.Item, num++);
    }
    Assert.IsFalse(queue.IsEmpty());
    Results.Print($"QueueTest1: {queue.ToString()}");
  }

  [Test]
  public void QueueTest2() {
    // add 0, enq 1
    Queue<int> queue = new Queue<int>(0);
    queue.Enqueue(1);
    int num = 0;
    foreach (Node<int> node in queue) {
      Assert.AreEqual(node.Item, num++);
    }
    Assert.AreEqual(2, queue.Size);
    Assert.IsFalse(queue.IsEmpty());
    Results.Print($"QueueTest2: {queue.ToString()}");
  }

  [Test]
  public void QueueEnqueueTest() {
    // add 0, enq 1 2 3 4
    Queue<int> queue = new Queue<int>(0);
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    int num = 0;
    foreach (Node<int> node in queue) {
      Assert.AreEqual(node.Item, num++);
    }
    Assert.AreEqual(5, queue.Size);
    Assert.IsFalse(queue.IsEmpty());
    Results.Print($"QueueEnqueueTest: {queue.ToString()}");
  }
  
  [Test]
  public void QueueDequeueAllTest() {
    // add 0, enq 1 2 3 4, deq 5 times  
    Queue<int> queue = new Queue<int>(0);
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Dequeue();
    queue.Dequeue();
    queue.Dequeue();
    queue.Dequeue();
    queue.Dequeue();
    Assert.AreEqual(0, queue.Size);
    int num = 0;
    foreach (Node<int> node in queue) {
      Assert.AreEqual(node.Item, num++);
    }
    Assert.True(queue.IsEmpty());
    Results.Print($"QueueDequeueAllTest: {queue.ToString()}");
  }

  [Test]
  public void QueueDequeueTest01() {
    // add 0, deq 
    Queue<int> queue = new Queue<int>(0);
    int actual = queue.Dequeue();
    Assert.AreEqual(0, actual);
    int num = 0;
    foreach (Node<int> node in queue) {
      Assert.AreEqual(node.Item, num++);
    }
    Assert.True(queue.IsEmpty());
    Assert.AreEqual(0, queue.Size);
    Results.Print($"QueueDequeueTest01: {queue.ToString()}");
  }
  
  [Test]
  public void QueueDequeueTest1() {
    // add 0, deq, enq 1
    Queue<int> queue = new Queue<int>(0);
    int actual = queue.Dequeue();
    queue.Enqueue(1);
    Assert.AreEqual(0, actual);
    Assert.AreEqual(1, queue.Size);
    int num = 1;
    foreach (Node<int> node in queue) {
      Assert.AreEqual(node.Item, num++);
    }
    Assert.IsFalse(queue.IsEmpty());
    Results.Print($"QueueDequeueTest1: {queue.ToString()}");
  }

  [Test]
  public void QueueDequeueTest02() {
    // add 0, deq, enq 1, deq
    Queue<int> queue = new Queue<int>(0);
    Assert.AreEqual(0, queue.Dequeue());
    queue.Enqueue(1);
    Assert.AreEqual(1, queue.Dequeue());
    int num = 0;
    foreach (Node<int> node in queue) {
      Assert.AreEqual(node.Item, num++);
    }
    Assert.AreEqual(0, queue.Size);
    Assert.IsTrue(queue.IsEmpty());
    Results.Print($"QueueDequeueTest02: {queue.ToString()}");
  }  

  [Test]
  public void QueueDequeueTest2() {
    // add 0, deq, enq 1, enq 2
    Queue<int> queue = new Queue<int>(0);
    int val1 = queue.Dequeue();
    queue.Enqueue(1);
    queue.Enqueue(2);
    Assert.AreEqual(0, val1);
    int num = 1;
    foreach (Node<int> node in queue) {
      Assert.AreEqual(node.Item, num++);
    }
    Assert.AreEqual(2, queue.Size);
    Assert.IsFalse(queue.IsEmpty());
    Results.Print($"QueueDequeueTest2: {queue.ToString()}");
  }  

  [Test]
  public void QueueDequeueTest3() {
    // add 0, deq, enq 1, enq 2, deq, deq
    Queue<int> queue = new Queue<int>(0);
    Assert.AreEqual(0, queue.Dequeue());
    queue.Enqueue(1);
    queue.Enqueue(2);
    Assert.AreEqual(1, queue.Dequeue());
    Assert.AreEqual(2, queue.Dequeue());
    int num = 0;
    foreach (Node<int> node in queue) {
      Assert.AreEqual(node.Item, num++);
    }
    Assert.AreEqual(0, queue.Size);
    Assert.True(queue.IsEmpty());
    Results.Print($"QueueDequeueTest3: {queue.ToString()}");
  }

  [Test]
  public void QueueDequeueEmptyThrows() {
    Queue<int> queue = new Queue<int>(0);
    queue.Dequeue();
    Assert.Throws<Exception>(() => queue.Dequeue());
    Results.Print($"Dequeue on Empty Throws");
  }

  [Test]
  public void FixedStackTest0() {
    IStack<string> names = new FixedStack<string>(5);
    names.Push("Ben");
    names.Push("Mags");
    names.Push("Finn");
    names.Push("Willie");
    names.Push("Cal");
    string msg = "FixedStackTest0 Iterator and Push check: ";
    foreach (string? name in names.Enum()) {
      msg += $"{name} ";
    }
    Results.Print(msg);
    Assert.Pass();
  }

  [Test]
  public void FixedStackTest1() {
    IStack<string> names = new FixedStack<string>(4);
    names.Push("Ben");
    names.Push("Mags");
    names.Push("Finn");
    names.Push("Willie");
    Assert.Throws<IndexOutOfRangeException>(() => names.Push("Cal"));
    Results.Print("FixedStackTest1: throws exception on a push after a maxed out stack");
  }

  [Test]
  public void FixedStackTest2() {
    IStack<string> names = new FixedStack<string>(4);
    Assert.True(names.IsEmpty());
    Results.Print("FixedStackTest2: IsEmpty() passes on no pushes");
  }
  
  [Test]
  public void FixedStackTest3() {
    IStack<string> names = new FixedStack<string>(4);
    names.Push("Ben");
    Assert.AreEqual(1, names.Size());
    Results.Print("FixedStackTest3: Size of 1 passes");
  }

  [Test]
  public void FixedStackTest4() {
    IStack<string> names = new FixedStack<string>(4);
    names.Push("Ben");
    names.Push("Mags");
    Assert.AreEqual(2, names.Size());
    Results.Print("FixedStackTest4: Size of 2 passes");
  }

  [Test]
  public void FixedStackTest5() {
    IStack<string> names = new FixedStack<string>(4);
    Assert.Throws<IndexOutOfRangeException>(() => names.Pop());
    Results.Print("FixedStackTest5: throws exception on a pop on empty stack");
  }

  [Test]
  public void FixedStackTest6() {
    IStack<string> names = new FixedStack<string>(4);
    names.Push("Ben");
    Assert.AreEqual("Ben", names.Pop());
    Assert.AreEqual(0, names.Size());
    Assert.True(names.IsEmpty());
    Results.Print("FixedStackTest6: push, pop passes");
  }

  [Test]
  public void FixedStackTest7() {
    IStack<string> names = new FixedStack<string>(4);
    names.Push("Ben");
    names.Push("Mags");
    Assert.AreEqual("Mags", names.Pop());
    Assert.AreEqual(1, names.Size());
    Assert.False(names.IsEmpty());
    Results.Print("FixedStackTest7: push, push, pop passes");
  }

  [Test]
  public void FixedStackTest8() {
    IStack<string> names = new FixedStack<string>(4);
    names.Push("Ben");
    names.Push("Mags");
    Assert.AreEqual("Mags", names.Pop());
    Assert.AreEqual("Ben", names.Pop());
    Assert.AreEqual(0, names.Size());
    Assert.True(names.IsEmpty());
    Results.Print("FixedStackTest8: push, push, pop, pop passes");
  }

  [Test]
  public void FixedStackTest9() {
    IStack<string> names = new FixedStack<string>(4);
    names.Push("Ben");
    names.Pop();
    names.Push("Mags");
    Assert.AreEqual(1, names.Size());
    Assert.False(names.IsEmpty());
    Results.Print("FixedStackTest9: push, pop, push passes");
  }

  [Test]
  public void FixedStackTest10() {
    IStack<string> names = new FixedStack<string>(4);
    names.Push("Ben");
    names.Pop();
    names.Push("Mags");
    names.Pop();
    Assert.AreEqual(0, names.Size());
    Assert.True(names.IsEmpty());
    Results.Print("FixedStackTest10: push, pop, push, pop passes");
  }

  [Test]
  public void FixedStackTest11() {
    IStack<string> names = new FixedStack<string>(4);
    names.Push("Ben");
    names.Push("Mags");
    names.Push("Finn");
    names.Push("Willie");
    Assert.AreEqual("Willie", names.Pop());
    Assert.AreEqual("Finn", names.Pop());
    Assert.AreEqual("Mags", names.Pop());
    Assert.AreEqual("Ben", names.Pop());
    Assert.AreEqual(0, names.Size());
    Assert.True(names.IsEmpty());
    Results.Print("FixedStackTest11: 4 pops passes");
  }

  [Test]
  public void EvaluateTest0() {
    string expr = "( 3 + 4.5 )";
    string actual = MathFunctions.Evaluate(expr);
    Assert.AreEqual("7.5", actual);
    Results.Print($"EvaluateTest0: {expr} = {actual}");
  }

  [Test]
  public void EvaluateTest1() {
    string expr = "( ( 3.0012 + 4.5 ) * 22.1 )";
    string actual = MathFunctions.Evaluate(expr);
    Assert.AreEqual("165.77652", actual);
    Results.Print($"EvaluateTest1: {expr} = {actual}");
  }

  [Test]
  public void EvaluateTest2() {
    // no wrapping ()
    string expr = "( 3.0012 + 4.5 ) * 22.1";
    Exception? ex = Assert.Throws<Exception>(() => MathFunctions.Evaluate(expr));
    Results.Print($"EvaluateTest2: {expr} throws \"{ex?.Message}\"");
  }

  [Test]
  public void EvaluateTest3() {
    // no space before last )
    string expr = "( 3.0012 + 4.5 ) * 22.1)";
    Exception? ex = Assert.Throws<Exception>(() => MathFunctions.Evaluate(expr));
    Results.Print($"EvaluateTest3: {expr} throws \"{ex?.Message}\"");
  }  

  [Test]
  public void EvaluateTest4() {
    // pop past the stack
    string expr = "( 3.0012 + 4.5 ) * )";
    IndexOutOfRangeException? ex = Assert.Throws<IndexOutOfRangeException>(() => MathFunctions.Evaluate(expr));
    Results.Print($"EvaluateTest4: {expr} throws \"{ex?.Message}\"");
  }  

  [Test]
  public void EvaluateTest5() {
    // extra )
    string expr = "( 3.0012 + 4.5 ) * 22.1))";
    Exception? ex = Assert.Throws<Exception>(() => MathFunctions.Evaluate(expr));
    Results.Print($"EvaluateTest5: {expr} throws \"{ex?.Message}\"");
  }  

  [Test]
  public void EvaluateTest6() {
    string expr = "( ( 3.0012 + 4.5 ) * ( 22.1 / 3 ) )";
    string actual = MathFunctions.Evaluate(expr);
    Assert.AreEqual("55.25884", actual);
    Results.Print($"EvaluateTest6: {expr} = {actual}");
  }

  [Test]
  public void EvaluateTest7() {
    string expr = "( ( 3.0012 + 4.5 ) * ( -22.1 / 3 ) )";
    string actual = MathFunctions.Evaluate(expr);
    Assert.AreEqual("-55.25884", actual);
    Results.Print($"EvaluateTest7: {expr} = {actual}");
  }

  [Test]
  public void EvaluateTest8() {
    string expr = "( ( ( 3.0012 + 4.5 ) * ( -22.1 / 3 ) ) - 8.46 )";
    string actual = MathFunctions.Evaluate(expr);
    Assert.AreEqual("-63.71884", actual);
    Results.Print($"EvaluateTest8: {expr} = {actual}");
  }  

  [Test]
  public void ResizingStack0() {
    IStack<string> names = new FixedStack<string>(5);
    names.Push("Ben");
    names.Push("Mags");
    names.Push("Finn");
    names.Push("Willie");
    names.Push("Cal");
    string msg = "ResizingStack0 Iterator and Push check: ";
    foreach (string? name in names.Enum()) {
      msg += $"{name} ";
    }
    Results.Print(msg);
    Assert.Pass();
  }

  [Test]
  public void ResizingStack2() {
    IStack<string> names = new ResizingStack<string>();
    Assert.True(names.IsEmpty());
    Results.Print("ResizingStack2: IsEmpty() passes on no pushes");
  }
  
  [Test]
  public void ResizingStack3() {
    IStack<string> names = new ResizingStack<string>();
    names.Push("Ben");
    Assert.AreEqual(1, names.Size());
    Results.Print("ResizingStack3: Size of 1 passes");
  }

  [Test]
  public void ResizingStack4() {
    IStack<string> names = new ResizingStack<string>();
    names.Push("Ben");
    names.Push("Mags");
    Assert.AreEqual(2, names.Size());
    Results.Print("ResizingStack4: Size of 2 passes");
  }

  [Test]
  public void ResizingStack5() {
    IStack<string> names = new ResizingStack<string>();
    Assert.Throws<IndexOutOfRangeException>(() => names.Pop());
    Results.Print("ResizingStack5: throws exception on a pop on empty stack");
  }

  [Test]
  public void ResizingStack6() {
    IStack<string> names = new ResizingStack<string>();
    names.Push("Ben");
    Assert.AreEqual("Ben", names.Pop());
    Assert.AreEqual(0, names.Size());
    Assert.True(names.IsEmpty());
    Results.Print("ResizingStack6: push, pop passes");
  }

  [Test]
  public void ResizingStack7() {
    IStack<string> names = new ResizingStack<string>();
    names.Push("Ben");
    names.Push("Mags");
    Assert.AreEqual("Mags", names.Pop());
    Assert.AreEqual(1, names.Size());
    Assert.False(names.IsEmpty());
    Results.Print("ResizingStack7: push, push, pop passes");
  }

  [Test]
  public void ResizingStack8() {
    IStack<string> names = new ResizingStack<string>();
    names.Push("Ben");
    names.Push("Mags");
    Assert.AreEqual("Mags", names.Pop());
    Assert.AreEqual("Ben", names.Pop());
    Assert.AreEqual(0, names.Size());
    Assert.True(names.IsEmpty());
    Results.Print("ResizingStack8: push, push, pop, pop passes");
  }

  [Test]
  public void ResizingStack9() {
    IStack<string> names = new ResizingStack<string>();
    names.Push("Ben");
    names.Pop();
    names.Push("Mags");
    Assert.AreEqual(1, names.Size());
    Assert.False(names.IsEmpty());
    Results.Print("ResizingStack9: push, pop, push passes");
  }

  [Test]
  public void ResizingStack10() {
    IStack<string> names = new ResizingStack<string>();
    names.Push("Ben");
    names.Pop();
    names.Push("Mags");
    names.Pop();
    Assert.AreEqual(0, names.Size());
    Assert.True(names.IsEmpty());
    Results.Print("ResizingStack10: push, pop, push, pop passes");
  }

  [Test]
  public void ResizingStack11() {
    IStack<string> names = new ResizingStack<string>();
    names.Push("Ben");
    names.Push("Mags");
    names.Push("Finn");
    names.Push("Willie");
    Assert.AreEqual("Willie", names.Pop());
    Assert.AreEqual("Finn", names.Pop());
    Assert.AreEqual("Mags", names.Pop());
    Assert.AreEqual("Ben", names.Pop());
    Assert.AreEqual(0, names.Size());
    Assert.True(names.IsEmpty());
    Results.Print("ResizingStack11: 4 pops passes");
  }

  [Test]
  public void LinkedListStack0() {
    IStack<string> names = new LinkedListStack<string>("Ben");
    names.Push("Mags");
    names.Push("Finn");
    names.Push("Willie");
    names.Push("Cal");
    string msg = $"LinkedListStack0 Iterator and Push check: {names.ToString()}";
    Results.Print(msg);
    Assert.Pass();
  }

  [Test]
  public void LinkedListStack2() {
    // empty stack check
    IStack<string> names = new LinkedListStack<string>("Ben");
    Assert.AreEqual("Ben", names.Pop());
    Assert.True(names.IsEmpty());
    Assert.AreEqual(names.Size(), 0);
    Results.Print($"LinkedListStack2: {names.ToString()}");
  }

  [Test]
  public void LinkedListStack3() {
    IStack<string> names = new LinkedListStack<string>("Ben");
    Assert.False(names.IsEmpty());
    Assert.AreEqual(1, names.Size());
    Results.Print($"LinkedListStack3: {names.ToString()}");
  }

  [Test]
  public void LinkedListStack4() {
    IStack<string> names = new LinkedListStack<string>("Ben");
    names.Push("Mags");
    Assert.False(names.IsEmpty());
    Assert.AreEqual(2, names.Size());
    Results.Print($"LinkedListStack4: {names.ToString()}");
  }

[Test]
  public void LinkedListStack5() {
    IStack<string> names = new LinkedListStack<string>("Ben");
    names.Pop();
    Assert.Throws<Exception>(() => names.Pop());
    Results.Print("LinkedListStack5: throws exception on a pop on empty stack");
  }

  [Test]
  public void LinkedListStack7() {
    IStack<string> names = new LinkedListStack<string>("Ben");
    names.Push("Mags");
    Assert.AreEqual("Mags", names.Pop());
    Assert.AreEqual(1, names.Size());
    Assert.False(names.IsEmpty());
    Results.Print($"LinkedListStack7: {names.ToString()}");
  }

  [Test]
  public void LinkedListStack8() {
    IStack<string> names = new LinkedListStack<string>("Ben");
    names.Push("Mags");
    Assert.AreEqual("Mags", names.Pop());
    Assert.AreEqual("Ben", names.Pop());
    Assert.AreEqual(0, names.Size());
    Assert.True(names.IsEmpty());
    Results.Print($"LinkedListStack8: {names.ToString()}");
  }

  [Test]
  public void LinkedListStack9() {
    IStack<string> names = new LinkedListStack<string>("Ben");
    names.Pop();
    names.Push("Mags");
    Assert.AreEqual(1, names.Size());
    Assert.False(names.IsEmpty());
    Results.Print($"LinkedListStack9: {names.ToString()}");
  }

  [Test]
  public void LinkedListStack10() {
    IStack<string> names = new LinkedListStack<string>("Ben");
    names.Pop();
    names.Push("Mags");
    names.Pop();
    Assert.AreEqual(0, names.Size());
    Assert.True(names.IsEmpty());
    Results.Print($"LinkedListStack10: {names.ToString()}");
  }

  [Test]
  public void LinkedListStack11() {
    IStack<string> names = new LinkedListStack<string>("Ben");
    names.Push("Mags");
    names.Push("Finn");
    names.Push("Willie");
    Assert.AreEqual("Willie", names.Pop());
    Assert.AreEqual("Finn", names.Pop());
    Assert.AreEqual("Mags", names.Pop());
    Assert.AreEqual("Ben", names.Pop());
    Assert.AreEqual(0, names.Size());
    Assert.True(names.IsEmpty());
    Results.Print($"LinkedListStack11: {names.ToString()}");
  }

}

// STOPPED ON PAGE 185 (not printed)
// execute one test, without the specific warning printed
// > dotnet test -warnAsMessage:NUnit2005 Test --filter "Chapter1Tests.EvaluateTest6"