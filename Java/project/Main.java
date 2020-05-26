public class Main {
    public static void main(String[] args) {
        Shop billa = new Shop("BILLA");
        Cashier c = new Cashier("Joro", 112, billa);
        Cashier c1 = new Cashier("Des", 221, billa);
        c1.startWorking();
        c.startWorking();
        Register r = new Register(billa);
        r.openRegister();
        Register r1 = new Register(billa);
        r1.openRegister();
        billa.assignCashiers();
        Client cl = new Client("Vik");
        Client c2 = new Client("Ros");
        Goods g = new Goods(1001, "Apple", 1, "21.07.2020");
        Goods g1 = new Goods(2004, "Corn", 2, "25.08.2020");
        cl.addToBuy("Corn", 2);
        cl.addToBuy("Apple", 6);
        billa.import_goods(g, 5);
        billa.import_goods(g1, 5);
        cl.goBuy(billa, r);
        c2.addToBuy("Apple", 3);
        c2.goBuy(billa, r1);    
        billa.handleClients();
        billa.getRevenue();
    }
}