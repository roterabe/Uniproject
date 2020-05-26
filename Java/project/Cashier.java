public class Cashier {
    private String name = "";
    private final int id;
    Shop s;

    Cashier(String name, int id, Shop s) {
        this.name = name;
        this.id = id;
        this.s = s;
    }

    String getName() {
        return name;
    }

    String getShop() {
        return s.getName();
    }

    void startWorking() {
        s.addWorker(this);
    }
}