namespace Lib.Chapter1;

using System.Collections;  // for IEnumerator

/*
  Bags are iterable unordered collections
*/

public class Bag<Item>  {

  public Node<Item> First{get; private set;}
  public int Size {get; private set;}

  public void Add(Item item) {
    // add it to the top
    Node<Item> old_first = First;
    First = new Node<Item>(item, old_first);
    ++Size;
  }

  public Bag(Node<Item> first) {
    First = first;
    Size = 1;
  }

  public Bag(Item first) {
    First = new Node<Item>(first, null);
    Size = 1;
  }

  public override string ToString() {
    string msg = $"({Size} Items) ";
    foreach (Node<Item> node in this) {
      msg += $"{node.ToString()}-> ";
    }
    msg += $"null";
    return msg;
  }

  public IEnumerator<Node<Item>> GetEnumerator() {
    return new BagIterator<Item>(this);
  }


}

internal class BagIterator<Item> : IEnumerator<Node<Item>> {

  private Bag<Item> Bag;
  private Node<Item> _curnode;
  private int raw_index = 0;

  public BagIterator(Bag<Item> bag) {
    Bag = bag; 
    _curnode = Bag.First;
  }

  public bool MoveNext() {
    if (_curnode.Next != null) {
      if (raw_index != 0) {
        _curnode = _curnode.Next;
      }
      ++raw_index;
      return true;
    }
    else {
      return false;
    }
  }

  public void Reset() {
    _curnode = Bag.First;
    raw_index = 0;
  }

  void IDisposable.Dispose() {}

  public Node<Item> Current {
    get {
      return _curnode;
    }
  }

  object IEnumerator.Current {
    get {
      return Current;
    }
  }

} 