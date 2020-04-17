
public enum Contract {
    PERMANENT(10), PARTTIME(5), TRAINEE(2);
    double inc;

    Contract(double inc) {
        this.inc = inc;
    }

    public double inc() {
        return inc;
    }
}