package Generics;

public class OverloadedMethods {
    public static void printArray(int[] inputArray){
        for(Integer element:inputArray) {
            System.out.print(element+" ");
        }
        System.out.println();
    }
    public static void printArray(double[] inputArray){
        for(Double element:inputArray) {
            System.out.print(element+" ");
        }
        System.out.println();
    }
    public static void printArray(char[] inputArray){
        for(Character element:inputArray) {
            System.out.print(element+" ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] integerArray={1,2,3,4,5,6};
        double[] doubleArray={1.1,2.2,3.3,4.4,5.5,6.6};
        char[] characterArray={'H','E','L','L','O'};
        System.out.println("Array integerArray contains:");
        printArray(integerArray);
        System.out.println("Array doubleArray contains:");
        printArray(doubleArray);
        System.out.println("Array characterArray contains:");
        printArray(characterArray);
    }
}