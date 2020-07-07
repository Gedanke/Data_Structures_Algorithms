package minesort;
/*
 * 直接插入排序
 */

import java.util.Scanner;

public class InsertSort {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        int[] array = new int[num];
        for (int i = 0; i < array.length; i++) {
            array[i] = input.nextInt();
        }
        System.out.println("InsertSort: ");
        insertSort(array);
        for (int value : array) {
            System.out.print(value + " ");
        }
    }

    public static void insertSort(int[] array) {
        int len = array.length;
        for (int i = 1; i < len; i++) {
            int temp = array[i];
            if (array[i] < array[i - 1]) {
                int j = i - 1;
                for (; j >= 0 && array[j] > temp; j--) {
                    array[j + 1] = array[j];
                }
                array[j + 1] = temp;
            }
        }
    }
}
