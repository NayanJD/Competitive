// You have recently started playing a brand new computer game called "Mr. President". 
// The game is about ruling a country, building infrastructures and developing it.

// Your country consists of N cities and M bidirectional roads connecting them. Each 
// road has assigned a cost of its maintenance. The greatest achievement in the game 
// is called "Great administrator" and it is given to a player who manage to have all 
// cities in the country connected by roads in such a way that it is possible to travel 
// between any two cities and that the sum of maintenance costs of these roads is not greater 
// than K.

// This is very hard to accomplish, but you are very close to do it. More precisely, 
// you have just discovered a new method of transforming standard roads into super roads, 
// with cost of maintenance just 1, due to their extreme durability.

// The bad news is that it is very expensive to transform a standard road into a super road, 
// but you are so excited that you are going to do it anyway.

// In addition, because you have a lot of other expenses, you also want to first demolish as 
// many roads as possible in order to safe some money on their maintenance first and then start 
// working on getting the achievement. You can demolish any road in the country and that operation 
// does not cost you anything.

// Because you want to spend the absolutely minimum money in order to get the achievement, 
// you are interested in the smallest number of transformations of standard roads into super 
// roads in such a way that you can do that.

// Input format:

// In the first line there are 3 integers N, M and K denoting the number of cities in the country, 
// the number of roads in it and the desired sum of costs of maintenance. M lines describing these 
// roads follow. In each of them there are 3 integers A, B and C, where A and B denote the endpoints 
// of the road while C denotes the cost of its maintenance.

// Output:

// In a single line, output the minimum number of roads which need to be transformed in order to get 
// the achievement. If you cannot do it no matter what, output -1.

// Constraints:

// 2 <= N, M <= 106
// 0 <= K <= 1018
// 1 <= A, B <= N and A != B
// 1 <= C <= 106

// SAMPLE INPUT 
// 3 3 25
// 1 2 10
// 2 3 20
// 3 1 30
// SAMPLE OUTPUT 
// 1
// Explanation
// You can transform to super a road either the road between cities 1 and 2 or the road 
// between cities 2 and 3 in order to produce the desired road network of costs respectively 
// 21 and 11. Doing that will cost you one transformation and it is optimal in this case.


// I used Prim's Algorithm for this. The problem is that it requires LinkedList representation of 
// graph which seemed very time expensive for 10^6 Nodes and Edges. Therefore, I used a complex but
// efficient representation of graph which uses variable 3D matrix. It can store both adjacent node and
// the corresponding weight of the edge.


import java.io.*;
import java.util.*;
 
class Writer{
    final private static PrintStream w=System.out;
    final private static int SIZE = 1 << 16;
    final private static byte[] buff=new byte[SIZE];
    private static int curr=0;
 
    public Writer(){
 
    }
 
    public static void write(String str){
        byte[] strbytes=str.getBytes();
 
        for(int i=0;i<strbytes.length;i++){
            if(curr==SIZE){
                System.out.write(buff,0,SIZE);
                curr=0;
            }
 
            buff[curr++]=strbytes[i];
        }
 
    }
 
    public static void flush(){
 
        System.out.write(buff,0,curr);
    }
}
 
class InputReader {
         
    private InputStream stream;
    private byte[] buf = new byte[8192];
    private int curChar, snumChars;
    private SpaceCharFilter filter;
 
    public InputReader(InputStream stream) {
        this.stream = stream;
    }
 
    public int snext() {
        if (snumChars == -1)
            throw new InputMismatchException();
        if (curChar >= snumChars) {
            curChar = 0;
            try {
                snumChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (snumChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }
 
    public int nextInt() {
        int c = snext();
        while (isSpaceChar(c))
            c = snext();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = snext();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = snext();
        } while (!isSpaceChar(c));
        return res * sgn;
    }
 
    public long nextLong() {
        int c = snext();
        while (isSpaceChar(c))
            c = snext();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = snext();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = snext();
        } while (!isSpaceChar(c));
        return res * sgn;
    }
 
    public int[] nextIntArray(int n) {
        int a[] = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = nextInt();
        return a;
    }
 
    public String readString() {
        int c = snext();
        while (isSpaceChar(c))
            c = snext();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = snext();
        } while (!isSpaceChar(c));
        return res.toString();
    }
 
    public int[] readCharCount() {
        int c = snext();
        while (isSpaceChar(c))
            c = snext();
        int[] map = new int[256];
        do {
            int val = c ;
            map[val]++;
            c = snext();
        } while (!isSpaceChar(c));
        return map;
    }
 
    public boolean isSpaceChar(int c) {
        if (filter != null)
            return filter.isSpaceChar(c);
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
 
    public interface SpaceCharFilter {
        public boolean isSpaceChar(int ch);
    }
}
 
class TestClass{
    public static Writer w=new Writer();
    public static InputReader r=null;
 
    static{
        try{
            //r=new InputReader(System.in);
            r=new InputReader(new FileInputStream(new File("tests.txt")));
        }catch(Exception e){
 
        }
    }
 
    static class Edge{
        public int v;
        public int w;
 
        public Edge(int v,int w){
            this.v=v;
            this.w=w;
        }
    }
 
    static class Vertex implements Comparable<Vertex>{
        public int v;
        public int w;
 
        public Vertex(int v,int w){
            this.v=v;
            this.w=w;
        }
 
        public int compareTo(Vertex node){
            return this.w-node.w;
        }
 
    }
 
    public static void main(String[] args)throws Exception{
        
        long start=System.currentTimeMillis();

        int N=r.nextInt();
        int M=r.nextInt();
        long k=r.nextLong();
 
        //LinkedList<Edge>[] graph=new LinkedList[N];

        int[][][] graph=new int[N][][];
 
        // for(int i=0;i<N;i++){
        //  graph[i]=new LinkedList<Edge>();
        // }
        
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<N;j++){
        //         graph[i][j]=-1;
        //     }
        // }
        int[][] input=new int[M][3];

        int a=0;
        int b=0;
        int c=0;
        for(int i=0;i<M;i++){
            a=r.nextInt()-1;
            b=r.nextInt()-1;
            c=r.nextInt();
 
            input[i][0]=a;
            input[i][1]=b;
            input[i][2]=c;
        }

        int[] adjcount=new int[N];

        for(int i=0;i<M;i++){
            adjcount[input[i][0]]++;
            adjcount[input[i][1]]++;
        }
        
        long end=System.currentTimeMillis();

        for(int i=0;i<N;i++){
            graph[i]=new int[2][adjcount[i]+1];
            graph[i][0][0]=1;
        }

        

        int index=0;
        int node=0;
        for(int i=0;i<M;i++){
            node=input[i][0];
            index=graph[node][0][0];
            graph[node][0][index]=input[i][1];
            graph[node][1][index++]=input[i][2];
            graph[node][0][0]=index;

            node=input[i][1];
            index=graph[node][0][0];
            graph[node][0][index]=input[i][0];
            graph[node][1][index++]=input[i][2];
            graph[node][0][0]=index;
        }


        PriorityQueue<Vertex> q=new PriorityQueue<>();
 
        boolean[] visited=new boolean[N];
 
        q.offer(new Vertex(0,0));
 
        int[] edges=new int[M];
        int edgesize=0;
 
        Vertex curr=null;
        Edge e=null;
 
        while(q.size()!=0){
            curr=q.poll();
 
            if(visited[curr.v])
                continue;
 
            visited[curr.v]=true;
 
            edges[edgesize++]=curr.w;
 
            // for(int i=0;i<graph[curr.v].size();i++){
            //  e=graph[curr.v].get(i);
            //  if(!visited[e.v])
            //      q.offer(new Vertex(e.v,e.w));
            // }

            // for(int i=0;i<N;i++){
            //     if(graph[curr.v][i]!=-1){
            //         if(!visited[i])
            //             q.offer(new Vertex(i,graph[curr.v][i]));
            //     }
            // }

            for(int i=1;i<graph[curr.v][0][0];i++){
                if(!visited[graph[curr.v][0][i]])
                    q.offer(new Vertex(graph[curr.v][0][i],graph[curr.v][1][i]));
            }
        }
 
        Arrays.sort(edges,0,edgesize);
 
        long[] ledges=new long[edgesize];
 
        ledges[0]=edges[0];
        for(int i=1;i<edgesize;i++){
            ledges[i]=ledges[i-1]+edges[i];
        }
 
        int count=0;
        int i=edgesize-1;
 
        while(i!=-1 && (ledges[i]+count)>k){
            if(i!=0)
                count++;
            i--;
        }
        
        boolean flag=false;
        int j=0;
        for(j=0;j<N;j++){
            if(!visited[j]){
                flag=true;
                break;
            }
        }

        if(i==-1 && !flag){
            w.write("-1\n");
        }else if(!flag)
            w.write(count+"\n");
        else
            w.write("-1");
        

        //w.write((end-start)+"\n");
        
        w.flush();
    }
}