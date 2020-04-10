import java.util.ArrayList;

interface Shipment {
    void shippingPrice();
}

abstract public class Item implements Shipment {
    Box box;
    Element element;
    ArrayList<Element> els;
    String address;
    int totalweight;
    int price;

    Item(Box box, String address, int price) {
        this.box = box;
        this.price = price;
        this.address = address;
    }

    abstract void addElement(Element element);

    abstract void totalWeight();

    abstract boolean isFragile();

    @Override
    abstract public void shippingPrice();

}

class Shoes extends Item {
    boolean weigh;

    Shoes(Box box, String address, int price, boolean weigh) {
        super(box, address, price);
        this.weigh = weigh;
    }

    @Override
    void addElement(Element element) {
        this.element = element;
        els.add(element);

    }

    @Override
    void totalWeight() {
        int totalweight = 0;
        Element e;
        for (int i = 0; i < els.size(); i++) {
            e = els.get(i);
            totalweight += e.getWeight();

        }
        System.out.println("The total weight of Shoes is: " + totalweight + ".kg.");
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
    public void shippingPrice() {
        int total = 0;
        total = price * totalweight;
        System.out.println("The shipping price for these Shoes is: " + total + ".lv.");
    }

}

class Furniture extends Item {
    String brand;

    Furniture(Box box, String address, int price, String brand) {
        super(box, address, price);
        this.brand = brand;
    }

    @Override
    void addElement(Element element) {
        // TODO Auto-generated method stub

    }

    @Override
    void totalWeight() {
        // TODO Auto-generated method stub

    }

    @Override
    boolean isFragile() {
        // TODO Auto-generated method stub
        return false;
    }

    @Override
    public void shippingPrice() {
        // TODO Auto-generated method stub

    }

}