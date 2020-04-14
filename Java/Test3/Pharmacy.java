import java.util.ArrayList;

public class Pharmacy {
    ArrayList<Item> it = new ArrayList<Item>();
    double income = 0;
    String name;

    Pharmacy(String name) {
        this.name = name;
    }

    void addItem(Item item) {
        it.add(item);
    }

    void income() {
        double inc = 0;
        for (int i = 0; i < it.size(); i++) {
            inc += it.get(i).totalPrice();
        }
        income = inc;
        System.out.println("The income of the company is: " + income + ".lv");
    }

    void incomeByAge(Age age) {
        double inc = 0;
        for (int i = 0; i < it.size(); i++){
            if (age.name() == it.get(i).getAge()) {
                inc += it.get(i).totalPrice();
            }
        }
        System.out.println("The income of the company for " + age + " is: " + inc + ".lv");
    }
}