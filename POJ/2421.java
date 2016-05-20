import java.util.PriorityQueue;
import java.util.Scanner;


public class Main {
	
	static class node implements Comparable<node>{
		private int distance;
		private int name;
		
		public node(int a, int b){
			distance = a;
			name = b;
		}

		@Override
		public int compareTo(node o) {
			if(this.distance<o.distance){
				return -1;
			}else if(o.distance<this.distance){
				return 1;
			}
			return 0;
		}
	}

	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		int number = in.nextInt();
		
		int[][] matrix = new int[number+1][number+1];
		for(int i=1; i<=number; i++){
			for(int j=1; j<=number; j++){
				matrix[i][j] = in.nextInt();
			}
		}
		
		int number2 = in.nextInt();
		for(int i=0; i<number2; i++){
			int a = in.nextInt();
			int b = in.nextInt();
			matrix[a][b] = 0;
			matrix[b][a] = 0;
		}
		
		boolean[] visited = new boolean[number+1];
		PriorityQueue<node> pq = new PriorityQueue<node>();
		node start = new node(0,1);
		pq.add(start);
		int ans = 0;
		
		while(!pq.isEmpty()){
			node current = pq.poll();
			if(visited[current.name]){
				continue;
			}
			ans += current.distance;
			visited[current.name] = true;
			for(int i=1; i<=number; i++){
				if(i==current.name){
					continue;
				}
				if(!visited[i]){
					pq.add(new node(matrix[current.name][i],i));
				}
			}
		}
		System.out.println(ans);
		
	}
	
}
