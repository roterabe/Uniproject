
abstract public class Item {
    final int inventory;
    double price = 0;
    Age age;

    Item(int inventory, double price, Age age) {
        this.age = age;
        this.inventory = inventory;
        this.price = price;
    }

    abstract double totalPrice();

    abstract String getAge();

    boolean forChildren() {
        if (age.name() == "CHILDREN") {
            return true;
        }
        return false;
    }

    boolean moreExpensiveThan(Item item) {
        if (totalPrice() > item.totalPrice()) {
            return true;
        }
        return false;
    }

    abstract public String toString();
}

class Medicine extends Item {
    String name;
    String insurance;
    static double percent = 0;

    Medicine(String name, int inventory, double price, Age age, String insurance) {
        super(inventory, price, age);
        this.name = name;
        this.insurance = insurance;
    }

    String getAge() {
        return age.name();
    }

    public static void healthInsurance(double num) {
        percent = num;
    }

    double totalPrice() {
        double pr = price + age.add();
        if (insurance == "insured") {
            pr = pr - pr * percent / 100;
        }
        return pr;
    }

    Medicine isLessExpensive(Medicine med) {
        if (!this.moreExpensiveThan(med)) {
            return this;
        }
        return med;
    }

    @Override
    public String toString() {
        return "The item is a box of: " + name + ". The inventory number is: " + inventory + ". It is suitable for: "
                + age.name() + " and ages up. The item is: " + insurance + " by health insurance.";
    }

}