public class Studio {
    private int workh = 8;

    public Studio() {

    }

    public int rent(int hours) {
        if (hours > workh) {
            System.out.println("The studio has only " + workh + " hours left for the day");
            return 1;
        } else {
            workh -= hours;
            return 0;
        }
    }

    public int left() {
        return workh;
    }

    public void remaining() {
        System.out.println("The studio can be hired for " + left() + " more hours.");
    }
}