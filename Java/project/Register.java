import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Vector;

public class Register extends Thread {
    Cashier c;
    Shop s;
    Map<Goods, Integer> goods = new HashMap<Goods, Integer>();
    Map<String, Integer> items = new HashMap<String, Integer>();
    Receipt r;
    private Thread t;
    private int cnt = 0;

    Register(Shop s) {
        this.s = s;
    }

    void openRegister() {
        s.addRegister(this);
    }

    void prepare_receipt(Map<String, Integer> items, Map<Goods, Integer> goods, int receipt_cnt) {
        this.items = items;
        this.goods = goods;
        Receipt r = new Receipt(c, items, goods);
        this.r = r;
        cnt = receipt_cnt;
    }

    void addCashier(Cashier c) {
        this.c = c;
    }

    public void run() {
        try {
            r.writeReceipt(cnt);
            Thread.sleep(50);

        } catch (

        InterruptedException e) {
            System.out.println(e);
        } catch (IOException e) {
            System.out.println(e);
        }
    }

    public void start() {
        if (t == null) {
            t = new Thread(this);
            t.start();
        }
    }

    void printR(String tt) {
        try {
            r.printReceipt(tt);
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    Vector<String> retR() {
        Vector<String> res = r.retR();
        return res;
    }

}