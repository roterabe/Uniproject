
public class Element {
    int weight;
    String name;
    Material material;

    Element(Material material, int weight) {
        this.material = material;
        this.weight = weight;

    }

    boolean isFragile() {
        if (material.retFragile() == true) {
            return true;
        } else
            return false;
    }

    String getName(){
        return material.getName();
    }

    int getWeight(){
        return weight;
    }

    public String toString()
    {
        return "Element is made from: " + material.toString() + "and weighs: " + weight + ".kg.";
    }
}