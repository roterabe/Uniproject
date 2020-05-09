public class Goods {
    final int id;
    String name = "";
    double price = 0;
    String expiration_date = "";

    Goods(int id, String name, double price, String expiration_date){
        this.id = id;
        this.name = name;
        this.price = price;
        this.expiration_date = expiration_date;
    }
}