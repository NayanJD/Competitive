// Xenny, the traveller, was in AlgoLand for vacation. He wanted to travel from city U to city V. 
// Being quite an explorer, he wanted to travel exactly once by roadways as well as by railways.
// Xenny should start from city U and go to some city Z by roadways only. He can traverse one or more than one edges 
// between U and Z by road. From city Z, he must go to city V by railways only. He can use railways one or more than 
// one times between city Z and city V.
// Or, he can also go from city U to city Z by railways only and then from city Z to city V by roadways only.
// The distance of all cities was known to him, since he had a map that showed not only the paths connecting all cities
//  with roadways, but it also showed all paths connecting all cities with railways.
// Since Xenny is now old and slow at calculation, help him find the minimum total distance he must travel, so that he
//  goes from city U to city V, and travels by both - roadways as well as railways, exactly once.

// Input
// First line contains a single integer N - the number of cities in AlgoLand.
// N lines follow, each containing N space-separated natural numbers.
// These N lines represent the roadways distance-matrix of size N x N. Aij represents the length of the road from city i to city j.
// N more lines follow, each containing N space-separated natural numbers.
// These N lines represent the railways distance-matrix of size N x N. Bij represents the length of the railway from city i to city j.
// The last line contains 2 space-separated integers - U and V - the starting and ending points respectively.

// Output
// Print a single natural number - the minimum distance Xenny must travel to satisfy the above-mentioned criteria.

// Constraints
// 3 ≤ N ≤ 1250
// 0 ≤ Aij, Bij ≤ 100
// 1 ≤ U, V ≤ N
// U ≠ V

// SAMPLE INPUT 
// 3
// 0 1 2
// 3 0 4
// 5 6 0
// 0 6 5
// 1 0 4
// 3 2 0
// 1 2
//
// SAMPLE OUTPUT 
// 4
//
// Explanation
// Xenny can go from 1 to 3 by roadway, and 3 to 2 by railway.
// Distance between 1 and 3 by roadway = 2
// Distance between 3 and 2 by railway = 2
// Total distance travelled = 4
//
// Below is an O(V^3) solution using Floyd-Warshall Algo.
// A better O(ElogV) solution also exists using Dijkstra and reverse Dijkstra algorithm.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






import java.io.*;
import java.util.*;

class TestClass {

    public static int[][] floyd(int[][] graph){
        int[][] dist=new int[graph.length][graph.length];

        for(int i=0;i<graph.length;i++){
            for(int j=0;j<graph.length;j++){
                if(graph[i][j]==0)
                    dist[i][j]=1000000000;
                else
                    dist[i][j]=graph[i][j];
            }
        }

        for (int k=0;k<graph.length;k++){
            for(int i=0;i<graph.length;i++){
                for(int j=0;j<graph.length;j++){
                    if(i==j)
                        continue;
                    if(dist[i][j]>dist[i][k]+dist[k][j])
                        dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }

        return dist;
    }
    public static void main(String args[] ) throws Exception {
       BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

       String[] str=null;
       int N=Integer.parseInt(br.readLine());

       int[][] roadgraph=new int[N][N];
       for(int i=0;i<N;i++){
            str=br.readLine().split(" ");
            for(int j=0;j<N;j++){
                roadgraph[i][j]=Integer.parseInt(str[j]);
            }
       }

       int[][] railgraph=new int[N][N];
       for(int i=0;i<N;i++){
            str=br.readLine().split(" ");
            for(int j=0;j<N;j++){
                railgraph[i][j]=Integer.parseInt(str[j]);
            }
       }

       str=br.readLine().split(" ");

       int src=Integer.parseInt(str[0])-1;
       int dest=Integer.parseInt(str[1])-1;

       int[][] roaddist=floyd(roadgraph);
       int[][] raildist=floyd(railgraph);

       // for(int i=0;i<roaddist.length;i++){
       //      for(int j=0;j<roaddist.length;j++){
       //          System.out.print(roaddist[i][j]+" ");
       //      }
       //      System.out.println();
       //  }

       //  System.out.println();
       //  for(int i=0;i<raildist.length;i++){
       //      for(int j=0;j<raildist.length;j++){
       //          System.out.print(raildist[i][j]+" ");
       //      }
       //      System.out.println();
       //  }

        List<Integer> vertices=new LinkedList<>();
        for(int i=0;i<N;i++)
            vertices.add(i);

        int fmin=Integer.MAX_VALUE;
        for(int v:vertices){
            if(v==src || v==dest)
                continue;
            if(fmin>roaddist[src][v]+raildist[v][dest])
                fmin=roaddist[src][v]+raildist[v][dest];
        }

        //System.out.println(fmin);
        int bmin=Integer.MAX_VALUE;
        for(int v:vertices){
            if(v==src || v==dest)
                continue;
            if(bmin>raildist[src][v]+roaddist[v][dest])
                bmin=raildist[src][v]+roaddist[v][dest];
        }
        
        //System.out.println(bmin);
        System.out.println(Math.min(fmin,bmin));

    }
}
