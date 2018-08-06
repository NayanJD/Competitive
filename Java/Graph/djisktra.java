// Our smart travel agent, Mr. X's current assignment is to show a group of tourists a distant city. 
// As in all countries, certain pairs of cities are connected by two-way roads. 
// Each pair of neighboring cities has a bus service that runs only between those two cities and uses the road that directly connects 
// them. Each bus service has a particular limit on the maximum number of passengers it can carry. 
// Mr. X has a map showing the cities and the roads connecting them, as well as the service limit for each bus service.

// It is not always possible for him to take all tourists to the destination city in a single trip. 
// For example, consider the following road map of seven cities, where the edges represent roads and the number written 
// on each edge indicates the passenger limit of the associated bus service.

// In the diagram below, It will take at least five trips for Mr. X. to take 99 tourists from city 1 to city 7, 
// since he has to ride the bus with each group. The best route to take is 1 - 2 - 4 - 7.

// enter image description here

// Problem:
// What is the best way for Mr. X to take all tourists to the destination city in the minimum number of trips?

// [Input]:
// The first line will contain two integers: N (N ≤ 100) and R, representing the number of cities and the number of road segments, 
// respectively. Each of the next R lines will contain three integers (C1, C2, and P) where C1 and C2 are the city numbers 
// and P (P > 1) is the maximum number of passengers that can be carried by the bus service between the two cities. 
// City numbers are positive integers ranging from 1 to N. The (R+1)th line will contain three integers (S, D, and T) representing, 
// respectively, the starting city, the destination city, and the number of tourists to be guided.

// [Output]:
// The output should contain 2 lines - the first line giving the route taken and the second line giving the minimum number of trips

// [Note]: If multiple solutions exist . Print lexicographically-smallest path .
// Agent is also travelling in the same path so he has to be counted while travelling in that path for each trip.
//
//Below is an O(n) solution
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


import java.util.*;
import java.io.*;

class Node implements Comparable{
    int priority=0;
    int vertex=0;
    
    public Node(int priority,int vertex){
        this.priority=priority;
        this.vertex=vertex;
    }
    
    public int compareTo(Object n){
        Node node=(Node)n;
        return -(this.priority-node.priority);
    }
}
class TestClass {

	public static void recur(int[] arr,int src){
		int val=src+1;

		if(arr[src]==-1){
			System.out.print(val+" ");
			return;
		}
		else
			recur(arr,arr[src]);

		System.out.print(val+" ");
	}
    public static void main(String args[] ) throws Exception {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        //BufferedReader br=new BufferedReader(new FileReader(new File("tests.txt")));
        String[] str=null;
        
        str=br.readLine().split(" ");
        
        int N=Integer.parseInt(str[0]);
        int M=Integer.parseInt(str[1]);
        
        int[][] graph=new int[N][N];
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                graph[i][j]=1000000000;

        // LinkedList<Integer>[] graph=new LinkedList<Integer>[N]

        int a=0,b=0,w=0;
        int count=0;
        for(int i=0;i< M;i++){
            str=br.readLine().split(" ");
            a=Integer.parseInt(str[0]);
            b=Integer.parseInt(str[1]);
            w=Integer.parseInt(str[2]);
            //System.out.println(count++);
            graph[a-1][b-1]=w;
            
        }
        
        str=br.readLine().split(" ");

        int src=Integer.parseInt(str[0])-1;
        int dest=Integer.parseInt(str[1])-1;
        int pass=Integer.parseInt(str[2]);

        int[] dist=new int[N];
        int[] path=new int[N];
        
        for(int i=0;i<N;i++)
            dist[i]=-1000000000;

       	for(int i=0;i<N;i++)
            path[i]=-1;
            
        dist[src]=0;
        PriorityQueue<Node> q=new PriorityQueue<Node>();
        
        q.offer(new Node(1000000000,0));
        
        Node node;
        int val=0;
        while(q.size()!=0){
            node=q.poll();
            if(node.vertex==dest)
            	break;
            
            //System.out.println(node.vertex);
            for(int i=0;i<N;i++){
                if(graph[node.vertex][i]==1000000000)
                    continue;
                
                val=Math.min(node.priority,graph[node.vertex][i]);

                if(dist[i] < val){
                    dist[i]=val;
                    q.offer(new Node(dist[i],i));
                    path[i]=node.vertex;
                }
            }
            
        }
        
        // for(int i=0;i<N;i++)
        // 	System.out.print(path[i]+" ");
       	//System.out.println();
        recur(path,dest);
        int div=dist[dest];
        
        int result=pass/div;

        if(pass%div!=0)
        	result=result+2;
        else
        	result++;
        System.out.println("\n"+result);

        int[] revd=Djk.revd(graph,6);

        System.out.println();
        for(int i=0;i<revd.length;i++)
        	System.out.print(revd[i]+" ");
        
    }
}
