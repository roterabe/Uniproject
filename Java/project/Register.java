import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

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
            Thread.sleep(1000);
            System.out.println(items.toString());

        } /*
           * catch (FileNotFoundException e) {
           * 
           * e.printStackTrace(); }
           */ catch (

        InterruptedException e) {
            e.printStackTrace();
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    public void start() {
        if (t == null) {
            t = new Thread(this);
            t.start();
        }
    }

}