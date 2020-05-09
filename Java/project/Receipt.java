import java.util.ArrayList;

public class Receipt {
    Cashier c;
    final int id;
    String date = "";
    ArrayList<Goods> items = new ArrayList<Goods>();
    double total = 0;
    ArrayList<Integer> qty = new ArrayList<>();
    static double revenue = 0;
    static int receipt_cnt = 0;
}