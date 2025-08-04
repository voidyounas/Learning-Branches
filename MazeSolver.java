import java.util.*;

public class MazeSolver {
    static int[][] maze = {
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 1},
        {1, 1, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };
    static boolean[][] visited = new boolean[5][5];
    static int rows = 5, cols = 5;
    static List<String> path = new ArrayList<>();

    public static void main(String[] args) {
        if (dfs(0, 0)) {
            for (String step : path) System.out.println(step);
        } else {
            System.out.println("No path found");
        }
    }

    static boolean dfs(int x, int y) {
        if (x < 0 || y < 0 || x >= rows || y >= cols || maze[x][y] == 0 || visited[x][y])
            return false;

        path.add("(" + x + "," + y + ")");
        visited[x][y] = true;

        if (x == rows - 1 && y == cols - 1)
            return true;

        if (dfs(x + 1, y) || dfs(x - 1, y) || dfs(x, y + 1) || dfs(x, y - 1))
            return true;

        path.remove(path.size() - 1);
        return false;
    }
}
