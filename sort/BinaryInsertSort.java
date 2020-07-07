package minesort;

import java.util.Scanner;

public class BinaryInsertSort {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        int[] array = new int[num];
        for (int i = 0; i < num; i++) {
            array[i] = input.nextInt();
        }
        binaryInsertSort(array);
        System.out.println("BinaryInsertSort:");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
    }

    public static void binaryInsertSort(int[] array) {
        int len = array.length;
        for (int i = 0; i < len; i++) {
            int temp = array[i];
            int low = 0, high = i - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (temp > array[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            for (int j = i; j > low; j--) {
                array[j] = array[j - 1];
            }
            array[low] = temp;
        }
    }
}
