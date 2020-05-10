import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Map;

public class Register {
    Cashier c;
    ArrayList<Goods> goods = new ArrayList<Goods>();

    Register(Cashier c) {
        this.c = c;
    }

    void make_receipt(Map<String, Integer> items, Map<Goods, Integer> goods) {
        try {
            Receipt r = new Receipt(c.getName(), items, goods);
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

}