import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Shop {
    ArrayList<Cashier> workers = new ArrayList<Cashier>();
    Map<Goods, Integer> goods = new HashMap<Goods, Integer>();
    int receipt_cnt = 0;

    Shop() {

    }

    void import_goods(Goods g, int number) {
        int count = goods.containsKey(g) ? goods.get(g) : 0;
        goods.put(g, number + count);
    }

    void sell(Map<String, Integer> items, Register r) {
        for (String s : items.keySet()) {
            for (Goods g : goods.keySet()) {
                if (s == g.name) {
                    int count = items.get(s);
                    int gcount = goods.get(g);
                    if (gcount >= count)
                        goods.put(g, goods.get(g) - count);
                        if(gcount == 0)
                        goods.remove(g);
                    else
                        System.out.println("Unable to do transaction! You need " + (count - gcount) + " " + s + ".");
                }
                if (s != g.name) {
                    items.remove(s);
                }
            }
        }
        r.make_receipt(items, goods);
    }

}