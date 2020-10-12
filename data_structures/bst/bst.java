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

  public void inorder(Node root) {
    if (root==null) {
      return;
    }
    
    inorder(root.left);
    System.out.println(root.value);
    inorder(root.right);
  }

  public void delete_tree() {
    root=null;
  }
  
  public boolean is_in_tree(int value) {
    return is_in_tree(root, value);
  }

  private boolean is_in_tree(Node root, int value) {
    if (root==null) {
      return false;
    }
    else if (root.value==value) {
      return true;
    }
    else if (value < root.value) {
      return is_in_tree(root.left, value);
    }
    else {
      return is_in_tree(root.right, value);
    }
  }

  public int max(int a, int b) {
    return a>b ? a : b;
  }

  public int height(Node root, int h) {
    if (root == null) {
      return 0;
    }
    return max(height(root.left, h), height(root.right, h))+1;
  }

  public int min_val(Node root) {
    if (root==null) {
      return -1;
    }
    if (root.left!=null) {
      return min_val(root.left);
    }
    else {
      return root.value;
    }
  }

  public int max_val(Node root) {
    if (root==null) {
      return -1;
    }

    if (root.right!=null) {
      return max_val(root.right);
    }
    else {
      return root.value;
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

    bst.inorder(bst.root);

    System.out.println("Is in tree 10 " + bst.is_in_tree(10));
    System.out.println("Is in tree 40 " + bst.is_in_tree(40));

    System.out.println("Height of tree " + bst.height(bst.root, 0));

    System.out.println("Minimum Value " + bst.min_val(bst.root));
    System.out.println("Maximum Value " + bst.max_val(bst.root));

    bst.delete_tree();

    bst.inorder(bst.root);
  }
}
