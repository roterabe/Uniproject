import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class Shop {
    ArrayList<Cashier> workers = new ArrayList<Cashier>();
    Map<Goods, Integer> goods = new HashMap<Goods, Integer>();
    Set<Goods> gRemove = new HashSet<Goods>();
    Set<String> iRemove = new HashSet<String>();
    int receipt_cnt = 0;

    Shop() {

    }

    void import_goods(Goods g, int number) {
        int count = 0;
        count = goods.containsKey(g) ? goods.get(g) : 0;
        goods.put(g, number + count);
    }

    void sell(Map<String, Integer> items, Register r) {
        boolean found = false;
        for (Map.Entry<String, Integer> s : items.entrySet()) {
            {
                found = false;
                for (Map.Entry<Goods, Integer> g : goods.entrySet()) {
                    {
                        if (s.getKey() == g.getKey().name) {
                            int count = s.getValue();
                            int gcount = g.getValue();
                            if (gcount < count)
                                System.out.println("Unable to do transaction! You need " + (count - gcount) + " "
                                        + s.getKey() + ".");
                            if (gcount == 0)
                                gRemove.add(g.getKey());
                            else
                                goods.put(g.getKey(), g.getValue() - count);
                            found = true;
                        }
                        if (found = false)
                            iRemove.add(s.getKey());
                    }
                }
            }
        }
        items.keySet().removeAll(iRemove);
        goods.keySet().removeAll(gRemove);
        r.make_receipt(items, goods);
    }
}
