package EasySort;

import edu.princeton.cs.algs4.StdOut;

import java.util.ArrayList;
import java.util.Random;

/**
 * Created by snake on 2017/6/15.
 * 堆排序
 */
public class MAXPQ<Key extends Comparable<Key>> {

    private Key[] pq;
    private int N = 0;

    public MAXPQ(int maxN) {
        pq = (Key[]) new Comparable[maxN + 1];
    }

    public boolean isEmpty() {
        return N == 0;
    }

    public int size() {
        return N;
    }

    public void insert(Key v) {
        pq[++N] = v;
        swim(N);
    }

    public Key delMax() {
        Key max = pq[1];
        exch(1, N--);//将其和最后一个节点交换
        pq[N + 1] = null;//防止对象游离
        sink(1);//恢复堆的有序性
        return max;
    }

    private boolean less(int i, int j) {
        return pq[i].compareTo(pq[j]) < 0;
    }

    private void exch(int i, int j) {
        Key t = pq[i];
        pq[i] = pq[j];
        pq[j] = t;
    }


    private void swim(int k) {
        while (k > 1 && less(k / 2, k)) {
            exch(k / 2, k);
            k = k / 2;
        }

    }

    private void sink(int k) {
        while (2 * k <= N) {
            int j = 2 * k;
            if (j < N && less(j, j + 1)) j++;
            exch(k, j);
            k = j;
        }
    }


    public static void main(String[] args) {
        MAXPQ<Integer> maxpq = new MAXPQ<>(30);
        Integer[] a = new Integer[30];
        Random random = new Random();
        StdOut.println("排序前:");
        for (int i = 0; i < 30; i++) {
            a[i] = random.nextInt(100);
            StdOut.print(a[i] + " ");
            maxpq.insert(a[i]);
        }


        StdOut.println();

        StdOut.println("排序后:");
        while (!maxpq.isEmpty()) {
            int i = maxpq.delMax();
            StdOut.print(i + " ");
        }
        StdOut.println();
    }
}
