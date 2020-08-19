struct Point
{

double x;
double y;

};


struct Plot
{

struct Point points[5];
int size;

};


void  addPoint(struct Plot *pPlot, double x, double y);
struct Point getAverage(struct Plot pPlot);










