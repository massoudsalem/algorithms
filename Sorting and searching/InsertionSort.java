import java.util.Arrays;

public class InsertionSort {
    public static void insertionSort(int [] array){
        for(int i = 1; i < array.length; i++){
            int j = i, temp = array[i];
            while (j > 0 && array[j - 1] >= temp){
                array[j] = array[j-1];
                j--;
            }
            array[j] = temp;
        }
    }
    private static void swap(int[] a, int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    public static void main(String [] args){
        int array[] = {1,5,6,7,2,3,4};
        insertionSort(array);
        System.out.println(Arrays.toString(array));
    }
}
