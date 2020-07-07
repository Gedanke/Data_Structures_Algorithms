package minesort;

import java.util.Scanner;

public class BubbleSort {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        int[] array = new int[num];
        for (int i = 0; i < array.length; i++) {
            array[i] = input.nextInt();
        }
        System.out.println("BubbleSort:");
        bubbleSort(array);
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println("\n" + "BubbleSort_:");
        bubbleSort_(array);
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
    }

    public static void bubbleSort(int[] array) {
        int len = array.length;
        for (int i = 0; i < len - 1; i++) {
            for (int j = 0; j < len - 1 - i; j++) {
                if (array[j] > array[j + 1]) {
                    int temp = array[j + 1];
                    array[j + 1] = array[j];
                    array[j] = temp;
                }
            }
        }
    }

    public static void bubbleSort_(int[] array) {
        int len = array.length;
        for (int i = 0; i < len - 1; i++) {
            boolean flag = false;
            for (int j = 0; j < len - 1 - i; j++) {
                if (array[j] > array[j + 1]) {
                    int temp = array[j + 1];
                    array[j + 1] = array[j];
                    array[j] = temp;
                    flag = true;
                }
            }
            if (!flag) {
                break;
            }
        }
    }
}
