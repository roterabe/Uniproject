
public class Shop {
    Client client;
    Device device;
    Oven oven;
    Washer washer;

    Shop() {

    }

    void Buy(Client client, Device device) {
        this.client = client;
        this.device = device;
    }

    void Buy(Client client, Oven oven) {
        this.client = client;
        this.oven = oven;
    }

    void Buy(Client client, Washer washer) {
        this.client = client;
        this.washer = washer;
    }
}