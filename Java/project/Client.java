public class Client {
    String name = "";
    double money = 0;

    Client(String name, double money){
        this.name = name;
        this.money = money;
    }

    void Buy(Shop s, String item){
        s.sell(item);
    }
}