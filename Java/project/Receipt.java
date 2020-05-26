import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.time.format.DateTimeFormatter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDateTime;

public class Receipt {
        String cname;
        Cashier c;
        //static int cnt = 0;
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

        /* void makeReceipt() throws FileNotFoundException {
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
                System.out.println(items.toString());
                writer.close();
                // printReceipt("receipt-" + (cnt) + ".txt");
                cnt++;
                for (String s : items.keySet()) {
                        for (Goods g : goods.keySet())
                                if (s == g.getName()) {
                                        System.out.println("---------- " + s + "  ||  " + items.get(s) + " X "
                                                        + g.getPrice() + " ----------\n");
                                        total += items.get(s) * g.getPrice();
                                }

                }
        } */

        void writeReceipt(int cnt) throws IOException {
                System.out.println(cnt);
                File receipt = new File("receipt-" + cnt + ".txt");
                FileWriter writer = new FileWriter(receipt.getAbsoluteFile(), true);

                writer.write("----- " + dtf.format(now) + " -----  Cashier: " + cname + " -----\n");
                writer.write(c.getShop() + "-Limited" + " --- ID:" + cnt + " -------------------\n");
                writer.write("\nItems: \n\n");
                for (String s : items.keySet()) {
                        for (Goods g : goods.keySet())
                                if (s == g.getName()) {
                                        writer.write("---------- " + s + "  ||  " + items.get(s) + " X " + g.getPrice()
                                                        + " ----------\n");
                                        total += items.get(s) * g.getPrice();
                                }
                }
                writer.write("\n----- Total: " + total + "lv. -----");
                System.out.println(items.toString());
                writer.close();
                cnt++;
        }

        void printReceipt(String file) throws FileNotFoundException {
                Scanner output = new Scanner(new FileReader(file));
                while (output.hasNextLine())
                        System.out.println(output.nextLine());

        }
}