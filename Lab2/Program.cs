// Name: Sarah Ann Roy
// Student Number: 0650615
// COIS 4470H Lab 2 - Calculating the value of Pi using Monte Carlo Simulation
//Source: https://www.geeksforgeeks.org/estimating-value-pi-using-monte-carlo/
using System;
using System.Collections.Generic;

class MonteCarloPILab
{
	static int NO_OF_POINTS = 1000000; //total number of random points generated (points in the square)

	public static void Main(string[] args)
	{
		double MATH_PI = Math.PI; //actual value of pi
		var random = new Random();//Random number generator 
		double x, y, pi = 0; //calculated value of pi
		int circle_points = 0; //number of points in the circle

		for (int i = 0; i < NO_OF_POINTS; i++) //for-loop that creates random points (x,y)
		{

			// Randomly generated x and y values in the range [-1,1]
			x = (double)(random.Next() % (NO_OF_POINTS + 1)) / NO_OF_POINTS;
			y = (double)(random.Next() % (NO_OF_POINTS + 1)) / NO_OF_POINTS;

			// Checking and counting the number of points (x, y) that lies inside circle using equation (x * x) + (y * y) <= 1.
			if ((Math.Pow(x, 2) + Math.Pow(y, 2)) <= 1)
            {
				circle_points++; //increment counter for number of points in the circle
			}

			//Calculate pi for every iteration in the for-loop
			pi = ((4.0 * circle_points) / NO_OF_POINTS);
		}

		//Print total number of points
		Console.WriteLine($"Total Number of points = {NO_OF_POINTS}");

		//Print final approximation of pi
		Console.WriteLine($"Final Approximation of Pi = {pi}");

		//Calculating the Limits of Error
		double E = ((MATH_PI - pi) / MATH_PI) * 100;
		
		//Print Error Limit
		Console.WriteLine($"Error limit = {E}%");
	}
}