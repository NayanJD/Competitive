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
// Below is an O(ElogV) solution using Dijkstra and reverse Dijkstra algorithm.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

import java.util.*;
import java.io.*;
class Djk{
	static class Node implements Comparable<Node>{
		public int priority=0;
		public int vertex=0;

		public Node(int priority,int vertex){
			this.priority=priority;
			this.vertex=vertex;
		}

		public int compareTo(Node node){
			return this.priority-node.priority;
		}
	}


	public static int[] revdjk(int[][] graph,int dest){
		LinkedList<Integer>[] rev=new LinkedList[graph.length];

		for(int i=0;i<graph.length;i++){
			rev[i]=new LinkedList<Integer>();
		}
		for(int i=0;i<graph.length;i++){
			for(int j=0;j<graph.length;j++){
				if(graph[j][i]!=0)
					rev[i].add(j);
			}
		}

		PriorityQueue<Node> q=new PriorityQueue<>();

		int[] dist=new int[graph.length];

		for(int i=0;i<graph.length;i++){
			dist[i]=1000000000;
		}

		// Node node=new Node(0,dest);
		q.add(new Djk.Node(0,dest));
		Node node=null;

		while(q.size()!=0){
			node=q.poll();

			for(int v:rev[node.vertex]){
				if(dist[v]> node.priority+graph[v][node.vertex]){
					dist[v]=node.priority+graph[v][node.vertex];
					q.offer(new Djk.Node(dist[v],v));
				}
			}
		}

		return dist;
	}

	public static int[] djk(int[][] graph,int src){
		LinkedList<Integer>[] rev=new LinkedList[graph.length];

		for(int i=0;i<graph.length;i++){
			rev[i]=new LinkedList<Integer>();
		}
		for(int i=0;i<graph.length;i++){
			for(int j=0;j<graph.length;j++){
				if(graph[i][j]!=0)
					rev[i].add(j);
			}
		}

		PriorityQueue<Node> q=new PriorityQueue<>();

		int[] dist=new int[graph.length];

		for(int i=0;i<graph.length;i++){
			dist[i]=1000000000;
		}

		// Node node=new Node(0,dest);
		q.add(new Djk.Node(0,src));
		Node node=null;

		while(q.size()!=0){
			node=q.poll();

			for(int v:rev[node.vertex]){
				if(dist[v]> node.priority+graph[node.vertex][v]){
					dist[v]=node.priority+graph[node.vertex][v];
					q.offer(new Djk.Node(dist[v],v));
				}
			}
		}

		return dist;
	}
}


class TestClass {


    public static void main(String args[] ) throws Exception {
       BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
       //BufferedReader br=new BufferedReader(new FileReader(new File("Tests.txt")));

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

       

       int[] froad=Djk.djk(roadgraph,src);
       int[] broad=Djk.revdjk(roadgraph,dest);
       int[] frail=Djk.djk(railgraph,src);
       int[] brail=Djk.revdjk(railgraph,dest);
       
    //   for(int i=0;i<N;i++)
    //         System.out.print(froad[i]+" ");
    //   System.out.println();
    //   for(int i=0;i<N;i++)
    //         System.out.print(brail[i]+" ");
    //   System.out.println();
       
        List<Integer> vertices=new LinkedList<>();
        for(int i=0;i<N;i++)
            vertices.add(i);

        int fmin=Integer.MAX_VALUE;
        for(int v:vertices){
            if(v==src || v==dest)
                continue;
            //System.out.println(froad[v]+" "+brail[v]);
            if(fmin>froad[v]+brail[v])
                fmin=froad[v]+brail[v];
        }

        //System.out.println(fmin);
        int bmin=Integer.MAX_VALUE;
        for(int v:vertices){
            if(v==src || v==dest)
                continue;
            if(bmin>frail[v]+broad[v])
                bmin=frail[v]+broad[v];
        }
        
       // System.out.println(bmin);
        System.out.println(Math.min(fmin,bmin));

    }
}
