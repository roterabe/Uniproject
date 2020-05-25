import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Map;

public class Register {
    Cashier c;
    Shop s;
    ArrayList<Goods> goods = new ArrayList<Goods>();

    Register(Shop s, Cashier c) {
        this.c = c;
        this.s = s;
    }

    void make_receipt(Map<String, Integer> items, Map<Goods, Integer> goods) {
        try {
            Receipt r = new Receipt(c, items, goods);
            r.makeReceipt();
            //System.out.println("booRegs");

        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

}