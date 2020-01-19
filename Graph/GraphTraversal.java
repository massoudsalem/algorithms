import java.util.*;

public class GraphTraversal {
    static ArrayList<Integer>[] adjList = new ArrayList[10];
    static boolean adjMatrix[][] = new boolean [10][10];
    static boolean visted[] = new boolean[10];

    static void uncheckVisted(){
        for(int i = 0; i < visted.length; i++)
            visted[i] = false;
    }

    static void DFT(int source){
        visted[source] = true;
        System.out.print(source + " ");

        // in case of adjacency matrix usage switch these loops
        /*for(int i = 0; i < adjMatrix[source].length; i++)
            if(adjMatrix[source][i]&&!visted[i])
                DFT(i);*/
        for(int v : adjList[source])
            if(!visted[v])
                DFT(v);
    }

    static void BFT(int source){
        visted[source] = true;

        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(source);
        while (!queue.isEmpty()){
            int top = queue.remove();
            System.out.print(top + " ");
            // in case of adjacency list usage switch these loops
            for(int i = 0; i < adjMatrix[top].length; i++)
                if(adjMatrix[top][i] && !visted[i]){
                    visted[i] = true;
                    queue.add(i);
                }
            /*for (int v : adjList[top]){
                if(!visted[v]){
                    visted[v] = true;
                    queue.add(v);
                }
            }*/
        }
    }

}
