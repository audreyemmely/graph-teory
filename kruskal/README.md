# Kruskal Algorithm

### Compiling the program
First, clone this repository on your local machine, using the following command through the terminal:
```
git clone https://github.com/audreyemmely/graph-teory.git
```
If you do not have Git installed on your machine, you can download the repository in "zip" format, just click on the green button named "Code" (top right) and choose the option "Download ZIP". After that, unzip the file and follow the next instructions.

After cloning/downloading the repository, find where the repository is located on your machine and open the folder named "graph-teory". Inside there are four folders named "dijkstra", "ford-fulkerson", "kruskal" and "prim".

Now, using the terminal go to the path where the folder is located on your machine (Ex.: C:\Users\Audrey\Desktop\graph-teory).

After access the folder "graph-teory" in the terminal, choose the folder named "kruskal" and run the following command
```
make kruskal
```
To be able to run the code type the following command
```
./kruskal < input.in
```

### About the input
In the first line we have two integers, V and E. V being the number of vertices and E the number of edges of the graph.
Then, we will have E lines, which represent the edges of the graph, each edge being composed of three integers: v1, v2, w. 
v1 and v2 are the vertices connected by the edge and w is the weight of the edge.

Note that the vertices are numbered from 0 to n - 1, therefore, for the algorithm to work, the entry must be made respecting these limits when identifying the vertices.
This input can be done interactively via the terminal, or via a text file.

### About the output 
The output returns the graph's minimum spanning tree.

### Example 
![kruskal](https://user-images.githubusercontent.com/52829664/134730104-bb174af3-b066-4b80-80f7-6cb0984612a4.png)
