public class bst {
  bst() {
    root=null;
  }

  class Node {
    Node left;
    Node right;
    int value;

    public Node(int value) {
      this.value=value;
    }
  }
  Node root;

  void insert(int value) {
    root=insert(this.root, value);
  }

  private Node insert(Node root, int value) {
    if (root==null) {
      root=new Node(value);
    }
    else if (value < root.value) {
      root.left=insert(root.left, value);
    }
    else {
      root.right=insert(root.right, value);
    }
    return root;
  }

  public int node_count() {
    return node_count(root, 0);
  }

  private int node_count(Node root, int count) {
    if (root==null) {
      return count;
    }
    else {
      return node_count(root.left, count)+node_count(root.right, count)+1;
    }
  }
  
  public static void main(String[] args) {
    bst bst=new bst();
    bst.insert(15);
    bst.insert(20);
    bst.insert(10);
    bst.insert(50);

    System.out.println("Root value " + bst.root.value);
    System.out.println("Right value " + (bst.root.right.value));
    System.out.println("Let value " + (bst.root.left.value));
    System.out.println("Right's right " + (bst.root.right.right.value));
    System.out.println("Node count " + bst.node_count());
  }
}
