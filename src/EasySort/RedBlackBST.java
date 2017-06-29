package EasySort;


/**
 * Created by snake on 2017/6/25.
 * 红黑树
 * 红链接均为左链接
 * 没有任何一个节点同时和两条红链接
 * 该树是完美黑色平衡的 即任意空链到根节点的路径上的黑链接数量相同
 * 根节点总是黑色
 *
 *
 */

public class RedBlackBST<Key extends Comparable<Key> ,Value> {

    private  Node root;

    private static final boolean RED = true;
    private static  final boolean BLACK  = false;
    private class Node{
        Key key;
        Value value;
        Node left , right;
        int N;
        boolean color;

        Node(Key key ,  Value val , int N , boolean color)
        {
            this.key = key;
            this.value = val;
            this.N = N;
            this.color = color;
        }

    }


    public int size()
    {
        return size(root);
    }

    private int size(Node x)
    {
        if(x==null)return 0;
        else       return x.N;
    }

    private boolean isRed(Node x)
    {
        if(x==null)return false;
        return x.color==RED;
    }

    /*
    左旋转
     */

    Node rotatedLeft(Node h)
    {
        Node x = h.right;
        h.right = x.left;
        x.color = h.color;
        h.color  = RED;
        x.N = h.N;
        h.N = 1 + size(h.left)+size(h.right);
        return x;
    }

    /*
    右旋转
     */

    Node rotatedRight(Node h)
    {
        Node x = h.left;
        h.left = x.right;
        x.right = h;
        x.color = h.color;
        h.color = RED;
        x.N = 1+size(h.left)+size(h.right);
        return h;
    }

    /*
    颜色转换
     */
    void flipColors(Node h)
    {
        h.color = RED;
        h.left.color  = BLACK;
        h.right.color = BLACK;
    }

    public void put( Key key , Value val)
    {
        root = put(root,key,val);
        root.color = BLACK;
    }

    /*
    红黑树的插入算法
    根据定义put()递归实现二叉查找树中的put()
    若红黑树的右链接为红色 则实现左旋转
    若红黑树的左链接和左子链接均为红色 则实现右旋转
    若红黑树的左链接和右链接均为红色 则实现颜色变换
     */
    private Node put(Node h , Key key , Value val)
    {

        if(h==null)
            return new Node(key ,val , 1 , RED);
        int cmp = key.compareTo(h.key);
        if(cmp<0)h.left = put(h.left,key,val);
        else if(cmp>0) h.right = put(h.right,key,val);
        else h.value = val;

        if(isRed(h.right)&&!isRed(h.left)) h = rotatedLeft(h);
        if(isRed(h.left)&&isRed(h.left.left)) h  =  rotatedRight(h);
        if (isRed(h.left)&&isRed(h.right)) flipColors(h);

        h.N = size(h.left)+size(h.right)+1;
        return h;

    }
    /*
    相当于二叉树的删除操作 要考虑颜色的变化

     */

    private Node moveRedLeft(Node h)
    {
        //颜色转换
        flipColors(h);
        if(isRed(h.right.left))
        {
            //判断其兄弟节点的左孩子是否为红 若是 对当前节点的父节点进行左右双旋转且颜色要转换
            h.right = rotatedRight(h.right);
            h = rotatedLeft(h);
        }
        return h;
    }

    public boolean isEmpty()
    {
        return root==null;
    }

    public void deleteMin()

    {
        if(!isRed(root.left)&&!isRed(root.right))
            root.color = RED;
        root = deleteMin(root);
        if(!isEmpty()) root.color = BLACK;

    }

    private Node deleteMin(Node h)
    {
        //递归条件结束到达左边界
        if(h.left==null)
            return null;

        //保证node节点或node.left为红节点 注意从父节点开始
        if(!isRed(h.left) && !isRed(h.left.left))//保证节点或父节点是红色
            h = moveRedLeft(h);//保证当前节点或其左孩子节点是红色 若不是则从右孩子中借一个节点

        h.left = deleteMin(h.left);//递归在左子树中进行

        return balance(h);//返回修复后的红色右节点
    }

    /*
    修复红黑树
     */

    private Node balance(Node h)
    {
        if(isRed(h.right))h = rotatedLeft(h);
        if(isRed(h.right)&&!isRed(h.left)) h = rotatedLeft(h);
        if(isRed(h.left)&&isRed(h.left.left)) h  =  rotatedRight(h);
        if (isRed(h.left)&&isRed(h.right)) flipColors(h);
        h.N = size(h.left)+size(h.right)+1;
        return h;
    }

    /*
    对于当前节点从其兄弟节点中借一个节点
     */
    private Node moveRedRight(Node h)
    {
        //先进行颜色转换
        flipColors(h);

        if(!isRed(h.left.left))
            //判断其兄弟节点的左孩子是否为红，若是，对当前节点的父节点进行左旋转且颜色要转换
            h = rotatedRight(h);
        return h;
    }

    public void deleteMax()
    {
        if (!isRed(root.left) && !isRed(root.right))
            root.color = RED;
        root = deleteMax(root);
        if(!isEmpty()) root.color = BLACK;
    }

    private Node deleteMax(Node h)
    {
        if(isRed(h.left))
            h  = rotatedRight(h);
        if(h.right==null)
            return null;

        //保证node或node.right为红节点，注意也是从父节点入手
        //因为3节点是用红节点来模拟的，红节点不可能是右孩子，所以不可能是h.right.right，
        //通过上面的一次左旋转，可以获得与h.right.right同样的效果

        if(!isRed(h.right) && !isRed(h.right.left))
            h = moveRedRight(h);
        h.right = deleteMax(h.right);//递归在右子树中删除
        return balance(h);
    }

    public  void delete(Key key)
    {
        if(!isRed(root.left) && !isRed(root.right))
        {
            root.color = RED;
        }
        root = delete(root,key);
        if(!isEmpty()) root.color = BLACK;
    }

    public Value get(Key key)
    {
        return get(root , key);
    }

    private Value get(Node x , Key key)
    {
        if(x==null) return null;
        int cmp = key.compareTo(x.key);
        if(cmp<0)return get(x.left,key);
        else if(cmp>0) return get(x.right,key);
        else return x.value;
    }

    public Key min()
    {return min(root).key;}

    private Node min(Node x)
    {
        if(x.left==null) return x;
        return min(x.left);
    }

    private Node delete(Node h , Key key)
    {
        /*
        若当前的键小于待删除的键 则在左子树中递归删除 在递归过程中要保证当前节点或当前节点的左孩子为红节点 同样作为父节点
         */

        if(key.compareTo(h.key)<0)
        {
            //确保删除的节点不是2节点
            if(!isRed(h.left) && !isRed(h.right))
                h = moveRedLeft(h);
            h.left = delete(h.left,key);
        }

        else {

            if (isRed(h.left))//确保右子树中能出现红色右孩子
                h = rotatedRight(h);//判断当前节点的左孩子是否为红 是则左旋转 将红链接旋转到右孩子

            /*
            待删除的节点为当前节点 且右孩子为空 待删除节点在树底
             */
            if (key.compareTo(h.key) == 0 && (h.right == null))
                return null;

            /*
            删除节点
            确保删除节点不为而节点
             */

            if (!isRed(h.right) && !isRed(h.right.left))
                h = moveRedRight(h);

            //待删除节点不在树底
            if (key.compareTo(h.key) == 0) {
                h.value = get(h.right, min(h.right).key);
                h.key = min(h.right).key;
                h.right = delete(h.right, key);
            }

            else {
                h.right = delete(h.right, key);
            }
        }
            return balance(h);
        }
    }











