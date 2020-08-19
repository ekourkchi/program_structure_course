# include "Plot.h"

void addPoint (struct Plot *pPlot, double x, double y)
{

if (pPlot->size < 5)
{

  pPlot->points[pPlot->size].x = x;
  pPlot->points[pPlot->size].y = y;
  pPlot->size ++;

}

}




struct Point getAverage(struct Plot pPlot)
{


double avg_x = 0;
double avg_y = 0;
int i;
struct Point avpoint;

avpoint.x = 0.;
avpoint.y = 0.;

if (pPlot.size == 0) return avpoint;

for (i=0; i < pPlot.size; i++)
{

avg_x += pPlot.points[i].x;
avg_y += pPlot.points[i].y;

}


avpoint.x = avg_x / pPlot.size;
avpoint.y = avg_y / pPlot.size;

return avpoint;



}

