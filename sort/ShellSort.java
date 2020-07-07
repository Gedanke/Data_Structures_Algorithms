package minesort;
/*
 * Shell 排序
 */

import java.util.Scanner;

public class ShellSort {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        int[] array = new int[num];
        for (int i = 0; i < array.length; i++) {
            array[i] = input.nextInt();
        }
        System.out.println("ShellSort: ");
        shellSort(array);
        for (int value : array) {
            System.out.print(value + " ");
        }
    }

    public static void shellSort(int[] array) {
        int len = array.length;

        int h = 1;
        while (h <= len / 3) {
            h = 3 * h + 1;
        }
        while (h > 0) {
            for (int i = h; i < len; i++) {
                int temp = array[i];
                if (array[i] < array[i - h]) {
                    int j = i - h;
                    for (; j >= 0 && array[j] > temp; j -= h) {
                        array[j + h] = array[j];
                    }
                    array[j + h] = temp;
                }
            }
            h = (h - 1) / 3;
        }
    }
}
