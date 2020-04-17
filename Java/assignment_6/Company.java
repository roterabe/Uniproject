import java.util.ArrayList;

public class Company {
    String name;
    int maxEmp = 0;
    ArrayList<Employee> emp = new ArrayList<Employee>();

    Company(String name, int maxEmp) {
        this.name = name;
        this.maxEmp = maxEmp;
    }

    void hire(Employee e) {
        if (emp.size() < maxEmp) {
            emp.add(e);
        } else
            System.out.println("You cannot hire any new employees!");
    }

    void terminate(Employee e) {
        if (emp.size() > 0) {
            emp.remove(e);
            System.out.println("Terminated: " + e.getName() + ".");
        } else
            System.out.println("No employees to terminate.");
    }

    void employees() {
        for (Employee e : emp) {
            System.out.println(e.toString());
        }
    }

    double totalSal() {
        double total = 0;
        for (Employee e : emp) {
            total += e.salary();
        }
        return total;
    }

    double avgTotalSal() {
        double avg = 0;
        avg = totalSal() / emp.size();
        return avg;
    }

    void raise(Employee e, double percent) {
        e.incBonus(percent);
        System.out.println("The employee: " + e.getName() + " now receives: " + e.salary() + ".lv a month.");
    }

    void incBonus(double percent) {
        if (emp.size() == 0) {
            System.out.println("No employees to receive new bonus");
        }
        else {
            for (Employee e : emp) {
                e.incBonus(percent);
                System.out.println("The employee: " + e.getName() + " now receives: " + e.salary() + ".lv a month.");
            }
        }
    }

}