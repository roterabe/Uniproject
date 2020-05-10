public class Cashier {
    private String name = "";
    private final int id;

    Cashier(String name, int id) {
        this.name = name;
        this.id = id;
    }

    String getName() {
        return name;
    }
}