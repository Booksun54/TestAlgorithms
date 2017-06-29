package EasySort;

import edu.princeton.cs.algs4.StdOut;

import java.util.Iterator;
import java.util.Queue;

/**
 * Created by snake on 2017/6/19.
 * 二叉查找树
 */
public class BST<Key extends Comparable<Key> , Value> {

    private Node root;

    private class Node
    {
        private Key key;
        private Value val;
        private Node left , right;
        private int N;

        public Node (Key key , Value val , int N)
        {this.key = key;this.val=val; this.N= N;}
    }

    public int size()
    {
        return  size(root);
    }

    private int size(Node x)
    {
        if(x==null) return 0;
        else return x.N;
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
        else return x.val;
    }

    public void put(Key key , Value value)
    {
        root = put(root,key,value);

    }

    private Node put(Node x , Key key , Value val)
    {
        if(x==null) return new Node(key,val,1);
        int cmp = key.compareTo(x.key);
        if(cmp<0) x.left = put(x.left,key,val);
        else if(cmp>0)x.right = put(x.right,key,val);
        else x.val = val;
        x.N = size(x.left) + size(x.right);
        return x;
    }

    /*
    二叉树最小值
     */
    public Key min()
    {return min(root).key;}

    private Node min(Node x)
    {
        if(x.left==null) return x;
        return min(x.left);
    }

    /*
    二叉树最大值
     */

    public Key max()
    {return max(root).key;}

    private Node max(Node x)
    {
        if(x.right==null) return x;
        return max(x.right);
    }

    /*
    二叉树向下取整
     */

    public Key floor(Key key)
    {
        Node x = floor(root,key);
        if(x==null)return null;
        return x.key;
    }

    private Node floor(Node x , Key key)
    {
        if(x==null) return null;
        int cmp = key.compareTo(x.key);
        if(cmp == 0) return x;
        if(cmp<0) return floor(x.left,key);
        Node t = floor(x.right,key);
        if(t != null) return x;
        else return  x;
    }


    /*
    二叉树向上取整
     */

    public Key ceiling(Key key)
    {
        Node x = ceiling(root,key);
        if(x==null)return null;
        return x.key;
    }

    private Node ceiling(Node x , Key key)
    {
        if(x==null) return null;
        int cmp = key.compareTo(x.key);
        if(cmp == 0) return x;
        if(cmp>0) return floor(x.right,key);
        Node t = floor(x.left,key);
        if(t != null) return x;
        else return  x;
    }

    public Key select(int k)
    {
        return select(root, k).key;
    }

    /*
    查找在树中排名k的键
     */
    private Node select(Node x , int k)
    {
        if(x==null)return null;
        int t = size(x.left);
        if(t>k) return select(x.left,k);
        else if(t<k) return select(x.right,k);
        else return x;
    }

    /*
    计算键在树中的排名
     */
    public int rank(Key key)
    {
        return rank(key , root);
    }

    private int rank(Key key , Node x)
    {
        if(x==null) return 0;
        int  cmp = key.compareTo(x.key);
        if(cmp<0) return rank(key,x.left);
        else if(cmp>0) return 1+size(x.left)+rank(key,x.right);
        else return size(x.left);
    }

    /*
    删除最大键和删除最小键
     */

    public void deleteMin()
    {
        root = deleteMin(root);
    }

    private Node deleteMin(Node x)
    {
        if(x.left==null)return x.right;
        x.left = deleteMin(x.left);
        x.N = size(x.left)+size(x.right)+1;
        return x;
    }

    public void delete(Key key)
    {
     root = delete(root , key);
    }

    private Node delete(Node x , Key key)
    {
        if (x==null)return null;
        int cmp = key.compareTo(x.key);
        if(cmp<0) x.left = delete(x.left,key);
        if(cmp>0) x.right = delete(x.right,key);
        else{
            if(x.right==null) return x.left;
            if(x.left == null) return x.right;
            Node t = x;
            x = min(t.right);
        }
        return x;

    }

    /*
    按照顺序打印二叉查找树中的所有键
     */

    private void print(Node x)
    {
        if(x==null)return;
        print(x.left);
        StdOut.println(x.left);
        print(x.right);
    }

    /*
    二叉查找树范围查找
     */
    public Iterable<Key> keys()
    {
        return keys(min(),max());
    }



    public Iterable<Key> keys(Key lo , Key hi)
    {
        edu.princeton.cs.algs4.Queue<Key> queue = new edu.princeton.cs.algs4.Queue<Key>();
        keys(root,queue,lo,hi);
        return queue;
    }

    /*
    在范围之内的节点加入队列中
     */
    private void keys(Node x , edu.princeton.cs.algs4.Queue<Key> queue , Key lo , Key hi)
    {
        if(x==null)return;
        int cmplo = lo.compareTo(x.key);
        int cmphi = hi.compareTo(x.key);
        if(cmplo<0)keys(x.left,queue,lo,hi);
        if(cmplo<=0 && cmphi>=0) queue.enqueue(x.key);
        if(cmphi>0) keys(x.right,queue,lo,hi);
    }
}
