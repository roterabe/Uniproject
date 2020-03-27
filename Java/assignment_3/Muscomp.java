public class Muscomp {
    String compName = "";
    private Director director;
    private Studio studio;
    private Client client;
    private static double minprice = 10;
    private double currprice = 25;
    private double revenue = 0;

    Muscomp() {

    }

    public Muscomp(String compName, Director director, Studio studio) {
        this.director = director;
        this.studio = studio;
        this.compName = compName;
    }

    public String getName() {
        return compName;
    }

    public void compareComp(Muscomp company) {
        String companyName = getName();
        String companyName2 = company.getName();
        if (this.currprice > company.currprice)
            System.out.println(companyName + " is more expensive than " + companyName2);
        else if (this.currprice < company.currprice)
            System.out.println(companyName2 + " is more expensive.");
        else
            System.out.println(companyName + " costs as much as " + companyName2);
    }

    public void changeValue(double price) {
        if (price >= minprice) {
            currprice = price;
            System.out.println("The price is " + currprice + ".lv");
        } else {
            currprice = minprice;
            System.out.println("The price cannot be below the minimum. " + "Setting to..: " + currprice + ".lv");
        }
    }

    public void discountPrice(double percent) {
        double discount = currprice * (percent / 100);
        double newprice = currprice - discount;
        if (newprice >= minprice) {
            currprice = newprice;
            System.out.println("The discount gives you " + currprice + ".lv an hour.");
        } else {
            currprice = minprice;
            System.out.println(
                    "The discounted price for you would be " + currprice + ".lv. I can't go any lower than that.");
        }
    }

    public int rentStudio(int hours) {
        return studio.rent(hours);
    }

    public int studioLeft() {
        return studio.left();
    }

    public void revenueStatus() {
        revenue = (8 - studio.left()) * currprice;
        System.out.println(compName + " has made " + revenue + ".lv" + " in revenue.");
    }

    public void convertMoney() {
        double money, money1;
        if (revenue > 0) {
            money = revenue / 1.95;
            money1 = revenue / 1.78;
            System.out.println("Revenue in dollars: " + String.format("%.2f", money1));
            System.out.println("Revenue in euro: " + String.format("%.2f", money));
        } else {
            money = 0;
            money1 = 0;
            System.out.println("Revenue in dollars: " + String.format("%.2f", money1));
            System.out.println("Revenue in euro: " + String.format("%.2f", money));
        }
    }
}