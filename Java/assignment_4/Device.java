
public class Device {
    Manufacturer manufacturer;
    int minGuarantee;
    int price;

    Device(Manufacturer manufacturer, int guarantee, int price) {
        this.manufacturer = manufacturer;
        minGuarantee = guarantee;
        this.price = price;
    }

    public String toString() {
        return manufacturer.getName() + " device";
    }

    int guaranteePeriod() {
        return minGuarantee + manufacturer.getExt();
    }

    int getPrice() {
        return price;
    }
}

class Oven extends Device {
    Manufacturer manufacturer;
    String type;

    Oven(Manufacturer manufacturer, String type, int guarantee, int price) {
        super(manufacturer, guarantee, price);
        this.type = type;
    }

    @Override
    public String toString() {
        return super.toString() + " : " + type + " : " + "oven.";
    }

    @Override
    int guaranteePeriod() {
        if (type == "gas")
            return super.guaranteePeriod() + 12;
        return super.guaranteePeriod();
    }

    int getPrice() {
        return super.getPrice();
    }
}

class Washer extends Device {
    Manufacturer manufacturer;
    String type;
    int rev = 0;

    Washer(Manufacturer manufacturer, int rev, String dryer, int guarantee, int price) {
        super(manufacturer, guarantee, price);
        this.rev = rev;
        type = dryer;
    }

    @Override
    public String toString() {
        return super.toString() + " : " + "washer" + " : " + "has dryer - " + type + " : " + rev + ".";
    }

    @Override
    int guaranteePeriod() {
        if (type == "yes")
            return super.guaranteePeriod() + super.guaranteePeriod() / 2;
        return super.guaranteePeriod();
    }

    int getPrice() {
        return super.getPrice();
    }
}