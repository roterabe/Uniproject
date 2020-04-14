import java.util.ArrayList;

public class MinistryOfEducation {
    ArrayList<DigitalResource> resource = new ArrayList<DigitalResource>();

    MinistryOfEducation() {

    }

    void addDigitalResource(DigitalResource d) {
        resource.add(d);
    }

    void allTime() {
        int time = 0;
        for (int i = 0; i < resource.size(); i++) {
            time += resource.get(i).totalTime();
        }
        System.out.println("The total time needed for all classes is: " + time);
    }

    void classTime(String type) {
        int time = 0;
        for (int i = 0; i < resource.size(); i++) {
            if (resource.get(i).type == type){
                time += resource.get(i).totalTime();
            }
        }
    }
}