import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Vector;
import java.time.format.DateTimeFormatter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDateTime;
import java.util.concurrent.ThreadLocalRandom;

public class Receipt {
        private String cname;
        private Cashier c;
        private double total = 0;
        private int counter = 0;
        private Vector<String> receipts = new Vector<String>();
        private DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss");
        private LocalDateTime now = LocalDateTime.now();
        private int randomNum = 0;

        Receipt(Cashier c) {
                this.c = c;
                cname = c.getName();
        }

        synchronized void writeReceipt(Map<Goods, Integer> goods, ArrayList<Map<String, Integer>> queue1, int id)
                        throws IOException {
                randomNum = ThreadLocalRandom.current().nextInt(1, 100 + 1);
                addR("receipt-" + id + randomNum + ".txt");
                File receipt = new File("receipt-" + id + randomNum + ".txt");
                FileWriter writer = new FileWriter(receipt.getAbsoluteFile());

                writer.write("----- " + dtf.format(now) + " -----  Cashier: " + cname + " -----\n");
                writer.write(c.getShop() + "-Limited" + " --- ID:" + id + randomNum + " -------------------\n");
                writer.write("\nItems: \n\n");
                for (String s : queue1.get(counter).keySet()) {
                        for (Goods g : goods.keySet())
                                if (s == g.getName()) {
                                        writer.write("---------- " + s + "  ||  " + queue1.get(counter).get(s) + " X "
                                                        + g.getPrice() + "lv ----------\n");
                                        total += queue1.get(counter).get(s) * g.getPrice();
                                }
                }
                writer.write("\n----- Total: " + total + "lv. -----");
                writer.close();
                counter += 1;
        }

        void printReceipt(String file) throws FileNotFoundException {
                Scanner output = new Scanner(new FileReader(file));
                while (output.hasNextLine())
                        System.out.println(output.nextLine());

        }

        private void addR(String text) {
                receipts.add(text);
        }

        Vector<String> retR() {
                if (receipts.size() > 0)
                        return receipts;
                else {
                        String empty = "Empty";
                        receipts.add(empty);
                        return receipts;
                }
        }
}