public class Manufacturer {
    String name;
    boolean g;
    int gur = 0;

    Manufacturer(String name, boolean g) {
        this.name = name;
        this.g = g;
        if (this.g == true) {
            gur = 12;
        } else
            gur = 0;
    }

    String getName() {
        return name;
    }

    int getExt() {
        return gur;
    }

}