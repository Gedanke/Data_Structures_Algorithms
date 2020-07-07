package minesort;
/*
 * 归并排序
 */

import java.util.Scanner;

public class MergeSort {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        int[] array = new int[num];
        for (int i = 0; i < array.length; i++) {
            array[i] = input.nextInt();
        }
        System.out.println("MergeSort: ");
        mergeSort(array);
        for (int value : array) {
            System.out.print(value + " ");
        }
    }

    public static void mergeSort(int[] array) {
        sort(array, 0, array.length - 1);
    }

    public static void sort(int[] array, int left, int right) {
        if (left < right) {
            int center = (left + right) / 2;
            sort(array, left, center);
            sort(array, center + 1, right);
            merge(array, left, center, right);
        }
    }

    public static void merge(int[] array, int left, int center, int right) {
        int[] tempArray = new int[array.length];
        int mid = center + 1;
        int temp = left, third = left;
        while (left <= center && mid <= right) {
            if (array[left] <= array[mid]) {
                tempArray[third++] = array[left++];
            } else {
                tempArray[third++] = array[mid++];
            }
            while (mid <= right) {
                tempArray[third++] = array[mid++];
            }
            while (left <= center) {
                tempArray[third++] = array[left++];
            }
            while (temp <= right) {
                array[temp] = tempArray[temp++];
            }
        }
    }
}
