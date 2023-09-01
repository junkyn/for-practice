import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Queue<Integer> rotation = new LinkedList<>();
		Set<Integer> set = new HashSet<>();
		Scanner s = new Scanner(System.in);
		int count = s.nextInt();
		int kind = s.nextInt();
		int dish = s.nextInt();
		int cou = s.nextInt();
		for(int i = 0; i<count; i++) {
			rotation.add(s.nextInt());
		}
		boolean isCan = false;
		int max = 0;
		for(int i = 0; i<count; i++) {
			Iterator<Integer> it = rotation.iterator();
			isCan = true;
			for(int j = 0; j<dish;j++) {
				int n = it.next();
				set.add(n);
				if(n==cou) {
					isCan = false;
				}
			}
			int an = set.size();
			if(isCan)
				an++;
			if(max<an)
				max = an;
			if(max == dish+1)
				break;
			set.clear();
			int tmp = rotation.poll();
			rotation.add(tmp);
		}
		System.out.println(max);
		
	}

}
