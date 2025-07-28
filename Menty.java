import java.util.Scanner;

public class Menty{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter ur name ");
        String Name = sc.nextLine();
        System.out.print("Enter your age ");
        int Age = sc.nextInt();

        System.out.println("Your name is " + Name + " and age is "+ Age);
    }
}