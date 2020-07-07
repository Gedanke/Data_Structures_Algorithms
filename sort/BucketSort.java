package minesort;

import java.util.Scanner;

public class BucketSort {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        int[] array = new int[num];
        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
        for (int i = 0; i < array.length; i++) {
            array[i] = input.nextInt();
            if (array[i] > max) {
                max = array[i];
            }
            if (array[i] < min) {
                min = array[i];
            }
        }
        System.out.println(min + " " + max);
        System.out.println("BubbleSort:");
        bucketSort(array, min - 1, max + 1);
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
    }

    public static void bucketSort(int[] array, int min, int max) {
        int len = array.length;
        int[] temp = new int[len];
        int[] buckets = new int[max - min];
        for (int i = 0; i < len; i++) {
            buckets[array[i] - min]++;
        }
        for (int i = 1; i < max - min; i++) {
            buckets[i] = buckets[i] + buckets[i - 1];
        }
        System.arraycopy(array, 0, temp, 0, len);
        for (int k = len - 1; k >= 0; k--) {
            array[--buckets[temp[k] - min]] = temp[k];
        }
    }
}
