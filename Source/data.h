#ifndef DATA_H
#define DATA_H

class Data
{
public:
    Data();
    Data(double xData, double yData);
    double getXData();
    double getYData();
    void setXData(double xData);
    void setYData(double yData);
private:
    double xData;
    double yData;
};

#endif // DATA_H
