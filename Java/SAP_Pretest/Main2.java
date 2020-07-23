import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main2 {
    public static void main(String[] args) {
        int N, M;
        String e = "";
        String redundant = "";
        String[] line;
        Map<String, Double> royals = new HashMap<String, Double>();
        ArrayList<String> plebians = new ArrayList<String>();
        ArrayList<String> heirs = new ArrayList<String>();
        ArrayList<String> people = new ArrayList<String>();
        ArrayList<String> will = new ArrayList<String>();
        Scanner input = new Scanner(System.in);
        redundant = input.nextLine();
        line = redundant.split(" ");
        N = Integer.parseInt(line[0]);
        M = Integer.parseInt(line[1]);
        e = input.nextLine();
        royals.put(e, 1.0);


        for (int i = 0; i < N; i++) {
            redundant = input.nextLine();
            line = redundant.split(" ");
            will.add(line[0]);
            people.add(line[0]);
            people.add(line[1]);
            people.add(line[2]);
        }
        for (int i = 0; i < people.size()-2; i++){
             e = people.get(i);
             String p = people.get(i + 1);
             String p1 = people.get(i + 2);

             if (will.contains(p) && !royals.containsKey(p)) {
                i += 2;
                continue;
             }

             else if (will.contains(p1) && !royals.containsKey(p1)) {
                i += 2;
                continue;
             }
            else if (!royals.containsKey(p) && royals.containsKey(p1)) {
                plebians.add(p);
                royals.put(e, (royals.get(p1) / 2) + 0);
            } else if (!royals.containsKey(p1) && royals.containsKey(p)) {
                plebians.add(p1);
                royals.put(e, (royals.get(p) / 2) + 0);
            } else if (royals.containsKey(p) && royals.containsKey(p1)) {
                royals.put(e, (royals.get(p) / 2) + (royals.get(p1) / 2));
            } else {
                i += 2;
                continue;
            } 
        }

        /* for (int i = 0; i < people.size(); i++) {
            String curr;
            String w = people.get(i);
            curr = w;
            String p = people.get(i + 1);
            String p1 = people.get(i + 2);
            if (will.contains(p)) {
                while (curr != p){
                i = i + 3;
                w = people.get(i);
                }
            }

        } */
         
            for (int i = 0; i < people.size() - 2; i++) {
                String h = people.get(i);
                String p = people.get(i + 1);
                String p1 = people.get(i + 2);
                if (!royals.containsKey(p) && royals.containsKey(p1)) {
                    royals.replace(h, (royals.get(p1) / 2) + 0);
                } else if (!royals.containsKey(p1) && royals.containsKey(p)) {
                    royals.replace(h, (royals.get(p) / 2) + 0);
                } else if (royals.containsKey(p1) && royals.containsKey(p)) {
                    royals.replace(h, (royals.get(p) / 2) + (royals.get(p1) / 2));
                }
                i = i + 2;
            }

        for (int i = 0; i < M; i++) {
            redundant = input.nextLine();
            heirs.add(redundant);
        }
        double max = 0;
        String heir = "";
        for (int i = 0; i < heirs.size(); i++) {
            if (!royals.containsKey(heirs.get(i)))
                continue;
            double curr = royals.get(heirs.get(i));
            String heir1 = heirs.get(i);
            if (curr > max) {
                max = royals.get(heirs.get(i));
                heir = heir1;
            }
        }
        System.out.println(heir);
    }
}