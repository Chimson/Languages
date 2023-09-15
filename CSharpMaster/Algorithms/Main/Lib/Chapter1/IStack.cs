namespace Lib.Chapter1;

public interface IStack<Item> {
  
  public bool IsEmpty();
  public int Size();
  public void Push(Item item);
  public Item Pop();
  public IEnumerable<Item?> Enum();
}