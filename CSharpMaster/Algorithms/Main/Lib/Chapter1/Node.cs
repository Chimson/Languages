public class Node<T> {
  private T Item {get;}
  public Node<T>? Next {get; set;}

  public Node(T item, Node<T>? next) {
    this.Item = item;
    this.Next = next;
  }

  public override string ToString() {
    return $"Item:{Item} ";
  }

}