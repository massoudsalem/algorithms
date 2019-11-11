import java.util.Arrays;

public class QuickSort {
    static void quickSort(int array[], int start, int end){
        if(start >= end)
            return;
        int pivotIndex = partition(array, start, end);
        quickSort(array, start, pivotIndex-1);
        quickSort(array, pivotIndex+1, end);
    }
    private static void swap(int[] a, int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    private static int partition(int[] array, int start, int end) {
        int pivot = array[end];
        int pivotIndex = start;
        for(int i = start; i < end; i++){
            if(array[i] <= pivot){
                swap(array, i, pivotIndex);
                pivotIndex++;
            }
        }
        swap(array, pivotIndex, end);
        return pivotIndex;
    }
    public static void main(String [] args){
        int array[] = {1,5,6,7,2,3,4};
        quickSort(array, 0, array.length-1);
        System.out.println(Arrays.toString(array));
    }
}
