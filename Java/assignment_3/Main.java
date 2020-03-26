package com.company;

class Muscomp {

}

class Studio extends Muscomp {
    private int minprice = 12;
    int price = 25;
    int workh = 8;

    public int getPrice() {
        return price;
    }

}

class Client extends Director {
    int hours;
    int cost;

    public Client(int hours) {
        this.hours = hours;
    }

    public int getHours() {
        return hours;
    }

    public void display() {
        System.out.println("Hours to book: " + hours);
    }

    public void rent() {
        int curr = 0;
        for (int i = 0; i < taken.length; i++) {
            curr += taken[i];
        }
        left = workh - curr;
        System.out.println(left);
        if (taken[0] == 0 && hours <= workh) {
            cost = hours * price;
            for (int i = 0; i < hours; i++) {
                taken[i] = 1;
            }
        } else if (left + hours <= workh) {
            cost = hours * price;
        } else if (left >= workh) {
            System.out.println("Not available for renting.");
        } else if (left + hours > workh)
            System.out.println("There are " + (workh - left) + " hours available for renting.");
        curr = 0;
        for (int i = 0; i < taken.length; i++) {
            curr += taken[i];
        }
        left = workh - curr;
        System.out.println(left);
    }

    void showrent() {
        System.out.println(cost);
    }
}

class Director extends Studio {
    int age;
    String name;
    int taken[] = new int[workh];
    int left;

    Director() {
    }

    public void setDir(int age, String name) {
        this.age = age;
        this.name = name;
    }

    public void displayDir() {
        System.out.println("Director name: " + name);
        System.out.println("Director age: " + age);
    }

    public int getLeft() {
        int curr = 0;
        for (int i = 0; i < taken.length; i++) {
            curr += taken[i];
        }
        left = workh - curr;
        return left;
    }

}

public class Main {

    public static void main(String[] args) {
        Muscomp company = new Muscomp();
        Director dir = new Director();
        dir.setDir(20, "Rosi");
        Client vik = new Client(3);
        Client ros = new Client(6);
        vik.rent();
        vik.showrent();
        ros.rent();
        ros.showrent();
    }
}
