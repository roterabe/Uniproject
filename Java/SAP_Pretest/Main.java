import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int N = 0;
        String s = "";
        String s1 = "";
        Scanner input = new Scanner(System.in);
        N = Integer.parseInt(input.nextLine());
        s = input.nextLine();
        s1 = input.nextLine();
        char[] sch = s.toCharArray();
        if (N % 2 != 0) {
            for (int i = 0; i < s.length(); i++) {
                sch[i] = (sch[i] == '0') ? '1' : '0';
            }
        }
        s = String.valueOf(sch);
        if (s.equals(s1)) {
            System.out.print("Deletion succeeded");
        } else if (!s.equals(s1)) {
            System.out.print("Deletion failed");
        }
    }
}
