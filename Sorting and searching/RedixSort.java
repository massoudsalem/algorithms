import java.util.*;

public class RedixSort {

    static void radixSort(int array[]){
        LinkedList[] buckets = new LinkedList[10];
        for (int i = 0; i < 10; i++) {
            buckets[i] = new LinkedList<Integer>();
        }
        int numberOfDigits = getNumberOfDigits(array);
        for (int i = 0; i < numberOfDigits; i++) {
            for (int element : array) {
                int digit = element / (int) Math.pow(10, i);
                digit %= 10;
                buckets[digit].addFirst(element);
            }
            int x = 0;
            for (int k = 0; k < 10; k++) {
                while (!buckets[k].isEmpty()) {
                    array[x] = (int)buckets[k].removeLast();
                    x++;
                }
            }
        }
    }

    private static int getNumberOfDigits(int array[]) {
        //getting max
        int maxElement = Integer.MIN_VALUE;
        for (int element : array) {
            if (maxElement < element) {
                maxElement = Math.max(maxElement, element);
            }
        }
        int numberOfDigits = 0;
        while (maxElement > 0) {
            numberOfDigits++;
            maxElement /= 10;
        }
        return numberOfDigits;
    }
    public static void main(String [] args){
        int array[] = {1000,54,698,667,92,37,43};
        radixSort(array);
        System.out.println(Arrays.toString(array));
    }
}