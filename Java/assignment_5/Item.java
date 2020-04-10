interface Shipment {
    int shippingPrice();
}

public class Item implements Shipment {
    Box box;
    Element element;

    void addElement(Element element) {

    }

    void totalWeight() {

    }

    void shipmentPrice() {
        
    }

    @Override
    public int shippingPrice() {
        // TODO Auto-generated method stub
        return 0;
    }

}

class Shoes {

}

class Furniture {

}