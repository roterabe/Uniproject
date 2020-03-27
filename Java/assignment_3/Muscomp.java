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
        String companyName1 = company.getName();
        if (this.currprice > company.currprice)
            System.out.println(companyName + " is more expensive than " + companyName1);
        else if (this.currprice < company.currprice)
            System.out.println(companyName1 + " is more expensive.");
        else
            System.out.println(companyName + " costs as much as " + companyName1);
    }

    public void compareDir(Muscomp company) {
        String companyName = getName();
        String companyName1 = company.getName();
        if (this.director.getDirectorAge() > company.director.getDirectorAge()) {
            System.out.println(companyName + "'s director is older than " + companyName1 + "'s director.");
        } else if (this.director.getDirectorAge() < company.director.getDirectorAge()) {
            System.out.println(companyName1 + "'s director is older than " + companyName + "'s director.");
        } else {
            System.out.println("Both companies' directors are of equal age.");
        }
    }

    public void changePrice(double price) {
        if (price >= minprice) {
            currprice = price;
            System.out.println("The price for " + getName() + " is " + currprice + ".lv");
        } else {
            currprice = minprice;
            System.out.println("The price cannot be below the minimum. " + "Setting price for " + getName() + " to..: "
                    + currprice + ".lv");
        }
    }

    public void discountPrice(double percent) {
        double discount = currprice * (percent / 100);
        double newprice = currprice - discount;
        if (newprice >= minprice) {
            currprice = newprice;
            System.out.println("The discount gives you " + currprice + ".lv an hour for " + getName() + ".");
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

    public void revenueStatus(int hours) {
        // revenue = (8 - studio.left()) * currprice;
        revenue += hours * currprice;
        System.out.println(compName + " has made " + revenue + ".lv" + " in revenue.");
    }

    public void convertMoney() {
        double money, money1;
        if (revenue > 0) {
            money = revenue / 1.95;
            money1 = revenue / 1.78;
            System.out.println("Revenue in dollars for " + getName() + ": " + String.format("%.2f", money1));
            System.out.println("Revenue in euro for " + getName() + ": " + String.format("%.2f", money));
        } else {
            money = 0;
            money1 = 0;
            System.out.println("Revenue in dollars for " + getName() + ": " + String.format("%.2f", money1));
            System.out.println("Revenue in euro for " + getName() + ": " + String.format("%.2f", money));
        }
    }
}