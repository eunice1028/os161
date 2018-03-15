/* 
 * stoplight.c
 *
 * 31-1-2003 : GWA : Stub functions created for CS161 Asst1.
 *
 * NB: You can use any synchronization primitives available to solve
 * the stoplight problem in this file.
 */


/*
 * 
 * Includes
 *
 */

#include <types.h>
#include <lib.h>
#include <test.h>
#include <thread.h>


/*
 *
 * Constants
 *
 */

/*
 * Number of cars created.
 */

#define NCARS 20

/*
 * enums for direction, turn, and stage of cars
 */

enum direction{North, East, South, West};
enum turn{Straight, Left, Right};
enum stage{Approach, Enter, Leave};

/*
 *
 * Func Definition
 *
 */
static void printcars(int carstage, int carnumber, int cardirection,int carturn);
int getdestination(int direction, int turn);

/*
 *
 * Function Definitions
 *
 */


/*
 * gostraight()
 *
 * Arguments:
 *      unsigned long cardirection: the direction from which the car
 *              approaches the intersection.
 *      unsigned long carnumber: the car id number for printing purposes.
 *
 * Returns:
 *      nothing.
 *
 * Notes:
 *      This function should implement passing straight through the
 *      intersection from any direction.
 *      Write and comment this function.
 */

static
void
gostraight(unsigned long cardirection,
           unsigned long carnumber)
{
        /*
         * Avoid unused variable warnings.
         */
        
        (void) cardirection;
        (void) carnumber;

	printcars(Enter, carnumber, cardirection, Straight);

	/**CAR TURN CODE HERE**/

	printcars(Leave, carnumber, cardirection, Straight);
}


/*
 * turnleft()
 *
 * Arguments:
 *      unsigned long cardirection: the direction from which the car
 *              approaches the intersection.
 *      unsigned long carnumber: the car id number for printing purposes.
 *
 * Returns:
 *      nothing.
 *
 * Notes:
 *      This function should implement making a left turn through the 
 *      intersection from any direction.
 *      Write and comment this function.
 */

static
void
turnleft(unsigned long cardirection,
         unsigned long carnumber)
{
        /*
         * Avoid unused variable warnings.
         */

        (void) cardirection;
        (void) carnumber;
	
	printcars(Enter, carnumber, cardirection, Left);

        /**CAR TURN CODE HERE**/

        printcars(Leave, carnumber, cardirection, Left);

}


/*
 * turnright()
 *
 * Arguments:
 *      unsigned long cardirection: the direction from which the car
 *              approaches the intersection.
 *      unsigned long carnumber: the car id number for printing purposes.
 *
 * Returns:
 *      nothing.
 *
 * Notes:
 *      This function should implement making a right turn through the 
 *      intersection from any direction.
 *      Write and comment this function.
 */

static
void
turnright(unsigned long cardirection,
          unsigned long carnumber)
{
        /*
         * Avoid unused variable warnings.
         */

        (void) cardirection;
        (void) carnumber;

	printcars(Enter, carnumber, cardirection, Right);

        /**CAR TURN CODE HERE**/

        printcars(Leave, carnumber, cardirection, Right);

}


/*
 * approachintersection()
 *
 * Arguments: 
 *      void * unusedpointer: currently unused.
 *      unsigned long carnumber: holds car id number.
 *
 * Returns:
 *      nothing.
 *
 * Notes:
 *      Change this function as necessary to implement your solution. These
 *      threads are created by createcars().  Each one must choose a direction
 *      randomly, approach the intersection, choose a turn randomly, and then
 *      complete that turn.  The code to choose a direction randomly is
 *      provided, the rest is left to you to implement.  Making a turn
 *      or going straight should be done by calling one of the functions
 *      above.
 */
 
static
void
approachintersection(void * unusedpointer,
                     unsigned long carnumber)
{
        int cardirection;
	int carturn; 

        /*
         * Avoid unused variable and function warnings.
         */

        (void) unusedpointer;
        //(void) carnumber;
	//(void) gostraight;
	//(void) turnleft;
	//(void) turnright;

        /*
         * cardirection  and turn is set randomly.
         */

        cardirection = random() % 4;
	carturn = random() %3;

	printcars(Approach, carnumber, cardirection, carturn);
	if(carturn == Straight)	
		gostraight(cardirection, carnumber);
	else if(carturn == Left)
		turnleft(cardirection, carnumber);
	else if(carturn == Right)
		turnright(cardirection, carnumber);
}

/*
 * getdestination()
 * Arguments:
 * 	int direction: starting direction
 * 	int turn: turning direction
 *
 * Returns:
 * 	int: destination
 *
 * Notes:
 * 	Calculates car's destination
 */

int getdestination(int direction, int turn)
{
	if(direction == North)
	{
		if(turn == Straight)
			return South;
		if(turn == Left)
			return East;
		if(turn == Right)
			return West;
	}
	if(direction == East)
        {
                if(turn == Straight)
                        return West;
                if(turn == Left)
                        return South;
                if(turn == Right)
                        return North;
        }
	if(direction == South)
        {
                if(turn == Straight)
                        return North;
                if(turn == Left)
                        return West;
                if(turn == Right)
                        return East;
        }
	if(direction == West)
        {
                if(turn == Straight)
                        return East;
                if(turn == Left)
                        return North;
                if(turn == Right)
                        return South;
        }
	return 0;
}


/*
 * printcars()
 * Arguments:
 * 	int stage: what stage the car is in (Approach, Enter, Leave)
 * 	int carnumber: car id
 * 	int cardirection: starting car direction
 * 	int carturn: car's turn
 * Returns:
 * 	nothing
 *
 * Notes:
 * 	Prints output for each car including car number, approach direction, 
 * 	and destination direction
 */

static void printcars(int carstage, int carnumber, int cardirection, int carturn)
{	
	char stage[25];
	char direction[25];
	char destination[25];

	//Fget stage string
	if(carstage == Approach) 
		strcpy(stage, "APPROACHING");
	else if(carstage == Enter) 
		if(carturn == Straight)
			strcpy(stage, "GOING STRAIGHT");
		else if(carturn == Left)
			strcpy(stage, "TURNING LEFT");
		else
			strcpy(stage, "TURNING RIGHT");
	else if(carstage == Leave)
		strcpy(stage, "LEAVING");

	//get starting direction string
	if(cardirection == North)
		strcpy(direction, "NORTH");
	else if(cardirection == East)
		strcpy(direction, "EAST");
	else if(cardirection == South)
                strcpy(direction, "SOUTH");
	else if(cardirection == West)
                strcpy(direction, "WEST");

	//get destination string
	int destvalue = getdestination(cardirection, carturn);
	if(destvalue == North)
                strcpy(direction, "NORTH");
        else if(destvalue == East)
                strcpy(direction, "EAST");
        else if(destvalue == South)
                strcpy(direction, "SOUTH");
        else if(destvalue == West)
                strcpy(direction, "WEST");

	//print strings
	kprintf("car %d is %s from the %s, going towards the %s\n", 
		carnumber, stage, direction, destination);
}


/*
 * createcars()
 *
 * Arguments:
 *      int nargs: unused.
 *      char ** args: unused.
 *
 * Returns:
 *      0 on success.
 *
 * Notes:
 *      Driver code to start up the approachintersection() threads.  You are
 *      free to modiy this code as necessary for your solution.
 */

int
createcars(int nargs,
           char ** args)
{
        int index, error;

        /*
         * Avoid unused variable warnings.
         */

        (void) nargs;
        (void) args;

        /*
         * Start NCARS approachintersection() threads.
         */

        for (index = 0; index < NCARS; index++) {

                error = thread_fork("approachintersection thread",
                                    NULL,
                                    index,
                                    approachintersection,
                                    NULL
                                    );

                /*
                 * panic() on error.
                 */

                if (error) {
                        
                        panic("approachintersection: thread_fork failed: %s\n",
                              strerror(error)
                              );
                }
        }

        return 0;
}
