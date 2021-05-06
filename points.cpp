#include <bits/stdc++.h>
using namespace std;

struct Point
{
    float x, y;
};

// 0 - collinear
// 1 - clockwise
// 2 - counterclockwise
int orientation(Point p, Point q, Point r)
{
    float m = (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y); 
    if(m<0) return 2;
    else if(m>0) return 1;
    else return 0;
}

// finds intersecting point of 2 lines
Point intersection(Point l1[2], Point l2[2])
{ 
    // finds different constant in the eqn: A1x + B1y = C1
    int A1 = l1[1].y-l1[0].y;
    int B1 = l1[1].x-l1[0].x;
    int C1 = A1*l1[0].x + B1*l1[0].y;

    int A2 = l2[1].y-l2[0].y;
    int B2 = l2[1].x-l2[0].x;
    int C2 = A2*l2[0].x + B2*l2[0].y;
    
    int det = A1 * B2 - A2 * B1;
    Point ans;
    if (det == 0) { // if lines are parallel
        ans.x = -INT_MAX;
        ans.y = -INT_MAX;
    } else {    // if there exists intersecting points
        float x = (B2 * C1 - B1 * C2) / det;
        float y = (A1 * C2 - A2 * C1) / det;
        ans.x = x;
        ans.y = y;
    }
    return ans;
}

int main()
{
    // Array of pair of points
    Point p[][2] = {{{253, 451}, {424, 449}}, {{90, 548}, {346, 531}}, {{114, 334}, {399, 348}}, {{189, 415}, {308, 415}}, {{212, 473}, {317, 470}}, {{239, 396}, {371, 398}}, {{241, 393}, {370, 395}}, {{73, 522}, {378, 507}}, {{189, 412}, {307, 412}}, {{218, 434}, {373, 434}}, {{258, 454}, {387, 452}}, {{104, 346}, {114, 157}}, {{108, 205}, {286, 224}}, {{101, 330}, {398, 345}}, {{128, 569}, {332, 552}}, {{25, 622}, {53, 302}}, {{28, 618}, {56, 305}}, {{154, 194}, {373, 221}}, {{86, 546}, {348, 528}}, {{182, 375}, {294, 378}}, {{107, 296}, {391, 315}}, {{189, 519}, {348, 511}}, {{439, 379}, {457, 546}}, {{96, 568}, {289, 552}}, {{219, 496}, {368, 491}}, {{107, 273}, {338, 293}}, {{122, 278}, {346, 297}}, {{269, 360}, {383, 364}}, {{112, 240}, {385, 269}}, {{208, 234}, {427, 253}}, {{150, 128}, {280, 150}}, {{131, 614}, {274, 587}}, {{100, 358}, {110, 170}}, {{143, 37}, {361, 56}}, {{107, 258}, {405, 284}}, {{420, 192}, {432, 306}}, {{76, 525}, {221, 518}}, {{115, 606}, {277, 584}}, {{137, 593}, {366, 573}}, {{139, 316}, {359, 331}}, {{266, 375}, {387, 379}}, {{122, 312}, {335, 326}}, {{137, 188}, {322, 214}}, {{111, 155}, {265, 177}}, {{251, 223}, {428, 242}}, {{178, 353}, {283, 357}}, {{243, 114}, {359, 120}}, {{92, 105}, {290, 132}}, {{234, 431}, {366, 431}}, {{94, 522}, {108, 315}}, {{275, 242}, {476, 260}}, {{308, 413}, {442, 413}}, {{54, 391}, {168, 391}}, {{110, 293}, {309, 307}}, {{427, 273}, {440, 399}}, {{272, 104}, {378, 104}}, {{48, 363}, {60, 232}}, {{109, 202}, {240, 218}}, {{56, 281}, {75, 73}}, {{207, 169}, {351, 189}}, {{321, 135}, {429, 145}}, {{169, 262}, {382, 280}}, {{105, 289}, {114, 114}}, {{111, 247}, {121, 95}}, {{380, 328}, {391, 492}}, {{92, 186}, {305, 212}}, {{68, 194}, {80, 63}}, {{84, 622}, {91, 481}}, {{179, 102}, {292, 115}}, {{6, 260}, {6, 158}}, {{121, 221}, {254, 237}}, {{104, 364}, {112, 241}}, {{355, 250}, {367, 382}}, {{0, 436}, {135, 436}}, {{230, 303}, {357, 312}}, {{198, 216}, {384, 236}}, {{198, 267}, {345, 280}}, {{259, 116}, {389, 127}}, {{350, 548}, {455, 544}}, {{105, 206}, {271, 223}}, {{2, 119}, {3, 219}}, {{51, 365}, {62, 246}}, {{164, 177}, {285, 194}}, {{105, 256}, {213, 265}}, {{109, 223}, {258, 238}}, {{157, 279}, {391, 299}}, {{166, 38}, {325, 52}}, {{173, 246}, {353, 265}}, {{163, 316}, {271, 323}}};
    int num_lines = sizeof(p)/sizeof(p[0]);
    
    // finds max and min in x-coordinates & max and min in y-coordinates 
    float maxX=INT_MIN, minY=INT_MAX, maxY=INT_MIN, minX=INT_MAX;
    for(int i=0; i<num_lines; i++)
    {
        maxX = max(maxX, p[i][0].x);
        maxY = max(maxY, p[i][0].y);
        minX = min(minX, p[i][0].x);
        minY = min(minY, p[i][0].y);

        maxX = max(maxX, p[i][1].x);
        maxY = max(maxY, p[i][1].y);
        minX = min(minX, p[i][1].x);
        minY = min(minY, p[i][1].y);
        
    }

    // stores intersecting points of each pair of lines
    vector<Point> v;
    for(int i=0; i<num_lines; i++)
    {
        for(int j=i+1; j<num_lines; j++)
        {
            Point inter = intersection(p[i], p[j]);
            // if lines are paralllel
            if(inter.x==-INT_MAX and inter.y==-INT_MAX) continue;
            // stores point in the vector if they are in the range of given points
            if(inter.x>=minX and inter.x<=maxX and inter.y>=minY and inter.y<=maxY) v.push_back(inter);
        }
    }
    vector<Point> hull;
    // finds the leftmost point
    int n=v.size(), l=0;
    for(int i=1; i<n; i++)
    {
        if(v[i].x<v[l].x) l=i;
    }
    // iterates till we come again from where we started and goes counterclockwise
    int start=l, next;
    do
    {
        hull.push_back(v[start]);
        next=(start+1)%n;
        // replaces 'next' point with the one which has more slope that current one
        for(int i=0; i<n; i++)
        {
            if(orientation(v[start], v[i], v[next])==2) next=i;
        }
        start=next;
    }while(start!=l);
    // prints set of points which represents the hull of the convex shape formed
    for(int i=0; i<hull.size(); i++)
    {
        cout << "(" << hull[i].x << ", " << hull[i].y << ")" << endl;
    }
    return 0;
}