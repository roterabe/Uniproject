package com.company;

public class Main {

    public static void DisplayDivisors(int number) {
        for (int i = 1; i <= number / 2; i++) {
            if (number % i == 0) {
                System.out.print(i + " ");
            }
        }
    }

    public static int SumofDivisors(int number) {
        int sum = 0;
        for (int i = 1; i <= number / 2; i++) {
            if (number % i == 0) {
                sum += i;
            }
        }
        return sum;
    }

    public static void isPerfect(int sum, int number) {
        if (sum == number) {
            System.out.println("The number " + sum + " is perfect.");
        } else {
            System.out.println("The number " + number + " is not perfect.");
        }
    }

    public static void checkPerfect(int res){

    }

    public static void main(String[] args) {
        int number = 28;
        DisplayDivisors(number);
        System.out.println();
        System.out.println(SumofDivisors(number));
        isPerfect(SumofDivisors(number), number);
    }
}
