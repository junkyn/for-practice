package baek2531;

import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

/**
백준 2531번
https://www.acmicpc.net/problem/2531
자바의 컬렉션쪽이 기억이 잘 안나 컬렉션을 사용하려 했다.
큐에 모든 초밥을 담고 반복문이 돌때마다 첫번째 원소가 마지막 원소로 옮겨지는걸 큐로 구현했다.
가짓수를 구현하기 위해 접시수만큼 반복할때마다 그 초밥을 셋에 넣어 중복을 방지하고 마지막에 set의 사이즈를 저장한다.
만약 접시수만큼 반복했을 때 쿠폰에 해당하는 초밥을 먹지 못했다면 한번 더 먹을 수 있으므로 +1을 해준다.
최댓값을 따로 저장해 마지막에 최댓값을 출력하면 끝
**/

public class Baek2531_sushi {

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
