public class DigitalResource {
    final int unique;
    String type;
    double time;

    DigitalResource(int unique, String type, double time) {
        this.unique = unique;
        this.type = type;
        this.time = time;
        if (type != "mathematics" && type != "biology" && type != "geography") {
            System.out.println("The class is math. Don't avoid math just because you dislike it.");
            this.type = "mathematics";
        }
    }

    double totalTime() {
        double r = 0;
        double timing = 0;
        if (type == "mathematics") {
            timing = 3;
            r = time + timing;
            return r;
        } else if (type == "biology") {
            timing = 2;
            r = time + timing;
            return r;
        } else if (type == "geography") {
            timing = 1;
            r = time + timing;
            return r;
        }
        return r;
    }

    boolean isMath() {
        if (type == "mathematics") {
            return true;
        }
        return false;
    }

    double slowerThan(DigitalResource r) {
        if (totalTime() < r.totalTime()) {
            return totalTime();
        } else if (r.totalTime() < totalTime()) {
            return r.totalTime();
        }
        return -1;
    }
}

class VideoClass extends DigitalResource {
    double percent = 0;

    VideoClass(int unique, String type, double time) {
        super(unique, type, time);
    }

    double incPercent(double percent) {
        this.percent = percent;
        return this.percent;
    }

    @Override
    double totalTime() {
        return super.totalTime() + super.totalTime() * percent / 100;
    }

    double slowerVid(VideoClass v) {
        if (totalTime() < v.totalTime()) {
            System.out.println("The " + type + " class is slower than the " + v.type + " class.");
            return totalTime();
        } else if (v.totalTime() < totalTime()) {
            System.out.println("The " + v.type + " class is slower than the " + type + " class.");
            return v.totalTime();
        }
        return -1;
    }

    @Override
    boolean isMath(){
        return super.isMath();
    }

}