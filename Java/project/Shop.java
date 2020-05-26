import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Shop {
    private ArrayList<Cashier> workers = new ArrayList<Cashier>();
    private Map<Goods, Integer> goods = new HashMap<Goods, Integer>();
    private Set<Goods> gRemove = new HashSet<Goods>();
    private Set<String> iRemove = new HashSet<String>();
    private int receipt_cnt = 0;
    private String name = "";
    private double revenue = 0;

    Shop(String name) {
        this.name = name;
    }

    void import_goods(Goods g, int number) {
        int count = 0;
        count = goods.containsKey(g) ? goods.get(g) : 0;
        goods.put(g, number + count);
    }

    void sell(Map<String, Integer> items, Register r) {
        boolean found = false;
        for (Map.Entry<String, Integer> s : items.entrySet()) {
            found = false;
            for (Map.Entry<Goods, Integer> g : goods.entrySet()) {
                if (s.getKey() == g.getKey().getName()) {
                    found = true;
                    int count = s.getValue();
                    int gcount = g.getValue();

                    if (gcount == 0)
                        gRemove.add(g.getKey());

                    else if (gcount < count) {
                        System.out.println("Unable to do transaction! The shop has " + (count - gcount) + " "
                                + s.getKey() + " less.");
                        iRemove.add(s.getKey());
                    }

                    else if (count <= gcount) {
                        goods.put(g.getKey(), gcount - count);
                    }
                }
            }
            if (found == false)
                iRemove.add(s.getKey());
        }

        items.keySet().removeAll(iRemove);
        goods.keySet().removeAll(gRemove);
        // System.out.println("boo");
        r.make_receipt(items, goods);
        incReceiptcnt();
        calcRevenue(items);
        iRemove.clear();
        gRemove.clear();
    }

    private void incReceiptcnt() {
        receipt_cnt += 1;
    }

    void calcRevenue(Map<String, Integer> items) {
        for (String s : items.keySet())
            for (Goods g : goods.keySet())
                if (s == g.getName())
                    revenue += items.get(s) * g.getPrice();
    }

    String getName() {
        return name;
    }

    void addWorker(Cashier c) {
        workers.add(c);
    }

    void getRevenue() {
        System.out.println("The current revenue for " + getName() + " is: " + revenue + "lv.");
    }

    void receiptCnt() {
        System.out.println("The amount of printed receipts as of this moment is: " + receipt_cnt);
    }
}
