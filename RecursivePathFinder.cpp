#include<iostream>
#include<stdlib.h>
#include<vector>
#include<fstream>
constexpr int order = 9;

std::vector<int>x; //vector to store x-co-ordinates
std::vector<int>y; //vector to store y-co-ordinates

static int corrSteps,wrngSteps;
void updatePosition(int row,int col){
    /*if current path has been found the 
    postion will be updated through this function*/
    ++corrSteps;
    x.push_back(row);
    y.push_back(col);
}
int valid(int row,int col){
    /*to check if the given co-ordinate 
    lies in the maze or not*/
    if(row<order && row>=0 && col<order && col>=0)
        return 1;
    else
        return 0;
}
void solutionPath(char maze[order][order]){
    int endx = x[x.size()-1];
    int endy = y[y.size()-1];
    if(maze[endx][endy] == 'E'){
        std::cout<<"x-co-ordinates";
        for(int a:x){
            std::cout<<a<<" ";
        }
        std::cout<<std::endl;
        std::cout<<"y-co-ordinates";
        for(int b:y){
            std::cout<<b<<" ";
        }
        std::cout<<"\ntotal no. of correct steps: "<<corrSteps;
        std::cout<<"\ntotal no. of wrong steps: "<<wrngSteps;
        std::cout<<"\nno of x cood: "<<x.size();
        std::cout<<"\nno of y cood: "<<y.size();
    }
    else{
        std::cout<<"\nNo possible exit path exits!";
    }
}
int findPath(char maze[order][order],int startRow,int startCol){
    /*recursive function*/
    if(valid(startRow,startCol)){
        /*Base Case 1: we have ran into a wall*/
        if(maze[startRow][startCol] == '#'){
            ++wrngSteps;
            return 0;
        }
        /*Base Case 2: we have found a cell which has
        already been explored*/
        if(maze[startRow][startCol] == '-'){
            ++wrngSteps;
            return 0;
        }
        /*Base Case 3: Success! an outside edge
        not occupied by an obstacle*/
        if(maze[startRow][startCol] == '.'){
            updatePosition(startRow,startCol);
            maze[startRow][startCol] = '-';/*change the traversed path
            to identify it later*/
        }
        if(maze[startRow][startCol] == 'B'){//B = Begin/Starting point
            updatePosition(startRow,startCol);
            maze[startRow][startCol] = '-';
        } 
        if(maze[startRow][startCol] == 'E'){
            updatePosition(startRow,startCol);
            return 0;
        }
        findPath(maze,startRow,startCol-1); /*going west recursively
        until base case is encountered*/
        findPath(maze,startRow-1,startCol);/*going north recursively
        until base case is encountered*/
        findPath(maze,startRow,startCol+1);/*going east recursively
        until base is encountered*/
        findPath(maze,startRow+1,startCol);/*going south recursively
        until base is encountered*/
    }
}
int main(){
    char maze[order][order];
    std::ifstream fin("mazeLayout.txt");
    for(int row = 0;row<order;row++){
        for(int col = 0;col<order;col++){
            fin>>maze[row][col];
        }
    }
    for(int row =0;row<order;row++){
        for(int col=0;col<order;col++){
            std::cout<<maze[row][col]<<" ";
        }
        std::cout<<std::endl;
    }
    fin.close();
    findPath(maze,0,0);
    std::cout<<'\n';
    std::cout<<"co-ordinates are:\n";
    solutionPath(maze);
    std::cout<<'\n';
    std::cout<<'\n';
    for(int row = 0;row<order;row++){
        for(int col = 0;col<order;col++){
            std::cout<<maze[row][col]<<" ";
        }
        std::cout<<std::endl;
    }
}