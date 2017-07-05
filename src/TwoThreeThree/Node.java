package TwoThreeThree;

/**
 * Created by snake on 2017/6/28.
 * 23树
 */
public class Node<T extends Comparable> {

    private Node<T> parent;
    private Node<T> leftChild;
    private Node<T> rightChild;
    private Node<T> middleChild;

    //when node is 2-node , leftVal is values , and rightVal is null.
    private T leftVal;
    private T rightVal;

    private boolean twoNode;

    protected Node(){

    }

    /*
    2节点
     */

    public static <T extends Comparable> Node<T> newTwoNode(T value)
    {
        Node <T> node = new Node<T>();
        node.leftVal = value;
        node.twoNode = true;
        return node;
    }

    /*
    3节点
     */

    public static <T extends Comparable> Node<T> newThreeNode(T leftVal , T rightVal)
    {
        Node<T> node = new Node<T>();
        if(leftVal.compareTo(rightVal)>0)
        {
            node.rightVal = leftVal;
            node.leftVal = rightVal;
        }else{
            node.leftVal = leftVal;
            node.rightVal = rightVal;
        }
        node.twoNode = false;
        return node;
    }

    /*
    空节点
     */

    public static HoleNode newHole()
    {
        return new HoleNode();
    }

    public void setLeftChild(Node<T> leftChild)
    {
        this.leftChild = leftChild;
        if(leftChild != null)
            leftChild.setParent(this);
    }

    /*
    将两个子节点置空
     */
    public void removeChildren(){
        this.leftChild = null;
        this.rightChild = null;
    }

    public void setRightChild(Node<T> rightChild)
    {
        this.rightChild = rightChild;
        if(rightChild!=null)
            rightChild.setParent(this);
    }

    public void setMiddleChild(Node<T> middleChild)
    {
        assert isThreeNode();
        this.middleChild = middleChild;
        if(middleChild != null)
        {
            middleChild.setParent(this);
        }
    }

    public final Node<T> parent(){
        return parent;
    }

    public final void setParent(Node<T> parent)
    {
        this.parent = parent;
    }

    /*
    判断节点是否两个子节点都存在
     */

    public boolean isTerminal(){
        return leftChild == null && rightChild == null;
    }

    public T val(){
        assert  isTwoNode();
        return leftVal;
    }

    public T leftVal()
    {
        assert isThreeNode();
        return leftVal;
    }

    public void setVal(T val)
    {
        assert isTwoNode();
        leftVal = val;
    }

    public T rightVal() {
        assert isThreeNode();
        return rightVal;
    }

    public void setLeftVal(T leftVal) {
        assert isThreeNode();
        this.leftVal = leftVal;
    }

    public void setRightVal(T rightVal) {
        assert isThreeNode();
        this.rightVal = rightVal;
    }

    public boolean isTwoNode() {
        // return rightVal == null;
        return twoNode;
    }

    public boolean isThreeNode() {
        return !isTwoNode();
    }

    public Node<T> leftChild() {
        return leftChild;
    }

    public Node<T> rightChild() {
        return rightChild;
    }

    public Node<T> middleChild() {
        assert isThreeNode();
        return middleChild;
    }

    /*
    新节点代替老节点
     */

    @SuppressWarnings("unchecked")
    public void replaceChild(Node currentChild, Node newChild) {
        if (currentChild == leftChild) {
            leftChild = newChild;
        } else if (currentChild == rightChild) {
            rightChild = newChild;
        } else {
            assert  middleChild == currentChild;
            middleChild = newChild;
        }
        newChild.setParent(this);//将替代节点的父节点设置为原来节点的父节点
        currentChild.setParent(null);//被替代的父节点设置为空
    }

}
