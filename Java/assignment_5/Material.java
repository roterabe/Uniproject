
public class Material {
    boolean fragile;
    String name;

    Material(String name, boolean fragile) {
        this.name = name;
        this.fragile = fragile;
    }

    boolean retFragile() {
        if (fragile == true) {
            return true;
        } else
            return false;
    }

    String getName() {
        return name;
    }

    public String toString() {
        return "Element name: " + name + ". Is fragile?: " + fragile + ".";
    }
}