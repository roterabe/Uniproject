public class Muscomp {
    private Director director;
    private Studio studio;
    private Client client;
    private static double minprice = 10;
    private double price = 25;

    Muscomp() {

    }

    public Muscomp(Director director, Studio studio) {
        this.director = director;
        this.studio = studio;
    }
}