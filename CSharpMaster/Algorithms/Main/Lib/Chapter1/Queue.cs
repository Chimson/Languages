namespace Lib.Chapter1;

using System.Collections;  // for IEnumerator

/*
  Queues are iterable unordered collections
*/

public class Queue<Item>  {

  public Node<Item> First{get; private set;}
  public Node<Item> Last{get; private set;}
  public int Size {get; private set;}

  public Queue(Item item) {
    AddFirst(item);
  }

  private void AddFirst(Item item) {
    First = new Node<Item>(item, null);
    Last = First;
    Size = 1;
  }

  public bool IsEmpty() {
    if (Size == 0) {
      return true;
    }
    else {
      return false;
    }
  }

  public void Enqueue(Item item) {
    
    // add to the null end
    if (IsEmpty()) {
      AddFirst(item);
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
      First = First.Next;
      --Size;
      return item;
    }
  }

  // public override string ToString() {
  //   string msg = $"({Size} Items) ";
  //   foreach (Node<Item> node in this) {
  //     msg += $"{node.ToString()}-> ";
  //   }
  //   msg += $"null";
  //   return msg;
  // }

  // public IEnumerator<Node<Item>> GetEnumerator() {
  //   return new QueueIterator<Item>(this);
  // }
}


// internal class QueueIterator<Item> : IEnumerator<Node<Item>> {

  // private Queue<Item> Queue;
  // private Node<Item> _curnode;
  // private int raw_index = 0;

  // public QueueIterator(Queue<Item> queue) {
  //   Queue = queue; 
  //   _curnode = queue.First;
  // }

  // public bool MoveNext() {
  //   if (_curnode.Next != null) {
  //     if (raw_index != 0) {
  //       _curnode = _curnode.Next;
  //     }
  //     ++raw_index;
  //     return true;
  //   }
  //   else {
  //     return false;
  //   }
  // }

  // public void Reset() {
  //   _curnode = Queue.First;
  //   raw_index = 0;
  // }

  // void IDisposable.Dispose() {}

  // public Node<Item> Current {
  //   get {
  //     return _curnode;
  //   }
  // }

  // object IEnumerator.Current {
  //   get {
  //     return Current;
  //   }
  // }

// } 