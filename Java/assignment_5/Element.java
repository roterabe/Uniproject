
public class Element extends Material {
    int weight;
    String name;
    boolean fragile;
    Material material;

    Element(Material material, String name, boolean fragile, int weight) {
        super(name, fragile);
        this.weight = weight;

    }

    void isFragile() {
        if (fragile == true) {
            System.out.println("The " + name + " is fragile.");
        } else
            System.out.println("The " + name + " is not fragile.");
    }

    public String toString()
    {
        return "Element is made from: " + material.toString() + "and weighs: " + weight + ".kg.";
    }
}