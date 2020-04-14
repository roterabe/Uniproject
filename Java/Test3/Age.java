
public enum Age {
    ADULTS(20), TEENAGERS(10), CHILDREN(0);

    double add;

    Age(double add) {
        this.add = add;
    }

    public double add() {
        return add;
    }
}