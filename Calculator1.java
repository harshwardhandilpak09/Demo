import java.util.*;

class Calculator {

    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }

    double add(double a, double b) {
        return a + b;
    }
}

public class Calculator1 {
    public static void main(String[] args) {
        Calculator calc = new Calculator();
        Scanner sc = new Scanner(System.in);

        int choice;

        do {
            System.out.println("\n===== Calculator Menu =====");
            System.out.println("1. Add two integers");
            System.out.println("2. Add three integers");
            System.out.println("3. Add two double values");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");

            choice = sc.nextInt();

            switch(choice){
                case 1: 
                    System.out.print("Enter first integer: ");
                    int a = sc.nextInt();
                    System.out.print("Enter second integer: ");
                    int b = sc.nextInt();
                    System.out.println("Result: " + calc.add(a, b));
                    break;

                case 2:
                    System.out.print("Enter first integer: ");
                    int x = sc.nextInt();
                    System.out.print("Enter second integer: ");
                    int y = sc.nextInt();
                    System.out.print("Enter third integer: ");
                    int z = sc.nextInt();
                    System.out.println("Result: " + calc.add(x, y, z));
                    break;

                case 3:
                    System.out.print("Enter first double: ");
                    double d1 = sc.nextDouble();
                    System.out.print("Enter second double: ");
                    double d2 = sc.nextDouble();
                    System.out.println("Result: " + calc.add(d1, d2));
                    break;

                case 4:
                    System.out.println("Exiting program...");
                    break;

                default:
                    System.out.println("Invalid choice! Please select 1-4.");
            }

        } while (choice != 4);

        sc.close();
    }
}