import java.io.*;
import java.util.*;



class Node implements Comparable<Node>{
    public int index=0;
    public long distance=0;
    public int dindex=0;
    
    public Node(int index,int dindex,long distance){
        this.index=index;
        this.distance=distance;
        this.dindex=dindex;
    }
    
    public int compareTo(Node node){
        return (int)(this.distance-node.distance);
    }
}


class TestClass {
    public static void main(String args[] ) throws Exception {
        
        //BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedReader br=new BufferedReader(new FileReader(new File("tests.txt")));
        
        String str=null;
        String[] arg=null;
        
        int N=Integer.parseInt(br.readLine());
        long[] apples=null;
        int[] surplus=null;
        int[] defi=null;
        List<Node> dp=new LinkedList<>();
        
        str=br.readLine();
        arg=str.split(" ");
        
        apples=new long[N];
        for(int i=0;i<arg.length;i++)
            apples[i]=Long.parseLong(arg[i]);
            
        long sum=0;
        for(int i=0;i<apples.length;i++){
            sum+=apples[i];
        }
        
        long limit=sum/N;
        
        int surpluscount=0;
        int deficount=0;
        HashMap<Integer,Long> mapsurplus=new HashMap<>();
        HashMap<Integer,Long> mapdefi=new HashMap<>();

        long start1=System.currentTimeMillis();
        for(int i=0;i<apples.length;i++){
            if(apples[i]>limit){
                mapsurplus.put(i,apples[i]-limit);
                surpluscount++;
            }
            else if(apples[i]<limit){
                mapdefi.put(i,limit-apples[i]);
                deficount++;
            }
                
        }
        long end1=System.currentTimeMillis();
        System.out.println(end1-start1);
        
        
        Set<Integer> keys=mapsurplus.keySet();
        long dist=0;
        long cydist=0;

        long start2=System.currentTimeMillis();
        
        Set<Integer> defikeys=mapdefi.keySet();
        for(int i:defikeys){
            
            for(int j:keys){
                dist=(j-i<0)?Math.abs(j-i):j-i;
                cydist=(j-i<0)?(j-i)+apples.length:(i-j)+apples.length;
                
                //System.out.println(i+" "+j+" "+dist+" "+cydist);
                if(cydist<dist)
                    dist=cydist;
                
                dp.add(new Node(j,i,dist));    
            }
        }
        long end2=System.currentTimeMillis();

        System.out.println("dp size="+dp.size());
        System.out.println(end2-start2);


        // dp.forEach(e->System.out.print("("+e.distance+","+e.index+") "));
        // System.out.println();

        long start3=System.currentTimeMillis();
        Collections.sort(dp);
        // dp.forEach(e->System.out.print("("+e.distance+","+e.index+","+e.dindex+") "));
        // System.out.println();
        long end3=System.currentTimeMillis();
        System.out.println(end3-start3);


        long start4=System.currentTimeMillis();
        long steps=0;
        long count=0;
        for(Node n:dp){
            //System.out.println(count++);

            if(mapdefi.get(n.dindex)==0 || mapsurplus.get(n.index)==0)
                continue;


            if(mapdefi.get(n.dindex)>mapsurplus.get(n.index)){
                steps+=n.distance*(mapsurplus.get(n.index));
                mapdefi.replace(n.dindex,mapdefi.get(n.dindex)-mapsurplus.get(n.index));
                mapsurplus.replace(n.index,0L);
            }else{
                steps+=n.distance*(mapdefi.get(n.dindex));
                mapsurplus.replace(n.index,mapsurplus.get(n.index)-mapdefi.get(n.dindex));
                mapdefi.replace(n.dindex,0L);
            }

            //System.out.println(steps+" "+n.index+" "+n.dindex);
        }
        long end4=System.currentTimeMillis();
        System.out.println(end4-start4);

        System.out.println(steps);

            

    }
}
