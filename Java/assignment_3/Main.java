public class Main {

    public static void main(String[] args) {
        Director dir = new Director(20, "Dracula");
        Client cl = new Client(3);
        Client cl1 = new Client(6);
        Studio studio1 = new Studio();
        Muscomp company = new Muscomp("Radio1", dir, studio1);
        cl.rent(company);
        cl1.rent(company);
    }
}
