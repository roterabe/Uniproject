package com.company;

import java.util.Scanner;

public class Main {

    public static void Funky(int bottom, int top, int difference) {
        int calculation = 0;
        int restofnum = 0;
        int result = 0;
        String res = "";
        for (int i = bottom; i < top; i++) {
            int firstDigit = i;
            while (firstDigit > 9) {
                firstDigit /= 10;
            }
            String first = "" + firstDigit;
            String s = "" + i;
            res = s + firstDigit;
            restofnum = Integer.parseInt(s.substring(1));
            result = Integer.parseInt(res.substring(1));
            calculation = Math.abs(i - result);

            if (calculation > difference)
                System.out.println(i + " " + result + " => " + i + " - " + result + " = " + calculation + " > " + difference);
        }
    }

    public static void main(String[] args) {
        int bottom, top, difference;
        Scanner input = new Scanner(System.in);
        System.out.print("bottom = ");
        bottom = input.nextInt();
        System.out.print("top = ");
        top = input.nextInt();
        System.out.print("difference = ");
        difference = input.nextInt();

        Funky(bottom, top, difference);

    }
}
