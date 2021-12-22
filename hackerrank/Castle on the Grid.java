import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {
    static class Coordinates{
        private int x, y;

        public Coordinates() {
        }

        public Coordinates(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public void setX(int x) {
            this.x = x;
        }

        public int getY() {
            return y;
        }

        public void setY(int y) {
            this.y = y;
        }
    }
    
    public static int minimumMoves(List<String> grid, int startX, int startY, int goalX, int goalY){
        int n = grid.size();
        boolean[][] visited = new boolean[n][n];

        for(int i = 0;i < n; ++i) Arrays.fill(visited[i], false);

        Queue<Coordinates> q = new LinkedList<>();

        q.add(new Coordinates(startX, startY));
        visited[startX][startY] = true;
        q.add(null);

        int round = 1;

        while(!q.isEmpty()){
            Coordinates front = q.poll();
            if(front == null){
                if(q.isEmpty()){
                    return -1;
                }
                q.add(null);
                round++;
            }

            else{
                boolean found = updateQueue(grid, q, front, visited, goalX, goalY);
                if(found){
                    break;
                }
            }
        }

        return round;
    }

    private static boolean updateQueue(List<String> grid, Queue<Coordinates> q, Coordinates c, boolean[][] visited
        ,int goalX, int goalY){
        int x = c.getX(), y = c.getY();
        int n = grid.size();

        // left
        for (int i = y-1; i >= 0 && grid.get(x).charAt(i) != 'X'; i--) {
            if(x == goalX && i == goalY){
                return true;
            }

            if(!visited[x][i]){
                visited[x][i] = true;
                q.add(new Coordinates(x, i));
            }
        }

        // right
        for(int i = y+1; i < n && grid.get(x).charAt(i) != 'X'; ++i){
            if(x == goalX && i == goalY){
                return true;
            }

            if(!visited[x][i]){
                visited[x][i] = true;
                q.add(new Coordinates(x, i));
            }
        }

        // up
        for (int i = x-1; i >= 0 && grid.get(i).charAt(y) != 'X'; i--) {
            if(i == goalX && y == goalY){
                return true;
            }
            
            if(!visited[i][y]){
                visited[i][y] = true;
                q.add(new Coordinates(i, y));
            }
        }

        // down
        for(int i = x+1; i < n && grid.get(i).charAt(y) != 'X'; ++i){
            if(i == goalX && y == goalY){
                return true;
            }

            if(!visited[i][y]){
                visited[i][y] = true;
                q.add(new Coordinates(i, y));
            }
        }

        return false;
    }
}
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<String> grid = IntStream.range(0, n).mapToObj(i -> {
            try {
                return bufferedReader.readLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .collect(toList());

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int startX = Integer.parseInt(firstMultipleInput[0]);

        int startY = Integer.parseInt(firstMultipleInput[1]);

        int goalX = Integer.parseInt(firstMultipleInput[2]);

        int goalY = Integer.parseInt(firstMultipleInput[3]);

        int result = Result.minimumMoves(grid, startX, startY, goalX, goalY);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
