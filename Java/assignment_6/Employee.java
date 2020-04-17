
public class Employee {
    private String name;
    private final int id;
    private static int cnt = 0;
    private double hoursMonth = 0;
    private double minsal = 0;
    private double bonus = 0;

    Employee(String name, double hoursMonth) {
        this.name = name;
        this.hoursMonth = hoursMonth;
        cnt += 1;
        id = cnt;
    }

    double salary() {
        double res = 0;
        res = (minsal + bonus) * hoursMonth;
        if (res == 0) {
            System.out.println("The employee has not worked or has no contract.");
            return -1;
        }
        return res;
    }

    void signContract(Contract c) {
        minsal = c.inc();
        bonus = minsal / 2;
    }

    void incBonus(double percent) {
        if (bonus == 0) {
            System.out.println("Unable to raise bonus by percentage since the employee has no bonus to begin with.");
        }
        else if (bonus > 0)
        bonus = bonus + bonus * (percent / 100);
    }

    String getName() {
        return name;
    }

    public String toString() {
        return name + " - id: " + id + " makes " + salary() + ".lv a month." + " The minimum hourly salary is " + minsal
                + ".lv. The employee also has a bonus of " + bonus + ".lv an hour. The employee works for " + hoursMonth + " hours a month.";
    }

}