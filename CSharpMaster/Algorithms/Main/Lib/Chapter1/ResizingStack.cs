namespace Lib.Chapter1;

public class ResizingStack<Item> : IStack<Item> {
  
  private Item?[] items;
  private int N;

  public ResizingStack() {
    items = new Item[1];
    N = 0;
  }

  public bool IsEmpty() => N == 0;
  
  public int Size() => N;

  private void resize(int max) {
    // create a new array for items
    Item?[] temp = new Item[max];
    for (int i = 0; i < N; ++i) {
      temp[i] = items[i];
    }
    items = temp;
  }

  public void Push(Item item) {
    // when N points past the array, resize it 2X larger
    // sizes are powers of 2: 1, 2, 4, 8, 16, ...
    if (N == items.Length) {
      resize(2 * items.Length);
    }
    items[N++] = item;
  }

  public Item Pop() {
    Item? pop = items[--N];

    // this will never throw, only used to prevent warning on returning a possible null
    if (pop == null) {
      throw new Exception("Pop returned a null ref");
    }
    
    // remove the possible ref for the garbage collector to destroy (prevent loitering) 
    items[N] = default(Item);  

    // shrink items by half when the array is 1/4 full
    // at N = 0 after popping that value, the size of items stays at 2
    if (N > 0 && N == items.Length/4) {
      resize(items.Length/2);
    }

    return pop;
  }

  public IEnumerable<Item?> Enum() {
    // top of the stack is on the left
    // in the array it is on the right side
    for (int i = N - 1; i > -1; --i) {
      yield return items[i];
    }
  }
}



/*
PUSH:
_      (size of 1)
^ N=0
0 
  ^ N=1
0 _     (resize to a size of 2)
  ^ N=1
0 1
    ^
========
POP:
0 1 2 3 4  _ _ _ _ _ _ _ _ _ _ _  (state at beginning of Pop())
           ^ N
0 1 2 3 /0 _ _ _ _ _ _ _ _ _ _ _  (size of 16) 
         ^ N=4
0 1 2 3 /0 _ _ _ (size of 8) 
        ^ N=4       
=========
POP: 
0 1 _ _   (size of 4)
    ^ N=2
0 /0 _ _   (size of 4)  
   ^ N=1
=========
POP:
0 /0   (size of 2)   
   ^ N=1
/0 /0  (no shrink)
^ N=0
*/