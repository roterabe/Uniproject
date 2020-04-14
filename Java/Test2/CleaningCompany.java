import java.util.ArrayList;

public class CleaningCompany {
    ArrayList<Service> s = new ArrayList<Service>();

    CleaningCompany() {

    }

    void addService(Service ser) {
        s.add(ser);
    }

    void income() {
        double inc = 0;
        for (int i = 0; i < s.size(); i++) {
            inc += s.get(i).servicePrice();
        }
        System.out.println("The total income of the company is: " + inc + ".lv.");
    }

    void specificIncome(String priority) {
        double inc = 0;
        for (int i = 0; i < s.size(); i++) {
            if (priority == s.get(i).priority) {
                inc += s.get(i).servicePrice();
            }
        }
        System.out.println(inc);
    }
}