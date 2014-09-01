/**
  Class: Data
  The Data Class stores information about a single data point's X and Y corodinates.
*/



#include "data.h"

/**
 * Data's constructor
 * @param xData - X coordinate of the data point
 * @param yData - Y coordinate of the data point
 */

Data::Data()
{

}

Data::Data(double xData, double yData)
{
    this->xData = xData;
    this->yData = yData;
}


/**
 * Method: getXData()
 * @return returns the X coordinate of the data point
 */
double Data::getXData()
{
    return xData;
}

/**
 * Method: getYData()
 * @return returns the Y coordinate of the data point
 */
double Data::getYData()
{
    return yData;
}

/**
 * Method setXData()
 * @param xData - The new X coordinate for the data point
 */
void Data::setXData(double xData)
{
    this->xData = xData;
}

/**
 * Method setYData()
 * @param yData - The new Y coordinate of the data point
 */
void Data::setYData(double yData)
{
    this->yData = yData;
}
