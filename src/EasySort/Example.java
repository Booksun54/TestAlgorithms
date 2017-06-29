package EasySort;

import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

import java.util.Random;

/**
 * Created by snake on 2017/6/13.
 */
public class Example {

    /*
        选择排序法
     */

    public static void Selectionsort(Comparable[] a) {
        int N = a.length;
        for (int i = 0; i < N; i++) {
            int min = i;
            for (int j = i + 1; j < N; j++)
                if (less(a[j], a[min])) min = j;
            exch(a, i, min);

        }

    }

    /*
        插入排序法
     */
    public static void Insertionsort(Comparable[] a) {
        int N = a.length;
        for (int i = 1; i < N; i++) {
            for (int j = i; j > 0 && less(a[j], a[j - 1]); j--)
                exch(a, j, j - 1);

        }
    }

    /*
    希尔排序
     */

    public static void Shellsort(Comparable[] a) {
        int N = a.length;
        int h = 1;
        while (h < N / 3) h = h * 3 + 1;
        while (h >= 1) {
            for (int i = h; i < N; i++) {
                for (int j = i; j >= h && less(a[j], a[j - h]); j -= h) {
                    exch(a, j, j - h);
                }
            }
            h = h / 3;
        }
    }

    /*
    快速排序
     */

    public static void Quicksort(Comparable[] a, int lo, int hi) {
        if (hi <= lo) return;
        int j = partition(a, lo, hi);
        Quicksort(a, lo, j - 1);
        Quicksort(a, j + 1, hi);
    }

    private static int partition(Comparable[] a, int lo, int hi) {
        int i = lo, j = hi + 1;
        Comparable v = a[lo];
        while (true) {
            while (less(a[++i], v)) if (i == hi) break;
            while (less(v, a[--j])) if (lo == j) break;
           if(i>j) break;
           exch(a,i,j);
        }
        exch(a, lo,j);
        return j;
    }

    /*
        三向切分
     */
    private static void Quick3sort(Comparable[]a , int lo , int hi)
    {
        if(lo>=hi)return;
        int lt = lo , i = lo+1,gt = hi;
        Comparable v= a[lo];
        while (i<=gt)
        {
            int cmp = a[i].compareTo(v);
            if(cmp<0) exch(a,lt++,i++);
            if(cmp>0) exch(a,i++,gt--);
            else i++;
        }
        Quick3sort(a,lo,lt-1);
        Quick3sort(a,gt+1,hi);




    }

    private static boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }

    private static void exch(Comparable[] a, int i, int j) {
        Comparable t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    private static void show(Comparable[] a) {
        for (int i = 0; i < a.length; i++) {
            StdOut.print(a[i] + " ");
        }
        StdOut.println();
    }

    public static boolean isSorted(Comparable[] a) {
        for (int i = 1; i < a.length; i++) {
            if (less(a[i], a[i - 1])) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Integer[] a = new Integer[30];
        Random random = new Random();
        StdOut.println("排序前:");
        for (int i = 0; i < 30; i++) {
            a[i] = random.nextInt(100);
            StdOut.print(a[i] + " ");
        }

        StdOut.println();
        //Selectionsort(a);//选择排序法
        //Insertionsort(a);//插入排序法
        Shellsort(a);//希尔排序法
        assert isSorted(a);

        StdOut.println("排序后:");
        show(a);
    }
}
