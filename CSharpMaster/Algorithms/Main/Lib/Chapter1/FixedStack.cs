namespace Lib.Chapter1;

public class FixedStack<Item> : IStack<Item> {
  // stacks pop in reverse order

  private Item[] items;
  private int N;

  public FixedStack(int size) {
    items = new Item[size];
  }

  public bool IsEmpty() => N == 0;

  public int Size() => N;

  public void Push(Item item) {
    items[N++] = item;
  }

  public Item Pop() {
    return items[--N];
  }

  public IEnumerable<Item> Enum() {
    for (int i = N - 1; i > -1; --i) {
      yield return items[i];
    }
  }

}