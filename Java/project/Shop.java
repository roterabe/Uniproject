import java.util.ArrayList;

public class Shop {
    ArrayList<Goods> goods = new ArrayList<Goods>();
    ArrayList<Cashier> workers = new ArrayList<Cashier>();
    int receipt_cnt = 0;

    Shop() {

    }

    void import_goods(Goods g) {
        goods.add(g);
    }

    void sell(String item) {
        for (int i = 0; i < goods.size(); i++){
            if (item == goods.get(i).name){
                goods.remove(i);
            }
        }
    }

}