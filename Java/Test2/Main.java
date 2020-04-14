public class Main {
    public static void main(String[] args) {
        Cleaning c = new Cleaning("LOW", 10, 10); // == 120
        Cleaning c1 = new Cleaning("MEDIUM", 10, 10); // == 132
        CleaningCompany comp = new CleaningCompany();
        comp.addService(c);
        comp.addService(c1);
        System.out.println(c1.servicePriceHigh());
        //comp.income();
        //comp.specificIncome("LOW");
        if (c.moreExpensive(c1)) {
            System.out.println("c is more expensive than c1");
        }
    }
}