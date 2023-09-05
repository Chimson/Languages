using System.Collections;

public class Bag<Item>  {

  public Node<Item> First{get; private set;}
  private IEnumerator<Node<Item>> Iter;

  public void Add(Item item) {
    Node<Item> old_first = this.First;
    this.First = new Node<Item>(item, old_first);
  }

  public Bag(Item pre, Item first) {
    this.First = new Node<Item>(first, null);
    this.Iter = new BagIterator<Item>(this, new Node<Item>(pre, First));
  }

  public override string ToString() {
    string msg = "";
    Node<Item> index = First;
    foreach (Node<Item> node in this) {
      msg += $"{node.ToString()}-> ";
    }
    msg += $"null";
    return msg;
  }

  public IEnumerator<Node<Item>> GetEnumerator() {
    return Iter;
  }


}

internal class BagIterator<Item> : IEnumerator<Node<Item>> {

  private Bag<Item> Bag;
  private Node<Item> CurNode;
  private Node<Item> Empty;

  public BagIterator(Bag<Item> bag, Node<Item> empty) {
    Bag = bag; 
    Empty = empty;
    Empty.Next = Bag.First;
    CurNode = Empty;
  }

  public bool MoveNext() {
    if (CurNode.Next == null) {
      return false;
    }
    else {
      CurNode = CurNode.Next;
      return true;
    }
  }

  public void Reset() {
    CurNode = Empty;
  }

  void IDisposable.Dispose() {}

  public Node<Item> Current {
    get {
      return CurNode;
    }
  }

  object IEnumerator.Current {
    get {
      return Current;
    }
  }

  public IEnumerator<Node<Item>> GetEnumerator() {
    return this;
  }


} 