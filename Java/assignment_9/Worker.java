import java.util.ArrayList;

public class Worker extends Thread {
    private final int id;
    private String name;
    private int sewn = 0;
    private static int cnt = -1;
    ArrayList<Clothing> clothes = new ArrayList<Clothing>();

    Worker(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public void run() {
        System.out.println("RUNNING...");
        try {
            cnt++;
            while (cnt < clothes.size()) {
                if (clothes.get(cnt).getState() == true) {
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

    void getNAME() {
        System.out.println(name);
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
