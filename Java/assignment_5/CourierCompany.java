import java.util.ArrayList;

public class CourierCompany {
    String name;
    double money = 0.0;
    Item item;
    ArrayList<Item> it = new ArrayList<Item>();

    CourierCompany(String name) {
        this.name = name;
    }

    void addItem(Item item) {
        this.item = item;
        it.add(item);
    }

    void totalEarnings() {
        Item e;
        double t = 0.0;
        for (int i = 0; i < it.size(); i++) {
            e = it.get(i);
            t += e.shippingPrice();
        }
        money = t;
        System.out.println("The total earnings for " + name + " are " + t + ".lv.");
    }

    void totalVolume() {
        Item e;
        double vol = 0;
        for (int i = 0; i < it.size(); i++) {
            e = it.get(i);
            vol += e.volume();
        }
        System.out.println("The total volume of all items is: " + vol + " cubic cm.");
    }

    public String toString() {
        return "The company is: " + name + " and it has made a total of: " + money + ".lv.";
    }

    void display() {
        System.out.println("The company is: " + name + " and it has made a total of: " + money + ".lv.");
    }
}