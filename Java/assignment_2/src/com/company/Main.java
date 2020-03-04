package com.company;

import java.lang.reflect.Array;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        int num = 4;
        int arr[] = new int[2 * num];
        String test = "";

        int tmp = num * 2 - 1;
        for (int i = 0; i < num; i++) {
            arr[i] = i + 1;
            arr[tmp] = i + 1;
            tmp--;
        }
        test = Arrays.toString(arr);
        test = test.replaceAll("[, ;]", "");
        test = test.substring(1, test.length() - 1);
        int save1, save2;
        save1 = 0;
        save2 = num * 2;
        for (int i = 0; i < num; i++) {
            System.out.println(test.substring(save1, save2));
            save1++;
            save2--;
        }
        for (int j = 0; j < num; j++) {
            save1--;
            save2++;
            System.out.println(test.substring(save1, save2));
        }

    }

}

