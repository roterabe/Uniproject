public class Main {
    public static void main(String[] args) {
        Pharmacy p = new Pharmacy("Optima");
        Medicine m = new Medicine("analgin", 112233, 5, Age.TEENAGERS, "insured");
        Medicine m1 = new Medicine("validol", 223344, 20, Age.ADULTS, "not insured");
        Medicine m2 = m.isLessExpensive(m1);
        Medicine m3 = new Medicine("martians", 9090, 10, Age.CHILDREN, "not insured");
        Medicine.healthInsurance(10);
        p.addItem(m);
        p.addItem(m1);
        p.addItem(m3);
        p.income();
        p.incomeByAge(Age.ADULTS);
        System.out.println(m.toString());
        if (m3.forChildren()) {
            System.out.println("The medicine \"" + m3.name + "\" is suitable for child consumption.");
        }
    }
}