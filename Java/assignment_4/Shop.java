
public class Shop {
    Device device;
    Oven oven;
    Washer washer;
    String name;
    Client client;

    Shop(String name) {
        this.name = name;
    }

    void Sell(Client client, Device device) {
        this.client = client;
        this.device = device;
        int price = device.getPrice();
        int money = client.getMoney();
        if (money < price) {
            System.out.println(
                    "Warning! ..." + "\"" + client.getName() + "\"" + " is unable to buy (" + device.toString() + ")");
            System.out.println("You need " + (price - money) + ".lv more in order to buy this product.");
        } else if (money >= price) {
            client.Bought(device);
            System.out.println("The client " + "\"" + client.getName() + "\"" + " has bought from " + name + " a ("
                    + device.toString() + ")." + "The guarantee period is " + device.guaranteePeriod() + " months.");
        }
    }

    void Sell(Client client, Oven oven) {
        this.client = client;
        this.oven = oven;
        int price = oven.getPrice();
        int money = client.getMoney();
        if (money < price) {
            System.out.println(
                    "Warning! ..." + "\"" + client.getName() + "\"" + " is unable to buy (" + oven.toString() + ")");
            System.out.println("You need " + (price - money) + ".lv more in order to buy this product.");
        } else if (money >= price) {
            client.Bought(oven);
            System.out.println("The client " + "\"" + client.getName() + "\"" + " has bought from " + name + " a ("
                    + oven.toString() + ")." + "The guarantee period is " + oven.guaranteePeriod() + " months.");
        }
    }

    void Sell(Client client, Washer washer) {
        this.client = client;
        this.washer = washer;
        int price = washer.getPrice();
        int money = client.getMoney();
        if (money < price) {
            System.out.println(
                    "Warning! ..." + "\"" + client.getName() + "\"" + " is unable to buy (" + washer.toString() + ")");
            System.out.println("You need " + (price - money) + ".lv more in order to buy this product.");
        } else if (money >= price) {
            client.Bought(washer);
            System.out.println("The client " + "\"" + client.getName() + "\"" + " has bought from " + name + " a ("
                    + washer.toString() + ")." + "The guarantee period is " + washer.guaranteePeriod() + " months.");
        }
    }

    String getName() {
        return name;
    }
}