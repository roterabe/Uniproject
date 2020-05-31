import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        SewingStudio s = new SewingStudio("KrankenWagen");
        Clothing c = new Clothing();
        Clothing c1 = new Clothing();
        Clothing c2 = new Clothing();
        Clothing c3 = new Clothing();
        Clothing c4 = new Clothing();
        Clothing c5 = new Clothing();
        Clothing c6 = new Clothing();
        Worker w = new Worker(12, "Bob");
        Worker w1 = new Worker(10, "Ross");
        Worker w2 = new Worker(13, "Van Gogh");
        s.addWorker(w);
        s.addWorker(w1);
        s.addWorker(w2);

        ArrayList<Clothing> clothes = new ArrayList<Clothing>();
        clothes.add(c);
        clothes.add(c1);
        clothes.add(c2);
        clothes.add(c3);
        clothes.add(c4);
        clothes.add(c5);
        clothes.add(c6);

        s.addClothing(c);
        s.addClothing(c1);
        s.addClothing(c2);
        s.addClothing(c3);
        s.addClothing(c4);
        s.addClothing(c5);
        s.addClothing(c6);

        s.beginSewing();
        System.out.println(w2.getSewn());

    }
}