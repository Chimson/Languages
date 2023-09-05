namespace Lib.Chapter1;

public class Node<T> {
  public T Item {get; private set;}
  public Node<T>? Next {get; set;}

  public Node(T item, Node<T>? next) {
    this.Item = item;
    this.Next = next;
  }

  public override string ToString() {
    return $"Item:{Item} ";
  }

}


