package cn.edu.nju.software151250171.graph;
import java.util.ArrayList;
public class Graph {
	private ArrayList<ArrayList<Integer>> edges = new ArrayList<>();
	public Graph(int n) {
		for (int i = 0; i < n + 1; i++) {
			edges.add(new ArrayList<Integer>());
		}
	}
	public void addEdges(int vertex_start, int vertex_end) {
		ArrayList<Integer> edge = edges.get(vertex_start);
		for (int each : edge) {
			if (each == vertex_end) {
				return;
			}
		}
		edge.add(vertex_end);
	}
	public void dfs() {
		ArrayList<Integer> vertex = null;
		int count = 0;
		// 寻找出度不为0的边，
		for (ArrayList<Integer> each : edges) {
			if (each.size() != 0) {
				vertex = each;
				break;
			}
			count++;
		}
		if (vertex == null) {
			System.out.println("No Cycle");
		} else {
			state = new int[edges.size()];
			for (int i = 0; i < edges.size(); i++) {
				state[i] = -1;
			}
			
			
			state[count - 1] = 0;
			stack = new PathStack(edges.size());
			stack.push(count);
			dfs(count, vertex);
		}
	}

	// 用于存放状态
	private int state[] = null;
	// 用于存放路径
	private PathStack stack = null;
	private void dfs(int number, ArrayList<Integer> vertex) {
		// 遍历下个点
		for (int each_v : vertex) {
			if (state[each_v - 1] != -1) {
				// Cycle
				ArrayList<Integer> cycle = new ArrayList<>();
				for (int i = state[each_v - 1]; i <= stack.ptr; i++) {
					cycle.add(stack.stack[i]);
				}
				cycle.add(each_v);
				addpath(cycle);
			} else {
				// 下一个点
				stack.push(each_v);
				state[each_v - 1] = stack.ptr;
				dfs(each_v, edges.get(each_v));
			}
		}

		state[number - 1] = -1;
		stack.pop();
	}
	private ArrayList<ArrayList<Integer>> cycles = new ArrayList<>();
	/**
	 * 
	 * 判断是否同环
	 * 
	 * @param cycle
	 * 
	 */
	private void addpath(ArrayList<Integer> cycle) {
		for (ArrayList<Integer> each : cycles) {
			if (each.size() == cycle.size()) {
				boolean is_in = true;
				for (int i : each) {
					if (!cycle.contains(i)) {
						is_in = false;
						break;
					}
				}
				if (is_in) {
					return;
				}
			}
		}
		cycles.add(cycle);
		System.out.print("Cycle : ");
		for (int i : cycle) {
			System.out.print(" " + i);
		}
		System.out.println("");
	}
	class PathStack {
		int stack[];
		int ptr;
		int capacity;
		public PathStack(int capacity) {
			stack = new int[capacity];
			this.capacity = capacity - 1;
			ptr = -1;
		}
		public int pop() {
			if (ptr >= 0) {
				ptr--;
				return stack[ptr + 1];
			} else {
				return -1;
			}
		}
		public void push(int data) {
			ptr++;
			stack[ptr] = data;
		}
	}

	public static void main(String[] args) {
		Graph graph = new Graph(6);
		graph.addEdges(1, 2);
		graph.addEdges(2, 3);
		graph.addEdges(3, 4);
		graph.addEdges(4, 5);
		graph.addEdges(5, 1);
		graph.addEdges(5, 2);
		graph.dfs();
	}

}
