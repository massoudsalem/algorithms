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

    static void buildAdjList(){
        for(int i = 0; i < adjList.length; i++)
            adjList[i] = new ArrayList<>();
        adjList[0].add(1);
        adjList[1].add(0);
        adjList[0].add(2);
        adjList[1].add(3);
        adjList[3].add(1);
        adjList[1].add(4);
        adjList[4].add(1);
        adjList[2].add(5);
        adjList[5].add(2);
        adjList[2].add(6);
        adjList[6].add(2);
        adjList[7].add(3);
        adjList[3].add(7);
        adjList[7].add(4);
        adjList[4].add(7);
        adjList[7].add(5);
        adjList[5].add(7);
        adjList[7].add(6);
        adjList[6].add(7);
    }

    static void buildAdjMatrix(){
        adjMatrix[0][1] = true;
        adjMatrix[1][0] = true;
        adjMatrix[0][2] = true;
        adjMatrix[1][3] = true;
        adjMatrix[3][1] = true;
        adjMatrix[1][4] = true;
        adjMatrix[4][1] = true;
        adjMatrix[2][5] = true;
        adjMatrix[5][2] = true;
        adjMatrix[2][6] = true;
        adjMatrix[6][2] = true;
        adjMatrix[7][3] = true;
        adjMatrix[3][7] = true;
        adjMatrix[7][4] = true;
        adjMatrix[4][7] = true;
        adjMatrix[7][5] = true;
        adjMatrix[5][7] = true;
        adjMatrix[7][6] = true;
        adjMatrix[6][7] = true;
    }

    static void buildGraph(){
        buildAdjList();
        buildAdjMatrix();
    }

    public static void main(String args[]){
        buildGraph();

        uncheckVisted();
        DFT(0);
        System.out.println();
        uncheckVisted();
        BFT(0);
        System.out.println();
    }

}
