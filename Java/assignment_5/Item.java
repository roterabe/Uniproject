import java.util.ArrayList;

interface Shipment {
    double shippingPrice();
}

abstract public class Item implements Shipment {
    Box box;
    Element element;
    ArrayList<Element> els = new ArrayList<Element>();
    String address;
    double price;

    Item(Box box, String address, double price) {
        this.box = box;
        this.price = price;
        this.address = address;
    }

    abstract void addElement(Element element);

    abstract double totalWeight();

    abstract boolean isFragile();

    abstract double volume();

    @Override
    abstract public double shippingPrice();

    public String toString() {
        return "Here is the data ( " + "address: " + address + " / weight: " + totalWeight() + " / price per kg: " + price + " / total price: " + shippingPrice() + ".lv";
    }

}

class Shoes extends Item {
    boolean weigh;

    Shoes(Box box, String address, double price, boolean weigh) {
        super(box, address, price);
        this.weigh = weigh;
    }

    @Override
    void addElement(Element element) {
        this.element = element;
        els.add(element);

    }

    @Override
    double totalWeight() {
        Element e;
        double w = 0.0;
        for (int i = 0; i < els.size(); i++) {
            e = els.get(i);
            w += e.getWeight();

        }
        return w;
    }

    @Override
    boolean isFragile() {
        for (int i = 0; i < els.size(); i++) {
            if (els.get(i).isFragile() == true) {
                return true;
            }
        }
        return false;
    }

    @Override
    public double shippingPrice() {
        double total = 0.0;
        if (weigh == false) {
            total = price * totalWeight();
        } else {
            total = price * totalWeight();
            total = total + total * 1.5 / 100;
        }
        return total;
    }

    @Override
    double volume() {
        return box.volume();
    }

    @Override
    public String toString() {
        return super.toString() + " / can weigh?: " + weigh + " ).";
    }

}

class Furniture extends Item {
    String brand;

    Furniture(Box box, String address, double price, String brand) {
        super(box, address, price);
        this.brand = brand;
    }

    @Override
    void addElement(Element element) {
        this.element = element;
        els.add(element);

    }

    @Override
    double totalWeight() {
        Element e;
        double w = 0.0;
        for (int i = 0; i < els.size(); i++) {
            e = els.get(i);
            w += e.getWeight();

        }
        return w;

    }

    @Override
    boolean isFragile() {
        for (int i = 0; i < els.size(); i++) {
            if (els.get(i).isFragile() == true) {
                return true;
            }
        }
        return false;
    }

    @Override
    public double shippingPrice() {
        double total = 0.0;
        if (isFragile() == true) {
            total = price * totalWeight();
            total = total + total * 3 / 100;
        } else {
            total = price * totalWeight();
        }
        return total;
    }

    @Override
    double volume() {
        return box.volume();
    }

    @Override
    public String toString() {
        return super.toString() + " / the brand is: " + brand + " ).";
    }

}