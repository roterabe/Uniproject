import jdk.dynalink.support.ChainedCallSite;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main1 {
    public static void main(String[] args) {
        double val = 0;
        String line = "";
        ArrayList<String> units = new ArrayList<String>();
        units.add("thou");
        units.add("inch");
        units.add("foot");
        units.add("yard");
        units.add("chain");
        units.add("furlong");
        units.add("mile");
        units.add("league");
        double[] vals = { 1.0, 1000.0, 12.0, 3.0, 22.0, 10.0, 8.0, 3.0 };

        String unit, unit1;

        Scanner input = new Scanner(System.in);
        val = input.nextDouble();
        line = input.nextLine();
        String[] data = line.split(" ");
        unit = data[1];
        if (unit.length() < 4)
            switch (unit) {
                case "in":
                    unit = "inch";
                    break;
                case "ft":
                    unit = "foot";
                    break;
                case "yd":
                    unit = "yard";
                    break;
                case "mi":
                    unit = "mile";
                    break;
                case "th":
                    unit = "thou";
                    break;
                case "lea":
                    unit = "league";
                    break;
                case "ch":
                    unit = "chain";
                    break;
                case "fur":
                    unit = "furlong";
                    break;
            }
        unit1 = data[data.length - 1];
        if (unit1.length() < 4)
            switch (unit1) {
                case "in":
                    unit1 = "inch";
                    break;
                case "ft":
                    unit1 = "foot";
                    break;
                case "yd":
                    unit1 = "yard";
                    break;
                case "mi":
                    unit1 = "mile";
                    break;
                case "th":
                    unit1 = "thou";
                    break;
                case "lea":
                    unit1 = "league";
                    break;
                case "ch":
                    unit1 = "chain";
                    break;
                case "fur":
                    unit1 = "furlong";
                    break;
            }
        // String c = "";
        // c = unit + "_" + unit1;
        // System.out.println();
        int pos = units.indexOf(unit);
        int pos1 = units.indexOf(unit1);
        if (pos1 > pos) {
            for (int i = pos + 1; i <= pos1; i++) {
                val = val / vals[i];
            }
        }
        if (pos1 < pos) {
            for (int i = pos; i > pos1; i--) {
                val = val * vals[i];
            }
        }

        System.out.print(val);

    }
}