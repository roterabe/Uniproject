
public class Material {
    boolean fragile;
    String name;

    Material(String name, boolean fragile) {
        this.name = name;
        this.fragile = fragile;
    }

   public String toString(){
        return "Element name: " + name + ". Is fragile?: " + fragile + ".";
    }
}