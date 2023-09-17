namespace Lib.Chapter1;

using System.Collections;  // for IEnumerator

/*
  Queues can preserve the order of the items
*/

public class Queue<Item>  {

  public Node<Item> First {get; private set;}
  public Node<Item> Last {get; private set;}
  public int Size {get; private set;}

  public Queue(Item item) {
    First = new Node<Item>(item, null);
    Last = First;
    Size = 1;
  }

  public bool IsEmpty() {
    return Size == 0;
  }

  public void Enqueue(Item item) {
    // add to the null end
    
    if (IsEmpty()) {
      First = new Node<Item>(item, null);
      Last = First;
      Size = 1;
    }
    else {
      Node<Item> old_last = Last;
      Last = new Node<Item>(item, null);
      old_last.Next = Last;
      ++Size;
    }

  }

  public Item Dequeue() {
    // remove from the beginning of the list
    if (IsEmpty()) {
      throw new Exception("Cannot Dequeue from an empty queue");
    }
    else if (Size == 1) {
      Size = 0;
      return First.Item;
    }
    else {
      Item item = First.Item;
      if (First.Next != null) {   // this should always be true
        First = First.Next;
      }
      --Size;
      return item;
    }
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
    return new QueueIterator<Item>(this);
  }
}


internal class QueueIterator<Item> : IEnumerator<Node<Item>> {

  private Queue<Item> Queue;
  private Node<Item> _curnode;
  private bool is_first = true;                

  public QueueIterator(Queue<Item> queue) {
    Queue = queue; 
    _curnode = queue.First;
  }

  // I didn't want to add a fake Node at the beginning
  public bool MoveNext() {
    if (Queue.Size == 0) {return false;}
    if (_curnode.Next != null && !is_first) {
      _curnode = _curnode.Next;
      is_first = false;
      return true;
    }
    else if (_curnode.Next != null && is_first) {
      is_first = false;
      return true;
    }
    else if (_curnode.Next == null && is_first) {
      is_first = false;
      return true;
    }
    else {
      // _curnode.Next == null && !is_first (first has already been read)
      return false;
    }
  }

  public void Reset() {
    _curnode = Queue.First;
    is_first = true;
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