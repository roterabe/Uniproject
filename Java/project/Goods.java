public class Goods {
    private final int id;
    private String name = "";
    private double price = 0;
    private String expiration_date = "";

    Goods(int id, String name, double price, String expiration_date) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.expiration_date = expiration_date;
    }

    double getPrice() {
        return price;
    }

    String getName() {
        return name;
    }

    @Override
    public String toString() {
        return name;
    }
}