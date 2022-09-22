# pracetice
for study
package Hanoi;

import java.util.Iterator;
import java.util.Scanner;

public class quickSort {
	public static void main(String[] args) {
		int[] a = new int [5];
		Scanner scan = new Scanner(System.in);
		for (int i = 0; i < 5; i++) {
			a[i] = scan.nextInt();
		}
		scan.close();
		sort(a, 0, 4);
		for (int i : a) {
			System.out.println(i+" ");
		}
	}
	public static void sort(int[] a, int left, int right) {
		if (left >= right) {
			return ;
		}
		int temp, temp_le = left, temp_ri = right;
		temp = a[left];
		int temp1;
		int b;
		while (temp_le > temp_ri) {
			while (temp_ri > temp_le) {
				if (a[temp_ri] < temp) {
					break;
				} else {
					temp_ri--;
				}
			}
			while (temp_ri > temp_le) {
				if (a[temp_le] > temp) {
					break;
				} else {
					temp_ri++;
				}
			}
			if (temp_le == temp_ri) {
				a[left] = a[temp_le];
				a[temp_le] = temp;
				break;
			} else {
				temp1 = a[temp_le];
				a[temp_le] = a[temp_ri];
				a[temp_ri] = temp1;
			}
		}
		sort(a, left, temp_ri-1);
		sort(a, temp_le+1, right);
	}
}
