public class Client {
    int hours;
    int cost;

    public Client(int hours) {
        this.hours = hours;
    }

    public int getHours() {
        return hours;
    }

    public void display() {
        System.out.println("Hours to book: " + hours);
    }

}