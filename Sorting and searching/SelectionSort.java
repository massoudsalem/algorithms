import java.util.Arrays;

public class SelectionSort {
    public static void selectionSort(int array[]){
        for (int i = 0; i < array.length; i++){
            int minimum = i;
            for (int j = i; j < array.length; j++){
                if(array[minimum] > array[j])
                    minimum = j;
            }
            swap(array, i, minimum);
        }
    }
    private static void swap(int[] a, int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    public static void main(String [] args){
        int array[] = {1,5,6,7,2,3,4};
        selectionSort(array);
        System.out.println(Arrays.toString(array));
    }
}
