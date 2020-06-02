import java.util.concurrent.TimeUnit;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        Shop billa = new Shop("BILLA");
        Cashier c = new Cashier("Joro", 112, billa);
        Cashier c1 = new Cashier("Des", 221, billa);
        c1.startWorking();
        c.startWorking();
        Register r = new Register(billa, 221);
        r.openRegister();
        Register r1 = new Register(billa, 222);
        r1.openRegister();
        billa.assignCashiers();
        Client cl = new Client("Vik");
        Client c2 = new Client("Ros");
        Client c3 = new Client("Bob");
        Goods g = new Goods(1001, "Apple", 1, "21.07.2020");
        Goods g1 = new Goods(2004, "Corn", 2, "25.08.2020");
        cl.addToBuy("Corn", 2);
        cl.addToBuy("Apple", 6);
        billa.import_goods(g, 5);
        billa.import_goods(g1, 5);
        cl.queue(billa, r);
        c2.addToBuy("Apple", 3);
        c2.queue(billa, r);
        c3.addToBuy("Corn", 3);
        c3.queue(billa, r1);
        billa.handleClients();
        billa.printReceipts();
        billa.getRevenue();
        billa.receiptCnt();
    }
}