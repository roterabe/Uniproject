
public class Device {
    String manufacturor;
    static int minGuarantee = 12;
    static int minPrice = 100;

    Device() {

    }

    public String toString() {
        return manufacturor;
    }

    public void guaranteePeriod() {
        System.out.println("The guarantee is " + minGuarantee + " months.");
    }
}

class Oven extends Device {
    String manufacturor;
    String type;
    int guarantee = minGuarantee + 12;
    int price = minPrice + 50;

    Oven() {

    }

    public String toString() {
        return manufacturor + " " + type;
    }

    public void guaranteePeriod() {
        System.out.println("The guarantee is " + guarantee + " months.");
    }
}

class Washer extends Device {
    String manufacturor;
    String type;
    int guarantee = minGuarantee + 12;
    int price = minPrice + 100;

    Washer() {

    }

    public String toString() {
        return manufacturor + " " + type;
    }

    public void guaranteePeriod() {
        System.out.println("The guarantee is " + guarantee + " months.");
    }
}