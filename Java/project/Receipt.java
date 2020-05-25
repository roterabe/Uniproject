import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.time.format.DateTimeFormatter;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.time.LocalDateTime;

public class Receipt {
        String cname;
        Cashier c;
        static int cnt = 0;
        private double total = 0;
        Map<String, Integer> items = new HashMap<String, Integer>();
        Map<Goods, Integer> goods = new HashMap<Goods, Integer>();
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();

        Receipt(Cashier c, Map<String, Integer> items, Map<Goods, Integer> goods) {
                this.c = c;
                this.items = items;
                this.goods = goods;
                cname = c.getName();
        }

        void makeReceipt() throws FileNotFoundException {
                PrintWriter writer = new PrintWriter("receipt-" + cnt + ".txt");
                writer.println("----- " + dtf.format(now) + " -----  Cashier: " + cname + " -----");
                writer.println(c.getShop() + "-Limited" + " --- ID:" + cnt + " -------------------");
                writer.print("\nItems: \n\n");
                for (String s : items.keySet()) {
                        for (Goods g : goods.keySet())
                                if (s == g.getName()) {
                                        writer.print("---------- " + s + "  ||  " + items.get(s) + " X " + g.getPrice()
                                                        + " ----------\n");
                                        total += items.get(s) * g.getPrice();
                                }
                }
                writer.print("\n----- Total: " + total + "lv. -----");
                cnt++;
                writer.close();
                //printReceipt("receipt-" + (cnt--) + ".txt");
              //  System.out.println("booRece");

        }

        void printReceipt(String file) throws FileNotFoundException {
                Scanner output = new Scanner(new FileReader(file));
                while (output.hasNextLine())
                        System.out.println(output.nextLine());

        }
}