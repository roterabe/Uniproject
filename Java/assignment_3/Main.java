public class Main {

    public static void main(String[] args) {
        Director dir = new Director(20, "Rosi");
        Client vik = new Client(3);
        Client ros = new Client(6);
        Studio studio1 = new Studio();
        Muscomp company = new Muscomp("Radio1", dir, studio1);
        vik.rent(company);
        ros.rent(company);
    }
}
