# Dijkstra Algorithm

### Compiling the program
First, clone this repository on your local machine, using the following command through the terminal:
```
git clone https://github.com/audreyemmely/graph-teory.git
```
If you do not have Git installed on your machine, you can download the repository in "zip" format, just click on the green button named "Code" (top right) and choose the option "Download ZIP". After that, unzip the file and follow the next instructions.

After cloning/downloading the repository, find where the repository is located on your machine and open the folder named "graph-teory". Inside there are four folders named "dijktra", "ford-fulkerson", "kruskal" and "prim".

Now, using the terminal go to the path where the folder is located on your machine (Ex.: C:\Users\Audrey\Desktop\graph-teory).

After access the folder "graph-teory" in the terminal, choose the folder named "dijkstra" and run the following command
```
make dijkstra
```
To be able to run the code type the following command
```
./dijkstra < input.in
```

### About the input 
The first line of the input must consist of four integers: n, Δ, m, d. Where n = number of vertices, Δ = maximum degree, m = number of edges and d = directed graph (0 or 1).
The second line of the input must consist of two integers, s and t. Where s is the source vertex and t is the destination vertex.
Then, m lines, which represent the edges of the graph, each with three integers: v1, v2 and w. Where v1 and v2 are the vertices connected by the edge and w is the weight of the edge.
Note that the vertices are numbered from 0 to n - 1, therefore, for the algorithm to work, the entry must be made respecting these limits when identifying the vertices.

This input can be done interactively via the terminal, or via a text file.

### About the output
The output will consist of one line, in the format s -> ... -> v -> ... -> t. Where s is the initial vertex and t is the destination, in addition to i vertices that make up the path between them. If there is no path between s and t in the input graph, the output will be No path.
