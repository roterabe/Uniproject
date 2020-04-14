public class Main {
    public static void main(String[] args) {
        MinistryOfEducation m = new MinistryOfEducation();
        VideoClass v = new VideoClass(12345, "mathematics", 3);
        VideoClass v1 = new VideoClass(54321, "geography", 1);
        v.incPercent(10);
        double t = v.totalTime();
        System.out.println(t);
        m.addDigitalResource(v);
        m.addDigitalResource(v1);
        m.allTime();
        if (v.isMath()){
            System.out.println("Tis math.");
        }

    }
}