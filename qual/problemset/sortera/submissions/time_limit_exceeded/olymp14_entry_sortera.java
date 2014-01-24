import java.util.Scanner;

public class olymp14_entry_sortera {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int[] tracks = new int[num];
		for(int i = 0; i < num; i++)
			tracks[i] = sc.nextInt();
		sc.close();
		doIt(tracks.clone(), 0);
		System.out.println(min);
	}
	
	static int min = Integer.MAX_VALUE;
	
	private static void doIt(int[] arr, int n) {
		if(n >= min) return;
		boolean sorted = true;
		for(int i = 0; i < arr.length - 1; i++)
			if(arr[i] > arr[i + 1]) {
				sorted = false;
				break;
			}
		if(sorted) min = Math.min(n, min);
		else for(int i = 0; i < arr.length - 1; i++)
			if(arr[i] > arr[i + 1]) {
				int[] clone = arr.clone();
				int bak = clone[i];
				clone[i] = clone[i + 1];
				clone[i + 1] = bak;
				doIt(clone, n + 1);
			}
	}
}

