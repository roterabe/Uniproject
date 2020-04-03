
public class Client {
    int money = 0;
    Shop technopolis;

    Client(int money) {
        this.money = money;
    }

    public void Buy(Shop technopolis) {
        this.technopolis = technopolis;
    }
}