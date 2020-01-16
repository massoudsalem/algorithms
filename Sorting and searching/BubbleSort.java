import java.util.Arrays;

public class BubbleSort {
    public static void bubbleSort(int array[]){
        for(int i = 0; i < array.length; i++)
            for(int j = 0; j < array.length - i - 1; j++){
                if(array[j] > array[j+1])
                    swap(array, j, j+1);
            }
    }
    private static void swap(int[] a, int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    public static void main(String [] args){
        int array[] = {1,5,6,7,2,3,4};
        bubbleSort(array);
        System.out.println(Arrays.toString(array));
    }
}
