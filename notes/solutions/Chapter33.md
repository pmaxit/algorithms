# Chapter 33

### Solution 35.1

P1 x P2 shows the area of parallelogram along with the sign of area.

### Solution 35.2
Sorting points with respect to a point.

Use Sorting with following boolean function

```
bool compare(P1, P2){
  if(p1.y>=0 && p2.y<0) return true;
  if (p1.y<=0 && p2.y>=0) return false;
  return sign(p1 X P2 ) > 0
}

where cross product is defined as
P1.x * p2.y - P2.x * p1.y
```

### Question
Given a convex polygon and point check whether this point lies inside a polygon or not.

Algorithm 1)

* Assuming points are given in sorted order. [P0, P1, P2, .. Pn-1 ]
*  Simply divide points in half and check which half contains the point
    * Simply connect point 0 with point MID
    * Check if point lies above or below the line. This can be done using cross product.
    * Choose side where point lies and recurse for rest of the polygon.
* In the end only 3 vertices will remain. Simply do brute force check if point lies inside the triangle or not.

BRUTE FORCE check
For all sides of polygon, simply check if point contains only on one side. ( using cross product )

Algorithm 2)

* Assume any interior point inside a convex polygon.
* Say it centroid or mid of two points.
* divide it triangular regions using that point.
* Using binary search find which triangular region contains the point
* Using above triangle check find if point lies inside the triangle or outside.


## Online Algorithm to update Convex hull
Input: Convex hull ( ordered points from reference point P0)
Output : Convex hull

### Algorithm:

1. Start from reference point.

2. Check if $ p_i , p_{i+1} , p_k $ is left turn or not?

3. if don't find any right turn, then point is interior

4. Say we find i where $ p_i, p_{i+1}, p_k $ is right turn

5. Continue and find j such that $ p_j, p_{j+1}, p_k $ is left turn.

6. Return new convex polygon points such that. $ p_j, p_j+1, p_i , p_k $
