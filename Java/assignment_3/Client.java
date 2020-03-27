public class Client {
    private int hours;
    //private Studio studio;
    private Muscomp company;

    public Client(int hours) {
        this.hours = hours;
    }

    public int getHours() {
        return hours;
    }

    public void display() {
        System.out.println("Hours to book: " + hours);
    }

 /*   public void rent(Studio studio) {
        this.studio = studio;
        studio.rent(hours);
        int remaining = studio.left();
        if (hours > studio.left()) {
            System.out.println("Unable to rent the studio for: " + hours + " hours.");
            System.out.println("You can rent the studio only for: " + studio.left() + " hours.");
        }
        else
        System.out.println("Successfully rented the studio for: " + hours + " hours.");
    }
*/
    public void rent(Muscomp company) {
        this.company = company;
        company.rentStudio(hours);
        int remaining = company.studioLeft();
        if (hours > remaining) {
            System.out.println("Unable to rent the studio for: " + hours + " hours.");
            System.out.println("You can rent the studio only for: " + remaining + " hours.");
        }
        else
        System.out.println("Successfully rented the studio for: " + hours + " hours.");
    }

}