import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Vector;

public class Register extends Thread {
    private Cashier c;
    private Shop s;
    private Map<Goods, Integer> goods = new HashMap<Goods, Integer>();
    private ArrayList<Map<String, Integer>> queue1 = new ArrayList<Map<String, Integer>>();
    private Receipt r;
    final int id;

    Register(Shop s, int id) {
        this.s = s;
        this.id = id;
    }

    void openRegister() {
        s.addRegister(this);
    }

    void prepare_receipt(Map<String, Integer> items) {
        queue1.add(items);
        Receipt r = new Receipt(c);
        this.r = r;
    }

    void addGoods(Map<Goods, Integer> goods) {
        this.goods = goods;
    }

    void addCashier(Cashier c) {
        this.c = c;
    }

    public void run() {
        try {
            r.writeReceipt(goods, queue1, id);
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            System.out.println(e);
        } catch (IOException e) {
            System.out.println(e);
        }
    }

    public void start() {
        Thread t = new Thread(this);
        t.start();
    }

    void printR(String tt) {
        try {
            r.printReceipt(tt);
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    Vector<String> retR() {
        return r.retR();
    }

}