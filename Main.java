import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int x = input.nextInt() + 1;
        int y = input.nextInt() + 1;
        input.close();
        print(x, y);
    }

    public static void print(int x, int y) {
        int L[][] = new int[x][y];
        // 进行初始化//可以不用这样设定，但是我个人习惯上将边界定为0
        for (int i = 0; i < x; i++) {
            L[i][0] = 0;
        }
        for (int i = 0; i < y; i++) {
            L[0][i] = 0;
        }
        for (int i = 1; i < x; i++) {
            for (int j = 1; j < y; j++) {
                L[i][j] = 1;
            }
        }
        //
        for (int i = 2; i < x; i++) {
            for (int j = 2; j < y; j++) {
                L[i][j] = L[i - 1][j] + L[i][j - 1];// 中间部分到每个点都有两条路可走
            }
        }
        System.out.print(L[x - 1][y - 1]);
    }

}
