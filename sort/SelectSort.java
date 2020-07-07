package minesort;
/*
 * 直接选择排序
 * 直接选择排序-改进
 */

import java.util.Scanner;

public class SelectSort {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        int[] array = new int[num];
        for (int i = 0; i < array.length; i++) {
            array[i] = input.nextInt();
        }
        System.out.println("SelectSort: ");
        selectSort(array);
        for (int value : array) {
            System.out.print(value + " ");
        }
        System.out.println("\nSelectSort_: ");
        selectSort_(array);
        for (int value : array) {
            System.out.print(value + " ");
        }
    }

    public static void selectSort(int[] array) {
        int len = array.length;
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                if (array[i] > array[j]) {
                    swap(array, i, j);
                }
            }
        }
    }

    public static void selectSort_(int[] array) {
        int len = array.length;
        for (int i = 0; i < len - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < len; j++) {
                if (array[minIndex] > array[j]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(array, i, minIndex);
            }
        }
    }

    public static void swap(int[] array, int i, int j) {
        var temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
