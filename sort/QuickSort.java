package minesort;
/*
 * 快速排序
 * 通过一趟排序将待排序记录分割成独立的两部分，其中一部分记录的关键字均比另一部分关键字小，
 * 则分别对这两部分继续进行排序，直到整个序列有序。
 */

import java.util.Scanner;

public class QuickSort {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        int[] array = new int[num];
        for (int i = 0; i < array.length; i++) {
            array[i] = input.nextInt();
        }
        System.out.println("QuickSort: ");
        quickSort(array, 0, array.length - 1);
        for (int value : array) {
            System.out.print(value + " ");
        }
    }

    public static void quickSort(int[] array, int start, int end) {
        if (start < end) {
            int base = array[start];
            int low = start, high = end + 1;
            while (true) {
                while (low < end && array[++low] <= base) {
                    ;
                }
                while (high > start && array[--high] >= base) {
                    ;
                }
                if (low < high) {
                    swap(array, low, high);
                } else {
                    break;
                }
            }
            swap(array, start, high);

            quickSort(array, start, high - 1);
            quickSort(array, high + 1, end);
        }
    }

    public static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
