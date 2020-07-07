package minesort;
/*
 * 堆排序
 */

import java.util.Scanner;

public class HeapSort {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        int[] array = new int[num];
        for (int i = 0; i < array.length; i++) {
            array[i] = input.nextInt();
        }
        System.out.println("HeapSort: ");
        heapSort(array);
        for (int value : array) {
            System.out.print(value + " ");
        }
    }

    public static void heapSort(int[] array) {
        int len = array.length;
        for (int i = 0; i < len - 1; i++) {
            buildMaxHeap(array, len - 1 - i);
            // 交换堆顶和最后一个元素
            swap(array, 0, len - 1 - i);
        }
    }

    public static void buildMaxHeap(int[] array, int lastIndex) {
        // 对数组从 0 到 lastIndex 建大顶堆
        // 从 lastIndex 处节点（最后一个节点）的父节点开始
        for (int i = (lastIndex - 1) / 2; i >= 0; i--) {
            // k 保存当前正在判断的节点
            int k = i;
            // 如果当前 k 节点的子节点存在
            while (k * 2 + 1 <= lastIndex) {
                // k 节点的左子节点的索引
                int biggerIndex = 2 * k + 1;
                // 如果 biggerIndex 小于 lastIndex，即 biggerIndex + 1
                // 代表k节点的右子节点存在
                if (biggerIndex < lastIndex) {
                    // 如果右子节点的值较大
                    if (array[biggerIndex] < array[biggerIndex + 1]) {
                        // biggerIndex 总是记录较大子节点的索引
                        biggerIndex++;
                    }
                }
                // 如果k节点的值小于其较大子节点的值
                if (array[k] < array[biggerIndex]) {
                    // 交换它们
                    swap(array, k, biggerIndex);
                    // 将 biggerIndex 赋给 k，开始while循环的下一次循环
                    // 重新保证 k 节点的值大于其左，右节点的值
                    k = biggerIndex;
                } else {
                    break;
                }
            }
        }
    }

    public static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
