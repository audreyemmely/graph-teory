# Prim Algorithm

### Compiling the program
First, clone this repository on your local machine, using the following command through the terminal:
```
git clone https://github.com/audreyemmely/graph-teory.git
```
If you do not have Git installed on your machine, you can download the repository in "zip" format, just click on the green button named "Code" (top right) and choose the option "Download ZIP". After that, unzip the file and follow the next instructions.

After cloning/downloading the repository, find where the repository is located on your machine and open the folder named "graph-teory". Inside there are four folders named "dijkstra", "ford-fulkerson", "kruskal" and "prim".

Now, using the terminal go to the path where the folder is located on your machine (Ex.: C:\Users\Audrey\Desktop\graph-teory).

After access the folder "graph-teory" in the terminal, choose the folder named "prim" and run the following command
```
make prim
```
To be able to run the code type the following command
```
./prim < input.in
```

### About the input
The first line of the input must consist of three whole numbers: n, m, v0. Where n = number of vertices, m = number of edges and v0 = initial vertex (0 <= v0 < n).
Then, m lines, which represent the edges of the graph, each with three integers: v1, v2 and w. Where v1 and v2 are the vertices connected by the edge and w is the weight of the edge.

Note that the vertices are numbered from 0 to n - 1, therefore, for the algorithm to work, the entry must be made respecting these limits when identifying the vertices.
This input can be done interactively via the terminal, or via a text file.

### About the output 
The output will be composed of n lines, each in the form ```v pai: u``` (v parent: u) indicating, for each vertex v of the graph, which would be its parent vertex (u) in the maximum spanning tree. Note that the starting vertex has no parent (-1), as the tree is rooted to it.

### Example 
![prim](https://user-images.githubusercontent.com/52829664/134730102-a981c29f-d840-49d5-8934-7600866c6095.png)
