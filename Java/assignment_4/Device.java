
public class Device {
    Manufacturer manufacturer;
    static int minGuarantee = 6;
    static int minPrice = 100;

    Device(Manufacturer manufacturer) {
        this.manufacturer = manufacturer;
    }

    public String toString() {
        return manufacturer.getName();
    }

    public void guaranteePeriod() {
        System.out.println("The guarantee is " + minGuarantee + " months.");
    }

    int getPrice() {
        return minPrice;
    }
}

class Oven extends Device {
    Manufacturer manufacturer;
    String type;
    int guarantee = minGuarantee;
    int price = minPrice + 50;

    Oven(Manufacturer manufacturer, String type) {
        super(manufacturer);
        this.type = type;
        guarantee = guarantee + manufacturer.getExt();
    }

    public String toString() {
        return manufacturer.getName() + " " + type;
    }

    public void guaranteePeriod() {
        System.out.println("The guarantee is " + guarantee + " months.");
    }

    int getPrice() {
        return price;
    }
}

class Washer extends Device {
    Manufacturer manufacturer;
    String type;
    int rev = 0;
    int guarantee = minGuarantee;
    int price = minPrice + 100;

    Washer(Manufacturer manufacturer, int rev, String dryer) {
        super(manufacturer);
        this.rev = rev;
        type = dryer;
        guarantee = guarantee + manufacturer.getExt();

        if (dryer == "dryer") {
            guarantee = guarantee + (minGuarantee / 2);
        }
    }

    public String toString() {
        return manufacturer.getName() + " : " + type + " : " + rev;
    }

    public void guaranteePeriod() {
        System.out.println("The guarantee is " + guarantee + " months.");
    }

    int getPrice() {
        return price;
    }
}