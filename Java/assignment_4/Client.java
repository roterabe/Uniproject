
public class Client {
    int money = 0;
    Shop shop;
    Device device;
    Oven oven;
    Washer washer;
    String name;

    Client(String name, int money) {
        this.money = money;
        this.name = name;
    }

    public int getMoney() {
        return money;
    }

    public String getName() {
        return name;
    }

    public void Bought(Device device) {
        this.device = device;
        money = money - device.getPrice();
    }

    public void Bought(Oven oven) {
        this.oven = oven;
        money = money - oven.getPrice();
    }

    public void Bought(Washer washer) {
        this.washer = washer;
        System.out.println(washer.getPrice());
        money = money - washer.getPrice();
    }

    public void display() {
        System.out.println("The client has \"" + money + ".lv\" left.");
    }
}