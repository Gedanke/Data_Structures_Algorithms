package minesort;
/*
 * 基数排序
 */

import java.util.Scanner;

public class MultiKeyRadixSort {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        int[] array = new int[num];
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < array.length; i++) {
            array[i] = input.nextInt();
            if (array[i] > max) {
                max = array[i];
            }
        }
        System.out.println("MultiKeyRadixSort: ");
        multiKeyRadixSort(array, max);
        for (int value : array) {
            System.out.print(value + " ");
        }
    }

    public static void multiKeyRadixSort(int[] array, int max) {
        for (int i = 1; max / i > 0; i *= 10) {
            countSort(array, i);
        }
    }

    public static void countSort(int[] array, int radix) {
        int len = array.length;
        int[] output = new int[len];
        int[] buckets = new int[10];
        for (int i = 0; i < len; i++) {
            buckets[(array[i] / radix) % 10]++;
        }
        for (int i = 1; i < 10; i++) {
            buckets[i] += buckets[i - 1];
        }
        for (int i = len - 1; i >= 0; i--) {
            output[buckets[(array[i] / radix) % 10] - 1] = array[i];
            buckets[(array[i] / radix) % 10]--;
        }
        for (int i = 0; i < len; i++) {
            array[i] = output[i];
        }
    }
}
