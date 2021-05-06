# Convex-Hull-Detection
Finds the convex hull from a given array of pair of points.

## Steps followed:
<ol>
<li> Found the maximum, minimum of all of the X-coordinates and Y-coordinates. </li>
<li> Iterated through all of the pairs of the points and found the intersection point of the 2 lines formed by 2 pairs of points. </li>
<li> If the intersection point (in step-2) is in the range (found in step-1) of the image, then only storing it in a vector. </li>
  <li> Started from the leftmost point and iterated till it reaches from where it started. </li>
<li> Selected next point based on its orientation, if the ith point makes less slope with 'start' point then 'next' point is replaced with 'i' point. </li>
</ol>

## Visualization of the points found:
<p align="center">
  <img alt="img-name" src="https://github.com/JeetKaria06/Convex-Hull-Detection/blob/main/fig.png">
  <br>
    <em>Red points represents the convex hull found and the blue lines are the lines generated from given array of pair of points.</em>
</p>

## Languages Used:
* <b>C++</b> for algorithm
* <b>Python</b> for visualization


## References referred:
* https://www.geeksforgeeks.org/orientation-3-ordered-points/
* https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/
* https://www.topcoder.com/thrive/articles/Geometry%20Concepts%20part%202:%20%20Line%20Intersection%20and%20its%20Applications
