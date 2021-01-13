#include <iostream>

using namespace std;

/**
 *  Calculates the cost per day to have a user use a computer. 
 *
 *  Task 1:
 *      Change the hourly pay of the user for station1 to 14
 *
 *  Task 2:
 *      Add the ability to specify the number of hours in a workday using a
 *      variable defined in the 'main' function (not passed from the command
 *      line).
 *
 *  Task 3:
 *      Add functionality that computes and returns the total cost per hour for
 *      a user and a computer, then modify the 'main' function to output that
 *      cost per hour.
 */

class  Computer
{
  /**
   *  A computer with a consuption of kwh for kilowatts per hour.
   */
  protected:
       float  kwh; // kilowatts consumed per hour

  public:
      Computer()
      {
          kwh = 1;
      }
      Computer(float kwh)
      {
          this->kwh = kwh;
      }
      /**
       *  Calculates the cost to use the computer per hour.
       *  Cost per hour is a product of cost per watt and kilowatts used per
       *  hour.
       *      @param kw_cost The cost per kilowatt.
       *      @returns The cost per hour to use the computer.
       */
      float  compute_cost_per_hour(float kw_cost)
      {
          return (kw_cost * kwh);
      }
};

class User
{
  /**
   *  A user with a hourly salary.
   */
  protected:
      float   hourly_pay; // hourly rate of user
  public:
      User()
      {
          hourly_pay = 5;
      }
      User(float hourly_pay)
      {
          this->hourly_pay = hourly_pay;
      }
};

class  UsedComputer : public  Computer, public User
{
  /**
   *  A computer used by an operator for a day.
   */
  private:
       float hours_per_day; // hours per day a user works.
  public:
       UsedComputer()
       {
           hours_per_day = 8;
       }
       UsedComputer(float kwh, float hourly_pay)
       {
           hours_per_day = 8;
           this->kwh = kwh;
           this->hourly_pay = hourly_pay;
       }
       /**
	*  Gets the cost of a user and a computer for a workday.
	*      @param cost_of_kw The cost per kilowatt.
	*      @returns The cost of a user and computer for a workday.
	*/
       float compute_cost_per_full_day(float cost_of_kw)
       {
           float hourly_rate = (hourly_pay + compute_cost_per_hour(cost_of_kw));
           return (hours_per_day * hourly_rate);
       };
};

int  main()
{
   float cost_per_kw = 0.13; // The cost per kilowatt.
   UsedComputer station1(1.5, 12.50);
   cout<<"The cost per day for a user to use station1 is $"<<station1.compute_cost_per_full_day(cost_per_kw)<<"\n";

   return 0;
}
