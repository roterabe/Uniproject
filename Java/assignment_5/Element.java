
public class Element {
    int weight;
    String name;
    Material material;

    Element(Material material, int weight) {
        this.material = material;
        this.weight = weight;

    }

    void isFragile() {
        if (material.retFragile() == true) {
            System.out.println("The " + name + " is fragile.");
        } else
            System.out.println("The " + name + " is not fragile.");
    }

    public String toString()
    {
        return "Element is made from: " + material.toString() + "and weighs: " + weight + ".kg.";
    }
}