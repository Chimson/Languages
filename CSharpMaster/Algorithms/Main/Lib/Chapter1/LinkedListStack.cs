namespace Lib.Chapter1;

public class LinkedListStack<Item> : IStack<Item> {
  
  public Node<Item> First {get; private set;}
  private int N;

  public LinkedListStack(Item item) {
    First = new Node<Item>(item, null);
    N = 1;
  }

  public int Size() => N;

  public bool IsEmpty() => N == 0;

  public void Push(Item item) {
    // add to left-most end (non-null end), which is the top    
    if (N == 0) {
      First = new Node<Item>(item, null);
      N = 1;
    }
    else {  
      Node<Item> oldfirst = First;
      First = new Node<Item>(item, oldfirst);
      ++N;
    }
  }

  public Item Pop() {
    // remove from the top
    if (N == 0) {
      throw new Exception("Cannot Pop from an Empty Stack");
    } 
    else if (N == 1) {
      --N;
      return First.Item;
    }
    else {
      Item pop = First.Item; 
      if (First.Next != null) {  // should always be tre, as long as N is not corrupted
        First = First.Next;
      }
      --N;
      return pop;
    }
  }

  public IEnumerable<Item> Enum() {
    // top the stack is accessed first
    if (N == 0) {
      yield break;
    }
    else {
      for (Node<Item>? index = First; index != null; index = index.Next) {
        yield return index.Item;
      }
    }
  }

  public override string ToString() {
    string msg = "";
    foreach (Item item in this.Enum()) {
      msg += $"{item} -> ";
    }
    msg += "null";
    return msg;
  }

}

/*
POP:
1 -> 0 -> null
      ^First
======
POP:
1 -> null
      ^First
======
*/