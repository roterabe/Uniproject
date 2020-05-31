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
        Worker w = new Worker(12, "Bob Ross");
        Worker w1 = new Worker(10, "Ross Geller");
        Worker w2 = new Worker(13, "Van Gogh");
        s.addWorker(w);
        s.addWorker(w1);
        s.addWorker(w2);

        s.addClothing(c);
        s.addClothing(c1);
        s.addClothing(c2);
        s.addClothing(c3);
        s.addClothing(c4);
        s.addClothing(c5);
        s.addClothing(c6);

        s.beginSewing();
        System.out.println("Worker " + w.getNAME() + " has sewn " + w.getSewn() + " pieces of fabic.");
        System.out.println("Worker " + w1.getNAME() + " has sewn " + w1.getSewn() + " pieces of fabic.");
        System.out.println("Worker " + w2.getNAME() + " has sewn " + w2.getSewn() + " pieces of fabic.");

    }
}