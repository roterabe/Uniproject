import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.time.format.DateTimeFormatter;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.time.LocalDateTime;

public class Receipt {
        String cname;
        static int cnt = 0;
        double total = 0;
        Map<String, Integer> items = new HashMap<String, Integer>();
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();

        Receipt(String cname, Map<String, Integer> items, Map<Goods, Integer> goods) throws FileNotFoundException {
                this.cname = cname;
                this.items = items;
                PrintWriter writer = new PrintWriter("receipt-" + cnt + ".txt");
                writer.println("---------------------------------------");
                writer.println("Test-receipt-" + cnt + "--------------------------");
                writer.print("Items: ");
                for (String s : items.keySet())
                        for (Goods g : goods.keySet())
                                if (s == g.name)
                                        writer.print(s + "  ||  " + items.get(s) + " X " + g.getPrice() + "\n");
                cnt++;
                writer.close();
        }

        void makeReceipt() {

        }
}