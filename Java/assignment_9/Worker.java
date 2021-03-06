import java.util.ArrayList;

public class Worker extends Thread {
    private final int id;
    private String name;
    private int sewn = 0;
    private int cnt = 0;
    ArrayList<Clothing> clothes = new ArrayList<Clothing>();

    Worker(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public void run() {
        System.out.println("RUNNING...");
        try {
            while (cnt < clothes.size()) {
                if (clothes.get(cnt).getState() == true) {
                    cnt++;
                    continue;
                } else if (clothes.get(cnt).getState() == false) {
                    clothes.get(cnt).sew();
                    cnt++;
                    sewn += 1;
                    System.out.println(this.toString() + " || " + sewn);
                }
            }
            Thread.sleep(100);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("STOPPING...");
    }

    String getNAME() {
        return name;
    }

    void getID() {
        System.out.println("The ID of the worker is: " + id + ".");
    }

    void getClothingPile(ArrayList<Clothing> clothes) {
        this.clothes = clothes;
    }

    int getSewn() {
        return sewn;
    }
}
