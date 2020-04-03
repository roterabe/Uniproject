public class Main {

    public static void main(String[] args) {
        Manufacturer sony = new Manufacturer("Sony", true);
        Manufacturer panasonic = new Manufacturer("Panasonic", false);
        Shop technopolis = new Shop("Technopolis");
        Shop technomarket = new Shop("Technomarket");
        Device toothbrush = new Device(sony, 6, 100);
        Washer pan = new Washer(panasonic, 100, "yes", 6, 200);
        Washer son = new Washer(sony, 100, "none", 6, 200);
        Oven pan1 = new Oven(sony, "gas", 6, 150);
        Oven son1 = new Oven(sony, "electric", 6, 150);
        Client vik = new Client("vik", 200);
        Client ros = new Client("ros", 150);
        Client ris = new Client("ris", 100);
        technopolis.Sell(vik, pan);
        vik.display();
        technomarket.Sell(vik, pan1);
        technomarket.Sell(ros, son1);
        ros.display();
        technopolis.Sell(ris, toothbrush);
        ris.display();
    }
}