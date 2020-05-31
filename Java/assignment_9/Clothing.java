public class Clothing {
    private static int id = -1;
    private boolean sewn = false;

    Clothing() {
        id += 1;
    }

    int getID() {
        return id;
    }

    void sew() {
        sewn = true;
    }

    boolean getState() {
        return sewn;    
    }
}