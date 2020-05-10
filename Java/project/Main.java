public class Main {
    public static void main(String[] args) {
        Shop billa = new Shop();
        Cashier c = new Cashier("Joro", 112);
        Register r = new Register(c);
        Client cl = new Client("Vik");
        Goods g = new Goods(1, "Apple", 1, "21.07.2020");
        Goods g1 = new Goods(2, "Corn", 2, "25.08.2020");
        cl.addToBuy("Corn", 2);
        cl.addToBuy("Apple", 5);
        billa.import_goods(g, 5);
        billa.import_goods(g1, 5);
        cl.Buy(billa, r);
    }
}