/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    
    void cleanRoom(Robot& robot) {
        //set<pair<int, int>> visited;
        unordered_set<string> visited;
        helper(robot, 0, 0, 0, visited);
        return;
    }

private:
    //up, left, right, down
    //vector<int> dx = {-1, 0, 0, 1};
    //vector<int> dy = {0, -1, 1, 0};
    //up, right, down, left
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    void helper(Robot& robot, int x, int y, int dir, unordered_set<string> &visited) {
        robot.clean();
        visited.insert(to_string(x) + "_" + to_string(y));
        //visited.insert({x, y});

        for (int i = 0; i < 4; ++i) {
            int newDir = (dir + i) % 4;
            int newX = x + dx[newDir];
            int newY = y + dy[newDir];
            //if (visited.find({newX, newY}) == visited.end() && robot.move()) {
            if (visited.find(to_string(newX) + "_" + to_string(newY)) == visited.end() && robot.move()) {
                helper(robot, newX, newY, newDir, visited);
                
                //go back to previous place
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnRight();
        }
        

    }
};