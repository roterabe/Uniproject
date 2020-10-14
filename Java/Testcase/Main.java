import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        //int a = 0;
        //int temp = 0;
        //int ans = 0;
        String test = "";
        Scanner in = new Scanner(System.in);
        //a = in.nextInt();
        test = in.nextLine();
        char[] ex = test.toCharArray();

        for (int i = test.length()-1; i >= 0; i--) {
            System.out.print(ex[i]);
        }
        /* while (a != 0) {
            ans = a % 10;
            temp = temp * 10 + ans;
            a /= 10;
        }

        System.out.println(temp); */
    }
}