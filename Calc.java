import java.util.Scanner;

public class Calc{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char choice;
        do {
            System.out.print("Enter first number: ");
            double a = sc.nextDouble();
            System.out.print("Enter operator (+, -, *, /): ");
            char op = sc.next().charAt(0);
            System.out.print("Enter second number: ");
            double b = sc.nextDouble();

            double result = 0;
            switch (op) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': 
                    if (b != 0) result = a / b;
                    else System.out.println("Can't divide by 0.");
                    break;
                default: System.out.println("Invalid operator");
            }

            System.out.println("Result: " + result);
            System.out.print("Do you want to continue? (y/n): ");
            choice = sc.next().charAt(0);
        } while (choice == 'y' || choice == 'Y');
    }
}
