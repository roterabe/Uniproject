public class Main {
    public static void main(String[] args) {
        Company c = new Company("Tesco", 3);
        Employee e = new Employee("Vik", 40);
        Employee e1 = new Employee("Somedude", 40);
        Employee e2 = new Employee("Wow", 40);
        Employee e3 = new Employee("Generic", 30);
        e.signContract(Contract.PERMANENT);
        e1.signContract(Contract.TRAINEE);
        e2.signContract(Contract.PARTTIME);
        c.hire(e);
        c.hire(e1);
        c.hire(e2);
        System.out.println(c.totalSal());
        System.out.println(c.avgTotalSal());
        c.employees();
        c.raise(e, 10);
        c.incBonus(10);
        c.terminate(e1);
        c.employees();
        c.hire(e1);
        c.hire(e3);
        c.employees();
    }
}