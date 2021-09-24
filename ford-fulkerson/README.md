# Ford-Fulkerson Algorithm

### Compiling the program
First, clone this repository on your local machine, using the following command through the terminal:
```
git clone https://github.com/audreyemmely/graph-teory.git
```
If you do not have Git installed on your machine, you can download the repository in "zip" format, just click on the green button named "Code" (top right) and choose the option "Download ZIP". After that, unzip the file and follow the next instructions.

After cloning/downloading the repository, find where the repository is located on your machine and open the folder named "graph-teory". Inside there are four folders named "dijkstra", "ford-fulkerson", "kruskal" and "prim".

Now, using the terminal go to the path where the folder is located on your machine (Ex.: C:\Users\Audrey\Desktop\graph-teory).

After access the folder "graph-teory" in the terminal, choose the folder named "ford-fulkerson" and run the following command
```
make ford_fulkerson
```
To be able to run the code type the following command
```
./ford_fulkerson < input.in
```

### About the input
The first line of the input must consist of two whole numbers: n and m. Where n = number of vertices and m = number of edges of the graph.
The second line of the input must consist of two integers, s and t. Where s is the source vertex and t is the target vertex.
Then, m lines, which represent the edges of the graph, each with three integers: v1, v2 and c. Where v1 and v2 are the vertices connected by the edge and c is the capacity of the edge. Note that the graph is directed, so the edge has sense v1 -> v2.
Note that the vertices are numbered from 0 to n - 1, therefore, for the algorithm to work, the entry must be made respecting these limits when identifying the vertices.

This input can be done interactively via the terminal, or via a text file.
