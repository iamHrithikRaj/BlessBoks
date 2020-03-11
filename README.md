# Recursive-Path-Finder
Finding a path through a maze is a popular problem for computers.In this problem a maze will consist of a rectangulat array of square cells,each of which may have walls on the north,south,east and/or west sides of the cells.One cell will be identified as the starting point,and another will be identified as the goal. The task is to find the unique route from the starting point to the goal,label each cell in the path with its sequence in the path,identify the cells that were visited but that were not in the path,and display the maze.
Imagin a robot positioned in the starting cell.The robot forst attempts to go west from that cell,then north,
then east,then south,in sequence.The robot can move int he selected direction if
(a) there is no wall preventing it from moving in that direction, and
(b) it has not yet been in the next cll in that direction
