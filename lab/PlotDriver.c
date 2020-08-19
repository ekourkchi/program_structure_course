/*****************************************************************
//
//  NAME:        Christopher Foo
//
//  HOMEWORK:    N/A
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Julia Patriarche / Ravi Narayan
//
//  DATE:        September 17, 2013
//
//  FILE:        PlotDriver.c
//
//  DESCRIPTION: This file contains the functions used to run a simple
//               interface for testing the Plot and Point structs.
//
//****************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Plot.h"

int menu(struct Plot *pPlot);
void addPointInterface(struct Plot * pPlot);
void printPlot(struct Plot plot);
void printAverage(struct Plot plot);
int readInt(char *prompt);
double readDouble(char *prompt);
void clearBuffer(char *input);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Runs the interface.
//
//  Parameters:    Nothing.
//
//  Return values: 0 = Success!
//
//****************************************************************/

int main(void)
{

    struct Plot plot;
    int action = 0;
    plot.size = 0;

    /* For Eclipse */
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("Welcome to a Simple C Plotter!\n\n");

    while (action != 4)
    {
        action = menu(&plot);
    }

    return 0;
}

/*****************************************************************
//
//  Function name: menu
//
//  DESCRIPTION:   Prints the options for the user and chooses the appropriate
//                 action based on the user's input.
//
//  Parameters:    pPlot (Plot *): A pointer to the plot that will be manipulated.
//
//  Return values: The user's choice as an int.
//
//****************************************************************/

int menu(struct Plot *pPlot)
{
    int action;
    printf(
            "Options:\n  1. Add a point to the plot\n  2. Print the points in the plot\n  3. Find the average of the plot\n  4. Exit\n");
    action = readInt("Please enter the number of an action: ");
    printf("\n");
    switch (action)
    {
        case 1:
            addPointInterface(pPlot);
            break;
        case 2:
            printPlot(*pPlot);
            break;
        case 3:
            printAverage(*pPlot);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid command.  Please enter a number between 1 and 4.\n");
            break;
    }
    printf("\n");
    return action;

}

/*****************************************************************
//
//  Function name: addPointInterface
//
//  DESCRIPTION:   Prompts the user for the coordinates of a new point and
//                 adds it to the end of the Plot.
//
//  Parameters:    pPlot (Plot *): A pointer to the Plot that the new point will be added to.
//
//  Return values: Nothing.
//
//****************************************************************/

void addPointInterface(struct Plot * pPlot)
{
    double x, y;

    if (pPlot && pPlot->size < 5)
    {
        x = readDouble("Enter the x coordinate of the new point: ");
        y = readDouble("Enter the y coordinate of the new point: ");

        addPoint(pPlot, x, y);
    }
    else
    {
        printf("Error: Plot is full.\n");
    }
}

/*****************************************************************
//
//  Function name: printPlot
//
//  DESCRIPTION:   Prints all of the points in the Plot.
//
//  Parameters:    plot (Plot): The Plot that will be printed.
//
//  Return values: Nothing.
//
//****************************************************************/

void printPlot(struct Plot plot)
{
    int i;

    if (plot.size == 0)
    {
        printf("Plot is empty!\n");
    }
    else
    {
        for (i = 0; i < plot.size; i++)
        {
            printf("[%d] = (%f, %f)\n", i, plot.points[i].x, plot.points[i].y);
        }
    }
}

/*****************************************************************
//
//  Function name: printAverage
//
//  DESCRIPTION:   Print's the point the average of the Plot.
//
//  Parameters:    plot (Plot): The Plot that will have its average printed.
//
//  Return values: Nothing.
//
//****************************************************************/

void printAverage(struct Plot plot)
{
    struct Point average;
    if (plot.size == 0)
    {
        printf("The plot is empty!\n");
    }
    else
    {
        average = getAverage(plot);
        printf("The average is (%f, %f).\n", average.x, average.y);
    }
}

/*****************************************************************
//
//  Function name: readInt
//
//  DESCRIPTION:   Prompts the user for a int and reads it.
//
//  Parameters:    prompt (char *): The prompt that will be printed for the user.
//
//  Return values: The user's input as an int.
//
//****************************************************************/

int readInt(char *prompt)
{
    int value;
    char input[50];
    if (prompt)
    {
        printf("%s", prompt);
    }
    fgets(input, 50, stdin);
    clearBuffer(input);
    value = atoi(input);
    return value;
}

/*****************************************************************
//
//  Function name: readDouble
//
//  DESCRIPTION:   Prompts the user for a double and reads it.
//
//  Parameters:    prompt (char *): The prompt that will be printed for the user.
//
//  Return values: The user's input as a double.
//
//****************************************************************/

double readDouble(char *prompt)
{
    double value;
    char input[50];
    if (prompt)
    {
        printf("%s", prompt);
    }
    fgets(input, 50, stdin);
    clearBuffer(input);
    value = atof(input);
    return value;
}

/*****************************************************************
//
//  Function name: clearBuffer
//
//  DESCRIPTION:   Clears any extra user input from the STDIN buffer.
//
//  Parameters:    input (char *): The user input that was successfully read with fgets.
//
//  Return values: Nothing.
//
//****************************************************************/

void clearBuffer(char *input)
{
    int indexOfLast;
    if (input)
    {
        indexOfLast = strlen(input) - 1;
        if (input[indexOfLast] != '\n')
        {
            while (getchar() != '\n')
                ;
        }
    }
}

